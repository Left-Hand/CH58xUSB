#pragma once

const uint8_t gamepad_descr[] = { //HID1.0�汾Э�飬˫����HID�����豸
    0x06, 0x00, 0xFF,   //UsagePage(Vendor-defined)���������Զ����÷����ܣ���UsagePageʹ���ˡ������Զ��塱֮�����µ�Usage��Ϊ�����Զ��壬�����Ҷ�д0xFF�ˣ������ܹ��������־ͺá���ʹ���˱�׼��UsagePage��Usage����Ҫ��������ȥ�õ���׼ֵ��
    0x09, 0xFF,     //Usage�����Զ���
    0xA1, 0xFF,     //Collection(Vendor-defined)���������Զ��弯��

        0x09, 0xFF,     //Usage�����Զ���
        0x15, 0x00,     //Logical Minimun(0)����������Ŀ����С��ֵ
        0x25, 0xFF,     //Logical Maximun(255)�����������������ֵ
        0x75, 0x08,     //Report Size(8)����ÿ�����ݶ�ռ8λ
        0x95, 0x40,     //Report Counet(64)����64�����ݶΡ���˫��64�ֽ����ݵ�IN������
        0x81, 0x02,     //Input(Data,Variable,Absolute)����0x02�����������

        0x09, 0xFF,     //Usage�����Զ���
        0x91, 0x02,     //Output(Data,Variable,Absolute)����0x02�����������

    0xC0            //End Collection �رռ���
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

//     0x07,0x05,0x81,0x03,0x40,0x00,0x01,              //�˵�������
    constexpr __UsbEndpointDescr getEndpointInDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.iaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = sizeof(DataFrame),
            .bInterval = 1//1ms
        };
    }

//     0x07,0x05,0x01,0x03,0x40,0x00,0x01               //�˵�������
    constexpr __UsbEndpointDescr getEndpointOutDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.oaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = sizeof(DataFrame),
            .bInterval = 1//1ms
        };
    }

    //     0x09,0x21,0x00,0x01,0x00,0x01,0x22,0x18,0x00,               //HID��������
    constexpr __UsbHidClassDescr getHidClassDescr() const{
        return __UsbHidClassDescr{
            .bcdHID = BcdUsb::V1_0,
            .bCountryCode = CountryCode::None,
            .bNumDescriptors = 1,
            .bDescriptorType2 = HidDescrType::Report,
            .wDescriptorLength = uint16_t(getReportDescr().size())
        };
    }

//     0x09,0x04,0x00,0x00,0x02,0x03,0x00,0x00,0x05,               //�ӿ�������
    constexpr __UsbInterfaceDescr getInterfaceDescr(const uint8_t interfaceNumber) const{
        return __UsbInterfaceDescr{
            .bInterfaceNumber = interfaceNumber,
            .bAlternateSetting = 0,//û�ж�������
            .bNumEndpoints = 2,//�ϴ����´��˵�
            .bInterfaceClass = UsbClassCode::HID,
            .bInterfaceSubClass = HidSubClassCode::None,
            .bInterfaceProtocol = HidProtocolCode::None,
            .iInterface = 5
        };
    }

};


// const uint8_t MyCfgDescr[] = {
//     0x09,0x02,0x29,0x00,0x01,0x01,0x04,0xA0,0x23,               //����������

