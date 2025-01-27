
#include "gpio.hpp"

void Pin::config(GPIOModeTypeDef _mode){
    if(gpiotype == GPIOA){
        GPIOA_ModeCfg(pin, _mode);
    }else if(gpiotype == GPIOB){
        GPIOB_ModeCfg(pin, _mode);
    }else FAULT;
}

void Pin::init(){
    if(gpiotype == GPIOA){
        out_reg = &R32_PA_OUT;
        clr_reg = &R32_PA_CLR;
        in_reg = &R32_PA_PIN;
    }else if(gpiotype == GPIOB){
        out_reg = &R32_PB_OUT;
        clr_reg = &R32_PB_CLR;
        in_reg = &R32_PB_PIN;
    }else FAULT;
}

void pinMode(Pin & _pin, GPIOModeTypeDef _mode){_pin.config(_mode);}
void digitalWrite(Pin & _pin, bool _state){_pin.write(_state);}
bool digitalRead(Pin & _pin){return _pin.read();}