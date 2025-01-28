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

// ��������0x07, //bLength ���������ֽ������� ��׼Ϊ0x07
// ��������0x05, //bDescriptorType ������������ 0x05Ϊ�˵�������
// ��������0x81, //bmEndpointAddress ����λΪ�˵�ţ����λΪ0��OUT����Ϊ1��IN��������λ������
// ��������0x03, //bmAttributes ����λΪ 00�����ƴ��䣻01��ʵʱ���䣻10���������䣻11���жϴ��䡣����λ����
// ��������0x08, 0x00, //bMaxPacketSize �˵��շ������ݰ���󾻳���
// ��������0x0a, //bInterval �������ݴ���˵��ʱ���϶�����������Ϳ��ƴ�����˵������
// ������������//���ö˵�����ʵʱ���䣬��ֵ����Ϊ1��ms�������ö˵������жϴ��䣬��ֵΪ1��255��ms��

    constexpr __UsbEndpointDescr getEndpointDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.iaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = 8,
            .bInterval = 10//10ms
        };
    }

// ����//HID����������
// ��������0x09, //bLength ���������ֽ������� ��׼Ϊ0x09
// ��������0x21, //bDescriptorType ������������ 0x21Ϊ�˻��ӿ���������
// ��������0x12, 0x01, //bcdHID HID�淶�汾�ŵ�BCD�룬�����������ð汾Ϊ1.12
// ��������0x00, //bCountryCode Ӳ��Ŀ�Ĺ��ҵ�ʶ����롣�����ô˹�����Ϊ0
// ��������0x01, //bNumDescriptors ֧�ֵĸ�����������Ŀ����СֵΪ1��HID�������и�����������
// ��������0x22, //bDescriptorType ��������������͡�ֻ�б���������Ϊ0x22�����и�ʵ����������Ϊ0x23
// ��������0x4e, 0x00, //wDescriptorLength �����������ܳ���
    constexpr __UsbHidClassDescr getHidClassDescr() const{
        return __UsbHidClassDescr{
            .bcdHID = BcdUsb::V1_12,
            .bCountryCode = CountryCode::None,
            .bNumDescriptors = 1,
            .bDescriptorType2 = HidDescrType::Report,
            .wDescriptorLength = uint16_t(getReportDescr().size())
        };
    }

// ����//�ӿ���������
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


    void report(const DataFrame & data){
        ep_.ideal({data.data(), sizeof(DataFrame)});
    }

};

// ����// ������������
// ��������0x09, //bLength ���������ֽ������� ��׼Ϊ0x09
// ��������0x02, //bDescriptorType ������������ 0x02Ϊ����������
// ��������0x22, 0x00, //wTotalLength ������Ϣ���ܳ����������á��ӿڡ��˵㡢��ͳ�����������
// ��������0x01, //bNumInterfaces ��������֧�ֵĽӿ���Ŀ
// ��������0x01, //bConfigurationValue ��SET_CONFIGURATION��������������ѡ��
// ��������0x00, //iConfiguration �����õ��ַ�������������ֵ����SET_CONFIGURATION������ѡ�����õĲ���
// ��������0xA0, //bmAttributes D6���Թ��� D5��Զ�̻��� ����λ������
// ����������������//��һ���豸�����Թ�������ʹ�����߹��磬D6ҲҪ��1����MaxPowerָ����Ҫ�����߻�ȡ�ĵ���
// ��������0x32, //MaxPower �������µ����ߵ�Դ�ķ�����Ϊ������ֵ����0x32*2 = 100��mA

