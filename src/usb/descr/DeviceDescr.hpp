#pragma once

// bcdUSB ����Ϊ2�ֽڣ���ʾ���豸֧�ֵ� USB �汾������ʹ�� BCD ������ʵ�ֵģ����� 0xAABC ����ʽ������ A �����汾�ţ� B �Ǵΰ汾�ţ� C ���Ӵΰ汾�š����磬 USB 2.0 Ϊ 0x0200 �� USB 1.1 Ϊ 0x0110 ��
// bDeviceClass ����1�ֽڣ��豸������룬�豸���������USBЭ��涨�������������ڹ���http://usb.org������defined class codes�Ϳ��Կ��������ڴ������׼��USB�豸��ͨ������Ϊ0�����ڽӿ��������е� bInterfaceClass ��ָ���ӿ���ʵ�ֵĹ��ܡ����bDeviceClassΪ0xFF����ʾ�ǳ����Զ�����豸�ࡣ
// bDeviceSubClass ����1�ֽڣ��豸��ʹ�õ�������룬��USBЭ��涨����bDeviceClassΪ0ʱ��bDeviceSubClassҲ����Ϊ0��
// bDeviceProtocol ����1�ֽڣ��豸��ʹ�õ�Э�飬Э�������USBЭ��涨��bDeviceProtocol����Ҫ����豸����豸��������ʹ�ò������壬��˵������Ϊ0ʱ��bDeviceProtocolҲ����Ϊ0��
// bMaxPacketSize ����1�ֽڣ���ʾ�˵� 0 ֧�ֵ����ݰ�������ֽ����������ݰ��Ĵ�С����Ϊ 8 ���ֽڡ� 16 ���ֽڡ� 32 ���ֽڻ� 64 ���ֽڡ�
// idVender ����2�ֽڣ�����ID�ţ���USBЭ����䡣
// idProduct ����2�ֽڣ���ƷID�ţ��ɳ����Լ��������Ƚ����ɡ�
// bcdDevice ����2�ֽڡ�
// iManufacturer�� iProduct �� iSerialNumber ���Ⱦ�Ϊ1�ֽڣ������ַ��������������� �ַ��������������й������̡���Ʒ�����кŵ���Ϣ����������ַ�������������Щ����Ӧ��ָ��������λ�á����û���κ��ַ�������ôӦ�ý���ֵ��䵽�����ֶ��ڡ�
// bNumConfigurations ����1�ֽڣ��������豸��֧�ֵ�����������ÿ�����ö�����һ���������������󲿷ֵ�USB�豸ֻ��һ�����á�

struct __UsbDeviceDescr : public __UsbDescrBase<18, UsbDescrType::Device> {
#pragma pack(push, 1)
    uint16_t bcdUSB;
    uint8_t  bDeviceClass;
    uint8_t  bDeviceSubClass;
    uint8_t  bDeviceProtocol;
    uint8_t  bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
#pragma pack(pop)
};
