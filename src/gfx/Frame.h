#ifndef __FRAME_H__
#define __FRAME_H__

#include <stdint.h>
#include "Vector2i.hpp"
#include <string>

using std::string;

class Frame{
    private:
        void drawByte(const Vector2i & pos, uint8_t cont);
        void drawByte(const int8_t & x, const int8_t & y, uint8_t cont); 

                
        void drawByteRow(const Vector2i & pos, uint8_t cont);
        void drawByteRow(const int8_t & x, const int8_t & y, uint8_t cont);

    public:
        uint32_t buf[128][2] __attribute__ ((aligned (4)));

        Frame(){;}
        ~Frame(){;}

     
        void clear();
        void clearRow(const uint8_t & row);

        void drawPixel(const Vector2i & pos);
        void drawPixel(const uint8_t & x, const uint8_t & y);
        void drawVerline(const Vector2i & start, const uint8_t & length);
        void drawHriline(const Vector2i & start, const uint8_t & length);

        void drawLine(const Vector2i & start, const Vector2i & end);
        void drawFragLine(const Vector2i & start, const Vector2i & end, const Vector2i & duty);
        
        void drawCircle(const Vector2i & center, const uint8_t rad);
        void drawFilledCircle(const Vector2i & center, const uint8_t rad);

        void drawRect(const Vector2i & start, const Vector2i & end);
        void drawFilledRect(const Vector2i & start, const Vector2i & end);

        void drawTriangle(const Vector2i & a, const Vector2i & b, const Vector2i & c);
        void drawFilledTriangle(const Vector2i & a, const Vector2i & b, const Vector2i & c);

        void drawCharRow(const Vector2i & pos, const char & chr);
        void drawStringRow(Vector2i pos, const string & str);

        void drawChar(const Vector2i & pos, const char & chr);
        void drawString(Vector2i pos, const string & str);
        void drawString(Vector2i pos, const char * _strp);

};

inline void Frame::drawPixel(const uint8_t & x, const uint8_t & y){
    if (x < 0 || x > 127 || y < 0 || y > 63) return;
    if (y < 32)
        buf[x][0] |= 1 << y;
    else
        buf[x][1] |= 1 << (y-32);
}

inline void Frame::drawPixel(const Vector2i & pos){
    drawPixel(pos.x, pos.y);
}

inline void Frame::drawByte(const int8_t & x, const int8_t & y, uint8_t cont){
    if (x < 0 || x > 127) return;
    if(y%8){
        if (y < 0){ // over 
            if (y < -8) return;
            buf[x][0] |= cont >> (-y);
        }else if (y > 64 + 8 - 1){ //below
            return;
        }else{
            if (y < 24)
                buf[x][0] |= cont << y;
            else if(y < 32){
                buf[x][0] |= cont << y;
                buf[x][1] |= cont >> (8-(y-24));
            }
            else
                buf[x][1] |= cont << (y-32);
            
        }
    }
    else drawByteRow(x, y / 8, cont);
}


inline void Frame::drawByte(const Vector2i & pos, uint8_t cont){
    drawByte(pos.x, pos.y, cont);
}

inline void Frame::drawByteRow(const int8_t & x, const int8_t & r, uint8_t cont){
	// uint32_t mask = (0x00ffffff >> (24-8*(r & 0b11)));
	// mask |= (0xffffff00 << 8*(r & 0b11));
    if (x < 0 || x > 127) return;
    if (r < 0 || r > 7) return;
	uint32_t temp = cont << ((r & 0x03) << 3);
	buf[x][r >> 2] |= temp;
};


inline void Frame::drawByteRow(const Vector2i & pos, uint8_t cont){
    drawByteRow(pos.x, pos.y, cont);
};


#endif