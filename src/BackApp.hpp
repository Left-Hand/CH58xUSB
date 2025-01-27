#ifndef __BACKAPP_HPP__

#define __BACKAPP_HPP__

#include <nova.hpp>
#include <bits/std_function.h>
#include <ina226.h>
#include <SSD1315.h>


class BackApp{
    private:
        std::function<void(uint8_t)> inputEventFunc;

        Pin led = Pin(GPIOA, GPIO_Pin_13);
        Pin outEn = Pin(GPIOB, GPIO_Pin_16);
        Pin bz = Pin(GPIOA, GPIO_Pin_7);

        Pin key_conf = Pin(GPIOA, GPIO_Pin_10);
        Pin key_right = Pin(GPIOA, GPIO_Pin_11);
        Pin key_left = Pin(GPIOA, GPIO_Pin_12);

        INA226 ina;
        SSD1315 oled;

        enum class inputEvents{
            LEFT = 0,
            RIGHT,
            UP,
            BACK,
            CONF,

            UNREACH,
            REACH,

            INV,
            I_OVER,
            U_OVER,
            P_OVER,
            
        };

    public:

        BackApp(std::function<void(uint8_t)> _inputEventFunc);
        ~BackApp(){};

        void scanKeys();
        void scanVolt();
        void changeVolt();
        

};

#endif // !__BACKAPP_HPP__