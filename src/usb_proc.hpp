#pragma once

#include "CH58x_common.h"
#include "usb/endpoint.hpp"
#include "usb/hiddev/hiddev.hpp"
#include "usb/usbdescr.hpp"
#include "usb/hiddev/keyboard/HidKeyboard.hpp"
#include "usb/hiddev/mouse/HidMouse.hpp"
#include "usb/hiddev/joystick/HidJoystick.hpp"

#define DevEP0SIZE    0x40




// ����������
constexpr auto MyLangDescr = usb::make_enlang_descr();
// ������Ϣ
constexpr auto MyManuInfo = usb::make_str_descr("wch.cn");
// ��Ʒ��Ϣ
constexpr auto MyProdInfo = usb::make_str_descr("CH57x");

constexpr auto MyDevDescr = usb::make_device_descr(DevEP0SIZE);

extern HidKeyboard keyboard;
extern HidMouse mouse;
extern HidJoytick joytick;


// ����������
constexpr uint8_t MyCfgDescr[] = {
    // 0x09����ʾ�����������ĳ��ȣ�������������ܹ��� 9 ���ֽڡ�
    // 0x02����ʾ����һ��������������Configuration Descriptor����
    // 0x3b, 0x00����ʾ�������������ܳ��ȣ��� 0x003B��59 �ֽڣ���
    // 0x02����ʾ����������� 2 ���ӿڡ�
    // 0x01����ʾ����ֵ�������� SET_CONFIGURATION ������ѡ��������á�
    // 0x00����ʾ�����ַ�����������������0 ��ʾû���ַ�����������
    // 0xA0����ʾ������õ����ԣ����У�
    // 0x80 ��ʾ�������Ƿ���Ҫ���߹��硣
    // 0x20 ��ʾ�Ƿ�֧��Զ�̻��ѡ�
    // 0x40 ��ʾ�Ƿ�֧���Թ��硣
    // 0x32����ʾ������õ���󹦺ģ���λ�� 2mA���� 0x32 * 2mA = 100mA
    0x09, 0x02, 0x3b, 0x00, 0x02, 0x01, 0x00, 0xA0, 0x32, //����������
    


    
    0x09, 0x04, 0x00, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, //�ӿ�������,����
    0x09, 0x21, 0x11, 0x01, 0x00, 0x01, 0x22, 0x3e, 0x00, //HID��������
    0x07, 0x05, 0x81, 0x03, 0x08, 0x00, 0x0a,             //�˵�������

    0x09, 0x04, 0x01, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00, //�ӿ�������,���
    0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x34, 0x00, //HID��������
    0x07, 0x05, 0x82, 0x03, 0x04, 0x00, 0x0a              //�˵�������
};

/* USB�ٶ�ƥ�������� */
constexpr uint8_t My_QueDescr[] = {0x0A, 0x06, 0x00, 0x02, 0xFF, 0x00, 0xFF, 0x40, 0x01, 0x00};




class UsbProcesser{
protected:

     __attribute__((aligned(4))) Endpoint endpoints_[4] = {
        Endpoint{usb_idx_, 0},
        Endpoint{usb_idx_, 1},
        Endpoint{usb_idx_, 2},
        Endpoint{usb_idx_, 3}
        // Endpoint{0},
        // Endpoint{1},
        // Endpoint{2},
        // Endpoint{3}
    };

    const uint8_t usb_idx_;

    uint8_t        DevConfig, Ready;
    uint8_t        SetupReqCode;
    uint16_t       SetupReqLen;
    const uint8_t *pDescr;
    uint8_t        Report_Value = 0x00;
    uint8_t        Idle_Value = 0x00;
    uint8_t        USB_SleepStatus = 0x00; /* USB˯��״̬ */
    uint8_t len, chtype;
    uint8_t errflag = 0;



    void handleSetup();
    void handleNonIdle();
    void handleReset();
public:
    UsbProcesser(const uint8_t usb_idx):
        usb_idx_(usb_idx){;}
    void init(){
        pEP0_RAM_Addr = endpoints_[0].data();
        pEP1_RAM_Addr = endpoints_[1].data();
        pEP2_RAM_Addr = endpoints_[2].data();
        pEP3_RAM_Addr = endpoints_[3].data();
    }

    void handle(void){

        uint8_t intflag = R8_USB_INT_FG;
        if(intflag & RB_UIF_TRANSFER){
            if((R8_USB_INT_ST & MASK_UIS_TOKEN) != MASK_UIS_TOKEN){ // �ǿ���
                handleNonIdle();
                R8_USB_INT_FG = RB_UIF_TRANSFER;
            }if(R8_USB_INT_ST & RB_UIS_SETUP_ACT){ // Setup������
                handleSetup();
                R8_USB_INT_FG = RB_UIF_TRANSFER;
            }
            
        }else if(intflag & RB_UIF_BUS_RST){
            handleReset();
            R8_USB_INT_FG = RB_UIF_BUS_RST;
        }else if(intflag & RB_UIF_SUSPEND){
            if(R8_USB_MIS_ST & RB_UMS_SUSPEND){
                // ����
            }else{
                // ����
            }
            R8_USB_INT_FG = RB_UIF_SUSPEND;
        }else{
            R8_USB_INT_FG = intflag;
        }
    }

    auto & endpoint(const uint8_t idx){
        return endpoints_[idx];
    }
};

extern UsbProcesser usb_processer;
