#pragma once

#include "sys/core/platform.h"
#include <span>

class Endpoint{
public:
    enum class Address: uint8_t {
        // EP1_OUT = 0x01,
        EP1_OUT = 0x01,
        EP2_OUT = 0x02,
        EP3_OUT = 0x03,
        EP4_OUT = 0x04,

        EP1_IN = 0x81,
        EP2_IN = 0x82,
        EP3_IN = 0x83,
        EP4_IN = 0x84
    };

    using InvervalMs = uint8_t;
protected:


    __attribute__((aligned(4))) uint8_t buf_[64 + 64 + 64];
    const uint8_t usb_idx_;
    const uint8_t idx_;
public:
    Endpoint(const uint8_t usb_idx, const uint8_t idx):
        usb_idx_(usb_idx), idx_(idx){}
    Endpoint(const Endpoint & other) = delete;
    Endpoint(const Endpoint && other) = delete;
    constexpr Address oaddr() const{return Address(idx_ & 0x7f);}
    constexpr Address iaddr() const{return Address(idx_ | 0x80);}

    void ideal(const std::span<const uint8_t> data);
    void odeal(const std::span<uint8_t> data);

    constexpr uint8_t uidx() const{return usb_idx_;}
    constexpr uint8_t idx() const{return idx_;}

    const uint8_t * data() const{return buf_;}
    uint8_t * data() {return buf_;}
};

using EndpointAddress = Endpoint::Address;
using EndpointInvervalMs = Endpoint::InvervalMs;
