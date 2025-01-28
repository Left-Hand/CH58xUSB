#pragma once

enum class UsbDescrType : uint8_t {
    Device = 0x01,
    Configuration = 0x02,
    String = 0x03,
    Interface = 0x04,
    Endpoint = 0x05,
    Que = 0x06,
    HidClass = 0x21
};
