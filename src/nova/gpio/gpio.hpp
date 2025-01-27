#ifndef __GPIO_HPP__

#define __GPIO_HPP__

#include <CH58x_common.h>
#include <nova.hpp>

enum GPIOType:uint8_t{
    GPIOA = 0,
    GPIOB
};

class Pin{
    protected:
        PUINT32V out_reg = &R32_PA_OUT;
        PUINT32V clr_reg = &R32_PA_CLR;
        PUINT32V in_reg = &R32_PA_PIN;

        GPIOType gpiotype = GPIOA;
        GPIOModeTypeDef mode = GPIO_ModeIN_Floating;
        uint32_t pin = GPIO_Pin_13;

        void init();

    public:
        Pin(GPIOType _gpiotype, uint32_t _pin):gpiotype(_gpiotype),pin(_pin){init();}
        Pin() = delete;
        ~Pin(){};
        void config(GPIOModeTypeDef _mode = GPIO_ModeIN_Floating);

        void set(){*out_reg |= pin;}
        void reset(){*clr_reg |= pin;}
        void write (bool _val){(_val) ? *out_reg |= pin : *clr_reg |= pin;}
        bool read() const{return (bool)(*in_reg & pin);}

        Pin & operator = (const bool _val){(_val) ? *out_reg |= pin : *clr_reg |= pin; return *this;}
        operator bool(){return (bool)(*in_reg & pin);}

};

void pinMode(Pin & _pin, GPIOModeTypeDef _mode);
void digitalWrite(Pin & _pin, bool _state);
bool digitalRead(Pin & _pin);

#endif // !__IO__