#pragma once

#include "usb/hiddev/hiddev.hpp"
#include "descr/EndpointDescr.hpp"

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

    void report(const DataFrame & data){
        ep_.ideal({data.data(), sizeof(DataFrame)});
    }

};


using HidMouseDataFrame = HidMouse::DataFrame;