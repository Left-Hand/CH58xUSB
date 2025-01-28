#pragma once

#include "DescrBase.hpp"

struct __UsbHidClassDescr: public __UsbDescrBase<0x09, UsbDescrType::HidClass>{
    uint16_t bcdHID;            // HID��淶�汾��
    uint8_t  bCountryCode;      // ���Ҵ���
    uint8_t  bNumDescriptors;   // ����������������
    uint8_t  bDescriptorType2;  // �������������ͣ�0x22��ʾ����������
    uint16_t wDescriptorLength; // �����������ĳ���
};