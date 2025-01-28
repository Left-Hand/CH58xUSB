#pragma once

#include "usb/hiddev/hiddev.hpp"

scexpr uint8_t touchpad_descr[] = {
//TOUCH PAD input TLC
    0x05, 0x0d,                         // USAGE_PAGE (Digitizers)          
    0x09, 0x05,                         // USAGE (Touch Pad)             
    0xa1, 0x01,                         // COLLECTION (Application)         
    // 0x85, REPORTID_TOUCHPAD,            //   REPORT_ID (Touch pad)              
    // 0x09, 0x22,                         //   USAGE (Finger)                 
    // 0xa1, 0x02,                         //   COLLECTION (Logical)  
    // 0x15, 0x00,                         //       LOGICAL_MINIMUM (0)
    // 0x25, 0x01,                         //       LOGICAL_MAXIMUM (1)
    // 0x09, 0x47,                         //       USAGE (Confidence) 
    // 0x09, 0x42,                         //       USAGE (Tip switch)
    // 0x95, 0x02,                         //       REPORT_COUNT (2)
    // 0x75, 0x01,                         //       REPORT_SIZE (1)
    // 0x81, 0x02,                         //       INPUT (Data,Var,Abs)
    // 0x95, 0x01,                         //       REPORT_COUNT (1)
    // 0x75, 0x02,                         //       REPORT_SIZE (2)
    // 0x25, 0x02,                         //       LOGICAL_MAXIMUM (2)
    // 0x09, 0x51,                         //       USAGE (Contact Identifier)
    // 0x81, 0x02,                         //       INPUT (Data,Var,Abs)
    // 0x75, 0x01,                         //       REPORT_SIZE (1)
    // 0x95, 0x04,                         //       REPORT_COUNT (4)             
    // 0x81, 0x03,                         //       INPUT (Cnst,Var,Abs)
    // 0x05, 0x01,                         //       USAGE_PAGE (Generic Desk..
    // 0x15, 0x00,                         //       LOGICAL_MINIMUM (0)
    // 0x26, 0xff, 0x0f,                   //       LOGICAL_MAXIMUM (4095)         
    // 0x75, 0x10,                         //       REPORT_SIZE (16)             
    // 0x55, 0x0e,                         //       UNIT_EXPONENT (-2)           
    // 0x65, 0x13,                         //       UNIT(Inch,EngLinear)                  
    // 0x09, 0x30,                         //       USAGE (X)                    
    // 0x35, 0x00,                         //       PHYSICAL_MINIMUM (0)         
    // 0x46, 0x90, 0x01,                   //       PHYSICAL_MAXIMUM (400)
    // 0x95, 0x01,                         //       REPORT_COUNT (1)         
    // 0x81, 0x02,                         //       INPUT (Data,Var,Abs)         
    // 0x46, 0x13, 0x01,                   //       PHYSICAL_MAXIMUM (275)
    // 0x09, 0x31,                         //       USAGE (Y)                    
    // 0x81, 0x02,                         //       INPUT (Data,Var,Abs)    
    // 0xc0,                               //    END_COLLECTION
    // 0x55, 0x0C,                         //    UNIT_EXPONENT (-4)           
    // 0x66, 0x01, 0x10,                   //    UNIT (Seconds)        
    // 0x47, 0xff, 0xff, 0x00, 0x00,      //     PHYSICAL_MAXIMUM (65535)
    // 0x27, 0xff, 0xff, 0x00, 0x00,         //  LOGICAL_MAXIMUM (65535) 
    // 0x75, 0x10,                           //  REPORT_SIZE (16)             
    // 0x95, 0x01,                           //  REPORT_COUNT (1) 
    // 0x05, 0x0d,                         //    USAGE_PAGE (Digitizers)
    // 0x09, 0x56,                         //    USAGE (Scan Time)    
    // 0x81, 0x02,                           //  INPUT (Data,Var,Abs)         
    // 0x09, 0x54,                         //    USAGE (Contact count)
    // 0x25, 0x7f,                           //  LOGICAL_MAXIMUM (127) 
    // 0x95, 0x01,                         //    REPORT_COUNT (1)
    // 0x75, 0x08,                         //    REPORT_SIZE (8)    
    // 0x81, 0x02,                         //    INPUT (Data,Var,Abs)
    // 0x05, 0x09,                         //    USAGE_PAGE (Button)         
    // 0x09, 0x01,                         //    USAGE_(Button 1)     
    // 0x25, 0x01,                         //    LOGICAL_MAXIMUM (1)          
    // 0x75, 0x01,                         //    REPORT_SIZE (1)              
    // 0x95, 0x01,                         //    REPORT_COUNT (1)             
    // 0x81, 0x02,                         //    INPUT (Data,Var,Abs)
    // 0x95, 0x07,                          //   REPORT_COUNT (7)                 
    // 0x81, 0x03,                         //    INPUT (Cnst,Var,Abs)
    // 0x05, 0x0d,                         //    USAGE_PAGE (Digitizer)
    // 0x85, REPORTID_MAX_COUNT,            //   REPORT_ID (Feature)              
    // 0x09, 0x55,                         //    USAGE (Contact Count Maximum)
    // 0x09, 0x59,                         //    USAGE (Pad TYpe)
    // 0x75, 0x04,                         //    REPORT_SIZE (4) 
    // 0x95, 0x02,                         //    REPORT_COUNT (2)
    // 0x25, 0x0f,                         //    LOGICAL_MAXIMUM (15)
    // 0xb1, 0x02,                         //    FEATURE (Data,Var,Abs)
    // 0x06, 0x00, 0xff,                   //    USAGE_PAGE (Vendor Defined)
    // 0x85, REPORTID_PTPHQA,               //    REPORT_ID (PTPHQA)  
    // 0x09, 0xC5,                         //    USAGE (Vendor Usage 0xC5)    
    // 0x15, 0x00,                         //    LOGICAL_MINIMUM (0)          
    // 0x26, 0xff, 0x00,                   //    LOGICAL_MAXIMUM (0xff) 
    // 0x75, 0x08,                         //    REPORT_SIZE (8)             
    // 0x96, 0x00, 0x01,                   //    REPORT_COUNT (0x100 (256))             
    // 0xb1, 0x02,                         //    FEATURE (Data,Var,Abs)
    // 0xc0,                               // END_COLLECTION
    // //CONFIG TLC
    // 0x05, 0x0d,                         //    USAGE_PAGE (Digitizer)
    // 0x09, 0x0E,                         //    USAGE (Configuration)
    // 0xa1, 0x01,                         //   COLLECTION (Application)
    // 0x85, REPORTID_FEATURE,             //   REPORT_ID (Feature)              
    // 0x09, 0x22,                         //   USAGE (Finger)              
    // 0xa1, 0x02,                         //   COLLECTION (logical)     
    // 0x09, 0x52,                         //    USAGE (Input Mode)         
    // 0x15, 0x00,                         //    LOGICAL_MINIMUM (0)      
    // 0x25, 0x0a,                         //    LOGICAL_MAXIMUM (10)
    // 0x75, 0x08,                         //    REPORT_SIZE (8)         
    // 0x95, 0x01,                         //    REPORT_COUNT (1)         
    // 0xb1, 0x02,                         //    FEATURE (Data,Var,Abs    
    // 0xc0,                               //   END_COLLECTION
    // 0x09, 0x22,                         //   USAGE (Finger)              
    // 0xa1, 0x00,                         //   COLLECTION (physical)     
    // 0x85, REPORTID_FUNCTION_SWITCH,     //     REPORT_ID (Feature)              
    // 0x09, 0x57,                         //     USAGE(Surface switch)
    // 0x09, 0x58,                         //     USAGE(Button switch)
    // 0x75, 0x01,                         //     REPORT_SIZE (1)
    // 0x95, 0x02,                         //     REPORT_COUNT (2)
    // 0x25, 0x01,                         //     LOGICAL_MAXIMUM (1)
    // 0xb1, 0x02,                         //     FEATURE (Data,Var,Abs)
    // 0x95, 0x06,                         //     REPORT_COUNT (6)             
    // 0xb1, 0x03,                         //     FEATURE (Cnst,Var,Abs)
    // 0xc0,                               //   END_COLLECTION
    // 0xc0,                               // END_COLLECTION
    // //MOUSE TLC
    // 0x05, 0x01,                         // USAGE_PAGE (Generic Desktop)     
    // 0x09, 0x02,                         // USAGE (Mouse)                    
    // 0xa1, 0x01,                         // COLLECTION (Application)        
    // 0x85, REPORTID_MOUSE,               //   REPORT_ID (Mouse)              
    // 0x09, 0x01,                         //   USAGE (Pointer)                
    // 0xa1, 0x00,                         //   COLLECTION (Physical)          
    // 0x05, 0x09,                         //     USAGE_PAGE (Button)          
    // 0x19, 0x01,                         //     USAGE_MINIMUM (Button 1)     
    // 0x29, 0x02,                         //     USAGE_MAXIMUM (Button 2)     
    // 0x25, 0x01,                         //     LOGICAL_MAXIMUM (1)          
    // 0x75, 0x01,                         //     REPORT_SIZE (1)              
    // 0x95, 0x02,                         //     REPORT_COUNT (2)             
    // 0x81, 0x02,                         //     INPUT (Data,Var,Abs)         
    // 0x95, 0x06,                         //     REPORT_COUNT (6)             
    // 0x81, 0x03,                         //     INPUT (Cnst,Var,Abs)         
    // 0x05, 0x01,                         //     USAGE_PAGE (Generic Desktop) 
    // 0x09, 0x30,                         //     USAGE (X)                    
    // 0x09, 0x31,                         //     USAGE (Y)                    
    // 0x75, 0x10,                         //     REPORT_SIZE (16)             
    // 0x95, 0x02,                         //     REPORT_COUNT (2)             
    // 0x25, 0x0a,                          //    LOGICAL_MAXIMUM (10)      
    // 0x81, 0x06,                         //     INPUT (Data,Var,Rel)         
    // 0xc0,                               //   END_COLLECTION                 
    // 0xc0,                                //END_COLLECTION
};

class HidTouchPad:public UsbHidDeviceBase{
public:
    using UsbHidDeviceBase::UsbHidDeviceBase;

    struct DataFrame:public U8Intf{


    #pragma pack(push, 1)

    struct FingerData{
        bool pressed;
        uint8_t finger_id;
        uint16_t x;
        uint16_t y;
        uint16_t radius;
    };

    uint8_t report_id;
    FingerData fingers[5];
    uint8_t left_click:1;
    uint8_t right_click:1;
    uint8_t middle_click:1;
    const uint8_t __resv__:5 = 0;

    int8_t x_delta;
    int8_t y_delta;
    int8_t wheel_delta;
    

    #pragma pack(pop)
    };

    constexpr std::span<const uint8_t> getReportDescr() const{return touchpad_descr;}

// 　　　　0x07, //bLength 描述符的字节数长度 标准为0x07
// 　　　　0x05, //bDescriptorType 描述符的类型 0x05为端点描述符
// 　　　　0x81, //bmEndpointAddress 低四位为端点号，最高位为0：OUT方向，为1：IN方向。其他位保留。
// 　　　　0x03, //bmAttributes 低两位为 00：控制传输；01：实时传输；10：批量传输；11：中断传输。其他位保留
// 　　　　0x08, 0x00, //bMaxPacketSize 端点收发的数据包最大净长度
// 　　　　0x0a, //bInterval 周期数据传输端点的时间间隙。对于批量和控制传输来说无意义
// 　　　　　　//若该端点配置实时传输，此值必须为1（ms）；若该端点配置中断传输，此值为1～255（ms）

    constexpr __UsbEndpointDescr getEndpointDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.iaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = 8,
            .bInterval = 10//10ms
        };
    }

// 　　//HID类描述符↓
// 　　　　0x09, //bLength 描述符的字节数长度 标准为0x09
// 　　　　0x21, //bDescriptorType 描述符的类型 0x21为人机接口类描述符
// 　　　　0x12, 0x01, //bcdHID HID规范版本号的BCD码，此描述符所用版本为1.12
// 　　　　0x00, //bCountryCode 硬件目的国家的识别号码。不启用此功能则为0
// 　　　　0x01, //bNumDescriptors 支持的附属描述符数目。最小值为1：HID类至少有个报表描述符
// 　　　　0x22, //bDescriptorType 类别描述符的类型。只有报表描述符为0x22；还有个实体描述符则为0x23
// 　　　　0x4e, 0x00, //wDescriptorLength 报表描述符总长度
    constexpr __UsbHidClassDescr getHidClassDescr() const{
        return __UsbHidClassDescr{
            .bcdHID = BcdUsb::V1_12,
            .bCountryCode = CountryCode::None,
            .bNumDescriptors = 1,
            .bDescriptorType2 = HidDescrType::Report,
            .wDescriptorLength = uint16_t(getReportDescr().size())
        };
    }

// 　　//接口描述符↓
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


    void report(const DataFrame & data){
        ep_.ideal({data.data(), sizeof(DataFrame)});
    }

};

// 　　// 配置描述符↓
// 　　　　0x09, //bLength 描述符的字节数长度 标准为0x09
// 　　　　0x02, //bDescriptorType 描述符的类型 0x02为配置描述符
// 　　　　0x22, 0x00, //wTotalLength 配置信息的总长（包括配置、接口、端点、类和厂商描述符）
// 　　　　0x01, //bNumInterfaces 该配置所支持的接口数目
// 　　　　0x01, //bConfigurationValue 被SET_CONFIGURATION请求用作参数来选定
// 　　　　0x00, //iConfiguration 该配置的字符串描述符索引值，在SET_CONFIGURATION中用作选定配置的参数
// 　　　　0xA0, //bmAttributes D6：自供电 D5：远程唤醒 其他位保留。
// 　　　　　　　　//若一个设备既能自供电又能使用总线供电，D6也要置1并在MaxPower指出需要从总线获取的电量
// 　　　　0x32, //MaxPower 该配置下的总线电源耗费量，为两倍此值（如0x32*2 = 100）mA

