// /*
//  * @Author: error: git config user.name && git config user.email & please set dead value or install git
//  * @Date: 2023-01-12 19:21:51
//  * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
//  * @LastEditTime: 2023-01-14 20:42:22
//  * @FilePath: \az\src\hardware_specific\UART.hpp
//  * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
//  */
// #ifndef __UART_H__

// #define __UART_H__

// #include "ch32v20x_usart.h"
// #include "ch32v20x_it.h"
// #include "ch32v20x_rcc.h"
// #include "misc/Printable.hpp" 
// #include <hardware/gpio.hpp>



//     class Serial: public Printable{
//         private:
//             USART_TypeDef* base = USART1;
//             uint32_t periph_c = 0;

//             uint32_t baudRate = (uint32_t)115200;
//             uint16_t wordLength = USART_WordLength_8b;
//             uint16_t stopBits = USART_StopBits_1;
//             uint16_t parity = USART_Parity_No;
//             uint16_t flowControl = USART_HardwareFlowControl_None;
//             uint16_t mode = USART_Mode_Tx | USART_Mode_Rx;

//             uint8_t index = 0;
//             uint8_t remap = 0;
            
//             bool remapped = false;
//             bool particle = false;

//             void _write(uint8_t data) override;

//             void classify();

//             void init();
//             void deinit();

//         public:
//             Serial(USART_TypeDef* _base):base(_base){};
            
//             void config(uint32_t _baudRate,
//                     uint16_t _wordLength = USART_WordLength_8b,
//                     uint16_t _mode = USART_Mode_Tx | USART_Mode_Rx,
//                     uint16_t _stopBits = USART_StopBits_1,
//                     uint16_t _parity = USART_Parity_No,
//                     uint16_t _flowControl = USART_HardwareFlowControl_None);


//             ~Serial(){deinit();}

//             void remapTo(uint8_t _remap);

//             void configBaud(uint32_t _baudRate){baudRate = _baudRate;init();}
//             void configMode(uint16_t _mode){mode = _mode;init();}

//             Pin getRxPin();
//             Pin getTxPin();

//             void settleRxPin(){getRxPin().config(GPIO_Mode_AF_PP);}
//             void settleTxPin(){getTxPin().config(GPIO_Mode_AF_PP);}
//     };


// #endif // !__UART_H__