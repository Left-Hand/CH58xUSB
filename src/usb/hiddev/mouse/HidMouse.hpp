#pragma once

#include "usb/hiddev/hiddev.hpp"


class HidMouse:public UsbHidDeviceBase{
public:
    using UsbHidDeviceBase::UsbHidDeviceBase;
    struct DataFrame:public U8Intf{
    #pragma pack(push, 1)

    uint8_t left_click:1;
    uint8_t right_click:1;
    uint8_t middle_click:1;
    const uint8_t __resv__:5 = 0;

    int8_t x_delta;
    int8_t y_delta;
    int8_t wheel_delta;
    

    #pragma pack(pop)
    };

    std::span<const uint8_t> getReportDescr() const{return mouse_descr;}
    __UsbEndpointDescr getEndpointDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.iaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = sizeof(DataFrame),
            .bInterval = 10//10ms
        };
    }

    __UsbHidClassDescr getHidClassDescr() const{
        return __UsbHidClassDescr{
            .bcdHID = BcdUsb::V1_1,
            .bCountryCode = CountryCode::None,
            .bNumDescriptors = 1,
            .bDescriptorType2 = HidDescrType::Report,
            .wDescriptorLength = uint16_t(getReportDescr().size())
        };
    }

    __UsbInterfaceDescr getInterfaceDescr(const uint8_t interfaceNumber) const{
        return __UsbInterfaceDescr{
            .bInterfaceNumber = interfaceNumber,
            .bAlternateSetting = 0,//没有额外配置
            .bNumEndpoints = 1,//只有一个端点
            .bInterfaceClass = UsbClassCode::HID,
            .bInterfaceSubClass = HidSubClassCode::Boot,
            .bInterfaceProtocol = HidProtocolCode::Mouse,
            .iInterface = 0//为0使用默认描述
        };
    }


    void report(const DataFrame & data){
        ep_.ideal({data.data(), sizeof(DataFrame)});
    }

};


using HidMouseDataFrame = HidMouse::DataFrame;