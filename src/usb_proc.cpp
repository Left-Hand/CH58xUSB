#include "usb_proc.hpp"

UsbProcesser usb_processer{1};



/* USBȫ��ģʽ,�����ٶ����������� */
static uint8_t USB_FS_OSC_DESC[sizeof(MyCfgDescr)] = {
    0x09, 0x07, /* ��������ͨ�������� */
};


/*********************************************************************
 * @fn      DevEP1_OUT_Deal
 *
 * @brief   �˵�1���ݴ���
 *
 * @return  none
 */
void DevEP1_OUT_Deal(uint8_t l)
{ /* �û����Զ��� */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP1_IN_DataBuf[i] = ~pEP1_OUT_DataBuf[i];
    }
    DevEP1_IN_Deal(l);
}

/*********************************************************************
 * @fn      DevEP2_OUT_Deal
 *
 * @brief   �˵�2���ݴ���
 *
 * @return  none
 */
void DevEP2_OUT_Deal(uint8_t l)
{ /* �û����Զ��� */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP2_IN_DataBuf[i] = ~pEP2_OUT_DataBuf[i];
    }
    DevEP2_IN_Deal(l);
}

/*********************************************************************
 * @fn      DevEP3_OUT_Deal
 *
 * @brief   �˵�3���ݴ���
 *
 * @return  none
 */
void DevEP3_OUT_Deal(uint8_t l)
{ /* �û����Զ��� */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP3_IN_DataBuf[i] = ~pEP3_OUT_DataBuf[i];
    }
    DevEP3_IN_Deal(l);
}

/*********************************************************************
 * @fn      DevEP4_OUT_Deal
 *
 * @brief   �˵�4���ݴ���
 *
 * @return  none
 */
void DevEP4_OUT_Deal(uint8_t l)
{ /* �û����Զ��� */
    uint8_t i;

    for(i = 0; i < l; i++)
    {
        pEP4_IN_DataBuf[i] = ~pEP4_OUT_DataBuf[i];
    }
    DevEP4_IN_Deal(l);
}


void UsbProcesser::handleSetup(){
    R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_NAK;
    SetupReqLen = pSetupReqPak->wLength;
    SetupReqCode = pSetupReqPak->bRequest;
    chtype = pSetupReqPak->bRequestType;

    len = 0;
    errflag = 0;
    if((pSetupReqPak->bRequestType & USB_REQ_TYP_MASK) != USB_REQ_TYP_STANDARD)
    {
        /* �Ǳ�׼���� */
        /* ��������,�������󣬲�������� */
        if(pSetupReqPak->bRequestType & 0x40){
            /* �������� */
        }else if(pSetupReqPak->bRequestType & 0x20){
            switch(SetupReqCode){
                case DEF_USB_SET_IDLE: /* 0x0A: SET_IDLE */
                    Idle_Value = endpoints_[0].data()[3];
                    break; //���һ��Ҫ��

                case DEF_USB_SET_REPORT: /* 0x09: SET_REPORT */
                    break;

                case DEF_USB_SET_PROTOCOL: /* 0x0B: SET_PROTOCOL */
                    Report_Value = endpoints_[0].data()[2];
                    break;

                case DEF_USB_GET_IDLE: /* 0x02: GET_IDLE */
                    endpoints_[0].data()[0] = Idle_Value;
                    len = 1;
                    break;

                case DEF_USB_GET_PROTOCOL: /* 0x03: GET_PROTOCOL */
                    endpoints_[0].data()[0] = Report_Value;
                    len = 1;
                    break;

                default:
                    errflag = 0xFF;
            }
        }
    }else{ /* ��׼���� */
        handleStdRequest();
    }
    if(errflag == 0xff){ // �����֧��
        //                  SetupReqCode = 0xFF;
        R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_STALL | UEP_T_RES_STALL; // STALL
    }else{
        if(chtype & 0x80){ // �ϴ�
            len = (SetupReqLen > DevEP0SIZE) ? DevEP0SIZE : SetupReqLen;
            SetupReqLen -= len;
        }else{
            len = 0; // �´�
        }
        R8_UEP0_T_LEN = len;
        R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_ACK; // Ĭ�����ݰ���DATA1
    }

}


void UsbProcesser::handleStdRequest(){
    switch(SetupReqCode){
        case USB_GET_DESCRIPTOR:
            handleGetDescriptor();
            break;

        case USB_SET_ADDRESS:
            SetupReqLen = (pSetupReqPak->wValue) & 0xff;
            break;

        case USB_GET_CONFIGURATION:
            pEP0_DataBuf[0] = DevConfig;
            if(SetupReqLen > 1)
                SetupReqLen = 1;
            break;

        case USB_SET_CONFIGURATION:
            DevConfig = (pSetupReqPak->wValue) & 0xff;
            break;

        case USB_CLEAR_FEATURE:
            handleClrFeature();
            break;
        case USB_SET_FEATURE:
            handleSetFeature();
            break;

        case USB_GET_INTERFACE:
            pEP0_DataBuf[0] = 0x00;
            if(SetupReqLen > 1)
                SetupReqLen = 1;
            break;

        case USB_SET_INTERFACE:
            break;

        case USB_GET_STATUS:
            handleGetStatus();
            break;

        default:
            errflag = 0xff;
            break;
    }
}


void UsbProcesser::handleClrFeature(){
    if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP){
        switch((pSetupReqPak->wIndex) & 0xff){
            case 0x83:
                R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_NAK;
                break;
            case 0x03:
                R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_ACK;
                break;
            case 0x82:
                R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_NAK;
                break;
            case 0x02:
                R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_ACK;
                break;
            case 0x81:
                R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_NAK;
                break;
            case 0x01:
                R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_ACK;
                break;
            default:
                errflag = 0xFF; // ��֧�ֵĶ˵�
                break;
        }
    }else if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_DEVICE){
        if(pSetupReqPak->wValue == 1){
            USB_SleepStatus &= ~0x01;
        }
    }else{
        errflag = 0xFF;
    }
}

void UsbProcesser::handleSetFeature(){
    if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP){
        switch(pSetupReqPak->wIndex){
            case 0x83:
                R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_STALL;
                break;
            case 0x03:
                R8_UEP3_CTRL = (R8_UEP3_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_STALL;
                break;
            case 0x82:
                R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_STALL;
                break;
            case 0x02:
                R8_UEP2_CTRL = (R8_UEP2_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_STALL;
                break;
            case 0x81:
                R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_T_TOG | MASK_UEP_T_RES)) | UEP_T_RES_STALL;
                break;
            case 0x01:
                R8_UEP1_CTRL = (R8_UEP1_CTRL & ~(RB_UEP_R_TOG | MASK_UEP_R_RES)) | UEP_R_RES_STALL;
                break;
            default:
                /* ��֧�ֵĶ˵� */
                errflag = 0xFF; // ��֧�ֵĶ˵�
                break;
        }
    }else if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_DEVICE){
        if(pSetupReqPak->wValue == 1){
            /* ����˯�� */
            USB_SleepStatus |= 0x01;
        }
    }else{
        errflag = 0xFF;
    }
}

void UsbProcesser::handleGetStatus(){
    if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP){
        /* �˵� */
        pEP0_DataBuf[0] = 0x00;
        switch(pSetupReqPak->wIndex)
        {
            case 0x83:
                if((R8_UEP3_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL)
                {
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x03:
                if((R8_UEP3_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL)
                {
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x82:
                if((R8_UEP2_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL)
                {
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x02:
                if((R8_UEP2_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL)
                {
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x81:
                if((R8_UEP1_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL)
                {
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x01:
                if((R8_UEP1_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL)
                {
                    pEP0_DataBuf[0] = 0x01;
                }
                break;
        }
    }
    else if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_DEVICE){
        pEP0_DataBuf[0] = 0x00;
        if(USB_SleepStatus){
            pEP0_DataBuf[0] = 0x02;
        }else{
            pEP0_DataBuf[0] = 0x00;
        }
    }
    pEP0_DataBuf[1] = 0;
    if(SetupReqLen >= 2){
        SetupReqLen = 2;
    }

}


void UsbProcesser::handleGetDescriptor(){
    switch(((pSetupReqPak->wValue) >> 8)){
        case USB_DESCR_TYP_DEVICE:{
            pDescr = MyDevDescr.data();
            len = MyDevDescr.size();
        }
        break;

        case USB_DESCR_TYP_CONFIG:{
            pDescr = MyCfgDescr;
            len = MyCfgDescr[2];
        }
        break;

        case USB_DESCR_TYP_HID:
            switch((pSetupReqPak->wIndex) & 0xff)
            {
                /* ѡ��ӿ� */
                case 0:
                    pDescr = (&MyCfgDescr[18]);
                    len = 9;
                    break;

                case 1:
                    pDescr = (&MyCfgDescr[43]);
                    len = 9;
                    break;

                default:
                    /* ��֧�ֵ��ַ��������� */
                    errflag = 0xff;
                    break;
            }
            break;

        case USB_DESCR_TYP_REPORT:{
            const uint8_t ep_index = ((pSetupReqPak->wIndex) & 0xff);
            const uint8_t dev_cnt = getDeviceCount();
            if(ep_index < dev_cnt){
                auto descr = hid_devices_.at(ep_index)->getReportDescr();
                pDescr = descr.data(); //����׼���ϴ�
                len = descr.size();
            }else{
                len = 0xff;
            }

            if(ep_index < dev_cnt - 1){
                Ready = 1;//��������һ���豸������λReady
            }
        }
        break;

        case USB_DESCR_TYP_STRING:{ // �����˻�ȡ�ַ���������
            switch((pSetupReqPak->wValue) & 0xff){
                case 0:
                    pDescr = MyLangDescr.data();
                    len = MyLangDescr.size();
                    break;
                case 1:
                    pDescr = MyManuInfo.data();
                    len = MyManuInfo.size();
                    break;
                case 2:
                    pDescr = MyProdInfo.data();
                    len = MyProdInfo.size();
                    break;
                default:
                    errflag = 0xFF; // ��֧�ֵ��ַ���������
                    break;
            }
        }
        break;

        case USB_DESCR_TYP_QUALIF: // ������������
            pDescr = (&My_QueDescr[0]);
            len = sizeof(My_QueDescr);
            break;

        case USB_DESCR_TYP_SPEED:
            memcpy(&USB_FS_OSC_DESC[2], &MyCfgDescr[2], sizeof(MyCfgDescr) - 2);
            pDescr = (&USB_FS_OSC_DESC[0]);
            len = sizeof(USB_FS_OSC_DESC);
            break;

        default:
            errflag = 0xff;
            break;
    }

    if(SetupReqLen > len)
        SetupReqLen = len; //ʵ�����ϴ��ܳ���
    len = (SetupReqLen >= DevEP0SIZE) ? DevEP0SIZE : SetupReqLen;
    memcpy(pEP0_DataBuf, pDescr, len);
    pDescr += len;

}




void UsbProcesser::handleNonIdle(){
    switch(R8_USB_INT_ST & (MASK_UIS_TOKEN | MASK_UIS_ENDP))
    // �����������ƺͶ˵��
    {
        case UIS_TOKEN_IN:
        {
            switch(SetupReqCode)
            {
                case USB_GET_DESCRIPTOR:
                    len = SetupReqLen >= DevEP0SIZE ? DevEP0SIZE : SetupReqLen; // ���δ��䳤��
                    memcpy(pEP0_DataBuf, pDescr, len);                          /* �����ϴ����� */
                    SetupReqLen -= len;
                    pDescr += len;
                    R8_UEP0_T_LEN = len;
                    R8_UEP0_CTRL ^= RB_UEP_T_TOG; // ��ת
                    break;
                case USB_SET_ADDRESS:
                    R8_USB_DEV_AD = (R8_USB_DEV_AD & RB_UDA_GP_BIT) | SetupReqLen;
                    R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                    break;

                case USB_SET_FEATURE:
                    break;

                default:
                    R8_UEP0_T_LEN = 0; // ״̬�׶�����жϻ�����ǿ���ϴ�0�������ݰ��������ƴ���
                    R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                    break;
            }
        }
        break;

        case UIS_TOKEN_OUT:
        {
            len = R8_USB_RX_LEN;
            if(SetupReqCode == 0x09)
            {
                PRINT("[%s] Num Lock\t", (pEP0_DataBuf[0] & (1<<0)) ? "*" : " ");
                PRINT("[%s] Caps Lock\t", (pEP0_DataBuf[0] & (1<<1)) ? "*" : " ");
                PRINT("[%s] Scroll Lock\n", (pEP0_DataBuf[0] & (1<<2)) ? "*" : " ");
            }
        }
        break;

        case UIS_TOKEN_OUT | 1:
        {
            if(R8_USB_INT_ST & RB_UIS_TOG_OK)
            { // ��ͬ�������ݰ�������
                R8_UEP1_CTRL ^= RB_UEP_R_TOG;
                len = R8_USB_RX_LEN;
                DevEP1_OUT_Deal(len);
            }
        }
        break;

        case UIS_TOKEN_IN | 1:
            R8_UEP1_CTRL ^= RB_UEP_T_TOG;
            R8_UEP1_CTRL = (R8_UEP1_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
            break;

        case UIS_TOKEN_OUT | 2:
        {
            if(R8_USB_INT_ST & RB_UIS_TOG_OK)
            { // ��ͬ�������ݰ�������
                R8_UEP2_CTRL ^= RB_UEP_R_TOG;
                len = R8_USB_RX_LEN;
                DevEP2_OUT_Deal(len);
            }
        }
        break;

        case UIS_TOKEN_IN | 2:
            R8_UEP2_CTRL ^= RB_UEP_T_TOG;
            R8_UEP2_CTRL = (R8_UEP2_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
            break;

        case UIS_TOKEN_OUT | 3:
        {
            if(R8_USB_INT_ST & RB_UIS_TOG_OK)
            { // ��ͬ�������ݰ�������
                R8_UEP3_CTRL ^= RB_UEP_R_TOG;
                len = R8_USB_RX_LEN;
                DevEP3_OUT_Deal(len);
            }
        }
        break;

        case UIS_TOKEN_IN | 3:
            R8_UEP3_CTRL ^= RB_UEP_T_TOG;
            R8_UEP3_CTRL = (R8_UEP3_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
            break;

        case UIS_TOKEN_OUT | 4:
        {
            if(R8_USB_INT_ST & RB_UIS_TOG_OK)
            {
                R8_UEP4_CTRL ^= RB_UEP_R_TOG;
                len = R8_USB_RX_LEN;
                DevEP4_OUT_Deal(len);
            }
        }
        break;

        case UIS_TOKEN_IN | 4:
            R8_UEP4_CTRL ^= RB_UEP_T_TOG;
            R8_UEP4_CTRL = (R8_UEP4_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_NAK;
            break;

        default:
            break;
    }
}

void UsbProcesser::handleReset(){
    R8_USB_DEV_AD = 0;
    R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
    R8_UEP1_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
    R8_UEP2_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
    R8_UEP3_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
}
