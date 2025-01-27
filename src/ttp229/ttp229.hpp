#ifndef __TTP229_HPP__
#define __TTP229_HPP__

#include <nova.hpp>

#define SCL_PIN GPIO_Pin_11
#define SDO_PIN GPIO_Pin_10

#define NDELAY __nop()

#define SET_SCL (R32_PA_OUT |= SCL_PIN)
#define CLR_SCL (R32_PA_CLR |= SCL_PIN)

#define SET_SDO (R32_PA_OUT |= SDO_PIN)
#define CLR_SDO (R32_PA_CLR |= SDO_PIN)
#define SDO_READ ((bool)(R32_PA_PIN & SDO_PIN))
#define SCL_OUT (GPIOA_ModeCfg(SCL_PIN, GPIO_ModeOut_PP_5mA))
#define SDO_IN (GPIOA_ModeCfg(SDO_PIN, GPIO_ModeIN_Floating))
#define SDO_OUT (GPIOA_ModeCfg(SDO_PIN, GPIO_ModeOut_PP_5mA))

#define CAP_SYM TMR0_3_IT_DATA_ACT

class TTP229{
    private:
        int8_t num = -1;
        uint16_t map = 0;
    public:
        TTP229();
        ~TTP229(){;}
        void scan();
        bool hasKey(){return (bool)(num >= 0);}

        int8_t getNum(){return num+1;}
        int8_t getONum(){return num;}
        uint16_t getMap(){return map;}
};

#endif