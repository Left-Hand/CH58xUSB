#pragma once

#include "DescrBase.hpp"


// bLength 1字节，表示配置描述符的长度，配置描述符的长度是9字节。
// bDescriptor 1字节，表示描述符的类型，配置描述符的类型编码为 0x02。
// wTotalLength 2字节，是整个配置描述符集合的总长度。包括配置描述符，接口描述符，端点描述符和类特殊描述符（如果有）。
// bNumInterfaces 1字节，则定义了在该指定配置中接口总数。最小为 1 个接口，通常功能单一的设备只有一个接口（如鼠标），而复合设备具有多个接口（如音频设备）。
// bConfigurationValue 1字节，表示该配置的值，设置配置请求时会发送一个配置值，如果某个配置的bConfigurationValue和它相匹配，就表示该配置被激活。
// 所谓配置请求是USB标准请求中的一种，后面会介绍。
// iConfiguration 1字节，描述该配置的字符串的索引，如果该值为0，表示没有字符串来描述它。
// bmAttributes 1字节，定义了 USB 设备的一些特性。 位7保留，必须设置为1，位6表示供电方式，设置为 0表示设备由总线供电，设置为 1 表示设备自供电。位5表示是否支持远程唤醒，设置为 1表示支持远程唤醒，设置为 0 表示不支持远程唤醒。位4~位0设置为0。
// bMaxPower 1字节，表示设备需要从总线获取的最大电流量，以 2 mA 为单位。如需要200mA的最大电流，则该字段的值为100。
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