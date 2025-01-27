#include "Printable.hpp"

void Printable::write(uint8_t data){
    _write(data);
}

void Printable::write16(uint16_t data){
    _write((uint8_t)data);
    _write((uint8_t)(data >> 8));
}

void Printable::write16(uint16_t data, bool msb){
    if(msb){
        _write((uint8_t)(data >> 8));
        _write((uint8_t)data);
    }else{
        write16(data);
    }
}

void Printable::write32(uint32_t data){
    _write((uint8_t)data);
    _write((uint8_t)(data >> 8));
    _write((uint8_t)(data >> 16));
    _write((uint8_t)(data >> 24));
}

void Printable::write32(uint32_t data, bool msb){
    if (msb){
    _write((uint8_t)(data >> 24));
    _write((uint8_t)(data >> 16));
    _write((uint8_t)(data >> 8));
    _write((uint8_t)data);
    }else{
        write32(data);
    }
}

void Printable::itoa(int value, char *str, uint16_t radix){
    char list[] = "0123456789ABCDEF";
    uint16_t tmp_value;
    uint16_t i = 0, j, k = 0;
    if ('\0' == *str) {
        return;
    }
    if (2 != radix && 8 != radix && 10 != radix && 16 != radix) {
        return;
    }
    if (radix == 10 && value < 0) {
        //十进制且为负数
        tmp_value = (unsigned int)(0 - value);
        str[i++] = '-';
        k = 1;
    } else {
        tmp_value = (unsigned int)value;
    }
    //数据转换为字符串，逆序存储
    do {
        str[i ++] = list[tmp_value%radix];
        tmp_value /= radix;
    } while(tmp_value);
    str[i] = '\0';
    //将逆序字符串转换为正序
    char tmp;
    for (j = k; j < (i+k)/2; j++) {
        tmp = str[j];
        str[j] = str[i-j-1+k];
        str[i-j-1+k] = tmp;
    }
}


void Printable::ftoa(double value, char *str, uint16_t eps){
    uint16_t integer;
    double decimal;
    char list[] = "0123456789";
    uint16_t i = 0, j, k = 0;
    //将整数及小数部分提取出来
    if (value < 0) {
        decimal = (double)(((int)value) - value);
        integer = (unsigned int)(0 - value);
        str[i ++] = '-';
        k = 1;
    } else {
        integer = (unsigned int)(value);
        decimal = (double)(value - integer);
    }
//整数部分数据转换为字符串，逆序存储
    do {
        str[i ++] = list[integer%10];
        integer /= 10;
    }while(integer);
    str[i] = '\0';
    //将逆序字符串转换为正序
    char tmp;
    for (j = k; j < (i+k)/2; j++) {
        tmp = str[j];
        str[j] = str[i-j-1+k];
        str[i-j-1+k] = tmp;
    }
//处理小数部分
    if (eps < 1 || eps > 4) {
        eps = 4;
    }

//精度问题，防止输入1.2输出1.19等情况
    double pp = 0.1;
    for (j = 0; j <= eps; j++) {
        pp *= 0.1;
    }
    decimal += pp;
    while (eps) {
        decimal *= 10;
        eps --;
    }
    int tmp_decimal = (int)decimal;
    str[i ++] = '.';
    k = i;
//整数部分数据转换为字符串，逆序存储
    do {
        str[i ++] = list[tmp_decimal%10];
        tmp_decimal /= 10;
    } while(tmp_decimal);
    str[i] = '\0';
//将逆序字符串转换为正序
    for (j = k; j < (i+k)/2; j++) {
        tmp = str[j];
        str[j] = str[i-j-1+k];
        str[i-j-1+k] = tmp;
    }
    str[i] = '\0';
}


// void Printable::printf(char * Data, ...){

// }

void Printable::printf(const char Data[], ...){
    const char *s;
    int d;   
    char buf[64];
    uint8_t txdata;
    va_list ap;
    va_start(ap, Data);
    while ( * Data != 0 ) {				                          
        if ( * Data == 0x5c )  {									  
            switch ( *++Data ) {
                case 'r':							          
                    txdata = 0x0d;
                    _write(txdata);
                    Data ++;
                    break;
                case 'n':							          
                    txdata = 0x0a;
                    _write(txdata);
                    Data ++;
                    break;
                default:
                    Data ++;
                    break;
            }			 
        } else if ( * Data == '%') {									  
            switch ( *++Data ) {				
            case 's':										 
                s = va_arg(ap, const char *);
                for ( ; *s; s++) {
                    _write(*((uint8_t *)s));
                }				
                Data++;				
                break;
            case 'd':			
                d = va_arg(ap, int);					
                itoa(d, buf, 10);					
                for (s = buf; *s; s++) {
                    _write(*((uint8_t *)s));
                }					
                Data++;				
                break;
            case 'x': {
                d = va_arg(ap, int);					
                itoa(d, buf, 16);					
                for (s = buf; *s; s++) {
                    _write(*((uint8_t *)s));
                }					
                Data++;			
                break;
            }
            case 'f': {
                double num = va_arg(ap, double);					
                ftoa((double)num, buf, 4);
                for (s = buf; *s; s++) {
                    _write(*((uint8_t *)s));
                }					
                Data++;			
                break;
            }
            default:
                Data++;				
                break;				
            }		 
        } else {
            _write(*((uint8_t *)Data));
            Data++;
        }
    }
}

void Printable::print(const char* pStr){
    while(*pStr != '\0'){
        _write((uint8_t)*pStr);
        pStr++;
    }
}

void Printable::print(const char* pStr, uint8_t len){
    while((*(pStr++) != '\0') && (len-- > 0)){
        _write((uint8_t)*pStr);
    }
}

void Printable::println(const char* pStr){
    while(*pStr != '\0'){
        _write((uint8_t)*pStr);
        pStr++;
    }
    _write((uint8_t)'\r');
    _write((uint8_t)'\n');
}

void Printable::print(int val){
    char str[10];
    itoa(val, str, 10);
    print(str);
}

void Printable::print(int val, int radix){
    char str[10];
    itoa(val, str, radix);
    print(str);
}

void Printable::print(float val){
    char str[10];
    ftoa((double)val, str, 4);
    print(str);
}

void Printable::print(float val, int eps){
    char str[10];
    ftoa((double)val, str, eps);
    print(str);
}

void Printable::print(double val){
    char str[10];
    ftoa(val, str, 4);
    print(str);
}

void Printable::print(double val, int eps){
    char str[10];
    ftoa(val, str, eps);
    print(str);
}

Printable& Printable::operator<<(int val){
    print(val);
    return *this;
}

Printable& Printable::operator<<(float val){
    print(val);
    return *this;
}

Printable& Printable::operator<<(double val){
    print(val);
    return *this;
}

Printable& Printable::operator<<(const char* pStr){
    print(pStr);
    return *this;
}

Printable& Printable::operator<<(const char chr){
    _write(chr);
    return *this;
}

Printable& Printable::operator<<(const string str){
    print(str.c_str());
    return *this;
}