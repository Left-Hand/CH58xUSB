#pragma once

#include "sys/core/platform.h"

struct U8Intf{
    uint8_t * data(){
        return reinterpret_cast<uint8_t *>(this);
    } 

    const uint8_t * data() const{
        return reinterpret_cast<const uint8_t *>(this);
    } 
    uint8_t operator [](const size_t idx) const {
        return *(reinterpret_cast<const uint8_t *>(this) + idx);
    }
};
