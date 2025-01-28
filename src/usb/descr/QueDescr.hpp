#pragma once

#include "DescrBase.hpp"


struct __UsbQueDescr : public __UsbDescrBase<0x0A, UsbDescrType::Que> {
#pragma pack(push, 1)
// bcdUSB (0x00, 0x02): 表示USB规范版本为2.0。
// bDeviceClass (0xFF): 设备类为0xFF，表示具体的类信息由接口描述符提供。
// bDeviceSubClass (0x00): 子类为0，表示无特定子类。
// bDeviceProtocol (0x00): 协议为0，表示无特定协议。
// bMaxPacketSize0 (0x40): 端点0的最大包大小为64字节。
// bNumConfigurations (0x01): 支持1个配置。
// bReserved (0x00): 保留字节，必须为0x00。

    const uint16_t bcdUSB;
    const uint8_t bDeviceClass = 0xFF;
    const uint8_t bDeviceSubClass = 0x00;
    const uint8_t bDeviceProtocol = 0x00;
    const uint8_t bMaxPacketSize0 = 0x40;
    const uint8_t bNumConfigurations = 0x01;
    const uint8_t bReserved = 0x00;

#pragma pack(pop)
};
