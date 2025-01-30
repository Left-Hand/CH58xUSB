

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

#include "usb_proc.hpp"

#include "usb/hiddev/keyboard/HidKeyboard.hpp"
#include "usb/hiddev/mouse/HidMouse.hpp"
#include "usb/hiddev/joystick/HidJoystick.hpp"
#include "usb/hiddev/gamepad/HidGamePad.hpp"
#include "usb/hiddev/touchpad/HidTouchPad.hpp"
#include "usb/descr/ConfigDescr.hpp"
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


template<typename ... Args>
struct __UsbTotalCfg{
#pragma pack(push, 1)
    __UsbConfigDescr cfg;
    std::tuple<Args...> args;

    __UsbTotalCfg(__UsbConfigDescr cfg, std::tuple<Args...> args)
        : cfg(std::move(cfg)), args(std::move(args)) {}
#pragma pack(pop)
};

template<typename ... Args>
auto make_usb_total_cfg(__UsbConfigDescr cfg, std::tuple<Args...> args){
    return __UsbTotalCfg<Args...>{cfg, args};
}

template <typename T>
size_t calculateSize(const T & arg) {
    return sizeof(arg.getEndpointDescr()) + sizeof(arg.getHidClassDescr()) + sizeof(arg.getInterfaceDescr(0));
}

template <typename T, typename... Args>
size_t calculateSize(const T & first, Args && ... rest) {
    return calculateSize(first) + calculateSize(rest...);
}

template<typename ... Args>
auto getCfg(Args &&... args){
    // 0x09, //bLength 描述符的字节数长度 标准为0x09
    // 0x02, //bDescriptorType 描述符的类型 0x02为配置描述符
    // 59, 0x00, //wTotalLength 配置信息的总长（包括配置、接口、端点、类和厂商描述符）
    // 0x02, //bNumInterfaces 该配置所支持的接口数目
    // 0x01, //bConfigurationValue 被SET_CONFIGURATION请求用作参数来选定
    // 0x00, //iConfiguration 该配置的字符串描述符索引值，在SET_CONFIGURATION中用作选定配置的参数
    // 0xA0, //bmAttributes D6：自供电 D5：远程唤醒 其他位保留。//若一个设备既能自供电又能使用总线供电，D6也要置1并在MaxPower指出需要从总线获取的电量
    // 0x32, //MaxPower 该配置下的总线电源耗费量，为两倍此值（如0x32*2 = 100）mA

    auto body = std::make_tuple(std::make_tuple(args.getEndpointDescr(),  args.getHidClassDescr(), args.getInterfaceDescr(0))...);
    auto size = sizeof(__UsbConfigDescr) + calculateSize(args...);
    return make_usb_total_cfg(
        __UsbConfigDescr{
            .wTotalLength = uint8_t(size),
            .bNumInterfaces = std::tuple_size_v<decltype(std::make_tuple(args...))>, //bNumInterfaces
            .bConfigurationValue = 0x01,
            .iConfiguration = 0x00,
            .bmAttributes = 0xA0,
            .bMaxPower = 0x32
        },
        body
    );

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

    usb_processer.init();

    HidMouse mouse{usb_processer.endpoint(2)};
    HidKeyboard keyboard{usb_processer.endpoint(3)};
    HidJoytick joytick{usb_processer.endpoint(1)};

    auto cfg = getCfg( mouse);

    usb_processer.bind(mouse, 2);
    // usb_processer.bind(keyboard, 3);
    usb_processer.bind(joytick, 1);

    PFIC_EnableIRQ(USB_IRQn);

    while(1){
        // joytick.report({
        //     .x = 1,
        // });

        // mDelaymS(100);

        // joytick.report({});
        // mDelaymS(400);
        // mDelaymS(200);
        // keyboard.report("wch");
        // mDelaymS(20);
        // keyboard.report({});

        // mouse.report({.left_click = true});
        // mDelaymS(20);
        // mouse.report({.left_click = false});
        // mDelaymS(100);

        // printf("%d\r\n", sizeof(cfg));
        for(size_t i = 0; i < sizeof(cfg); i++){
            printf("%02x,", +reinterpret_cast<const uint8_t *>(&cfg)[i]);
            DelayMs(10);
        }
        printf("\r\n");
        // //win + r
        // DevHIDKeyReport({"r",{.left_gui_pressed = 1}});

        // DevHIDKeyReport(HidKeyboardCode::KEY_CAPS_LOCK);

        // //delete chars
        // for(size_t i = 0; i < 6; i++){
        //     DevHIDKeyReport(HidKeyboardCode::KEY_RIGHT_ARROW);
        //     DevHIDKeyReport(HidKeyboardCode::KEY_BACKSPACE);
        // }

        // //cmd + enter
        // DevHIDKeyReport("cmd");
        // DevHIDKeyReport(HidKeyboardCode::KEY_ENTER);

        // //input gcc
        // DevHIDKeyReport("gcc");
        // DevHIDKeyReport(HidKeyboardCode::KEY_ENTER);

        // mDelaymS(10);
        
        // DevHIDKeyReport();
        // while(true);
        mDelaymS(1000);
    }
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
    // printf("usb\r\n");
    // USB_DevTransProcess();
    usb_processer.handle();
}

}




