#ifndef __PWM_HPP__

#define __PWM_HPP__

#include "nova.hpp"

#define Fsys 60000000
#define ust 60
#define mst 60000
#define PWM_PIN GPIO_Pin_22
class PWM{
    private:
        uint32_t arr = 80*ust;

    public:
        PWM();
        ~PWM(){};

        void setArr(const uint32_t & _arr);
        void setPsc(const uint32_t & _psc);
        void setPer(const float & _per);
};

#endif // !__PWM_HPP__
