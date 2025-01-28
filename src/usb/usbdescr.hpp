#pragma once

#include "sys/core/platform.h"
#include "utils.hpp"

#include "descr/ConfigDescr.hpp"
#include "descr/StrDescr.hpp"
#include "descr/LangDescr.hpp"


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
    
