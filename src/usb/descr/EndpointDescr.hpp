#pragma once

#include "DescrBase.hpp"

// bLength 1�ֽڣ���ʾ�˵��������ĳ��ȣ���׼�Ķ˵��������ĳ���Ϊ7�ֽڡ�
// bDescriptorType 1�ֽڣ���ʾ�����������ͣ��˵������������ͱ���Ϊ 0x05��
// bEndpointAddress 1�ֽڣ���ʾ�ö˵�ĵ�ַ�ͷ���
// bmAttributes 1�ֽڣ���ʾ�ö˵�����ԣ���ϸ���ϱ�
// wMaxPacketSize 2�ֽڣ���ʾ�ö˵�����ݰ���󳤶ȡ�
// bInterval 1�ֽ�
struct __UsbEndpointDescr : public __UsbDescrBase<7, UsbDescrType::Endpoint> {
#pragma pack(push, 1)
    uint8_t  bEndpointAddress;
    uint8_t  bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t  bInterval;
#pragma pack(pop)
};
