#pragma once

#include "DescrBase.hpp"

struct __UsbHidClassDescr: public __UsbDescrBase<0x09, UsbDescrType::HidClass>{
    uint16_t bcdHID;            // HID类规范版本号
    uint8_t  bCountryCode;      // 国家代码
    uint8_t  bNumDescriptors;   // 报告描述符的数量
    uint8_t  bDescriptorType2;  // 报告描述符类型，0x22表示报告描述符
    uint16_t wDescriptorLength; // 报告描述符的长度
};