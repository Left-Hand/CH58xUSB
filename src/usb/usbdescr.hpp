#pragma once

#include "sys/core/platform.h"
#include "utils.hpp"

#include "descr/ConfigDescr.hpp"
#include "descr/StrDescr.hpp"
#include "descr/LangDescr.hpp"
#include "descr/DeviceDescr.hpp"


namespace usb{
template <size_t N>
consteval auto make_str_descr(const char (&input)[N]) {
    return __UsbStrDescr<N-1>(input);
}

template<uint16_t Lang>
consteval auto make_lang_descr() {
    return __UsbLangDescr<Lang>();
}

consteval auto make_enlang_descr() {
    return make_lang_descr<0x0409>();
}
}
    


namespace usb{
consteval __UsbDeviceDescr make_device_descr(const uint8_t bMaxPacketSize, const BcdUsb bcdUsb = BcdUsb::V1_1){
    return __UsbDeviceDescr{.bcdUSB = bcdUsb, .bMaxPacketSize = bMaxPacketSize};
}

}