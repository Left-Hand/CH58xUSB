#pragma once

#include "usb/hiddev/hiddev.hpp"

class HidJoytick:public UsbHidDeviceIntf{
public:
    struct DataFrame{
        #pragma pack(push, 1)
        int8_t throttle;
        int8_t x;
        int8_t y;

        uint8_t hat:4;
        uint8_t buttons:4;

        #pragma pack(pop)
    };

    std::span<const uint8_t> getReportDescr() const {return joystick_descr;}
};
