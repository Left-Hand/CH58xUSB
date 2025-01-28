#pragma once

const uint8_t gamepad_descr[] = { //HID1.0版本协议，双向传输HID兼容设备
    0x06, 0x00, 0xFF,   //UsagePage(Vendor-defined)　　厂商自定义用法或功能（在UsagePage使用了“厂商自定义”之后，以下的Usage都为厂商自定义，这里我都写0xFF了，厂商能够自行区分就好。在使用了标准的UsagePage后，Usage才需要继续查表格去得到标准值）
    0x09, 0xFF,     //Usage　　自定义
    0xA1, 0xFF,     //Collection(Vendor-defined)　　厂商自定义集合

        0x09, 0xFF,     //Usage　　自定义
        0x15, 0x00,     //Logical Minimun(0)　　报表项目的最小数值
        0x25, 0xFF,     //Logical Maximun(255)　　报表内容最大数值
        0x75, 0x08,     //Report Size(8)　　每个数据段占8位
        0x95, 0x40,     //Report Counet(64)　　64个数据段　　双向64字节数据的IN方向传输
        0x81, 0x02,     //Input(Data,Variable,Absolute)　　0x02各项含义详见卷标

        0x09, 0xFF,     //Usage　　自定义
        0x91, 0x02,     //Output(Data,Variable,Absolute)　　0x02各项含义详见卷标

    0xC0            //End Collection 关闭集合
};

class HidGamePad:public UsbHidDeviceBase{
public:
    using UsbHidDeviceBase::UsbHidDeviceBase;

    struct DataFrame{
        #pragma pack(push, 1)
        uint8_t x:2;
        uint8_t y:2;
        uint8_t pad:4;
        uint8_t button1:4;
        uint8_t button2:4;
        uint8_t button3:4;
        uint8_t button4:4;
        uint8_t button5:4;
        uint8_t button6:4;
        uint8_t padh:2;

        #pragma pack(pop)
    };

    constexpr std::span<const uint8_t> getReportDescr() const {return gamepad_descr;}

//     0x07,0x05,0x81,0x03,0x40,0x00,0x01,              //端点描述符
    constexpr __UsbEndpointDescr getEndpointInDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.iaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = sizeof(DataFrame),
            .bInterval = 1//1ms
        };
    }

//     0x07,0x05,0x01,0x03,0x40,0x00,0x01               //端点描述符
    constexpr __UsbEndpointDescr getEndpointOutDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.oaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = sizeof(DataFrame),
            .bInterval = 1//1ms
        };
    }

    //     0x09,0x21,0x00,0x01,0x00,0x01,0x22,0x18,0x00,               //HID类描述符
    constexpr __UsbHidClassDescr getHidClassDescr() const{
        return __UsbHidClassDescr{
            .bcdHID = BcdUsb::V1_0,
            .bCountryCode = CountryCode::None,
            .bNumDescriptors = 1,
            .bDescriptorType2 = HidDescrType::Report,
            .wDescriptorLength = uint16_t(getReportDescr().size())
        };
    }

//     0x09,0x04,0x00,0x00,0x02,0x03,0x00,0x00,0x05,               //接口描述符
    constexpr __UsbInterfaceDescr getInterfaceDescr(const uint8_t interfaceNumber) const{
        return __UsbInterfaceDescr{
            .bInterfaceNumber = interfaceNumber,
            .bAlternateSetting = 0,//没有额外配置
            .bNumEndpoints = 2,//上传和下传端点
            .bInterfaceClass = UsbClassCode::HID,
            .bInterfaceSubClass = HidSubClassCode::None,
            .bInterfaceProtocol = HidProtocolCode::None,
            .iInterface = 5
        };
    }

};


// const uint8_t MyCfgDescr[] = {
//     0x09,0x02,0x29,0x00,0x01,0x01,0x04,0xA0,0x23,               //配置描述符

