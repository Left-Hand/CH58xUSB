

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

    usb_processer.init();

    // HidKeyboard & keyboard = usb_processer.createHidDevice<HidKeyboard>();
    HidKeyboard keyboard{usb_processer.endpoint(1)};
    HidMouse mouse{usb_processer.endpoint(2)};
    HidJoytick joytick{usb_processer.endpoint(3)};

    usb_processer.bind(keyboard, 1);
    usb_processer.bind(mouse, 2);

    PFIC_EnableIRQ(USB_IRQn);

    while(1){

        mDelaymS(200);
        keyboard.report("wch");
        mDelaymS(20);
        keyboard.report({});

        mouse.report({.left_click = true});
        mDelaymS(20);
        mouse.report({.left_click = false});


        // mDelaymS(100);

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