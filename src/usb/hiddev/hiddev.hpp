#pragma once

#include "sys/core/platform.h"
#include "hiddescr.hpp"
#include <span>
#include "usb/endpoint.hpp"

class UsbHidDeviceBase{
protected:
    Endpoint & ep_;
public:
    UsbHidDeviceBase(Endpoint & ep):ep_(ep){;}
    virtual std::span<const uint8_t> getReportDescr() const = 0;


};