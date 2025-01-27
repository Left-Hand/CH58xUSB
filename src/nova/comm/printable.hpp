
#ifndef __PRINTABLE_HPP__
#define __PRINTABLE_HPP__

#include <stdarg.h>
#include <string>
#define endl "\r\n"

using std::string;

class Printable{
    protected:
        virtual void _write(uint8_t data) = 0;
        virtual uint8_t _transmit(uint8_t data) = 0;

    private:
        void itoa(int value, char *str, uint16_t radix);
        void ftoa(double value, char *str, uint16_t eps);

    public:

        Printable(){};
        ~Printable(){};
        void write(uint8_t data);
        void write16(uint16_t data);
        void write16(uint16_t data, bool msb);
        void write32(uint32_t data);
        void write32(uint32_t data, bool msb);

        // void printf(char * Data, ...);
        void printf(const char Data[], ...);

        void print(const char* pStr);
        void print(const char* pStr, uint8_t len);
        void print(string str){print(str.c_str());}
        void println(const char* pStr);
        void println(string str){println(str.c_str());}

        void print(int val);
        void print(int val, int radix);
        void print(float val);
        void print(float val, int eps);
        void print(double val);
        void print(double val, int eps);


        Printable& operator<<(int val);
        Printable& operator<<(float val);
        Printable& operator<<(double val);

        Printable& operator<<(const char* pStr);
        Printable& operator<<(const char chr);

        Printable& operator<<(const string str);
};
    
#endif // !__PRINTABLE_HPP__