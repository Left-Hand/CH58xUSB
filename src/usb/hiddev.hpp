#pragma once

#include "sys/core/platform.h"
#include "hiddescr.hpp"
#include <span>


class UsbHidDeviceIntf{
public:
    // virtual std::span<const uint8_t> getReportDescr() const = 0;
};

class UsbHidMouse:public UsbHidDeviceIntf{
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



class UsbHidJoytick:public UsbHidDeviceIntf{
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









// std::span<const uint8_t> UsbHidMouse::getReportDescr() const {
//     scexpr uint8_t descr[] = {
//         0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00, 0x05, 0x09, 0x19, 0x01, 0x29,
//         0x03, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01, 0x95, 0x03, 0x81, 0x02, 0x75, 0x05, 0x95, 0x01,
//         0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x09, 0x38, 0x15, 0x81, 0x25, 0x7f, 0x75,
//         0x08, 0x95, 0x03, 0x81, 0x06, 0xC0, 0xC0}; 

//     return descr;
// }


// std::span<const uint8_t> UsbHidKeyboard::getReportDescr() const {
//     scexpr uint8_t descr[] = {
//         0x05, 0x01, 0x09, 0x06, 0xA1, 0x01, 0x05, 0x07, 0x19, 0xe0, 0x29, 0xe7, 0x15, 0x00, 0x25,
//         0x01, 0x75, 0x01, 0x95, 0x08, 0x81, 0x02, 0x95, 0x01, 0x75, 0x08, 0x81, 0x01, 0x95, 0x03,
//         0x75, 0x01, 0x05, 0x08, 0x19, 0x01, 0x29, 0x03, 0x91, 0x02, 0x95, 0x05, 0x75, 0x01, 0x91,
//         0x01, 0x95, 0x06, 0x75, 0x08, 0x26, 0xff, 0x00, 0x05, 0x07, 0x19, 0x00, 0x29, 0x91, 0x81,
//         0x00, 0xC0}; 

//     return descr;
// }

// std::span<const uint8_t> UsbHidJoytick::getReportDescr() const {
//     scexpr uint8_t descr[] = {
//         0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
//         0x09, 0x04,        // Usage (Joystick)
//         0xA1, 0x01,        // Collection (Application)
//         0x05, 0x02,        //   Usage Page (Sim Ctrls)
//         0x09, 0xBB,        //   Usage (Throttle)
//         0x15, 0x81,        //   Logical Minimum (-127)
//         0x25, 0x7F,        //   Logical Maximum (127)
//         0x75, 0x08,        //   Report Size (8)
//         0x95, 0x01,        //   Report Count (1)
//         0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
//         0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
//         0x09, 0x01,        //   Usage (Pointer)
//         0xA1, 0x00,        //   Collection (Physical)
//         0x09, 0x30,        //     Usage (X)
//         0x09, 0x31,        //     Usage (Y)
//         0x95, 0x02,        //     Report Count (2)
//         0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
//         0xC0,              //   End Collection
//         0x09, 0x39,        //   Usage (Hat switch)
//         0x15, 0x00,        //   Logical Minimum (0)
//         0x25, 0x03,        //   Logical Maximum (3)
//         0x35, 0x00,        //   Physical Minimum (0)
//         0x46, 0x0E, 0x01,  //   Physical Maximum (270)
//         0x65, 0x04,        //   Unit (System: English Rotation)
//         0x55, 0x00,        //   Unit Exponent (0)
//         0x75, 0x04,        //   Report Size (4)
//         0x95, 0x01,        //   Report Count (1)
//         0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
//         0x05, 0x09,        //   Usage Page (Button)
//         0x19, 0x01,        //   Usage Minimum (0x01)
//         0x29, 0x04,        //   Usage Maximum (0x04)
//         0x15, 0x00,        //   Logical Minimum (0)
//         0x25, 0x01,        //   Logical Maximum (1)
//         0x35, 0x00,        //   Physical Minimum (0)
//         0x45, 0x01,        //   Physical Maximum (1)
//         0x95, 0x04,        //   Report Count (4)
//         0x75, 0x01,        //   Report Size (1)
//         0x64,              //   Unit
//         0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
//         0xC0,              // End Collection
//     };

//     return descr;
// }