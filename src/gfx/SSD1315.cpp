#include "SSD1315.h"

#define ADR 0x78 

#define SCL_PIN GPIO_Pin_13
#define SDA_PIN GPIO_Pin_12

#define NDELAY __nop()
// #define NDELAY 

#define SET_SCL (R32_PB_OUT |= SCL_PIN)
#define CLR_SCL (R32_PB_CLR |= SCL_PIN)

#define SET_SDA (R32_PB_OUT |= SDA_PIN)
#define CLR_SDA (R32_PB_CLR |= SDA_PIN)
#define WRT_SDA(b) (b?SET_SDA:CLR_SDA);


static const uint8_t initCmds[] = { 
    0x0ae,        /* display off, sleep mode */
    0x0d5, 0x080,     /* clock divide ratio (0x00=1) and oscillator frequency (0x8) */
    0x0a8, 0x03f,     /* multiplex ratio */
    0x0d3, 0x000,     /* display offset */
    0x040,        /* start line */
    0x08d, 0x010,     /* charge pump setting (p62): 0x014 enable, 0x010 disable */
    0x0a1,        /* segment remap a0/a1*/
    0x0c8,        /* c0: scan dir normal, c8: reverse */
    0x0da, 0x012,     /* com pin HW config, sequential com pin config (bit 4), disable left/right remap (bit 5) */
    0x081, 0x09f,     /* set contrast control */
    0x0d9, 0x022,     /* pre-charge period */
    0x0db, 0x040,     /* vcomh deselect level */
    0x022, 0x000,     /* page addressing mode WRONG: 3 byte cmd! */
    0x0a4,        /* output ram to display */
    0x0a6,        /* none inverted normal display mode */
    0x0af,        /* display on */
};


RAM_ATTR
void OLEDclk(){
    SET_SCL;
    CLR_SCL;
}

RAM_ATTR
void OLEDstart(){
    SET_SDA;
    SET_SCL;
    CLR_SDA;
    CLR_SCL;
}

RAM_ATTR
void OLEDend(){
    CLR_SDA;
    SET_SCL;
    SET_SDA;
}

RAM_ATTR
void OLEDack(){
    CLR_SDA;
    SET_SCL;
    CLR_SCL;
    SET_SDA;
    CLR_SDA;
}

RAM_ATTR
void OLEDwaitAck(void){
	SET_SDA;
	SET_SCL;
    CLR_SCL;
}

RAM_ATTR
void OLEDbreak(){
    CLR_SDA;
    CLR_SCL;
    SET_SCL;
    SET_SDA;
    CLR_SDA;
    CLR_SCL;
}


RAM_ATTR
void OLEDbyte (const uint8_t & b){
    if(b == 0){
        WRT_SDA(0);
        
        SET_SCL;
        CLR_SCL;
        SET_SCL;
        CLR_SCL;
        SET_SCL;
        CLR_SCL;
        SET_SCL;
        CLR_SCL;

        SET_SCL;
        CLR_SCL;
        SET_SCL;
        CLR_SCL;
        SET_SCL;
        CLR_SCL;
        SET_SCL;
        CLR_SCL;
        return;
    }
    WRT_SDA(0x80&b);
    SET_SCL;
    CLR_SCL;
    WRT_SDA(0x40&b);
    SET_SCL;
    CLR_SCL;
    WRT_SDA(0x20&b);
    SET_SCL;
    CLR_SCL;
    WRT_SDA(0x10&b);
    SET_SCL;
    CLR_SCL;
    WRT_SDA(0x08&b);
    SET_SCL;
    CLR_SCL;
    WRT_SDA(0x04&b);
    SET_SCL;
    CLR_SCL;
    WRT_SDA(0x02&b);
    SET_SCL;
    CLR_SCL;
    WRT_SDA(0x01&b);
    SET_SCL;
    CLR_SCL;

}

RAM_ATTR
void OLEDcmd(const uint8_t & cmd){
    OLEDstart();
    OLEDbyte(0x78);
    OLEDwaitAck();
    OLEDbyte(0x00);
    OLEDwaitAck();
    OLEDbyte(cmd); // sends one byte
    OLEDack();
    OLEDend();
}

RAM_ATTR
void  OLEDdata (const uint8_t & data){
    OLEDstart();
    OLEDbyte(0x78);
    OLEDwaitAck();
    OLEDbyte(0x40);
    OLEDwaitAck();
    OLEDbyte(data); // sends one byte
    OLEDwaitAck();
    OLEDend();
}

RAM_ATTR
void OLEDwrite(const uint8_t & data){
    OLEDstart();
    OLEDbyte(data); // sends one byte
    OLEDwaitAck();
    OLEDend();  
}
void SSD1315::init(){

    GPIOB_ModeCfg(SCL_PIN, GPIO_ModeOut_PP_5mA);
    GPIOB_ModeCfg(SDA_PIN, GPIO_ModeOut_PP_5mA);


    for(uint8_t cmd:initCmds){
        OLEDcmd(cmd);
    }
    // clear();
    // turnOn();
    // turnColor(true);
    // turnDisplay(false);
}


// void SSD1315::clear(){
//   uint8_t i,n;       
//   for(i=0xb0;i<0xb5;i++)  
//   {  
//     OLEDcmd(i);
//     OLEDcmd(0x0c);
//     OLEDcmd(0x11);    
//     for(n=0;n<72;n++) OLEDdata(0); 
//   }
// }


void SSD1315::turnOn(){
  OLEDcmd(0X8D);  //SET DCDC命令
  OLEDcmd(0X14);  //DCDC ON
  OLEDcmd(0XAF);  //DISPLAY ON
}


void SSD1315::turnOff(){
  OLEDcmd(0X8D);  //SET DCDC命令
  OLEDcmd(0X10);  //DCDC OFF
  OLEDcmd(0XAE);  //DISPLAY OFF
}    


void SSD1315::setPos(uint8_t x,uint8_t y){
  x+=2;
  OLEDcmd(0xb0 | y);
  OLEDcmd(((x&0xf0)>>4)|0x10);
  OLEDcmd((x&0x0f));
}


void SSD1315::flush()
{
    for(uint8_t m=0;m<8;m++)
    {
        OLEDcmd(0xb0+m);
        OLEDcmd(0x00);
        OLEDcmd(0x10);
        
        for(uint8_t n=0;n<128;n++)
        {
                OLEDdata(0xff);
        }
    }
}

void SSD1315::turnColor(const bool & i){
    OLEDcmd(0xA7 - i);
}

void SSD1315::hriMirror(const bool & i){
    OLEDcmd(0xC0 | (i << 3));
}

void SSD1315::verMirror(const bool & i){
    OLEDcmd(0xA0 | i);
}
void SSD1315::clear(){    
	for(uint8_t i=0;i<4;i++)  
	{  
		OLEDcmd (0xb0+i);    //设置页地址（0~7）
		OLEDcmd (0x00);      //设置显示位置—列低地址
		OLEDcmd (0x10);      //设置显示位置—列高地址   
		for(uint8_t n=0;n<128;n++) OLEDdata(0); 
	} //更新显示
}

void SSD1315::turnDisplay(const bool & i){
    OLEDcmd(0xC8 - 8*i);//正常显示
    OLEDcmd(0xA1 - i);
}

RAM_ATTR
void OLEDpoll(uint8_t * pdata, const uint8_t & dur, const uint8_t & size){
    OLEDstart();
    OLEDbyte(0x78);
    OLEDwaitAck();
    OLEDbyte(0x40);
    OLEDwaitAck();
    for(uint8_t i =0; i<size; i++){
        OLEDbyte(*pdata);
        OLEDwaitAck();
        pdata += dur;
    }
    OLEDend();
}
void SSD1315::pushStream(){

    Frame* fp = fetchFrame();

    for(uint8_t i = 0; i < 8;i++){
        setPos(0, i);
        OLEDpoll((uint8_t * )(&((*fp).buf[0][0]))+i, 8, 128);  
    }
    // setPos(0, 0);

    // OLEDpoll((uint8_t * )(&((*fp).buf[0][0])), 8, 128);

    // setPos(0, 1);
    // for(uint8_t m = 0; m < 128;m++){
    //     OLEDdata((((*fp).buf[m][0] >> 8) & 0xff));
    // }

    // setPos(0, 2);
    // for(uint8_t m = 0; m < 128;m++){
    //     OLEDdata((((*fp).buf[m][0] >> 16) & 0xff));
    // }

    // setPos(0, 3);
    // for(uint8_t m = 0; m < 128;m++){
    //     OLEDdata((((*fp).buf[m][0] >> 24)));
    // }

    // setPos(0, 4);
    // for(uint8_t m = 0; m < 128;m++){
    //     OLEDdata((((*fp).buf[m][1]) & 0xff));
    // }

    // setPos(0, 5);
    // for(uint8_t m = 0; m < 128;m++){
    //     OLEDdata((((*fp).buf[m][1] >> 8) & 0xff));
    // }

    // setPos(0, 6);
    // for(uint8_t m = 0; m < 128;m++){
    //     OLEDdata((((*fp).buf[m][1] >> 16) & 0xff));
    // }

    // setPos(0, 7);
    // for(uint8_t m = 0; m < 128;m++){
    //     OLEDdata((((*fp).buf[m][1] >> 24)));
    // }

}
