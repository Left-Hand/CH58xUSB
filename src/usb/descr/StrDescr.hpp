#pragma once

#include "DescrBase.hpp"

//N表示字符数量
template<uint8_t N>
struct __UsbStrDescr:public __UsbDescrBase<N * 2 + 2, UsbDescrType::String>{
protected:
#pragma pack(push,1)
    uint16_t str[N] = {0};
#pragma pack(pop)
public:
    consteval __UsbStrDescr(const char (&input)[N+1]) {
        for (size_t i = 0; i < N; ++i) { // N-1 to exclude the null terminator
            str[i] = static_cast<uint16_t>(input[i]);
        }
    }
};
