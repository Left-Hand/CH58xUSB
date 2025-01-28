#pragma once

#include "CH58x_common.h"
#include "usb/endpoint.hpp"
#include "usb/hiddev/hiddev.hpp"
#include "usb/usbdescr.hpp"

#include <vector>
#include <memory>

#define DevEP0SIZE    0x40




// 语言描述符
constexpr auto MyLangDescr = usb::make_enlang_descr();
// 厂家信息
constexpr auto MyManuInfo = usb::make_str_descr("wch.cn");
// 产品信息
constexpr auto MyProdInfo = usb::make_str_descr("CH582m");

constexpr auto MyDevDescr = usb::make_device_descr(DevEP0SIZE);


// 配置描述符
constexpr uint8_t MyCfgDescr[] = {
    // 0x09：表示配置描述符的长度，即这个描述符总共有 9 个字节。
    // 0x02：表示这是一个配置描述符（Configuration Descriptor）。
    // 0x3b, 0x00：表示配置描述符的总长度，即 0x003B（59 字节）。
    // 0x02：表示这个配置中有 2 个接口。
    // 0x01：表示配置值，用于在 SET_CONFIGURATION 请求中选择这个配置。
    // 0x00：表示配置字符串描述符的索引，0 表示没有字符串描述符。
    // 0xA0：表示这个配置的属性，其中：
    // 0x80 表示该配置是否需要总线供电。
    // 0x20 表示是否支持远程唤醒。
    // 0x40 表示是否支持自供电。
    // 0x32：表示这个配置的最大功耗，单位是 2mA，即 0x32 * 2mA = 100mA
    0x09, 0x02, 0x3b, 0x00, 0x02, 0x01, 0x00, 0xA0, 0x32, //配置描述符
    


    
    0x09, 0x04, 0x00, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, //接口描述符,键盘
    0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x3e, 0x00, //HID类描述符
    0x07, 0x05, 0x81, 0x03, 0x08, 0x00, 0x0a,             //端点描述符

    0x09, 0x04, 0x01, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00, //接口描述符,鼠标
    0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x34, 0x00, //HID类描述符
    0x07, 0x05, 0x82, 0x03, 0x04, 0x00, 0x0a              //端点描述符
};

/* USB速度匹配描述符 */
constexpr uint8_t My_QueDescr[] = {0x0A, 0x06, 0x00, 0x02, 0xFF, 0x00, 0xFF, 0x40, 0x01, 0x00};




class UsbProcesser{
protected:

     __attribute__((aligned(4))) std::array<Endpoint,4> endpoints_;

    const uint8_t usb_idx_;

    uint8_t        DevConfig, Ready;
    uint8_t        SetupReqCode;
    uint16_t       SetupReqLen;
    const uint8_t *pDescr;
    uint8_t        Report_Value = 0x00;
    uint8_t        Idle_Value = 0x00;
    uint8_t        USB_SleepStatus = 0x00; /* USB睡眠状态 */
    uint8_t len, chtype;
    uint8_t errflag = 0;

    // std::vector<UsbHidDeviceBase> hid_devices_;
    std::array<UsbHidDeviceBase *,3> hid_devices_; 

    void handleSetup();
    void handleNonIdle();
    void handleReset();
    void handleStdRequest();
    void handleClrFeature();
    void handleSetFeature();
    void handleGetStatus();
    void handleGetDescriptor();
public:
    UsbProcesser(const uint8_t usb_idx):
        endpoints_{
            Endpoint{usb_idx, 0},
            Endpoint{usb_idx, 1},
            Endpoint{usb_idx, 2},
            Endpoint{usb_idx, 3}
        },usb_idx_(usb_idx){;}
    void init(){
        pEP0_RAM_Addr = endpoints_[0].data();
        pEP1_RAM_Addr = endpoints_[1].data();
        pEP2_RAM_Addr = endpoints_[2].data();
        pEP3_RAM_Addr = endpoints_[3].data();
        USB_DeviceInit();
    }

    void bind(UsbHidDeviceBase & device, const uint8_t ep_idx){
        hid_devices_.at(ep_idx - 1) = &device;
    }
    // template<typename Device, typename... Args>
    // Device & createHidDevice(Args &&... args){
    //     // if(hid_devices_.size() >= 3) {HALT;}
    //     const auto valid_idx = getDeviceCount();
    //     if(valid_idx >= 3) HALT;
    //     hid_devices_.at(valid_idx) = std::make_shared<Device>(this->endpoint(valid_idx + 1), std::forward(args)...);
    //     return *hid_devices_.at(valid_idx);
    // }

    size_t getDeviceCount(){
        for(size_t i = 0; i < hid_devices_.size(); ++i){
            if(hid_devices_[i] == nullptr) return i;
        }

        return 0;
    }
    void handle(void){

        uint8_t intflag = R8_USB_INT_FG;
        if(intflag & RB_UIF_TRANSFER){
            if((R8_USB_INT_ST & MASK_UIS_TOKEN) != MASK_UIS_TOKEN){ // 非空闲
                handleNonIdle();
                R8_USB_INT_FG = RB_UIF_TRANSFER;
            }if(R8_USB_INT_ST & RB_UIS_SETUP_ACT){ // Setup包处理
                handleSetup();
                R8_USB_INT_FG = RB_UIF_TRANSFER;
            }
            
        }else if(intflag & RB_UIF_BUS_RST){
            handleReset();
            R8_USB_INT_FG = RB_UIF_BUS_RST;
        }else if(intflag & RB_UIF_SUSPEND){
            if(R8_USB_MIS_ST & RB_UMS_SUSPEND){
                // 挂起
            }else{
                // 唤醒
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
