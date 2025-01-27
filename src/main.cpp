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

struct HidMouseDataFrame{
    #pragma pack(push, 1)

    uint8_t left_click:1;
    uint8_t right_click:1;
    uint8_t middle_click:1;
    const uint8_t __resv__:5 = 0;

    int8_t x_delta;
    int8_t y_delta;
    int8_t wheel_delta;
    
    uint8_t operator [](const size_t idx) const {
        return *((const uint8_t*)this + idx);
    }

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


struct HidKeyboardDataFrame{
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

    HidKeyboardDataFrame(const Modifiers _modifiers, const char * str):
        modifiers(_modifiers){
            for(size_t i = 0; i < 6; i++){
                keycodes[i] = ascii_to_keycode(str[i]);
            }
        }
    uint8_t operator [](const size_t idx) const {
        return *((const uint8_t*)this + idx);
    }

    #pragma pack(pop)
};

/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2022/01/25
 * Description        : 模拟USB复合设备，键鼠，支持类命令
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#include "CH58x_common.h"

#define DevEP0SIZE    0x40
// 设备描述符
const uint8_t MyDevDescr[] = {0x12, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, DevEP0SIZE, 0x3d, 0x41, 0x07, 0x21, 0x00, 0x00,
                              0x00, 0x00, 0x00, 0x01};
// 配置描述符
const uint8_t MyCfgDescr[] = {
    0x09, 0x02, 0x3b, 0x00, 0x02, 0x01, 0x00, 0xA0, 0x32, //配置描述符
    0x09, 0x04, 0x00, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, //接口描述符,键盘
    0x09, 0x21, 0x11, 0x01, 0x00, 0x01, 0x22, 0x3e, 0x00, //HID类描述符
    0x07, 0x05, 0x81, 0x03, 0x08, 0x00, 0x0a,             //端点描述符
    0x09, 0x04, 0x01, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00, //接口描述符,鼠标
    0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x34, 0x00, //HID类描述符
    0x07, 0x05, 0x82, 0x03, 0x04, 0x00, 0x0a              //端点描述符

};
/* USB速度匹配描述符 */
const uint8_t My_QueDescr[] = {0x0A, 0x06, 0x00, 0x02, 0xFF, 0x00, 0xFF, 0x40, 0x01, 0x00};

/* USB全速模式,其他速度配置描述符 */
uint8_t USB_FS_OSC_DESC[sizeof(MyCfgDescr)] = {
    0x09, 0x07, /* 其他部分通过程序复制 */
};

// 语言描述符
const uint8_t MyLangDescr[] = {0x04, 0x03, 0x09, 0x04};
// 厂家信息
const uint8_t MyManuInfo[] = {0x0E, 0x03, 'w', 0, 'c', 0, 'h', 0, '.', 0, 'c', 0, 'n', 0};
// 产品信息
const uint8_t MyProdInfo[] = {0x0C, 0x03, 'C', 0, 'H', 0, '5', 0, '7', 0, 'x', 0};
/*HID类报表描述符*/
const uint8_t KeyRepDesc[] = {0x05, 0x01, 0x09, 0x06, 0xA1, 0x01, 0x05, 0x07, 0x19, 0xe0, 0x29, 0xe7, 0x15, 0x00, 0x25,
                              0x01, 0x75, 0x01, 0x95, 0x08, 0x81, 0x02, 0x95, 0x01, 0x75, 0x08, 0x81, 0x01, 0x95, 0x03,
                              0x75, 0x01, 0x05, 0x08, 0x19, 0x01, 0x29, 0x03, 0x91, 0x02, 0x95, 0x05, 0x75, 0x01, 0x91,
                              0x01, 0x95, 0x06, 0x75, 0x08, 0x26, 0xff, 0x00, 0x05, 0x07, 0x19, 0x00, 0x29, 0x91, 0x81,
                              0x00, 0xC0};
const uint8_t MouseRepDesc[] = {0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00, 0x05, 0x09, 0x19, 0x01, 0x29,
                                0x03, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01, 0x95, 0x03, 0x81, 0x02, 0x75, 0x05, 0x95, 0x01,
                                0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x09, 0x38, 0x15, 0x81, 0x25, 0x7f, 0x75,
                                0x08, 0x95, 0x03, 0x81, 0x06, 0xC0, 0xC0};

/**********************************************************/
uint8_t        DevConfig, Ready;
uint8_t        SetupReqCode;
uint16_t       SetupReqLen;
const uint8_t *pDescr;
uint8_t        Report_Value = 0x00;
uint8_t        Idle_Value = 0x00;
uint8_t        USB_SleepStatus = 0x00; /* USB睡眠状态 */

/*鼠标键盘数据*/
uint8_t HIDMouse[4] = {0x0, 0x0, 0x0, 0x0};
uint8_t HIDKey[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
/******** 用户自定义分配端点RAM ****************************************/
__attribute__((aligned(4))) uint8_t EP0_Databuf[64 + 64 + 64]; //ep0(64)+ep4_out(64)+ep4_in(64)
__attribute__((aligned(4))) uint8_t EP1_Databuf[64 + 64];      //ep1_out(64)+ep1_in(64)
__attribute__((aligned(4))) uint8_t EP2_Databuf[64 + 64];      //ep2_out(64)+ep2_in(64)
__attribute__((aligned(4))) uint8_t EP3_Databuf[64 + 64];      //ep3_out(64)+ep3_in(64)

/*********************************************************************
 * @fn      USB_DevTransProcess
 *
 * @brief   USB 传输处理函数
 *
 * @return  none
 */
void USB_DevTransProcess(void)
{
    uint8_t len, chtype;
    uint8_t intflag, errflag = 0;

    intflag = R8_USB_INT_FG;
    if(intflag & RB_UIF_TRANSFER)
    {
        if((R8_USB_INT_ST & MASK_UIS_TOKEN) != MASK_UIS_TOKEN) // 非空闲
        {
            switch(R8_USB_INT_ST & (MASK_UIS_TOKEN | MASK_UIS_ENDP))
            // 分析操作令牌和端点号
            {
                case UIS_TOKEN_IN:
                {
                    switch(SetupReqCode)
                    {
                        case USB_GET_DESCRIPTOR:
                            len = SetupReqLen >= DevEP0SIZE ? DevEP0SIZE : SetupReqLen; // 本次传输长度
                            memcpy(pEP0_DataBuf, pDescr, len);                          /* 加载上传数据 */
                            SetupReqLen -= len;
                            pDescr += len;
                            R8_UEP0_T_LEN = len;
                            R8_UEP0_CTRL ^= RB_UEP_T_TOG; // 翻转
                            break;
                        case USB_SET_ADDRESS:
                            R8_USB_DEV_AD = (R8_USB_DEV_AD & RB_UDA_GP_BIT) | SetupReqLen;
                            R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                            break;

                        case USB_SET_FEATURE:
                            break;

                        default:
                            R8_UEP0_T_LEN = 0; // 状态阶段完成中断或者是强制上传0长度数据包结束控制传输
                            R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                            break;
                    }
                }
                break;

                case UIS_TOKEN_OUT:
                {
                    len = R8_USB_RX_LEN;
                    if(SetupReqCode == 0x09)
                    {
                        PRINT("[%s] Num Lock\t", (pEP0_DataBuf[0] & (1<<0)) ? "*" : " ");
                        PRINT("[%s] Caps Lock\t", (pEP0_DataBuf[0] & (1<<1)) ? "*" : " ");
                        PRINT("[%s] Scroll Lock\n", (pEP0_DataBuf[0] & (1<<2)) ? "*" : " ");
                    }
                }
                break;

                case UIS_TOKEN_OUT | 1:
                {
                    if(R8_USB_INT_ST & RB_UIS_TOG_OK)
                    { // 不同步的数据包将丢弃
                        R8_UEP1_CTRL ^= RB_UEP_R_TOG;
                        len = R8_USB_RX_LEN;
                        DevEP1_OUT_Deal(len);
                    }
                }
                break;

                case UIS_TOKEN_IN | 1:
                    R8_UEP1_CTRL ^= RB_UEP_T_TOG;
                    R8_UEP1_CTRL = (R8_UEP1_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
                    break;

                case UIS_TOKEN_OUT | 2:
                {
                    if(R8_USB_INT_ST & RB_UIS_TOG_OK)
                    { // 不同步的数据包将丢弃
                        R8_UEP2_CTRL ^= RB_UEP_R_TOG;
                        len = R8_USB_RX_LEN;
                        DevEP2_OUT_Deal(len);
                    }
                }
                break;

                case UIS_TOKEN_IN | 2:
                    R8_UEP2_CTRL ^= RB_UEP_T_TOG;
                    R8_UEP2_CTRL = (R8_UEP2_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
                    break;

                case UIS_TOKEN_OUT | 3:
                {
                    if(R8_USB_INT_ST & RB_UIS_TOG_OK)
                    { // 不同步的数据包将丢弃
                        R8_UEP3_CTRL ^= RB_UEP_R_TOG;
                        len = R8_USB_RX_LEN;
                        DevEP3_OUT_Deal(len);
                    }
                }
                break;

                case UIS_TOKEN_IN | 3:
                    R8_UEP3_CTRL ^= RB_UEP_T_TOG;
                    R8_UEP3_CTRL = (R8_UEP3_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
                    break;

                case UIS_TOKEN_OUT | 4:
                {
                    if(R8_USB_INT_ST & RB_UIS_TOG_OK)
                    {
                        R8_UEP4_CTRL ^= RB_UEP_R_TOG;
                        len = R8_USB_RX_LEN;
                        DevEP4_OUT_Deal(len);
                    }
                }
                break;

                case UIS_TOKEN_IN | 4:
                    R8_UEP4_CTRL ^= RB_UEP_T_TOG;
                    R8_UEP4_CTRL = (R8_UEP4_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
                    break;

                default:
                    break;
            }
            R8_USB_INT_FG = RB_UIF_TRANSFER;
        }
        if(R8_USB_INT_ST & RB_UIS_SETUP_ACT) // Setup包处理
        {
            R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_NAK;
            SetupReqLen = pSetupReqPak->wLength;
            SetupReqCode = pSetupReqPak->bRequest;
            chtype = pSetupReqPak->bRequestType;

            len = 0;
            errflag = 0;
            if((pSetupReqPak->bRequestType & USB_REQ_TYP_MASK) != USB_REQ_TYP_STANDARD)
            {
                /* 非标准请求 */
                /* 其它请求,如类请求，产商请求等 */
                if(pSetupReqPak->bRequestType & 0x40)
                {
                    /* 厂商请求 */
                }
                else if(pSetupReqPak->bRequestType & 0x20)
                {
                    switch(SetupReqCode)
                    {
                        case DEF_USB_SET_IDLE: /* 0x0A: SET_IDLE */
                            Idle_Value = EP0_Databuf[3];
                            break; //这个一定要有

                        case DEF_USB_SET_REPORT: /* 0x09: SET_REPORT */
                            break;

                        case DEF_USB_SET_PROTOCOL: /* 0x0B: SET_PROTOCOL */
                            Report_Value = EP0_Databuf[2];
                            break;

                        case DEF_USB_GET_IDLE: /* 0x02: GET_IDLE */
                            EP0_Databuf[0] = Idle_Value;
                            len = 1;
                            break;

                        case DEF_USB_GET_PROTOCOL: /* 0x03: GET_PROTOCOL */
                            EP0_Databuf[0] = Report_Value;
                            len = 1;
                            break;

                        default:
                            errflag = 0xFF;
                    }
                }
            }
            else /* 标准请求 */
            {
                switch(SetupReqCode)
                {
                    case USB_GET_DESCRIPTOR:
                    {
                        switch(((pSetupReqPak->wValue) >> 8))
                        {
                            case USB_DESCR_TYP_DEVICE:
                            {
                                pDescr = MyDevDescr;
                                len = MyDevDescr[0];
                            }
                            break;

                            case USB_DESCR_TYP_CONFIG:
                            {
                                pDescr = MyCfgDescr;
                                len = MyCfgDescr[2];
                            }
                            break;

                            case USB_DESCR_TYP_HID:
                                switch((pSetupReqPak->wIndex) & 0xff)
                                {
                                    /* 选择接口 */
                                    case 0:
                                        pDescr = (uint8_t *)(&MyCfgDescr[18]);
                                        len = 9;
                                        break;

                                    case 1:
                                        pDescr = (uint8_t *)(&MyCfgDescr[43]);
                                        len = 9;
                                        break;

                                    default:
                                        /* 不支持的字符串描述符 */
                                        errflag = 0xff;
                                        break;
                                }
                                break;

                            case USB_DESCR_TYP_REPORT:
                            {
                                if(((pSetupReqPak->wIndex) & 0xff) == 0) //接口0报表描述符
                                {
                                    pDescr = KeyRepDesc; //数据准备上传
                                    len = sizeof(KeyRepDesc);
                                }
                                else if(((pSetupReqPak->wIndex) & 0xff) == 1) //接口1报表描述符
                                {
                                    pDescr = MouseRepDesc; //数据准备上传
                                    len = sizeof(MouseRepDesc);
                                    Ready = 1; //如果有更多接口，该标准位应该在最后一个接口配置完成后有效
                                }
                                else
                                    len = 0xff; //本程序只有2个接口，这句话正常不可能执行
                            }
                            break;

                            case USB_DESCR_TYP_STRING:
                            {
                                switch((pSetupReqPak->wValue) & 0xff)
                                {
                                    case 1:
                                        pDescr = MyManuInfo;
                                        len = MyManuInfo[0];
                                        break;
                                    case 2:
                                        pDescr = MyProdInfo;
                                        len = MyProdInfo[0];
                                        break;
                                    case 0:
                                        pDescr = MyLangDescr;
                                        len = MyLangDescr[0];
                                        break;
                                    default:
                                        errflag = 0xFF; // 不支持的字符串描述符
                                        break;
                                }
                            }
                            break;

                            case 0x06:
                                pDescr = (uint8_t *)(&My_QueDescr[0]);
                                len = sizeof(My_QueDescr);
                                break;

                            case 0x07:
                                memcpy(&USB_FS_OSC_DESC[2], &MyCfgDescr[2], sizeof(MyCfgDescr) - 2);
                                pDescr = (uint8_t *)(&USB_FS_OSC_DESC[0]);
                                len = sizeof(USB_FS_OSC_DESC);
                                break;

                            default:
                                errflag = 0xff;
                                break;
                        }
                        if(SetupReqLen > len)
                            SetupReqLen = len; //实际需上传总长度
                        len = (SetupReqLen >= DevEP0SIZE) ? DevEP0SIZE : SetupReqLen;
                        memcpy(pEP0_DataBuf, pDescr, len);
                        pDescr += len;
                    }
                    break;

                    case USB_SET_ADDRESS:
                        SetupReqLen = (pSetupReqPak->wValue) & 0xff;
                        break;

                    case USB_GET_CONFIGURATION:
                        pEP0_DataBuf[0] = DevConfig;
                        if(SetupReqLen > 1)
                            SetupReqLen = 1;
                        break;

                    case USB_SET_CONFIGURATION:
                        DevConfig = (pSetupReqPak->wValue) & 0xff;
                        break;

                    case USB_CLEAR_FEATURE:
                    {
                        if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP) // 端点
                        {
                            switch((pSetupReqPak->wIndex) & 0xff)
                            {
                                case 0x83:
                                    R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_NAK;
                                    break;
                                case 0x03:
                                    R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_ACK;
                                    break;
                                case 0x82:
                                    R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_NAK;
                                    break;
                                case 0x02:
                                    R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_ACK;
                                    break;
                                case 0x81:
                                    R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_NAK;
                                    break;
                                case 0x01:
                                    R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_ACK;
                                    break;
                                default:
                                    errflag = 0xFF; // 不支持的端点
                                    break;
                            }
                        }
                        else if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_DEVICE)
                        {
                            if(pSetupReqPak->wValue == 1)
                            {
                                USB_SleepStatus &= ~0x01;
                            }
                        }
                        else
                        {
                            errflag = 0xFF;
                        }
                    }
                    break;

                    case USB_SET_FEATURE:
                        if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP)
                        {
                            /* 端点 */
                            switch(pSetupReqPak->wIndex)
                            {
                                case 0x83:
                                    R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_STALL;
                                    break;
                                case 0x03:
                                    R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_STALL;
                                    break;
                                case 0x82:
                                    R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_STALL;
                                    break;
                                case 0x02:
                                    R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_STALL;
                                    break;
                                case 0x81:
                                    R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_STALL;
                                    break;
                                case 0x01:
                                    R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_STALL;
                                    break;
                                default:
                                    /* 不支持的端点 */
                                    errflag = 0xFF; // 不支持的端点
                                    break;
                            }
                        }
                        else if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_DEVICE)
                        {
                            if(pSetupReqPak->wValue == 1)
                            {
                                /* 设置睡眠 */
                                USB_SleepStatus |= 0x01;
                            }
                        }
                        else
                        {
                            errflag = 0xFF;
                        }
                        break;

                    case USB_GET_INTERFACE:
                        pEP0_DataBuf[0] = 0x00;
                        if(SetupReqLen > 1)
                            SetupReqLen = 1;
                        break;

                    case USB_SET_INTERFACE:
                        break;

                    case USB_GET_STATUS:
                        if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP)
                        {
                            /* 端点 */
                            pEP0_DataBuf[0] = 0x00;
                            switch(pSetupReqPak->wIndex)
                            {
                                case 0x83:
                                    if((R8_UEP3_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL)
                                    {
                                        pEP0_DataBuf[0] = 0x01;
                                    }
                                    break;

                                case 0x03:
                                    if((R8_UEP3_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL)
                                    {
                                        pEP0_DataBuf[0] = 0x01;
                                    }
                                    break;

                                case 0x82:
                                    if((R8_UEP2_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL)
                                    {
                                        pEP0_DataBuf[0] = 0x01;
                                    }
                                    break;

                                case 0x02:
                                    if((R8_UEP2_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL)
                                    {
                                        pEP0_DataBuf[0] = 0x01;
                                    }
                                    break;

                                case 0x81:
                                    if((R8_UEP1_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL)
                                    {
                                        pEP0_DataBuf[0] = 0x01;
                                    }
                                    break;

                                case 0x01:
                                    if((R8_UEP1_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL)
                                    {
                                        pEP0_DataBuf[0] = 0x01;
                                    }
                                    break;
                            }
                        }
                        else if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_DEVICE)
                        {
                            pEP0_DataBuf[0] = 0x00;
                            if(USB_SleepStatus)
                            {
                                pEP0_DataBuf[0] = 0x02;
                            }
                            else
                            {
                                pEP0_DataBuf[0] = 0x00;
                            }
                        }
                        pEP0_DataBuf[1] = 0;
                        if(SetupReqLen >= 2)
                        {
                            SetupReqLen = 2;
                        }
                        break;

                    default:
                        errflag = 0xff;
                        break;
                }
            }
            if(errflag == 0xff) // 错误或不支持
            {
                //                  SetupReqCode = 0xFF;
                R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_STALL | UEP_T_RES_STALL; // STALL
            }
            else
            {
                if(chtype & 0x80) // 上传
                {
                    len = (SetupReqLen > DevEP0SIZE) ? DevEP0SIZE : SetupReqLen;
                    SetupReqLen -= len;
                }
                else
                    len = 0; // 下传
                R8_UEP0_T_LEN = len;
                R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_ACK; // 默认数据包是DATA1
            }

            R8_USB_INT_FG = RB_UIF_TRANSFER;
        }
    }
    else if(intflag & RB_UIF_BUS_RST)
    {
        R8_USB_DEV_AD = 0;
        R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
        R8_UEP1_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
        R8_UEP2_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
        R8_UEP3_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
        R8_USB_INT_FG = RB_UIF_BUS_RST;
    }
    else if(intflag & RB_UIF_SUSPEND)
    {
        if(R8_USB_MIS_ST & RB_UMS_SUSPEND)
        {
            ;
        } // 挂起
        else
        {
            ;
        } // 唤醒
        R8_USB_INT_FG = RB_UIF_SUSPEND;
    }
    else
    {
        R8_USB_INT_FG = intflag;
    }
}

void DevHIDMouseReport(const HidMouseDataFrame & data){
    memcpy(HIDMouse, &data, 4);
    memcpy(pEP2_IN_DataBuf, HIDMouse, sizeof(HIDMouse));
    DevEP2_IN_Deal(sizeof(HIDMouse));
}
void DevHIDKeyReport(const HidKeyboardDataFrame & data){
    memcpy(HIDKey, &data, 8);
    memcpy(pEP1_IN_DataBuf, HIDKey, sizeof(HIDKey));
    DevEP1_IN_Deal(sizeof(HIDKey));
}

/*********************************************************************
 * @fn      DevWakeup
 *
 * @brief   设备模式唤醒主机
 *
 * @return  none
 */
void DevWakeup(void)
{
    R16_PIN_ANALOG_IE &= ~(RB_PIN_USB_DP_PU);
    R8_UDEV_CTRL |= RB_UD_LOW_SPEED;
    mDelaymS(2);
    R8_UDEV_CTRL &= ~RB_UD_LOW_SPEED;
    R16_PIN_ANALOG_IE |= RB_PIN_USB_DP_PU;
}

/*********************************************************************
 * @fn      DebugInit
 *
 * @brief   调试初始化
 *
 * @return  none
 */
void DebugInit(void)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
}

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数
 *
 * @return  none
 */
int main()
{
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    DebugInit();
    PRINT("start\n");

    pEP0_RAM_Addr = EP0_Databuf;
    pEP1_RAM_Addr = EP1_Databuf;
    pEP2_RAM_Addr = EP2_Databuf;
    pEP3_RAM_Addr = EP3_Databuf;

    USB_DeviceInit();

    PFIC_EnableIRQ(USB_IRQn);

    while(1)
    {
        mDelaymS(1000);
        //鼠标左键
        // printf("left\r\n");
        // DevHIDMouseReport({
        //     // .left_click = 1
        //     // .wheel_delta = 1
        //     .x_delta = 100
        //     // .middle_click = 1
        // });
        // mDelaymS(100);
        // DevHIDMouseReport({});
        // mDelaymS(200);

        // DevHIDMouseReport({
        //     // .right_click = 1
        //     // .wheel_delta = -1
        //     .x_delta = -100
        //     // .middle_click = 0
        // });
        // mDelaymS(100);
        // DevHIDMouseReport({});
        // mDelaymS(200);

        // //键盘按键“wch”
        // printf("kb\r\n");
        // mDelaymS(1000);
        // DevHIDKeyReport({
        //     {},
        //     "wch"
        // });
        mDelaymS(100);
        DevHIDKeyReport(HidKeyboardDataFrame{
            HidKeyboardModifiers{.left_shift_pressed = 1},
            // {},
            "wch"
        });
        mDelaymS(10);
        DevHIDKeyReport(HidKeyboardDataFrame{
        });
        mDelaymS(1000);
    }
}

/*********************************************************************
 * @fn      DevEP1_OUT_Deal
 *
 * @brief   端点1数据处理
 *
 * @return  none
 */
void DevEP1_OUT_Deal(uint8_t l)
{ /* 用户可自定义 */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP1_IN_DataBuf[i] = ~pEP1_OUT_DataBuf[i];
    }
    DevEP1_IN_Deal(l);
}

/*********************************************************************
 * @fn      DevEP2_OUT_Deal
 *
 * @brief   端点2数据处理
 *
 * @return  none
 */
void DevEP2_OUT_Deal(uint8_t l)
{ /* 用户可自定义 */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP2_IN_DataBuf[i] = ~pEP2_OUT_DataBuf[i];
    }
    DevEP2_IN_Deal(l);
}

/*********************************************************************
 * @fn      DevEP3_OUT_Deal
 *
 * @brief   端点3数据处理
 *
 * @return  none
 */
void DevEP3_OUT_Deal(uint8_t l)
{ /* 用户可自定义 */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP3_IN_DataBuf[i] = ~pEP3_OUT_DataBuf[i];
    }
    DevEP3_IN_Deal(l);
}

/*********************************************************************
 * @fn      DevEP4_OUT_Deal
 *
 * @brief   端点4数据处理
 *
 * @return  none
 */
void DevEP4_OUT_Deal(uint8_t l)
{ /* 用户可自定义 */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP4_IN_DataBuf[i] = ~pEP4_OUT_DataBuf[i];
    }
    DevEP4_IN_Deal(l);
}

/*********************************************************************
 * @fn      USB_IRQHandler
 *
 * @brief   USB中断函数
 *
 * @return  none
 */

extern "C"{
__INTERRUPT
__HIGH_CODE
void USB_IRQHandler(void) /* USB中断服务程序,使用寄存器组1 */
{
    printf("usb\r\n");
    USB_DevTransProcess();
}

}