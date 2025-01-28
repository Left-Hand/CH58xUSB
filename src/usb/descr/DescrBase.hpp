#pragma once

#include "sys/core/platform.h"
#include "utils.hpp"
#include "usb/endpoint.hpp"


template<uint8_t Length, UsbDescrType DescrType>
struct __UsbDescrBase:public U8Intf{
    #pragma pack(push,1)
    const uint8_t bLength = Length;
    const uint8_t bDescriptorType = uint8_t(DescrType);
    #pragma pack(pop)

    constexpr uint8_t size() const {return Length;}
};
