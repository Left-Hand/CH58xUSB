#pragma once

#include "DescrBase.hpp"



struct __UsbDeviceDescr : public __UsbDescrBase<18, UsbDescrType::Device> {
#pragma pack(push, 1)
    BcdUsb bcdUSB; //[3:2]
    uint8_t  bDeviceClass = 0; //[4]һ��Ϊ0
    uint8_t  bDeviceSubClass = 0;//[5]һ��Ϊ0
    uint8_t  bDeviceProtocol = 0;//[6]ǰ����Ϊ0 ��һ��Ҳ��0
    uint8_t  bMaxPacketSize;//[7]�˵�0�Ĵ�С

    uint16_t idVendor = 0; //[9:8]����id
    uint16_t idProduct = 0; //[11:10]��Ʒid
    uint16_t bcdDevice = 0; //[13:12]�汾��

    uint8_t  iManufacturer = 0;//[14]
    uint8_t  iProduct = 0;//[15]
    uint8_t  iSerialNumber = 0;//[16]
    uint8_t  bNumConfigurations = 0x01; //bNumConfigurations ���ܵ�������������Ŀ ֻ��һ������ʱ��ֵΪ1
#pragma pack(pop)
};


