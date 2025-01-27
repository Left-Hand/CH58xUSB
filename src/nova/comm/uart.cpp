// #include "UART.hpp"



//     void Serial::init(){
//         classify();
        
//         if(index == 1){
//             RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//         }else if(index <= 4){
//             RCC_APB1PeriphClockCmd(periph_c, ENABLE);
//         }else{
//             while(1);
//         }

//         USART_InitTypeDef USART_InitStructure = {
//                 .USART_BaudRate = baudRate,
//                 .USART_WordLength = wordLength,
//                 .USART_StopBits = stopBits,
//                 .USART_Parity = parity,
//                 .USART_Mode = mode,
//                 .USART_HardwareFlowControl = flowControl
//         };

//         USART_Init(base, &USART_InitStructure);
//         USART_Cmd(base, ENABLE);
//     }

//     void Serial::deinit(){
//         USART_Cmd(base, DISABLE);
//         USART_DeInit(base);
//         if(index == 1){
//             RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, DISABLE);
//         }else if(index <= 4){
//             RCC_APB1PeriphClockCmd(periph_c, DISABLE);
//         }else{
//             while(1);
//         }
//     }

//     void Serial::remapTo(uint8_t _remap){
//         remap = _remap;

//         switch(index){
//             case 1:
//                 if(remap > 1) while(1);
//                 GPIO_PinRemapConfig(GPIO_Remap_USART1, (remap)?ENABLE:DISABLE);
//                 break;
//             case 4:
//                 GPIO_PinRemapConfig(GPIO_PartialRemap_USART4, (remap & 0x01)?ENABLE:DISABLE);
//                 break;
//             default:
//                 while(1);
//         }
//     }


//     Pin Serial::getRxPin(){
//         switch(index){
//             case 1:
//                 if (remap) return Pin(GPIOB, GPIO_Pin_7);
//                 else return Pin(GPIOA, GPIO_Pin_10);
//             case 2:
//                 return Pin(GPIOA, GPIO_Pin_3);
//             case 3:
//                 return Pin(GPIOB, GPIO_Pin_11);
//             case 4:
//                 return Pin(GPIOB, (remap & 0x01)?GPIO_Pin_5 : GPIO_Pin_1);
//             default:
//                 while(1);
//                 return Pin((GPIO_TypeDef *)(0), 0);
//         }
//     }

//     Pin Serial::getTxPin(){
//         switch(index){
//             case 1:
//                 if (remap) Pin(GPIOB, GPIO_Pin_6);
//                 else return Pin(GPIOA, GPIO_Pin_9);
//             case 2:
//                 return Pin(GPIOA, GPIO_Pin_2);
//             case 3:
//                 return Pin(GPIOB, GPIO_Pin_10);
//             case 4:
//                 if (remap & 0x01) Pin(GPIOA, GPIO_Pin_5);
//                 else return Pin(GPIOB, GPIO_Pin_0);
//             default:
//                 while(1);

//         }
//         return Pin((GPIO_TypeDef *)(0), 0);
//     }

//     void Serial::classify(){
//         if((uint32_t)base == USART1_BASE){
//             index = 1;
//             periph_c = RCC_APB2Periph_USART1;
//         }else if((uint32_t)base >= USART2_BASE){
//             index = ((uint32_t)base - USART2_BASE) / (USART3_BASE - USART2_BASE) + 2;
//             periph_c = RCC_APB1Periph_USART2 << (index - 2);
//         }else{
//             while(1);
//         }
//     }

        
//     void Serial::config(uint32_t _baudRate,
//             uint16_t _wordLength,
//             uint16_t _mode,
//             uint16_t _stopBits,
//             uint16_t _parity,
//             uint16_t _flowControl){
    
//         baudRate = _baudRate;
//         wordLength = _wordLength;
//         mode = _mode;
//         stopBits = _stopBits;
//         parity = _parity;
//         flowControl = _flowControl;

//         init();
//     }

// 	void Serial::_write(uint8_t data){
// 		// while((base->STATR & (uint16_t)0x40) == RESET);
// 		// base->DATAR = (data & (uint16_t)0x01FF);
// 	}
