#pragma once

#include "DescrBase.hpp"


// bEndpointAddress 1字节，表示该端点的地址和方向。
// bmAttributes 1字节，表示该端点的属性，详细看上表。
// wMaxPacketSize 2字节，表示该端点的数据包最大长度。
// bInterval 1字节


// 0x81：表示端点地址，其中：
// 0x80 表示这是一个 IN 端点。
// 0x01 表示端点编号为 1。
// 0x03：表示端点的传输类型，其中：
// 0x03 表示这是一个中断传输（Interrupt Transfer）。
// 0x08, 0x00：表示端点的最大包大小，即 0x0008（8 字节）。
// 0x0a：表示端点的轮询间隔，即 10 毫秒。





struct __UsbEndpointDescr : public __UsbDescrBase<7, UsbDescrType::Endpoint> {
    enum class TransferType : uint8_t {
        Control = 0x00,
        Isochronous = 0x01,
        Bulk = 0x02,
        Interrupt = 0x03
    };

#pragma pack(push, 1)
    const EndpointAddress  bEndpointAddress; //[2]
    const TransferType bmAttributes; //[3]
    const uint16_t wMaxPacketSize; //[5:4] 
    const EndpointInvervalMs  bInterval; //[6]
#pragma pack(pop)
};
