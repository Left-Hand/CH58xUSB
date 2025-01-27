#include "Frame.h"
#include "oledfont.h"
// #define 
// #include <Arduino.h>


void Frame::clear(){
    for(uint8_t i = 0; i<128; i++){
        buf[i][0] = 0;
        buf[i][1]=0;
    }
}

void Frame::clearRow(const uint8_t & row){
    uint32_t mask = 0xffffff00 << 8*(row & 0b11);
    mask |= 0x00ffffff >> (24 - 8*(row & 0b11));
    for(uint8_t i = 0; i<128; i++){
        buf[i][0] &= mask;
    }
}

void Frame::drawLine(const Vector2i & start, const Vector2i & end){

    if(start.x == end.x) drawHriline(start, end.x - start.x);
    else if (start.y == end.y) drawVerline(start, end.y - start.y);
    
    uint8_t x0 = start.x;
    uint8_t x1 = end.x;
    uint8_t y0 = start.y;
    uint8_t y1 = end.y;

    int dx=abs(x1-x0), sx=(x1 > x0)? 1: -1;
    int dy=abs(y1-y0), sy=(y1 > y0)?  1 : -1;

    int err=(dx>dy ? dx : -dy)/2, e2;
    for (;;) {
        drawPixel(x0, y0);
        if (x0==x1 && y0==y1) 
        break;
        e2=err;
        if (e2>-dx) { 
        err-=dy; 
        x0+=sx; 
        }
        if (e2<dy) { 
        err+=dx; 
        y0+=sy; 
        }
    }
}


void Frame::drawHriline(const Vector2i & pos, const uint8_t & length){
	uint8_t x = (uint8_t)pos.x;
	uint32_t mask = 1 << (pos.y & 0x1f);
    uint8_t end = min(x + length, 127);
	for(uint8_t i = max(x,(uint8_t)0); i < end; i++){
		buf[i][0] |= mask;
	}
}


void Frame::drawVerline(const Vector2i & pos, const uint8_t & length){
	if (!length) return;  
	uint8_t start = (uint8_t)pos.y;
	uint8_t end = (uint8_t)(pos.y + length);
    if (length < 0){
        uint8_t temp = end;
        end = start;
        start = temp;
    }
	buf[pos.x][0] |= ((0xffffffff << start) & (0xffffffff >> (32-end)));

}


void Frame::drawRect(const Vector2i & pos, const Vector2i & size){
	drawVerline(pos, size.y);
	drawVerline(Vector2i(pos.x + size.x, pos.y), size.y);
	drawHriline(pos, size.x);
	drawHriline(Vector2i(pos.x, pos.y + size.y), size.x + 1);
}


void Frame::drawFilledRect(const Vector2i & pos, const Vector2i & size){
	for(uint8_t i = pos.x; i < pos.x + size.x; i++){
		drawHriline(Vector2i(i, pos.y), size.y);
	}
}


void Frame::drawCharRow(const Vector2i & pos,const char & chr){
	uint8_t x = (uint8_t)pos.x;
	uint8_t r = (uint8_t)pos.y;
	for(uint8_t i = 0; i<6; i++)
	{
		drawByteRow(x + i, r, en[max(chr - 0x20, 0)][i]);
	}
}


void Frame::drawStringRow(Vector2i pos, const string & str)
{
	uint8_t len = str.length();
	const char *chr = str.c_str();
	for(uint8_t i = 0; i < len; i++){
		drawCharRow(pos, *chr);
		pos = pos + Vector2i(7,0);
		chr++;
	}
}


void Frame::drawChar(const Vector2i & pos,const char & chr){
	uint8_t x = (uint8_t)pos.x;
	uint8_t r = (uint8_t)pos.y;
	for(uint8_t i = 0; i<6; i++)
	{
		drawByte(x + i, r, en[max(chr - 0x20, 0)][i]);
	}
}


void Frame::drawString(Vector2i pos, const string & str)
{
	uint8_t len = str.length();
	const char *chr = str.c_str();
	for(uint8_t i = 0; i < len; i++){
		drawChar(pos, *chr);
		pos = pos + Vector2i(8,0);
		chr++;
	}
}


void Frame::drawString(Vector2i pos, const char * _strp){
    char * chr = (char *)_strp;
	for(;*chr;){
		drawChar(pos, (*chr));
		pos = pos + Vector2i(8,0);
		chr++;
	}
}