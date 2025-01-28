#pragma once

#include "usb/hiddev.hpp"

#include "utils.hpp"

class HidKeyboard:public UsbHidDeviceIntf{
public:
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
};

using  HidKeyboardModifiers = HidKeyboard::Modifiers;
using  HidKeyboardDataFrame = HidKeyboard::DataFrame;