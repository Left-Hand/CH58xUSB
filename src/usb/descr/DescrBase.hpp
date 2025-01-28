#pragma once

#include "sys/core/platform.h"


#include "usb/descr/utils.hpp"


template<uint8_t Length, UsbDescrType DescrType>
struct __UsbDescrBase:public U8Intf{
    #pragma pack(push,1)
    const uint8_t bLength = Length;
    const uint8_t bDescriptorType = uint8_t(DescrType);
    #pragma pack(pop)

    constexpr uint8_t size() const {return Length;}
};
