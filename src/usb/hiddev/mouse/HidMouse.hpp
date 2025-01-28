#pragma once

#include "usb/hiddev/hiddev.hpp"

class HidMouse:public UsbHidDeviceIntf{
public:
    struct DataFrame{
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

};
