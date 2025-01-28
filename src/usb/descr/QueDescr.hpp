#pragma once

#include "DescrBase.hpp"


struct __UsbQueDescr : public __UsbDescrBase<0x0A, UsbDescrType::Que> {
#pragma pack(push, 1)
// bcdUSB (0x00, 0x02): ��ʾUSB�淶�汾Ϊ2.0��
// bDeviceClass (0xFF): �豸��Ϊ0xFF����ʾ���������Ϣ�ɽӿ��������ṩ��
// bDeviceSubClass (0x00): ����Ϊ0����ʾ���ض����ࡣ
// bDeviceProtocol (0x00): Э��Ϊ0����ʾ���ض�Э�顣
// bMaxPacketSize0 (0x40): �˵�0��������СΪ64�ֽڡ�
// bNumConfigurations (0x01): ֧��1�����á�
// bReserved (0x00): �����ֽڣ�����Ϊ0x00��

    const uint16_t bcdUSB;
    const uint8_t bDeviceClass = 0xFF;
    const uint8_t bDeviceSubClass = 0x00;
    const uint8_t bDeviceProtocol = 0x00;
    const uint8_t bMaxPacketSize0 = 0x40;
    const uint8_t bNumConfigurations = 0x01;
    const uint8_t bReserved = 0x00;

#pragma pack(pop)
};
