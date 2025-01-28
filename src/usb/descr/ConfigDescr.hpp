#pragma once

#include "DescrBase.hpp"


// bLength 1�ֽڣ���ʾ�����������ĳ��ȣ������������ĳ�����9�ֽڡ�
// bDescriptor 1�ֽڣ���ʾ�����������ͣ����������������ͱ���Ϊ 0x02��
// wTotalLength 2�ֽڣ��������������������ϵ��ܳ��ȡ������������������ӿ����������˵���������������������������У���
// bNumInterfaces 1�ֽڣ��������ڸ�ָ�������нӿ���������СΪ 1 ���ӿڣ�ͨ�����ܵ�һ���豸ֻ��һ���ӿڣ�����꣩���������豸���ж���ӿڣ�����Ƶ�豸����
// bConfigurationValue 1�ֽڣ���ʾ�����õ�ֵ��������������ʱ�ᷢ��һ������ֵ�����ĳ�����õ�bConfigurationValue������ƥ�䣬�ͱ�ʾ�����ñ����
// ��ν����������USB��׼�����е�һ�֣��������ܡ�
// iConfiguration 1�ֽڣ����������õ��ַ����������������ֵΪ0����ʾû���ַ�������������
// bmAttributes 1�ֽڣ������� USB �豸��һЩ���ԡ� λ7��������������Ϊ1��λ6��ʾ���緽ʽ������Ϊ 0��ʾ�豸�����߹��磬����Ϊ 1 ��ʾ�豸�Թ��硣λ5��ʾ�Ƿ�֧��Զ�̻��ѣ�����Ϊ 1��ʾ֧��Զ�̻��ѣ�����Ϊ 0 ��ʾ��֧��Զ�̻��ѡ�λ4~λ0����Ϊ0��
// bMaxPower 1�ֽڣ���ʾ�豸��Ҫ�����߻�ȡ�������������� 2 mA Ϊ��λ������Ҫ200mA��������������ֶε�ֵΪ100��
struct __UsbConfigDescr: public __UsbDescrBase<0x09, UsbDescrType::Configuration>{
#pragma pack(push, 1)
    const uint16_t wTotalLength;
    const uint8_t  bNumInterfaces;
    const uint8_t  bConfigurationValue;
    const uint8_t  iConfiguration;
    const uint8_t  bmAttributes;
    const uint8_t  bMaxPower;
#pragma pack(pop)
};