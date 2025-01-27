#include <BackApp.hpp>

BackApp::BackApp(std::function<void(uint8_t)> _inputEventFunc){
    inputEventFunc = _inputEventFunc;
        // config UART
    GPIOA_SetBits( GPIO_Pin_9 );
    GPIOA_ModeCfg( GPIO_Pin_8, GPIO_ModeIN_PU );
    GPIOA_ModeCfg( GPIO_Pin_9, GPIO_ModeOut_PP_5mA );
    UART1_DefInit();

    //config outen
    outEn.set();
    outEn.config(GPIO_ModeOut_PP_5mA);    

    //config bz
    bz.reset();
    bz.config(GPIO_ModeOut_PP_5mA);

    //config keys
    PWR_UnitModCfg(DISABLE, UNIT_SYS_LSE);

    key_left.reset();
    key_conf.reset();
    key_right.reset();

    key_left.config(GPIO_ModeIN_PU);
    key_conf.config(GPIO_ModeIN_PU);
    key_right.config(GPIO_ModeIN_PU);

    INA226_Init(&ina, 0x80, 0.007f,3.2f);
    ina.mI2C_Address = 0x80;

    oled.init();

}
