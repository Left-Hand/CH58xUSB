#pragma once

#include "usb/utils.hpp"

enum class UsbDescrType : uint8_t {
    Device = 0x01,
    Configuration = 0x02,
    String = 0x03,
    Interface = 0x04,
    Endpoint = 0x05,
    Que = 0x06,
    HidClass = 0x21
};

enum BcdUsb:uint16_t{
    V1_0 = 0x0100,
    V1_1 = 0x0110,
    V1_12 = 0x0112,
    V2_0 = 0x0200,
    V2_1 = 0x0210,
    V3_0 = 0x0300,
    V3_1 = 0x0310,
    V3_2 = 0x0320,
    V3_3 = 0x0330,
};