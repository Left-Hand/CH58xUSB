#pragma once

// bcdUSB 长度为2字节，表示该设备支持的 USB 版本。它是使用 BCD 编码来实现的，采用 0xAABC 的形式，其中 A 是主版本号， B 是次版本号， C 是子次版本号。例如， USB 2.0 为 0x0200 ， USB 1.1 为 0x0110 。
// bDeviceClass 长度1字节，设备的类代码，设备的类代码由USB协会规定，具体的类代码在官网http://usb.org上搜索defined class codes就可以看到，对于大多数标准的USB设备，通常设置为0，而在接口描述符中的 bInterfaceClass 中指定接口所实现的功能。如果bDeviceClass为0xFF，表示是厂商自定义的设备类。
// bDeviceSubClass 长度1字节，设备所使用的子类代码，由USB协会规定，当bDeviceClass为0时，bDeviceSubClass也必须为0。
// bDeviceProtocol 长度1字节，设备所使用的协议，协议代码由USB协会规定。bDeviceProtocol必须要结合设备类和设备子类联合使用才有意义，因此当类代码为0时，bDeviceProtocol也必须为0。
// bMaxPacketSize 长度1字节，表示端点 0 支持的数据包的最大字节数量。数据包的大小可以为 8 个字节、 16 个字节、 32 个字节或 64 个字节。
// idVender 长度2字节，厂家ID号，由USB协会分配。
// idProduct 长度2字节，产品ID号，由厂家自己决定，比较自由。
// bcdDevice 长度2字节。
// iManufacturer、 iProduct 和 iSerialNumber 长度均为1字节，都是字符串描述符索引。 字符串描述符包括有关制造商、产品和序列号等信息。如果存在字符串描述符，这些变量应该指向其索引位置。如果没有任何字符串，那么应该将零值填充到各个字段内。
// bNumConfigurations 长度1字节，定义了设备可支持的配置总数。每种配置都会有一个配置描述符，大部分的USB设备只有一个配置。

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
