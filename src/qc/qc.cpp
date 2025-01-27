#include "qc.hpp"

void QC_controller::startV2(){
    DM_NC();
    DP_0V6();
    yield(1260);
}

void QC_controller::startV3(){
    DM_NC();
    DP_0V6();
    DelayMs(1260);
    DM_3V3();
}

void QC_controller::switchVolt(uint8_t _volt){
    if (isV3){
        startV2();
        isV3 = false;
    }

    switch (_volt){
    case 5:
        DP_NC();
        DM_NC();
        volt = 5.0f;
        break;
    
    case 9:
        DP_3V3();
        DM_3V3();
        volt = 9.0f;
        break;
    
    case 12:
        DP_0V6();
        DM_3V3();
        volt = 12.0f;
        break;

    case 20:
        DP_3V3();
        DM_0V6();
        volt = 20.0f;
    
    default:
        break;
    }
}

void QC_controller::forward(){
    if(!isV3){
        startV3();
        isV3 = true;
        volt = 5.0f;
    }
    DP_0V6();
    DM_3V3();
    DelayMs(1);
    DP_3V3();
    DelayMs(1);
    DP_0V6();

    volt += 0.2f;
}

void QC_controller::backward(){
    if(!isV3){
        startV3();
        isV3 = true;
        volt = 5.0f;
    }
    DP_0V6();
    DM_3V3();
    DelayMs(1);
    DM_0V6();
    DelayMs(1);
    DM_3V3();

    volt -= 0.2;
}