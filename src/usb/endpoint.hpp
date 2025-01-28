#pragma once

#include "sys/core/platform.h"

class EndPoint{
protected:
    const uint8_t idx_;
    __attribute__((aligned(4))) uint8_t buf_[64 + 64 + 64];
public:
    EndPoint(const uint8_t idx):idx_(idx){}

    EndPoint(const EndPoint & other) = delete;
    EndPoint(const EndPoint && other) = delete;

    constexpr uint8_t index() const{return idx_;}

    const uint8_t * data() const{return buf_;}
    uint8_t * data() {return buf_;}
};