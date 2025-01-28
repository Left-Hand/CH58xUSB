#include "endpoint.hpp"
#include "CH58x_common.h"
#include "usb/hiddev/keyboard/utils.hpp"

#define USB1_IDEAL_IMPL(n)\
    memcpy(pEP##n##_IN_DataBuf, data.data(), data.size());\
    DevEP##n##_IN_Deal(data.size())\

#define USB2_IDEAL_IMPL(n)\
    memcpy(pU2EP##n##_IN_DataBuf, data.data(), data.size());\
    U2DevEP##n##_IN_Deal(data.size())\



void Endpoint::ideal(const std::span<const uint8_t> data){

    switch(usb_idx_){
        case 1:
            switch(idx_){
                case 1: USB1_IDEAL_IMPL(1); break;
                case 2: USB1_IDEAL_IMPL(2); break;
                case 3: USB1_IDEAL_IMPL(3); break;
            }
            break;
        case 2:
            //如果不绑定缓冲区会有警告
            // switch(idx_){
            //     case 1: USB2_IDEAL_IMPL(1); break;
            //     case 2: USB2_IDEAL_IMPL(2); break;
            //     case 3: USB2_IDEAL_IMPL(3); break;
            // }
            break;
    }
}

void Endpoint::odeal(const std::span<uint8_t> data){
    // U2DevEP1_OUT_Deal
}
