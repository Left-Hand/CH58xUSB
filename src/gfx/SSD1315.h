#ifndef __SSD1315_H__
#define __SSD1315_H__

#include <stdint.h>
#include "nova.hpp"
#include "Frame.h"
#include "CH58x_common.h"
#include "core_riscv.h"
// #include <Arduino.h>


class SSD1315{
    private:
        Frame frame;
    public:

        void init();
        void turnOn();
        void turnOff();
        void turnColor(const bool & i);
        void turnDisplay(const bool & i);
        void clear();
        void flush();
        void verMirror(const bool & i);
        void hriMirror(const bool & i);

        Frame* fetchFrame(){return (&frame);}

        void setPos(uint8_t x,uint8_t y);
        void pushStream();
};


#endif