#pragma once

#include "DescrBase.hpp"

enum BcdUsb:uint16_t{
    V1_0 = 0x0100,
    V1_1 = 0x0110,
    V2_0 = 0x0200,
    V2_1 = 0x0210,
    V3_0 = 0x0300,
    V3_1 = 0x0310,
    V3_2 = 0x0320,
    V3_3 = 0x0330,
};

struct __UsbDeviceDescr : public __UsbDescrBase<18, UsbDescrType::Device> {
#pragma pack(push, 1)
    BcdUsb bcdUSB; //[3:2]
    uint8_t  bDeviceClass = 0; //[4]一般为0
    uint8_t  bDeviceSubClass = 0;//[5]一般为0
    uint8_t  bDeviceProtocol = 0;//[6]前两者为0 这一项也是0
    uint8_t  bMaxPacketSize;//[7]端点0的大小

    uint16_t idVendor = 0; //[9:8]厂商id
    uint16_t idProduct = 0; //[11:10]产品id
    uint16_t bcdDevice = 0; //[13:12]版本号

    uint8_t  iManufacturer = 0;//[14]
    uint8_t  iProduct = 0;//[15]
    uint8_t  iSerialNumber = 0;//[16]
    uint8_t  bNumConfigurations = 0x01; //bNumConfigurations 可能的配置描述符数目 只有一种配置时此值为1
#pragma pack(pop)
};


