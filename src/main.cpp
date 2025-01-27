// // /********************************** (C) COPYRIGHT *******************************
// //  * File Name          : Main.c
// //  * Author             : WCH
// //  * Version            : V1.0
// //  * Date               : 2020/08/06
// //  * Description 		    : 串口1收发演示
// //  *******************************************************************************/

#include "CH58x_common.h"
// // #include "ina226.h"
// // #include "start.h"
// // #include "math.h"
// // #include "main.h"
// // #include "SSD1315.h"
// // #include "ttp229.hpp"
// // #include "string.h"
// // #include "qc/qc.hpp"
// // #include <Vector2.hpp>
// // #include "pwm.hpp"
// // #include "PID.hpp"

// // SSD1315 oled;
// // INA226 ina;

// // #define ESPVGAX_WIDTH 128
// // #define ESPVGAX_HEIGHT 64
// // struct PW{
// //     float v;
// //     float a;
// //     float t;
// // };

// // PW pw;

// // float set = 0.0;
// // TTP229 touchKey;
// // uint8_t cap_cnt = 0;
// // PWM pwm;
// // PID pid;

// // #define PCOUNT 8

// // int cube2d[PCOUNT][2];

// // float cube3d[PCOUNT][3]={
// //   { -0.5f, +0.5f, -0.5f },
// //   { +0.5f, +0.5f, -0.5f },
// //   { -0.5f, -0.5f, -0.5f },
// //   { +0.5f, -0.5f, -0.5f },
// //   { -0.5f, +0.5f, +0.5f },
// //   { +0.5f, +0.5f, +0.5f },
// //   { -0.5f, -0.5f, +0.5f },
// //   { +0.5f, -0.5f, +0.5f }
// // };
// // void zrotate(float v[3], float q, float rx, float ry) {
// //   float tx,ty,temp;
// //   tx=v[0]-rx;
// //   ty=v[1]-ry;
// //   temp=tx*cosf(q)-ty*sinf(q);
// //   ty=tx*sinf(q)+ty*cosf(q);
// //   tx=temp;
// //   v[0]=tx+rx;
// //   v[1]=ty+ry;
// // }
// // void yrotate(float v[3], float q, float rx, float rz) {
// //   float tx,tz,temp;
// //   tx=v[0]-rx;
// //   tz=v[2]-rz;
// //   temp=tz*cosf(q)-tx*sinf(q);
// //   tx=tz*sinf(q)+tx*cosf(q);
// //   tz=temp;
// //   v[0]=tx+rx;
// //   v[2]=tz+rz;
// // }
// // void xrotate(float v[3], float q, float ry, float rz) {
// //   float ty,tz,temp;
// //   ty=v[1]-ry;
// //   tz=v[2]-rz;
// //   temp=ty*cosf(q)-tz*sinf(q);
// //   tz=ty*sinf(q)+tz*cosf(q);
// //   ty=temp;
// //   v[1]=ty+ry;
// //   v[2]=tz+rz;
// // }
// // void draw_line(int p1, int p2) {
// //         Frame & frame = *(oled.fetchFrame());
// //   frame.drawLine(Vector2i(cube2d[p1][0], cube2d[p1][1]), Vector2i(cube2d[p2][0], cube2d[p2][1]));
// // }
// // void draw_cube(float cz, float a, float b, float c) {
// //   for (int i=0; i<PCOUNT; i++) {
// //     float *v=cube3d[i];
// //     float tmp[3]={ v[0], v[1], v[2] };
// //     xrotate(tmp, a, 0, 0);
// //     yrotate(tmp, b, 0, 0);
// //     zrotate(tmp, c, 0, 0);
// //     float z=tmp[2]+cz;
// //     cube2d[i][0]=(int)((tmp[0]/z)*ESPVGAX_WIDTH +(ESPVGAX_WIDTH /2));
// //     cube2d[i][1]=(int)((tmp[1]/z)*ESPVGAX_HEIGHT+(ESPVGAX_HEIGHT/2));
// //   }
// //   draw_line(0, 1); draw_line(0, 2); draw_line(0, 4); 
// //   draw_line(1, 5); draw_line(1, 3);
// //   draw_line(2, 6); draw_line(2, 3);
// //   draw_line(4, 6); draw_line(4, 5);
// //   draw_line(7, 6); draw_line(7, 3); draw_line(7, 5);
// // }

// // #define r 0.007f * 49.28f / 46.88f * 1.54f / 1.61f 

// // void setup(){

// //     PWR_UnitModCfg(DISABLE, UNIT_SYS_LSE); 
// //     //config ina226
// //     INA226_Init(&ina, 0x80, r ,3.2f);
// //     ina.mI2C_Address = 0x80;
// //     //config OLED
// //     oled.init(); 
// //     pwm = PWM();
// //     touchKey = TTP229();
    
// //     // TMR0_TimerInit(mst * 5);
// //     // TMR0_ITCfg(ENABLE, TMR0_3_IT_CYC_END); // 开启中断
// //     // PFIC_EnableIRQ(TMR0_IRQn);

// //     // TMR2_TimerInit(mst * 48);
// //     // TMR2_ITCfg(ENABLE, TMR0_3_IT_CYC_END); // 开启中断
// //     // PFIC_EnableIRQ(TMR0_IRQn);

// //     pid = PID(0.004, 0.0012, 0.0);
// //     pid._max = 1.0f;
// // }


// // string floatStr(float val, int fixed) {
// //     string str = std::to_string(val);
// //     return str.substr(0, str.find(".") + fixed + 1);
// // }

// // void process_ui(){
// //     static float a=0, b=0, c=0;
// //     Frame & frame = *(oled.fetchFrame());
// //     frame.clear();
// //     // static int8_t rr = 0;
// //     // auto v = INA226_GetBusVoltage_uV(&ina) * (1E-6f);
// //     // auto vs = INA226_GetShuntVoltage_uV(&ina) * (1E-6f);

// //     // auto a = vs / r;
// //     // auto w = v * a;
// //     // pw.v = v;
// //     // pw.a = a;

// //     // frame.clear();
// //     // for(Vector2i pos(rr-7,0); pos.x < 128; pos = pos + Vector2i(64,0)){
// //     //     frame.drawLine(pos, pos + Vector2i(0, 64));
// //     //     // frame.drawChar(pos + Vector2i(7, 64), '.');
// //     // }
// //     // rr++;
// //     // rr  = rr%64;
// //     frame.drawString(Vector2i(0,0), std::to_string(touchKey.getNum()));
// //     // frame.drawString(Vector2i(0,8),floatStr(a,3));
// //     // frame.drawString(Vector2i(0,16),floatStr(b,3));
// //     // frame.drawString(Vector2i(0,24),floatStr(c,3));
// //     // frame.drawString(Vector2i(0,32), std::to_string(pw.t));
// //     // frame.drawString(Vector2i(0,40), "SetPoint: " + floatStr(set,3));
// //     // frame.drawString(Vector2i(0,48), "Error: " + floatStr(abs(100.0f*(a-set)/set),4) + "%");

// //     draw_cube(2, c, 0, 0);
// //     draw_cube(4, b, c, a);
// //     draw_cube(9, c, a, b);
// //     a+=0.1f;
// //     b+=0.05f;
// //     c+=0.03f;
// //     oled.pushStream();
// // }

#define PI 3.1415f

uint8_t sin_map[96] = {128, 135, 142, 149, 156, 163, 170, 177, 183, 189, 195, 201, 207, 212, 217, 221, 226, 230, 233, 237, 240, 243, 245, 247, 249, 251, 252, 253, 254, 254, 255, 255, 255, 255, 255, 255, 254, 254, 253, 253, 252, 252, 252, 251, 251, 251, 250, 250, 250, 250, 250, 251, 251, 251, 252, 252, 252, 253, 253, 254, 254, 255, 255, 255, 255, 255, 255, 254, 254, 253, 252, 251, 249, 247, 245, 243, 240, 237, 233, 230, 226, 221, 217, 212, 207, 201, 195, 189, 183, 177, 170, 163, 156, 149, 142, 135};

__HIGH_CODE
uint8_t get_fast_sin(const uint32_t & i){
    uint8_t ret = sin_map[i % 96];
    if ((i / 96) % 2 == 1){
        ret = 255 - ret;
    }
    return ret;
}

struct foc_t{
    uint32_t i = 0;
    uint32_t n = 0;
    uint32_t t = 6;
    uint8_t u;
    uint8_t v;
    uint8_t w;
};

foc_t foc_ctrl;

void DebugInit(void)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
}

void test(){
        GPIOA_SetBits(GPIO_Pin_4);
        GPIOA_ResetBits(GPIO_Pin_4);
        GPIOA_SetBits(GPIO_Pin_4);
        GPIOA_ResetBits(GPIO_Pin_4);
}
extern "C" {
__HIGH_CODE
int main(){

    SetSysClock( CLK_SOURCE_PLL_60MHz);
    DelayMs(5);
    DebugInit();
    printf("init done\r\n");
    /* 配置GPIO */
    GPIOA_ModeCfg(GPIO_Pin_12, GPIO_ModeOut_PP_5mA); // PA12 - PWM4
    GPIOA_ModeCfg(GPIO_Pin_13, GPIO_ModeOut_PP_5mA); // PA13 - PWM5
    GPIOB_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);  // PB4 - PWM7
    // GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_20mA);

    R8_PWM_INT_CTRL |= RB_PWM_IF_CYC;

    // R8_PWM_INT_CTRL |= RB_PWM_CYC_PRE;

    PWMX_CLKCfg(1);                                   // cycle = 4/Fsys
    PWMX_CycleCfg(PWMX_Cycle_255);                     // 周期 = 256*cycle
    PWMX_ACTOUT(CH_PWM4, 0, Low_Level, ENABLE);  // 25% 占空比
    PWMX_ACTOUT(CH_PWM5, 0, Low_Level, ENABLE);  // 25% 占空比
    PWMX_ACTOUT(CH_PWM7, 0, Low_Level, ENABLE);  // 25% 占空比
    // PWMX_ACTOUT
    R8_PWM_INT_CTRL |= RB_PWM_IE_CYC;

    while(1){
        // test();
        while(!(R8_PWM_INT_CTRL & RB_PWM_IF_CYC));
        R8_PWM_INT_CTRL |= RB_PWM_IF_CYC;//clear flag
        //set new data
        R8_PWM4_DATA = foc_ctrl.u;
        R8_PWM5_DATA = foc_ctrl.v;
        R8_PWM7_DATA = foc_ctrl.w;

        //calculate for next turn
        // foc_ctrl.i++;
        // printf("%d %d\r\n", (int)foc_ctrl.i, (int)foc_ctrl.u);
        foc_ctrl.n = foc_ctrl.i >> 7;
        foc_ctrl.u = get_fast_sin(foc_ctrl.n);
        foc_ctrl.v = get_fast_sin(foc_ctrl.n + 64);
        foc_ctrl.w = get_fast_sin(foc_ctrl.n + 128);

        //clear interrupt flag

    }
}

}
// extern"C"{
// __INTERRUPT
// __HIGH_CODE
// void TMR1_IRQHandler(void) 
// {
//     if(TMR1_GetITFlag(CAP_SYM))
//     {
//         PFIC_DisableIRQ(TMR1_IRQn);
//         TMR1_CapInit(CAP_NULL);
//         touchKey.scan();
//         TMR1_CapInit(FallEdge_To_FallEdge);
//         TMR1_ClearITFlag(CAP_SYM);    // 清除中断标志
//         PFIC_EnableIRQ(TMR1_IRQn);
//     }
// }

// __INTERRUPT
// __HIGH_CODE
// void PWMX_IRQHandler(void){
//     // printf("int\r\n");
//     while(!(R8_PWM_INT_CTRL & RB_PWM_IF_CYC));
//     //set new data
//     R8_PWM4_DATA = foc_ctrl.u;
//     R8_PWM5_DATA = foc_ctrl.v;
//     R8_PWM7_DATA = foc_ctrl.w;

//     //calculate for next turn
//     foc_ctrl.i++;
//     foc_ctrl.n = foc_ctrl.i >> foc_ctrl.t;
//     foc_ctrl.u = get_fast_sin(foc_ctrl.n);
//     foc_ctrl.v = get_fast_sin(foc_ctrl.n + 64);
//     foc_ctrl.w = get_fast_sin(foc_ctrl.n + 128);

//     //clear interrupt flag
//     R8_PWM_INT_CTRL |= RB_PWM_IF_CYC;//clear flag
// }
// __HIGH_CODE
// void process_pid(){
//     if(pw.v > 30.5) return;
//     if (touchKey.getNum())set = touchKey.getNum() * 0.1f;
//     pw.t -= pid.update(pw.a,set);
//     pwm.setPer(0.5 + 0.25*pw.t);
//     // const auto a = 12.34e5;

// }

// __INTERRUPT
// __HIGH_CODE
// void TMR0_IRQHandler(void) // TMR0 定时中断
// {
//     if(TMR0_GetITFlag(TMR0_3_IT_CYC_END))
//     {
//         TMR0_ClearITFlag(TMR0_3_IT_CYC_END); // 清除中断标志
//         process_pid();
//     }
// }

// __INTERRUPT
// __HIGH_CODE
// void TMR2_IRQHandler(void) // TMR0 定时中断
// {
//     if(TMR2_GetITFlag(TMR0_3_IT_CYC_END))
//     {
//         TMR2_ClearITFlag(TMR0_3_IT_CYC_END); // 清除中断标志
//         // process_ui();
//     }
// }
// // #include "CH58x_common.h"

// // void setup();
// // void loop();
// // void DebugInit();

// // uint8_t adcBuff[20] = {0};
// // int main(){
// //     SetSysClock(CLK_SOURCE_PLL_60MHz);
// //     DebugInit();
// //     setup();
// //     while(true){
// //         loop();
// //     }
// // }

// // void DebugInit(void)
// // {
// //     GPIOA_SetBits(GPIO_Pin_9);
// //     GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
// //     GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
// //     UART1_DefInit();
// // }


// // void setup(){
    
// //     /* TouchKey采样：选择adc通道 2 做采样，对应 PA12 */
// //     PRINT("\n5.TouchKey sampling...\n");
// //     GPIOA_ModeCfg(GPIO_Pin_12, GPIO_ModeIN_Floating);
// //     TouchKey_ChSampInit();
// //     ADC_ChannelCfg(2);

// // }

// // void loop(){
// //     for(uint8_t i = 0; i < 20; i++)
// //     {
// //         adcBuff[i] = TouchKey_ExcutSingleConver(0x10, 0); // 连续采样20次
// //     }
// //     for(uint8_t i = 0; i < 20; i++)
// //     {
// //         PRINT("%d,", adcBuff[i]);
// //     }
// //     printf("\r\n");
// //     DelayMs(400);

// // }

// /********************************** (C) COPYRIGHT *******************************
//  * File Name          : Main.c
//  * Author             : WCH
//  * Version            : V1.0
//  * Date               : 2021/03/09
//  * Description        : adc采样示例，包括温度检测、单通道检测、差分通道检测、TouchKey检测、中断方式采样。
//  * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
//  * SPDX-License-Identifier: Apache-2.0
//  *******************************************************************************/

// #include "CH58x_common.h"
// #include "CH58x_adc.h"

// uint16_t adcBuff[40];

// volatile uint8_t adclen;
// volatile uint8_t DMA_end = 0;

// /*********************************************************************
//  * @fn      DebugInit
//  *
//  * @brief   调试初始化
//  *
//  * @return  none
//  */
// void DebugInit(void)
// {
//     GPIOA_SetBits(GPIO_Pin_9);
//     GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
//     GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
//     UART1_DefInit();
// }

// /*********************************************************************
//  * @fn      main
//  *
//  * @brief   主函数
//  *
//  * @return  none
//  */
// int main()
// {
//     uint8_t      i;
//     signed short RoughCalib_Value = 0; // ADC粗调偏差值

//     SetSysClock(CLK_SOURCE_PLL_60MHz);

//     /* 配置串口调试 */
//     DebugInit();
//     PRINT("Start @ChipID=%02X\n", R8_CHIP_ID);
//     /* 温度采样并输出 */
//     PRINT("\n1.Temperature sampling...\n");
//     ADC_InterTSSampInit();
//     for(i = 0; i < 20; i++)
//     {
//         adcBuff[i] = ADC_ExcutSingleConver(); // 连续采样20次
//     }
//     for(i = 0; i < 20; i++)
//     {
//         PRINT("%d \n", adcBuff[i]);
//     }

//     /* 单通道采样：选择adc通道0做采样，对应 PA4引脚， 带数据校准功能 */
//     PRINT("\n2.Single channel sampling...\n");
//     GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_Floating);
//     ADC_ExtSingleChSampInit(SampleFreq_3_2, ADC_PGA_0);

//     RoughCalib_Value = ADC_DataCalib_Rough(); // 用于计算ADC内部偏差，记录到全局变量 RoughCalib_Value中
//     PRINT("RoughCalib_Value =%d \n", RoughCalib_Value);

//     ADC_ChannelCfg(0);

//     for(i = 0; i < 20; i++)
//     {
//         adcBuff[i] = ADC_ExcutSingleConver() + RoughCalib_Value; // 连续采样20次
//     }
//     for(i = 0; i < 20; i++)
//     {
//         PRINT("%d \n", adcBuff[i]); // 注意：由于ADC内部偏差的存在，当采样电压在所选增益范围极限附近的时候，可能会出现数据溢出的现象
//     }

//     /* DMA单通道采样：选择adc通道0做采样，对应 PA4引脚 */
//     PRINT("\n3.Single channel DMA sampling...\n");
//     GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_Floating);
//     ADC_ExtSingleChSampInit(SampleFreq_3_2, ADC_PGA_0);
//     ADC_ChannelCfg(0);
//     ADC_AutoConverCycle(192); // 采样周期为 (256-192)*16个系统时钟
//     ADC_DMACfg(ENABLE, (uint16_t)(uint32_t)&adcBuff[0], (uint16_t)(uint32_t)&adcBuff[40], ADC_Mode_Single);
//     PFIC_EnableIRQ(ADC_IRQn);
//     ADC_StartDMA();
//     while(!DMA_end);
//     DMA_end = 0;
//     ADC_DMACfg(DISABLE, 0, 0, ADC_Mode_Single);

//     for(i = 0; i < 40; i++)
//     {
//         PRINT("%d \n", adcBuff[i]);
//     }

//     /* 差分通道采样：选择adc通道0做采样，对应 PA4(AIN0)、PA12(AIN2) */
//     PRINT("\n4.Diff channel sampling...\n");
//     GPIOA_ModeCfg(GPIO_Pin_4 | GPIO_Pin_12, GPIO_ModeIN_Floating);
//     ADC_ExtDiffChSampInit(SampleFreq_3_2, ADC_PGA_0);
//     ADC_ChannelCfg(0);
//     for(i = 0; i < 20; i++)
//     {
//         adcBuff[i] = ADC_ExcutSingleConver(); // 连续采样20次
//     }
//     for(i = 0; i < 20; i++)
//     {
//         PRINT("%d \n", adcBuff[i]);
//     }

//     /* TouchKey采样：选择adc通道 2 做采样，对应 PA12 */
//     PRINT("\n5.TouchKey sampling...\n");
//     GPIOA_ModeCfg(GPIO_Pin_12, GPIO_ModeIN_Floating);
//     TouchKey_ChSampInit();
//     ADC_ChannelCfg(2);

//     for(i = 0; i < 20; i++)
//     {
//         adcBuff[i] = TouchKey_ExcutSingleConver(0x10, 0); // 连续采样20次
//     }
//     for(i = 0; i < 20; i++)
//     {
//         PRINT("%d \n", adcBuff[i]);
//     }

//     /* 单通道采样：中断方式,选择adc通道1做采样，对应 PA5引脚， 不带数据校准功能 */
//     PRINT("\n6.Single channel sampling in interrupt mode...\n");
//     GPIOA_ModeCfg(GPIO_Pin_5, GPIO_ModeIN_Floating);
//     ADC_ExtSingleChSampInit(SampleFreq_3_2, ADC_PGA_0);
//     ADC_ChannelCfg(1);
//     adclen = 0;
//     ADC_ClearITFlag();
//     PFIC_EnableIRQ(ADC_IRQn);

//     ADC_StartUp();
//     while(adclen < 20);
//     PFIC_DisableIRQ(ADC_IRQn);
//     for(i = 0; i < 20; i++)
//     {
//         PRINT("%d \n", adcBuff[i]);
//     }

//     while(1);
// }

// /*********************************************************************
//  * @fn      ADC_IRQHandler
//  *
//  * @brief   ADC中断函数
//  *
//  * @return  none
//  */
// __INTERRUPT
// __HIGH_CODE
// void ADC_IRQHandler(void) //adc中断服务程序
// {
//     if(ADC_GetDMAStatus())
//     {
//         ADC_StopDMA();
//         R16_ADC_DMA_BEG = ((uint32_t)adcBuff) & 0xffff;
//         ADC_ClearDMAFlag();
//         DMA_end = 1;
//     }
//     if(ADC_GetITStatus())
//     {
//         ADC_ClearITFlag();
//         if(adclen < 20)
//         {
//             adcBuff[adclen] = ADC_ReadConverValue();
//             ADC_StartUp(); // 作用清除中断标志并开启新一轮采样
//         }
//         adclen++;
//     }
// }
