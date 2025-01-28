#pragma once

#include "DescrBase.hpp"

// bLength 1字节，表示端点描述符的长度，标准的端点描述符的长度为7字节。
// bDescriptorType 1字节，表示描述符的类型，端点描述符的类型编码为 0x05。
// bEndpointAddress 1字节，表示该端点的地址和方向。
// bmAttributes 1字节，表示该端点的属性，详细看上表。
// wMaxPacketSize 2字节，表示该端点的数据包最大长度。
// bInterval 1字节
struct __UsbEndpointDescr : public __UsbDescrBase<7, UsbDescrType::Endpoint> {
#pragma pack(push, 1)
    uint8_t  bEndpointAddress;
    uint8_t  bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t  bInterval;
#pragma pack(pop)
};
