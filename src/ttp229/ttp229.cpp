#include "ttp229.hpp"

TTP229::TTP229(){
    PWR_UnitModCfg(DISABLE, UNIT_SYS_LSE);
    GPIOA_ResetBits(SDO_PIN);
    GPIOA_ModeCfg(SDO_PIN, GPIO_ModeIN_PU);

    TMR1_CapInit(FallEdge_To_FallEdge);
    TMR1_CAPTimeoutCfg(0xFFFFFFFF);
    TMR1_ITCfg(ENABLE,CAP_SYM);
    PFIC_EnableIRQ(TMR1_IRQn);
    SCL_OUT;
    SDO_IN;
}

RAM_ATTR
void TTP229::scan(){
    uint16_t new_map = 0;
    CLR_SCL;

    for (int i = 0; i < 16; i++)
    {
        SET_SCL;
        CLR_SCL;
        new_map |= SDO_READ << i;
    }
    map = new_map;
    uint8_t new_num = 0;
    while(new_map != (1 << new_num)){
        new_num++;
        if(new_num >= 16){
            num = -1;
            return;
        }
    }
    num = new_num;
}
