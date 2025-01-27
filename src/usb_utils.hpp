// #include "CH58x_common.h"

// void DebugInit(void)
// {
//     GPIOA_SetBits(GPIO_Pin_9);
//     GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
//     GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
//     UART1_DefInit();
// }

// extern "C" {
// __HIGH_CODE
// int main(){

//     SetSysClock( CLK_SOURCE_PLL_60MHz);
//     DelayMs(5);
//     DebugInit();
//     printf("init done\r\n");

//     while(true);

// }

// }
#include "stdint.h"
#include "stddef.h"


struct U8Intf{
    // operator uint8_t * (){
    //     return reinterpret_cast<uint8_t *>(this);
    // } 

    // operator const uint8_t * () const{
    //     return reinterpret_cast<const uint8_t *>(this);
    // } 
    uint8_t operator [](const size_t idx) const {
        return *(reinterpret_cast<const uint8_t *>(this) + idx);
    }
};

struct HidMouseDataFrame:public U8Intf{
    #pragma pack(push, 1)

    uint8_t left_click:1;
    uint8_t right_click:1;
    uint8_t middle_click:1;
    const uint8_t __resv__:5 = 0;

    int8_t x_delta;
    int8_t y_delta;
    int8_t wheel_delta;
    

    #pragma pack(pop)
};

enum class HidKeyboardCode:uint8_t{
    KEY_A = 0x04,
    KEY_B = 0x05,
    KEY_C = 0x06,
    KEY_D = 0x07,
    KEY_E = 0x08,
    KEY_F = 0x09,
    KEY_G = 0x0A,
    KEY_H = 0x0B,
    KEY_I = 0x0C,
    KEY_J = 0x0D,
    KEY_K = 0x0E,
    KEY_L = 0x0F,
    KEY_M = 0x10,
    KEY_N = 0x11,
    KEY_O = 0x12,
    KEY_P = 0x13,
    KEY_Q = 0x14,
    KEY_R = 0x15,
    KEY_S = 0x16,
    KEY_T = 0x17,
    KEY_U = 0x18,
    KEY_V = 0x19,
    KEY_W = 0x1A,
    KEY_X = 0x1B,
    KEY_Y = 0x1C,
    KEY_Z = 0x1D,
    KEY_1 = 0x1E,
    KEY_2 = 0x1F,
    KEY_3 = 0x20,
    KEY_4 = 0x21,
    KEY_5 = 0x22,
    KEY_6 = 0x23,
    KEY_7 = 0x24,
    KEY_8 = 0x25,
    KEY_9 = 0x26,
    KEY_0 = 0x27,
    KEY_ENTER = 0x28,
    KEY_ESCAPE = 0x29,
    KEY_BACKSPACE = 0x2A,
    KEY_TAB = 0x2B,
    KEY_SPACEBAR = 0x2C,
    KEY_MINUS = 0x2D,
    KEY_EQUALS = 0x2E,
    KEY_LEFT_BRACKET = 0x2F,
    KEY_RIGHT_BRACKET = 0x30,
    KEY_BACKSLASH = 0x31,
    KEY_SEMICOLON = 0x33,
    KEY_APOSTROPHE = 0x34,
    KEY_GRAVE_ACCENT = 0x35,
    KEY_COMMA = 0x36,
    KEY_PERIOD = 0x37,
    KEY_SLASH = 0x38,
    KEY_CAPS_LOCK = 0x39,
    KEY_F1 = 0x3A,
    KEY_F2 = 0x3B,
    KEY_F3 = 0x3C,
    KEY_F4 = 0x3D,
    KEY_F5 = 0x3E,
    KEY_F6 = 0x3F,
    KEY_F7 = 0x40,
    KEY_F8 = 0x41,
    KEY_F9 = 0x42,
    KEY_F10 = 0x43,
    KEY_F11 = 0x44,
    KEY_F12 = 0x45,
    KEY_PRINT_SCREEN = 0x46,
    KEY_SCROLL_LOCK = 0x47,
    KEY_PAUSE = 0x48,
    KEY_INSERT = 0x49,
    KEY_HOME = 0x4A,
    KEY_PAGE_UP = 0x4B,
    KEY_DELETE = 0x4C,
    KEY_END = 0x4D,
    KEY_PAGE_DOWN = 0x4E,
    KEY_RIGHT_ARROW = 0x4F,
    KEY_LEFT_ARROW = 0x50,
    KEY_DOWN_ARROW = 0x51,
    KEY_UP_ARROW = 0x52,
    KEY_NUM_LOCK = 0x53,
    KEY_KEYPAD_DIVIDE = 0x54,
    KEY_KEYPAD_MULTIPLY = 0x55,
    KEY_KEYPAD_SUBTRACT = 0x56,
    KEY_KEYPAD_ADD = 0x57,
    KEY_KEYPAD_ENTER = 0x58,
    KEY_KEYPAD_1 = 0x59,
    KEY_KEYPAD_2 = 0x5A,
    KEY_KEYPAD_3 = 0x5B,
    KEY_KEYPAD_4 = 0x5C,
    KEY_KEYPAD_5 = 0x5D,
    KEY_KEYPAD_6 = 0x5E,
    KEY_KEYPAD_7 = 0x5F,
    KEY_KEYPAD_8 = 0x60,
    KEY_KEYPAD_9 = 0x61,
    KEY_KEYPAD_0 = 0x62,
    KEY_KEYPAD_PERIOD = 0x63,
    KEY_NON_US_BACKSLASH = 0x64,
    KEY_APPLICATION = 0x65,
    KEY_POWER = 0x66,
    KEY_KEYPAD_EQUALS = 0x67,
    KEY_F13 = 0x68,
    KEY_F14 = 0x69,
    KEY_F15 = 0x6A,
    KEY_F16 = 0x6B,
    KEY_F17 = 0x6C,
    KEY_F18 = 0x6D,
    KEY_F19 = 0x6E,
    KEY_F20 = 0x6F,
    KEY_F21 = 0x70,
    KEY_F22 = 0x71,
    KEY_F23 = 0x72,
    KEY_F24 = 0x73,
    KEY_EXECUTE = 0x74,
    KEY_HELP = 0x75,
    KEY_MENU = 0x76,
    KEY_SELECT = 0x77,
    KEY_STOP = 0x78,
    KEY_AGAIN = 0x79,
    KEY_UNDO = 0x7A,
    KEY_CUT = 0x7B,
    KEY_COPY = 0x7C,
    KEY_PASTE = 0x7D,
    KEY_FIND = 0x7E,
    KEY_MUTE = 0x7F,
    KEY_VOLUME_UP = 0x80,
    KEY_VOLUME_DOWN = 0x81,
    KEY_LOCKING_CAPS_LOCK = 0x82,
    KEY_LOCKING_NUM_LOCK = 0x83,
    KEY_LOCKING_SCROLL_LOCK = 0x84,
    KEY_KEYPAD_COMMA = 0x85,
    KEY_KEYPAD_EQUAL_SIGN = 0x86,
    KEY_INTERNATIONAL1 = 0x87,
    KEY_INTERNATIONAL2 = 0x88,
    KEY_INTERNATIONAL3 = 0x89,
    KEY_INTERNATIONAL4 = 0x8A,
    KEY_INTERNATIONAL5 = 0x8B,
    KEY_INTERNATIONAL6 = 0x8C,
    KEY_INTERNATIONAL7 = 0x8D,
    KEY_INTERNATIONAL8 = 0x8E,
    KEY_INTERNATIONAL9 = 0x8F,
    KEY_LANG1 = 0x90,
    KEY_LANG2 = 0x91,
    KEY_LANG3 = 0x92,
    KEY_LANG4 = 0x93,
    KEY_LANG5 = 0x94,
    KEY_LANG6 = 0x95,
    KEY_LANG7 = 0x96,
    KEY_LANG8 = 0x97,
    KEY_LANG9 = 0x98,
    KEY_ALTERNATE_ERASE = 0x99,
    KEY_SYSREQ_ATTENTION = 0x9A,
    KEY_CANCEL = 0x9B,
    KEY_CLEAR = 0x9C,
    KEY_PRIOR = 0x9D,
    KEY_RETURN = 0x9E,
    KEY_SEPARATOR = 0x9F,
    KEY_OUT = 0xA0,
    KEY_OPER = 0xA1,
    KEY_CLEAR_AGAIN = 0xA2,
    KEY_CRSEL = 0xA3,
    KEY_EXSEL = 0xA4,
    KEY_KEYPAD_00 = 0xB0,
    KEY_KEYPAD_000 = 0xB1,
    KEY_THOUSANDS_SEPARATOR = 0xB2,
    KEY_DECIMAL_SEPARATOR = 0xB3,
    KEY_CURRENCY_UNIT = 0xB4,
    KEY_CURRENCY_SUB_UNIT = 0xB5,
    KEY_KEYPAD_LEFT_PARENTHESIS = 0xB6,
    KEY_KEYPAD_RIGHT_PARENTHESIS = 0xB7,
    KEY_KEYPAD_LEFT_BRACE = 0xB8,
    KEY_KEYPAD_RIGHT_BRACE = 0xB9,
    KEY_KEYPAD_TAB = 0xBA,
    KEY_KEYPAD_BACKSPACE = 0xBB,
    KEY_KEYPAD_A = 0xBC,
    KEY_KEYPAD_B = 0xBD,
    KEY_KEYPAD_C = 0xBE,
    KEY_KEYPAD_D = 0xBF,
    KEY_KEYPAD_E = 0xC0,
    KEY_KEYPAD_F = 0xC1,
    KEY_KEYPAD_XOR = 0xC2,
    KEY_KEYPAD_CARET = 0xC3,
    KEY_KEYPAD_PERCENT = 0xC4,
    KEY_KEYPAD_LESS_THAN = 0xC5,
    KEY_KEYPAD_GREATER_THAN = 0xC6,
    KEY_KEYPAD_AMPERSAND = 0xC7,
    KEY_KEYPAD_DOUBLE_AMPERSAND = 0xC8,
    KEY_KEYPAD_VERTICAL_BAR = 0xC9,
    KEY_KEYPAD_DOUBLE_VERTICAL_BAR = 0xCA,
    KEY_KEYPAD_COLON = 0xCB,
    KEY_KEYPAD_HASH = 0xCC,
    KEY_KEYPAD_SPACE = 0xCD,
    KEY_KEYPAD_AT_SIGN = 0xCE,
    KEY_KEYPAD_EXCLAMATION_MARK = 0xCF,
    KEY_KEYPAD_MEMORY_STORE = 0xD0,
    KEY_KEYPAD_MEMORY_RECALL = 0xD1,
    KEY_KEYPAD_MEMORY_CLEAR = 0xD2,
    KEY_KEYPAD_MEMORY_ADD = 0xD3,
    KEY_KEYPAD_MEMORY_SUBTRACT = 0xD4,
    KEY_KEYPAD_MEMORY_MULTIPLY = 0xD5,
    KEY_KEYPAD_MEMORY_DIVIDE = 0xD6,
    KEY_KEYPAD_PLUS_MINUS = 0xD7,
    KEY_KEYPAD_CLEAR = 0xD8,
    KEY_KEYPAD_CLEAR_ENTRY = 0xD9,
    KEY_KEYPAD_BINARY = 0xDA,
    KEY_KEYPAD_OCTAL = 0xDB,
    KEY_KEYPAD_DECIMAL = 0xDC,
    KEY_KEYPAD_HEXADECIMAL = 0xDD
};


inline HidKeyboardCode ascii_to_keycode(char chr) {
    if (chr >= 'a' && chr <= 'z') {
        return HidKeyboardCode(chr - 'a' + 0x04);
    } else if (chr >= 'A' && chr <= 'Z') {
        return HidKeyboardCode(chr - 'A' + 0x04);
    } else if (chr >= '0' && chr <= '9') {
        return HidKeyboardCode(chr - '0' + 0x1E);
    }
    // 如果字符不在上述范围内，可以返回一个默认值或错误码
    return HidKeyboardCode(0x00); // 或者其他适当的默认值
}

struct HidKeyboardModifiers {
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


struct HidKeyboardDataFrame:public U8Intf{
    #pragma pack(push, 1)
    using Modifiers = HidKeyboardModifiers;

    Modifiers modifiers;
    const uint8_t __resv__ = 0;

    HidKeyboardCode keycodes[6];
    
    HidKeyboardDataFrame() = default;

    HidKeyboardDataFrame(const Modifiers _modifiers):
        modifiers(_modifiers){;}

    // template<typename ...Args>
    // HidKeyboardDataFrame(const Modifiers _modifiers):
    //     modifiers(_modifiers){;}

    HidKeyboardDataFrame(const char * str, const Modifiers _modifiers = Modifiers()):
        modifiers(_modifiers)
    {
        for(size_t i = 0; i < 6; i++){
            keycodes[i] = ascii_to_keycode(str[i]);
        }
    }

    HidKeyboardDataFrame(const HidKeyboardCode code, const Modifiers _modifiers = Modifiers()):
        modifiers(_modifiers)
    {
        keycodes[0] = code;
    }
    uint8_t operator [](const size_t idx) const {
        return *((const uint8_t*)this + idx);
    }

    #pragma pack(pop)
};

enum class UsbDescrType : uint8_t {
    Device = 0x01,
    Configuration = 0x02,
    String = 0x03,
    Interface = 0x04,
    Endpoint = 0x05,
};

template<size_t Length, UsbDescrType DescrType>
struct __UsbDescrBase:public U8Intf{
    #pragma pack(push,1)
    const uint8_t bLength = Length;
    const uint8_t bDescriptorType = uint8_t(DescrType);
    #pragma pack(pop)
};

//N表示字符数量
template<size_t N>
struct __UsbStrDescr:public __UsbDescrBase<N * 2 + 2, UsbDescrType::String>{
protected:
#pragma pack(push,1)
    uint16_t str[N] = {0};
#pragma pack(pop)
public:
    consteval __UsbStrDescr(const char (&input)[N+1]) {
        for (size_t i = 0; i < N; ++i) { // N-1 to exclude the null terminator
            str[i] = static_cast<uint16_t>(input[i]);
        }
    }
};


struct __UsbEndpointDescr : public __UsbDescrBase<7, UsbDescrType::Endpoint> {
#pragma pack(push, 1)
    uint8_t  bEndpointAddress;
    uint8_t  bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t  bInterval;
#pragma pack(pop)
};

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


template <size_t N>
consteval auto create_usb_strdescr(const char (&input)[N]) {
    return __UsbStrDescr<N-1>(input);
}
    

// const auto Descr = create_usb_strdescr("wch.cn");
// const auto size = sizeof(Descr);