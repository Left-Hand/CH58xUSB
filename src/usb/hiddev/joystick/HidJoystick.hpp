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
            .bAlternateSetting = 0,//û�ж�������
            .bNumEndpoints = 1,//ֻ��һ���˵�
            .bInterfaceClass = UsbClassCode::HID,
            .bInterfaceSubClass = HidSubClassCode::None,
            .bInterfaceProtocol = HidProtocolCode::None,
            .iInterface = 0//Ϊ0ʹ��Ĭ������
        };
    }

};


// ��������0x09, //bLength ���������ֽ������� ��׼Ϊ0x09
// ��������0x04, //bDescriptorType ������������ 0x04Ϊ�ӿ�������
// ��������0x00, //bInterfaceNumber �ӿںţ���ǰ����֧�ֵĽӿ�������������0��ʼ����
// ����������������//�������������ӿڣ��������Ľӿ���������ֵ��Ϊ1
// ��������0x00, //bAlternateSetting ��ѡ���õ�����ֵ��һ���ӿڿ����ж���ӿ��������������ֶ�����
// ��������0x01, //bNumEndpoints ����USB�豸����֧�ֵĶ˵�0�⣬�˽ӿ��������Ķ˵�ĸ�������ֵΪ0��ʾ�ýӿ�ֻʹ�ö˵�0��
// ��������0x03, //bInterfaceClass �ӿ���������ֵ��Ϊ0��ʾΪ�����ı�׼������ΪFF��ʾ�˽ӿ����ɳ���˵��������ֵ���ֲᡣ0x03ΪHID��
// ��������0x00, //bInterfaceSublass �ӿ����������ֵ�������ֲ��Լ�bInterfaceClass��ֵ�������������ֵΪ0����ֵҲҪΪ0��
// ��������0x00, //bInterfaceProtocol Э���룬���ֲ��Լ������߶�����������Ϊ0����ֵҲҪΪ0��
// ��������0x00, //iInterface �˽ӿڵ��ַ���������������ֵ��
// ����//HID����������
// ��������0x09, //bLength ���������ֽ������� ��׼Ϊ0x09
// ��������0x21, //bDescriptorType ������������ 0x21Ϊ�˻��ӿ���������
// ��������0x12, 0x01, //bcdHID HID�淶�汾�ŵ�BCD�룬�����������ð汾Ϊ1.12
// ��������0x00, //bCountryCode Ӳ��Ŀ�Ĺ��ҵ�ʶ����롣�����ô˹�����Ϊ0
// ��������0x01, //bNumDescriptors ֧�ֵĸ�����������Ŀ����СֵΪ1��HID�������и�����������
// ��������0x22, //bDescriptorType ��������������͡�ֻ�б���������Ϊ0x22�����и�ʵ����������Ϊ0x23
// ��������0x4e, 0x00, //wDescriptorLength �����������ܳ���
// ����//�˵���������
// ��������0x07, //bLength ���������ֽ������� ��׼Ϊ0x07
// ��������0x05, //bDescriptorType ������������ 0x05Ϊ�˵�������
// ��������0x81, //bmEndpointAddress ����λΪ�˵�ţ����λΪ0��OUT����Ϊ1��IN��������λ������
// ��������0x03, //bmAttributes ����λΪ 00�����ƴ��䣻01��ʵʱ���䣻10���������䣻11���жϴ��䡣����λ����
// ��������0x08, 0x00, //bMaxPacketSize �˵��շ������ݰ���󾻳���
// ��������0x0a, //bInterval �������ݴ���˵��ʱ���϶�����������Ϳ��ƴ�����˵������
// ������������//���ö˵�����ʵʱ���䣬��ֵ����Ϊ1��ms�������ö˵������жϴ��䣬��ֵΪ1��255��ms��