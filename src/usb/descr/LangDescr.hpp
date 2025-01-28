#pragma once

#include "DescrBase.hpp"

template<uint16_t Lang>
struct __UsbLangDescr : public __UsbDescrBase<4, UsbDescrType::String> {
#pragma pack(push, 1)
    const uint16_t lang = Lang;
#pragma pack(pop)
};
