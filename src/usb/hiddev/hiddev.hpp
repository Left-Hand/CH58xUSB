#pragma once

#include "sys/core/platform.h"
#include "hiddescr.hpp"
#include <span>
#include "usb/endpoint.hpp"

#include "descr/EndpointDescr.hpp"
#include "descr/HidClassDescr.hpp"
#include "descr/InterfaceDescr.hpp"

class UsbHidDeviceBase{
protected:
    Endpoint & ep_;
public:
    UsbHidDeviceBase(Endpoint & ep):ep_(ep){;}
    virtual std::span<const uint8_t> getReportDescr() const = 0;

    auto & endpoint() {return ep_;}
};