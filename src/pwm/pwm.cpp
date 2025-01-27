#include "pwm.hpp"
#define RAM_ATTR __HIGH_CODE
#define INTR_ATTR __INTERRUPT

PWM::PWM(){
    GPIOB_ResetBits(PWM_PIN); // 配置PWM口 PB22
    GPIOB_ModeCfg(PWM_PIN, GPIO_ModeOut_PP_5mA);

    TMR3_PWMInit(High_Level, PWM_Times_1);
    TMR3_PWMCycleCfg(arr); // 周期 100us
    TMR3_Disable();
    TMR3_PWMActDataWidth(arr >> 1); // 占空比 50%, 修改占空比必须暂时关闭定时器
    TMR3_Enable();
}

RAM_ATTR
void PWM::setArr(const uint32_t & _arr){
    arr = _arr;
    TMR3_PWMCycleCfg(_arr); // 周期 100us
}

RAM_ATTR
void PWM::setPsc(const uint32_t & _psc){
    TMR3_Disable();
    TMR3_PWMActDataWidth(_psc);
    TMR3_Enable();
}

RAM_ATTR
void PWM::setPer(const float & _per){
    setPsc(arr * _per);
}