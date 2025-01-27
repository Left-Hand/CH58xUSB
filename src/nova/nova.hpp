#ifndef  __NOVA_HPP__

#define __NOVA_HPP__

#include <CH58x_common.h>
#include <gpio.hpp>

#define FAULT while(1);
#define RAM_ATTR __HIGH_CODE
#define INTR_ATTR __INTERRUPT

#define yield(x) DelayMs(x)
#define getTick() SysTick->CNT;
#define delay(x) DelayMs(x)
#define delayMircos(x) DelayUs(x)

#endif // ! __NOVA_HPP__
