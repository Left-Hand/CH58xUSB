#pragma once

#include "CH58x_common.h"
#include "usb/endpoint.hpp"
#include "usb/hiddev/hiddev.hpp"
#include "usb/usbdescr.hpp"

#include <vector>
#include <memory>

#define DevEP0SIZE    0x40

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
    void handle(void);

    auto & endpoint(const uint8_t idx){
        return endpoints_[idx];
    }
};

extern UsbProcesser usb_processer;
