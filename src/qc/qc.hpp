#ifndef __QC_CTRL_HPP

#define __QC_CTRL_HPP

#include "nova.hpp"

class QC_controller{
    private:
        Pin D0,D1,D2,D3;
        bool isV3 = false;

        void DP_3V3(){
            D2.config(GPIO_ModeIN_PU);
            D3.config(GPIO_ModeIN_PU);
        }

        void DP_0V6(){
            D2.set();
            D3.reset();
            D2.config(GPIO_ModeOut_PP_5mA);
            D3.config(GPIO_ModeOut_PP_5mA);
        }

        void DP_0V0(){
            D2.config(GPIO_ModeIN_PD);
            D3.config(GPIO_ModeIN_PD);
        }

        void DP_NC(){
            D2.config(GPIO_ModeIN_Floating);
            D3.config(GPIO_ModeIN_Floating);
        }


        void DM_3V3(){
            D0.config(GPIO_ModeIN_PU);
            D1.config(GPIO_ModeIN_PU);
        }

        void DM_0V6(){
            D0.set();
            D1.reset();
            D0.config(GPIO_ModeOut_PP_5mA);
            D1.config(GPIO_ModeOut_PP_5mA);
        }

        void DM_0V0(){
            D0.config(GPIO_ModeIN_PD);
            D1.config(GPIO_ModeIN_PD);
        }

        void DM_NC(){
            D0.config(GPIO_ModeIN_Floating);
            D1.config(GPIO_ModeIN_Floating);
        }

    public:
        QC_controller(Pin _D0,Pin _D1,Pin _D2,Pin _D3):D0(_D0), D1(_D1), D2(_D2), D3(_D3){;}
        ~QC_controller(){};

        void startV2();
        void startV3();

        void switchVolt(uint8_t _volt);

        void forward();
        void backward();

        float volt = 5.0f;
};
#endif // !__QC_CTRL_HPP