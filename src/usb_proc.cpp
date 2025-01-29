#include "usb_proc.hpp"

UsbProcesser usb_processer{1};


// 语言描述符
constexpr auto MyLangDescr = usb::make_enlang_descr();
// 厂家信息
constexpr auto MyManuInfo = usb::make_str_descr("wch.cn");
// 产品信息
constexpr auto MyProdInfo = usb::make_str_descr("CH582m");

constexpr auto MyDevDescr = usb::make_device_descr(DevEP0SIZE);


// 配置描述符
constexpr uint8_t MyCfgDescr[] = {

    // 0x09：表示配置描述符的长度，即这个描述符总共有 9 个字节。
    // 0x02：表示这是一个配置描述符（Configuration Descriptor）。
    // 0x3b, 0x00：表示配置描述符的总长度，即 0x003B（59 字节）。
    // 0x02：表示这个配置中有 2 个接口。
    // 0x01：表示配置值，用于在 SET_CONFIGURATION 请求中选择这个配置。
    // 0x00：表示配置字符串描述符的索引，0 表示没有字符串描述符。
    // 0xA0：表示这个配置的属性，其中：
    // 0x80 表示该配置是否需要总线供电。
    // 0x20 表示是否支持远程唤醒。
    // 0x40 表示是否支持自供电。
    // 0x32：表示这个配置的最大功耗，单位是 2mA，即 0x32 * 2mA = 100mA
    0x09, 0x02, 0x3b, 0x00, 0x02, 0x01, 0x00, 0xA0, 0x32, //配置描述符
    


    
    0x09, 0x04, 0x00, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, //接口描述符,键盘
    0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x3e, 0x00, //HID类描述符
    0x07, 0x05, 0x81, 0x03, 0x08, 0x00, 0x0a,             //端点描述符

    0x09, 0x04, 0x01, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00, //接口描述符,鼠标
    0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x34, 0x00, //HID类描述符
    0x07, 0x05, 0x82, 0x03, 0x04, 0x00, 0x0a              //端点描述符


    // 0x09：表示配置描述符的长度，即这个描述符总共有 9 个字节。
    // 0x02：表示这是一个配置描述符（Configuration Descriptor）。
    // 0x3b, 0x00：表示配置描述符的总长度，即 0x003B（59 字节）。
    // 0x02：表示这个配置中有 2 个接口。
    // 0x01：表示配置值，用于在 SET_CONFIGURATION 请求中选择这个配置。
    // 0x00：表示配置字符串描述符的索引，0 表示没有字符串描述符。
    // 0xA0：表示这个配置的属性，其中：
    // 0x80 表示该配置是否需要总线供电。
    // 0x20 表示是否支持远程唤醒。
    // 0x40 表示是否支持自供电。
    // 0x32：表示这个配置的最大功耗，单位是 2mA，即 0x32 * 2mA = 100mA


    // 0x09, 0x02, 0x3b, 0x00, 0x02, 0x01, 0x00, 0xA0, 0x32, //配置描述符
    // // 0x09, 0x02, 84, 0x00, 0x03, 0x01, 0x00, 0xA0, 0x32, //配置描述符
    


    
    // 0x09, 0x04, 0x00, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, //接口描述符,键盘
    // 0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x3e, 0x00, //HID类描述符
    // 0x07, 0x05, 0x81, 0x03, 0x08, 0x00, 0x0a,             //端点描述符

    // 0x09, 0x04, 0x01, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00, //接口描述符,鼠标
    // 0x09, 0x21, 0x10, 0x01, 0x00, 0x01, 0x22, 0x34, 0x00, //HID类描述符
    // 0x07, 0x05, 0x82, 0x03, 0x04, 0x00, 0x0a,              //端点描述符

    // 0x09, //bLength 描述符的字节数长度 标准为0x09
    // 0x04, //bDescriptorType 描述符的类型 0x04为接口描述符
    // 0x02, //bInterfaceNumber 接口号，当前配置支持的接口数组索引（从0开始）。//若该配置有俩接口，接下来的接口描述符此值就为1
    // 0x00, //bAlternateSetting 可选设置的索引值。一个接口可以有多个接口描述符，靠此字段区分
    // 0x01, //bNumEndpoints 除了USB设备必须支持的端点0外，此接口所包括的端点的个数。此值为0表示该接口只使用端点0。
    // 0x03, //bInterfaceClass 接口所属的类值。为0表示为将来的标准保留。为FF表示此接口类由厂商说明。其他值查手册。0x03为HID类
    // 0x00, //bInterfaceSublass 接口所属子类的值。根据手册以及bInterfaceClass的值来定，若上面的值为0，此值也要为0。
    // 0x00, //bInterfaceProtocol 协议码，视手册以及上两者而定。上两者为0，此值也要为0。
    // 0x00, //iInterface 此接口的字符串描述符的索引值。//HID类描述符↓

    // 0x09, //bLength 描述符的字节数长度 标准为0x09
    // 0x21, //bDescriptorType 描述符的类型 0x21为人机接口类描述符
    // 0x12, 0x01, //bcdHID HID规范版本号的BCD码，此描述符所用版本为1.12
    // 0x00, //bCountryCode 硬件目的国家的识别号码。不启用此功能则为0
    // 0x01, //bNumDescriptors 支持的附属描述符数目。最小值为1：HID类至少有个报表描述符
    // 0x22, //bDescriptorType 类别描述符的类型。只有报表描述符为0x22；还有个实体描述符则为0x23
    // 0x4e, 0x00, //wDescriptorLength 报表描述符总长度//端点描述符↓

    // 0x07, //bLength 描述符的字节数长度 标准为0x07
    // 0x05, //bDescriptorType 描述符的类型 0x05为端点描述符
    // 0x81, //bmEndpointAddress 低四位为端点号，最高位为0：OUT方向，为1：IN方向。其他位保留。
    // 0x03, //bmAttributes 低两位为 00：控制传输；01：实时传输；10：批量传输；11：中断传输。其他位保留
    // 0x08, 0x00, //bMaxPacketSize 端点收发的数据包最大净长度
    // 0x0a //bInterval 周期数据传输端点的时间间隙。对于批量和控制传输来说无意义//若该端点配置实时传输，此值必须为1（ms）；若该端点配置中断传输，此值为1～255（ms）
};

/* USB速度匹配描述符 */
constexpr uint8_t My_QueDescr[] = {0x0A, 0x06, 0x00, 0x02, 0xFF, 0x00, 0xFF, 0x40, 0x01, 0x00};


/* USB全速模式,其他速度配置描述符 */
static uint8_t USB_FS_OSC_DESC[sizeof(MyCfgDescr)] = {
    0x09, 0x07, /* 其他部分通过程序复制 */
};


void DevEP1_OUT_Deal(uint8_t l){ /* 用户可自定义 */
    for(uint8_t i = 0; i < l; i++){
        pEP1_IN_DataBuf[i] = ~pEP1_OUT_DataBuf[i];
    }
    DevEP1_IN_Deal(l);
}

void DevEP2_OUT_Deal(uint8_t l){ /* 用户可自定义 */
    for(uint8_t i = 0; i < l; i++){
        pEP2_IN_DataBuf[i] = ~pEP2_OUT_DataBuf[i];
    }
    DevEP2_IN_Deal(l);
}

void DevEP3_OUT_Deal(uint8_t l){ /* 用户可自定义 */
    for(uint8_t i = 0; i < l; i++){
        pEP3_IN_DataBuf[i] = ~pEP3_OUT_DataBuf[i];
    }
    DevEP3_IN_Deal(l);
}

void DevEP4_OUT_Deal(uint8_t l){ /* 用户可自定义 */
    for(uint8_t i = 0; i < l; i++){
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
    if((pSetupReqPak->bRequestType & USB_REQ_TYP_MASK) != USB_REQ_TYP_STANDARD){
        /* 非标准请求 */
        /* 其它请求,如类请求，产商请求等 */
        if(pSetupReqPak->bRequestType & 0x40){
            /* 厂商请求 */
        }else if(pSetupReqPak->bRequestType & 0x20){
            switch(SetupReqCode){
                case DEF_USB_SET_IDLE: /* 0x0A: SET_IDLE */
                    Idle_Value = endpoints_[0].data()[3];
                    break; //这个一定要有

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
    }else{ /* 标准请求 */
        handleStdRequest();
    }if(errflag == 0xff){ // 错误或不支持
        //                  SetupReqCode = 0xFF;
        R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_STALL | UEP_T_RES_STALL; // STALL
    }else{
        if(chtype & 0x80){ // 上传
            len = (SetupReqLen > DevEP0SIZE) ? DevEP0SIZE : SetupReqLen;
            SetupReqLen -= len;
        }else{
            len = 0; // 下传
        }
        R8_UEP0_T_LEN = len;
        R8_UEP0_CTRL = RB_UEP_R_TOG | RB_UEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_ACK; // 默认数据包是DATA1
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
                errflag = 0xFF; // 不支持的端点
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
                /* 不支持的端点 */
                errflag = 0xFF; // 不支持的端点
                break;
        }
    }else if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_DEVICE){
        if(pSetupReqPak->wValue == 1){
            /* 设置睡眠 */
            USB_SleepStatus |= 0x01;
        }
    }else{
        errflag = 0xFF;
    }
}

void UsbProcesser::handleGetStatus(){
    if((pSetupReqPak->bRequestType & USB_REQ_RECIP_MASK) == USB_REQ_RECIP_ENDP){
        /* 端点 */
        pEP0_DataBuf[0] = 0x00;
        switch(pSetupReqPak->wIndex)
        {
            case 0x83:
                if((R8_UEP3_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL){
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x03:
                if((R8_UEP3_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL){
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x82:
                if((R8_UEP2_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL){
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x02:
                if((R8_UEP2_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL){
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x81:
                if((R8_UEP1_CTRL & (RB_UEP_T_TOG | MASK_UEP_T_RES)) == UEP_T_RES_STALL){
                    pEP0_DataBuf[0] = 0x01;
                }
                break;

            case 0x01:
                if((R8_UEP1_CTRL & (RB_UEP_R_TOG | MASK_UEP_R_RES)) == UEP_R_RES_STALL){
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
            switch((pSetupReqPak->wIndex) & 0xff){
                /* 选择接口 */
                case 0:
                    pDescr = (&MyCfgDescr[18]);
                    len = 9;
                    break;

                case 1:
                    pDescr = (&MyCfgDescr[43]);
                    len = 9;
                    break;

                // case 2:
                //     pDescr = (&MyCfgDescr[43 + 25]);
                //     len = 9;
                //     break;

                default:
                    /* 不支持的字符串描述符 */
                    errflag = 0xff;
                    break;
            }
            break;

        case USB_DESCR_TYP_REPORT:{
            const uint8_t ep_index = ((pSetupReqPak->wIndex) & 0xff);
            const uint8_t dev_cnt = getDeviceCount();
            if(ep_index < dev_cnt){
                auto descr = hid_devices_.at(ep_index)->getReportDescr();
                pDescr = descr.data(); //数据准备上传
                len = descr.size();
            }else{
                len = 0xff;
            }
            if(ep_index < dev_cnt - 1){
                Ready = 1;//如果是最后一个设备，则置位Ready
            }
        }
        break;

        case USB_DESCR_TYP_STRING:{ // 定义了获取字符串描述符
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
                    errflag = 0xFF; // 不支持的字符串描述符
                    break;
            }
        }
        break;

        case USB_DESCR_TYP_QUALIF: // 兼容性描述符
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
        SetupReqLen = len; //实际需上传总长度
    len = (SetupReqLen >= DevEP0SIZE) ? DevEP0SIZE : SetupReqLen;
    memcpy(pEP0_DataBuf, pDescr, len);
    pDescr += len;

}



void UsbProcesser::handleNonIdle(){
    switch(R8_USB_INT_ST & (MASK_UIS_TOKEN | MASK_UIS_ENDP)){
    // 分析操作令牌和端点号
        case UIS_TOKEN_IN:{
            switch(SetupReqCode){
                case USB_GET_DESCRIPTOR:
                    len = SetupReqLen >= DevEP0SIZE ? DevEP0SIZE : SetupReqLen; // 本次传输长度
                    memcpy(pEP0_DataBuf, pDescr, len);                          /* 加载上传数据 */
                    SetupReqLen -= len;
                    pDescr += len;
                    R8_UEP0_T_LEN = len;
                    R8_UEP0_CTRL ^= RB_UEP_T_TOG; // 翻转
                    break;
                case USB_SET_ADDRESS:
                    R8_USB_DEV_AD = (R8_USB_DEV_AD & RB_UDA_GP_BIT) | SetupReqLen;
                    R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                    break;

                case USB_SET_FEATURE:
                    break;

                default:
                    R8_UEP0_T_LEN = 0; // 状态阶段完成中断或者是强制上传0长度数据包结束控制传输
                    R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                    break;
            }
        }
        break;

        case UIS_TOKEN_OUT:{
            len = R8_USB_RX_LEN;
            if(SetupReqCode == 0x09){
                PRINT("[%s] Num Lock\t", (pEP0_DataBuf[0] & (1<<0)) ? "*" : " ");
                PRINT("[%s] Caps Lock\t", (pEP0_DataBuf[0] & (1<<1)) ? "*" : " ");
                PRINT("[%s] Scroll Lock\n", (pEP0_DataBuf[0] & (1<<2)) ? "*" : " ");
            }
        }
        break;

        case UIS_TOKEN_OUT | 1:{
            if(R8_USB_INT_ST & RB_UIS_TOG_OK){ // 不同步的数据包将丢弃
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

        case UIS_TOKEN_OUT | 2:{
            if(R8_USB_INT_ST & RB_UIS_TOG_OK){ // 不同步的数据包将丢弃
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

        case UIS_TOKEN_OUT | 3:{
            if(R8_USB_INT_ST & RB_UIS_TOG_OK){ // 不同步的数据包将丢弃
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

        case UIS_TOKEN_OUT | 4:{
            if(R8_USB_INT_ST & RB_UIS_TOG_OK){
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

void UsbProcesser::handle(){
    uint8_t intflag = R8_USB_INT_FG;
    if(intflag & RB_UIF_TRANSFER){
        if((R8_USB_INT_ST & MASK_UIS_TOKEN) != MASK_UIS_TOKEN){ // 非空闲
            handleNonIdle();
            R8_USB_INT_FG = RB_UIF_TRANSFER;
        }if(R8_USB_INT_ST & RB_UIS_SETUP_ACT){ // Setup包处理
            handleSetup();
            R8_USB_INT_FG = RB_UIF_TRANSFER;
        }
        
    }else if(intflag & RB_UIF_BUS_RST){
        handleReset();
        R8_USB_INT_FG = RB_UIF_BUS_RST;
    }else if(intflag & RB_UIF_SUSPEND){
        if(R8_USB_MIS_ST & RB_UMS_SUSPEND){
            // 挂起
        }else{
            // 唤醒
        }
        R8_USB_INT_FG = RB_UIF_SUSPEND;
    }else{
        R8_USB_INT_FG = intflag;
    }
}