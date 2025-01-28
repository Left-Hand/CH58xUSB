#pragma once

#include "DescrBase.hpp"

enum class UsbClassCode : uint8_t {
    Audio = 0x01,
    CDCControl = 0x02,          // ͨ���豸�� - ���ƽӿ�
    HID = 0x03,                 // ����ӿ��豸��
    Physical = 0x05,            // ����ӿ��豸��
    Image = 0x06,               // ͼ����
    Printer = 0x07,             // ��ӡ����
    MassStorage = 0x08,         // �������洢��
    Hub = 0x09,                 // ��������
    CDCData = 0x0A,             // ͨ���豸�� - ���ݽӿ�
    SmartCard = 0x0B,           // ���ܿ���
    ContentSecurity = 0x0D,     // ���ݰ�ȫ��
    Video = 0x0E,               // ��Ƶ��
    PersonalHealthcare = 0x0F,  // ���˽���������
    AudioVideo = 0x10,          // ��Ƶ/��Ƶ�豸��
    Billboard = 0x11,           // �������
    USBTypeCBridge = 0x12,      // USB ���� C �Ž���
    USBBulkDisplay = 0x13,     // USB ��ʾ��
    MCTPOverUSB = 0x14,        // MCTP over USB ��
    I3C = 0x3c,                 // I3C ��
    DiagnosticDevice = 0xDC,    // ����豸��
    WirelessController = 0xE0,  // ���߿�������
    Miscellaneous = 0xEF,       // ������
    ApplicationSpecific = 0xFE, // Ӧ���ض���
    VendorSpecific = 0xFF       // �����ض���
};

enum class HidSubClassCode : uint8_t {
    None = 0x00,
    Boot = 0x01,
    //Reserverd
};

enum class HidProtocolCode : uint8_t {
    None = 0x00,
    Keyboard = 0x01,
    Mouse = 0x02,
    // Resrvered
};

struct __UsbInterfaceDescr : public __UsbDescrBase<0x09, UsbDescrType::Interface> {
    // �ӿڱ�ţ����ڱ�ʶ�豸�еĲ�ͬ�ӿ�
    const uint8_t bInterfaceNumber;

    // ��������ֵ�����ڱ�ʶ�ӿڵĲ�ͬ��������
    const uint8_t bAlternateSetting;

    // �ýӿ�ʹ�õĶ˵�����
    const uint8_t bNumEndpoints;

    // �ӿ�����룬��ʶ�ӿ���������
    const UsbClassCode bInterfaceClass;

    // �ӿ�������룬��ʶ�ӿ������ľ�������
    const HidSubClassCode bInterfaceSubClass;

    // �ӿ�Э����룬��ʶ�ӿ�ʹ�õľ���Э��
    const HidProtocolCode bInterfaceProtocol;

    // �ӿ��ַ����������������������ṩ�ӿڵ��������ַ���
    // Ϊ0ʹ��Ĭ������
    const uint8_t iInterface;
};