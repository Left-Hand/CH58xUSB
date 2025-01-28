#pragma once

#include "usb/hiddev/hiddev.hpp"

class HidJoytick:public UsbHidDeviceBase{
public:
    using UsbHidDeviceBase::UsbHidDeviceBase;
    struct DataFrame{
        #pragma pack(push, 1)
        int8_t throttle;
        int8_t x;
        int8_t y;

        uint8_t hat:4;
        uint8_t buttons:4;

        #pragma pack(pop)
    };

    constexpr std::span<const uint8_t> getReportDescr() const {return joystick_descr;}

    constexpr __UsbEndpointDescr getEndpointDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.iaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = sizeof(DataFrame),
            .bInterval = 10//10ms
        };
    }

    constexpr __UsbHidClassDescr getHidClassDescr() const{
        return __UsbHidClassDescr{
            .bcdHID = BcdUsb::V1_12,
            .bCountryCode = CountryCode::None,
            .bNumDescriptors = 1,
            .bDescriptorType2 = HidDescrType::Report,
            .wDescriptorLength = uint16_t(getReportDescr().size())
        };
    }

    constexpr __UsbInterfaceDescr getInterfaceDescr(const uint8_t interfaceNumber) const{
        return __UsbInterfaceDescr{
            .bInterfaceNumber = interfaceNumber,
            .bAlternateSetting = 0,//没有额外配置
            .bNumEndpoints = 1,//只有一个端点
            .bInterfaceClass = UsbClassCode::HID,
            .bInterfaceSubClass = HidSubClassCode::None,
            .bInterfaceProtocol = HidProtocolCode::None,
            .iInterface = 0//为0使用默认描述
        };
    }

};


// 　　　　0x09, //bLength 描述符的字节数长度 标准为0x09
// 　　　　0x04, //bDescriptorType 描述符的类型 0x04为接口描述符
// 　　　　0x00, //bInterfaceNumber 接口号，当前配置支持的接口数组索引（从0开始）。
// 　　　　　　　　//若该配置有俩接口，接下来的接口描述符此值就为1
// 　　　　0x00, //bAlternateSetting 可选设置的索引值。一个接口可以有多个接口描述符，靠此字段区分
// 　　　　0x01, //bNumEndpoints 除了USB设备必须支持的端点0外，此接口所包括的端点的个数。此值为0表示该接口只使用端点0。
// 　　　　0x03, //bInterfaceClass 接口所属的类值。为0表示为将来的标准保留。为FF表示此接口类由厂商说明。其他值查手册。0x03为HID类
// 　　　　0x00, //bInterfaceSublass 接口所属子类的值。根据手册以及bInterfaceClass的值来定，若上面的值为0，此值也要为0。
// 　　　　0x00, //bInterfaceProtocol 协议码，视手册以及上两者而定。上两者为0，此值也要为0。
// 　　　　0x00, //iInterface 此接口的字符串描述符的索引值。
// 　　//HID类描述符↓
// 　　　　0x09, //bLength 描述符的字节数长度 标准为0x09
// 　　　　0x21, //bDescriptorType 描述符的类型 0x21为人机接口类描述符
// 　　　　0x12, 0x01, //bcdHID HID规范版本号的BCD码，此描述符所用版本为1.12
// 　　　　0x00, //bCountryCode 硬件目的国家的识别号码。不启用此功能则为0
// 　　　　0x01, //bNumDescriptors 支持的附属描述符数目。最小值为1：HID类至少有个报表描述符
// 　　　　0x22, //bDescriptorType 类别描述符的类型。只有报表描述符为0x22；还有个实体描述符则为0x23
// 　　　　0x4e, 0x00, //wDescriptorLength 报表描述符总长度
// 　　//端点描述符↓
// 　　　　0x07, //bLength 描述符的字节数长度 标准为0x07
// 　　　　0x05, //bDescriptorType 描述符的类型 0x05为端点描述符
// 　　　　0x81, //bmEndpointAddress 低四位为端点号，最高位为0：OUT方向，为1：IN方向。其他位保留。
// 　　　　0x03, //bmAttributes 低两位为 00：控制传输；01：实时传输；10：批量传输；11：中断传输。其他位保留
// 　　　　0x08, 0x00, //bMaxPacketSize 端点收发的数据包最大净长度
// 　　　　0x0a, //bInterval 周期数据传输端点的时间间隙。对于批量和控制传输来说无意义
// 　　　　　　//若该端点配置实时传输，此值必须为1（ms）；若该端点配置中断传输，此值为1～255（ms）