

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






void DevHIDMouseReport(const HidMouseDataFrame & data = HidMouseDataFrame()){
    memcpy(pEP2_IN_DataBuf, &data, 4);
    DevEP2_IN_Deal(4);
}
void DevHIDKeyReport(const HidKeyboardDataFrame & data = HidKeyboardDataFrame()){
    memcpy(pEP1_IN_DataBuf, &data, 8);
    DevEP1_IN_Deal(8);
    // DelayMs(10);
    // memset(pEP1_IN_DataBuf, 0, 8 );
    // DevEP1_IN_Deal(8);
    // DelayMs(10);
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

    usb_processer.init();

    USB_DeviceInit();

    PFIC_EnableIRQ(USB_IRQn);

    while(1)
    {
        // mDelaymS(1000);
        // printf("left\r\n");
        // DevHIDMouseReport({
        //     // .left_click = 1
        //     // .wheel_delta = 1
        //     .x_delta = 100
        //     // .middle_click = 1
        // });
        // mDelaymS(100);
        // DevHIDMouseReport({
        //     .x_delta = -100
        // });
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

        //键盘按键“wch”
        printf("kb\r\n");
        mDelaymS(1000);
        // keyboard.report("wch");
        DevHIDKeyReport("wch");


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