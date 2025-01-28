#pragma once

#include "usb/hiddev/hiddev.hpp"
#include "usb/descr/EndpointDescr.hpp"

#include "utils.hpp"

class HidKeyboard:public UsbHidDeviceBase{
public:
    using UsbHidDeviceBase::UsbHidDeviceBase;
    struct Modifiers {
        #pragma pack(push, 1)
        uint8_t left_ctrl_pressed:1;
        uint8_t left_shift_pressed:1;
        uint8_t left_alt_pressed:1;
        uint8_t left_gui_pressed:1;

        uint8_t right_ctrl_pressed:1;
        uint8_t right_shift_pressed:1;
        uint8_t right_alt_pressed:1;
        uint8_t right_gui_pressed:1;

        #pragma pack(push, 1)
    };


    struct DataFrame:public U8Intf{
        #pragma pack(push, 1)

        Modifiers modifiers;
        const uint8_t __resv__ = 0;

        HidKeyboardCode keycodes[6];
        #pragma pack(pop)

        DataFrame() = default;

        DataFrame(const Modifiers _modifiers):
            modifiers(_modifiers){;}

        // template<typename ...Args>
        // DataFrame(const Modifiers _modifiers):
        //     modifiers(_modifiers){;}

        DataFrame(const char * str, const Modifiers _modifiers = Modifiers()):
            modifiers(_modifiers)
        {
            for(size_t i = 0; i < 6; i++){
                keycodes[i] = ascii_to_keycode(str[i]);
            }
        }

        DataFrame(const HidKeyboardCode code, const Modifiers _modifiers = Modifiers()):
            modifiers(_modifiers)
        {
            keycodes[0] = code;
        }

    };

    std::span<const uint8_t> getReportDescr() const {return keyboard_descr;}

    __UsbEndpointDescr getEndpointDescr() const{
        return __UsbEndpointDescr{
            .bEndpointAddress = ep_.iaddr(), 
            .bmAttributes = __UsbEndpointDescr::TransferType::Interrupt,
            .wMaxPacketSize = sizeof(DataFrame),
            .bInterval = 10//10ms
        };
    }

    __UsbHidClassDescr getHidClassDescr() const{
        return __UsbHidClassDescr{
            .bcdHID = BcdUsb::V1_1,
            .bCountryCode = CountryCode::None,
            .bNumDescriptors = 1,
            .bDescriptorType2 = HidDescrType::Report,
            .wDescriptorLength = uint16_t(getReportDescr().size())
        };
    }

    __UsbInterfaceDescr getInterfaceDescr(const uint8_t interfaceNumber) const{
        return __UsbInterfaceDescr{
            .bInterfaceNumber = interfaceNumber,
            .bAlternateSetting = 0,//没有额外配置
            .bNumEndpoints = 1,//只有一个端点
            .bInterfaceClass = UsbClassCode::HID,
            .bInterfaceSubClass = HidSubClassCode::Boot,
            .bInterfaceProtocol = HidProtocolCode::Keyboard,
            .iInterface = 0//为0使用默认描述
        };
    }
    void report(const DataFrame & data){
        ep_.ideal({data.data(), sizeof(DataFrame)});
        // ep_.ideal({DataFrame{.__resv__ = 0}, sizeof(DataFrame)});
    }
};

using  HidKeyboardModifiers = HidKeyboard::Modifiers;
using  HidKeyboardDataFrame = HidKeyboard::DataFrame;