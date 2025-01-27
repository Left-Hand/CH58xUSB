// #include "ina226.h"

// int32_t mCurrentMicroAmpsPerBit = 0;
// int32_t mPowerMicroWattPerBit =0 ;

// void delay_nns(uint16_t D)  //30纳秒ns  根据手册要用到IIC的HS高速模式
// {
//     while(--D);
// }

// void delay_nms(uint16_t ms)  //毫秒
// {
//     uint16_t i;
//     uint32_t M = 0;//720W
//     for(i = 0;i < ms; i++)
//     for(M=12000;M > 0;M--);
// }

// void delay_nus(uint16_t us)//微秒
// {
//     uint16_t i;
//     uint16_t M = 0;//720W
//     for(i = 0;i < us; i++)
//     for(M=72;M > 0;M--);
// }

// /****************IIC***************************/
// void IIC_Init(void)
// {
    
//     IIC_SDA_H;
//     IIC_SCL_H;  
//         delay_nms(5);
// }
    
// void IIC_Start(void)
// {
//     IIC_SDA_H;            
//     IIC_SCL_H;
//     delay_nns(5);
//      IIC_SDA_L;//START:when CLK is high,DATA change form high to low 
//     delay_nns(5);
//     IIC_SCL_L;//钳住I2C总线，准备发送或接收数据 
//     delay_nns(5);
// }    

// void IIC_Stop(void)
// {
//     IIC_SDA_L;//STOP:when CLK is high DATA change form low to high
//      delay_nns(5);
//     IIC_SCL_H; 
//         delay_nns(5);
//     IIC_SDA_H;//发送I2C总线结束信号
//     delay_nns(5);                                   
// }

// void IIC_Ack(void)
// {
//     IIC_SDA_L;
//     delay_nns(5);
//     IIC_SCL_H;
//     delay_nns(5);
//     IIC_SCL_L;
//         delay_nns(5);
//     IIC_SDA_H;
// }

// void IIC_NAck(void)
// {
//     IIC_SDA_H;
//     delay_nns(5);
//     IIC_SCL_H;
// delay_nns(5);
//     IIC_SCL_L;
//     delay_nns(5);
//     IIC_SDA_L;
// }        

// uint8_t IIC_Wait_Ack(void)
// {
//     uint8_t ucErrTime=0;
//     //SDA_IN();      //SDA设置为输入  
//     IIC_SDA_H;
//     delay_nns(5);       
//     IIC_SCL_H;
//     delay_nns(5);          
    
//     while(SDA_READ)
//     {
//         ucErrTime++;
//         if(ucErrTime>250)
//         {
//             IIC_Stop();
//             return 1;
//         }
//     }
//     IIC_SCL_L;//时钟输出0        
//     return 0;  
// }

// void IIC_Send_Byte(uint8_t txd)
// {                              
//    IIC_SCL_L;//拉低时钟开始数据传输
//    for(uint8_t i = 0;i < 8;i++)
//     {              
//         if(txd&0x80)
//                     IIC_SDA_H;
//                 else
//                     IIC_SDA_L;                
//         txd<<=1;       
                
//         IIC_SCL_H;
//         delay_nns(5);
//         IIC_SCL_L;
//         delay_nns(5);
//     }            
//     //    IIC_SDA_H;
//     //    IIC_SCL_H;            //当去掉wait_ack时的时候添加
//     //    delay_nns(5);
//         //IIC_SCL_L;
// } 

// uint8_t IIC_Read_Byte(unsigned char ack)
// {
//       uint8_t TData=0,i;
//     for(i=0;i<8;i++)
//     {
//         IIC_SCL_H;
//         delay_nns(5);
//         TData=TData<<1;
//         //if(GPIOB->IDR& GPIO_IDR_IDR7)        //判断SDA是否为高
//             if(SDA_READ)
//         {
//             TData|=0x01;
//         }
//         IIC_SCL_L;
//         delay_nns(5);
//     }
//         if(!ack)
//             IIC_NAck();
//         else
//             IIC_Ack();

//     return TData;
// }
// void INA226_Init(float aShuntResistor_Ohms, float aMaxCurrent_Amps){	

// 	IIC_Init();
// 	INA226_SendData(CFG_REG,0x8000);
// 	INA226_SendData(CFG_REG,0x4527);

// 	float CurrentLSB = ceilf( ( aMaxCurrent_Amps * 1000000.0f) / (float)32767.0f);
// 	float Cal = 0.00512f /  (aShuntResistor_Ohms * (CurrentLSB/1000000.0f));

// 	mCurrentMicroAmpsPerBit = ((int32_t)CurrentLSB);
// 	mPowerMicroWattPerBit = ((int32_t)mCurrentMicroAmpsPerBit) * 25;
// 	INA226_SendData(CAL_REG,(uint16_t)Cal);//设置分流电压转电流转换参数	
// }
// //设置寄存器指针
// void INA226_SetRegPointer(uint8_t reg){
// 	IIC_Start();

// 	IIC_Send_Byte(0x80);
// 	IIC_Wait_Ack();

// 	IIC_Send_Byte(reg);
// 	IIC_Wait_Ack();

// 	IIC_Stop();
// }

// //发送,写入数据
// void INA226_SendData(uint8_t reg,uint16_t data)
// {
// 	uint8_t temp=0;
// 	IIC_Start();

// 	IIC_Send_Byte(0x80);
// 	IIC_Wait_Ack();

// 	IIC_Send_Byte(reg);
// 	IIC_Wait_Ack();
	
// 	temp = (uint8_t)(data>>8);
// 	IIC_Send_Byte(temp);
// 	IIC_Wait_Ack();

// 	temp = (uint8_t)(data&0x00FF);
// 	IIC_Send_Byte(temp);
// 	IIC_Wait_Ack();
	
// 	IIC_Stop();
// }

// //读取数据
// uint16_t INA226_ReadData()
// {
// 	uint16_t temp=0;
// 	IIC_Start();

// 	IIC_Send_Byte(0x80+1);
// 	IIC_Wait_Ack();
	
// 	temp = IIC_Read_Byte(1);
// 	temp<<=8;	
// 	temp |= IIC_Read_Byte(1);

// 	// IIC_Ack();
// 	IIC_Stop();
// 	return temp;
// }




// //获取校准值
// uint16_t INA226_GET_CAL_REG()
// {	
// 	uint32_t temp=0;
// 	INA226_SetRegPointer(CAL_REG);
// 	temp = INA226_ReadData();
// 	return (uint16_t)temp;
// }

// //1.25mV/bit
// int32_t INA226_GetBusVoltage_uV()
// {
// 	uint32_t temp = 0;
// 	INA226_SetRegPointer(BV_REG);
//     delay_nus(40);
// 	temp = INA226_ReadData();
// 	return (uint16_t)temp;	
// }

// //2.5uV/bit
// int32_t INA226_GetShuntVoltage_uV()
// {
// 	uint16_t temp = 0;
// 	INA226_SetRegPointer(SV_REG);
//         delay_nus(40);
// 	temp = INA226_ReadData();
// 	if(temp&0x8000)	temp = ~(temp - 1);	
// 	return (int32_t)temp * 1250;	
// }

// //1mA/bit
// int32_t INA226_GetCurrent_uA(){
// 	uint16_t temp=0;	
// 	INA226_SetRegPointer(CUR_REG);
//         delay_nus(40);
// 	temp = INA226_ReadData();
// 	if(temp&0x8000)	temp = ~(temp - 1);	
// 	return temp * mCurrentMicroAmpsPerBit;
// }


// int32_t INA226_GetPower_uW(){
// 	INA226_SetRegPointer(PWR_REG);
//         delay_nus(40);
// 	// return (int32_t)INA226_ReadData()*mPowerMicroWattPerBit;
// 	return (int32_t)INA226_ReadData();
// }

/*
Library to facilitate use of the INA226 Voltage, Current & Power monitor
from Texas Instruments.
See spec. here: http://www.ti.com/lit/ds/symlink/ina226.pdf.

Copyright [2018] [AutoFox] autofoxsys@gmail.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

This library is for Arduino.

In developing this library, besides reading the INA226 spec, I consulted
the following code:

* Linux drivers for the INA family (written in C)
* https://github.com/SV-Zanshin/INA226 (most useful)

PLATFORM DEPENDENCE
Embodied in 3 functions related to I2C reading/writing

*/

#include "INA226.h"
#include <math.h>




//=============================================================================
//Some helper macros for this source file

#define CALL_FN(fn); { status s = fn; if(fn != OK){return s;} }
#define CHECK_INITIALIZED(); if(!this->mInitialized) return NOT_INITIALIZED;

//=============================================================================

static const uint8_t    INA226_CONFIG              = 0x00;
static const uint8_t    INA226_SHUNT_VOLTAGE       = 0x01; // readonly
static const uint8_t    INA226_BUS_VOLTAGE         = 0x02; // readonly
static const uint8_t    INA226_POWER               = 0x03; // readonly
static const uint8_t    INA226_CURRENT             = 0x04; // readonly
static const uint8_t    INA226_CALIBRATION         = 0x05;
static const uint8_t    INA226_MASK_ENABLE         = 0x06;
static const uint8_t    INA226_ALERT_LIMIT         = 0x07;
static const uint8_t    INA226_MANUFACTURER_ID     = 0xFE; // readonly
static const uint8_t    INA226_DIE_ID              = 0xFF; // readonly


//=============================================================================

static const int32_t    INA226_BUS_VOLTAGE_LSB     = 1250; //1250uV per bit
//static const int32_t    INA226_SHUNT_VOLTAGE_LSB   = 2500;    //2500 nano volts per bit (=2.5uV)
static const int32_t    INA226_POWER_LSB_FACTOR    = 25;
static const uint16_t   INA226_MANUFACTURER_ID_K   = 0x5449;
static const uint16_t   INA226_DIE_ID_K            = 0x2260;
//static const uint16_t   INA226_CONFIG_RESET_VALUE  = 0x4127; // value of config reg after a reset

//=============================================================================

static const uint8_t    INA226_DEFAULT_I2C_ADDRESS  = 0x40;
static const uint16_t   INA226_CONFIG_DEFAULT       = 0x4527; // Our default config reg settings
//=============================================================================
const uint16_t cResetCommand                = 0x8000;
const uint16_t cOperatingModeMask           = 0x0007;
const uint16_t cAlertPinModeMask            = 0xFC00;
const uint16_t cAlertCauseMask              = 0x001E;
const uint16_t cAlertLatchingMode           = 0x0001;
const uint16_t cSampleAvgMask               = 0x0E00;
const uint16_t cBusVoltageConvTimeMask      = 0x01C0;
const uint16_t cShuntVoltageConvTimeMask    = 0x0038;
const int      cSampleAvgIdxShift           = 9;
const int      cBusVoltConvTimeIdxShift     = 6;
const int      cShuntVoltConvTimeIdxShift   = 3;
const int      cMaxSampleAvgTblIdx          = 7;    //occupies 3 bit positions
const int      cMaxConvTimeTblIdx           = 7; //occupies 3 bit positions
//=============================================================================


void delay_nns(uint16_t D)  //30纳秒ns  根据手册要用到IIC的HS高速模式
{
    // while(--D);
}

void delay_nms(uint16_t ms)  //毫秒
{
    // uint16_t i;
    // uint32_t M = 0;//720W
    // for(i = 0;i < ms; i++)
    // for(M=12000;M > 0;M--);
}

void delay_nus(uint16_t us)//微秒
{
    // uint16_t i;
    // uint16_t M = 0;//720W
    // for(i = 0;i < us; i++)
    // for(M=72;M > 0;M--);
}

/****************IIC***************************/
void IIC_Init(void)
{
    
    IIC_SDA_H;
    IIC_SCL_H;  
        delay_nms(5);
}
    
void IIC_Start(void)
{
    IIC_SDA_H;            
    IIC_SCL_H;
    delay_nns(5);
     IIC_SDA_L;//START:when CLK is high,DATA change form high to low 
    delay_nns(5);
    IIC_SCL_L;//钳住I2C总线，准备发送或接收数据 
    delay_nns(5);
}    

void IIC_Stop(void)
{
    
    IIC_SDA_L;//STOP:when CLK is high DATA change form low to high
     delay_nns(5);
    IIC_SCL_H; 
        delay_nns(5);
    IIC_SDA_H;//发送I2C总线结束信号
    delay_nns(5);                                   
}

void IIC_Ack(void)
{
    IIC_SDA_L;
    delay_nns(5);
    IIC_SCL_H;
    delay_nns(5);
    IIC_SCL_L;
        delay_nns(5);
    IIC_SDA_H;
}

void IIC_NAck(void)
{
    IIC_SDA_H;
    delay_nns(5);
    IIC_SCL_H;
delay_nns(5);
    IIC_SCL_L;
    delay_nns(5);
    IIC_SDA_L;
}        

uint8_t IIC_Wait_Ack(void)
{
    uint8_t ucErrTime=0;
    //SDA_IN();      //SDA设置为输入  
    IIC_SDA_H;
    delay_nns(5);       
    IIC_SCL_H;
    delay_nns(5);          
    
    while(SDA_READ)
    {
        ucErrTime++;
        if(ucErrTime>250)
        {
            IIC_Stop();
            return 1;
        }
    }
    IIC_SCL_L;//时钟输出0        
    return 0;  
}

void IIC_Send_Byte(uint8_t txd)
{                              
   IIC_SCL_L;//拉低时钟开始数据传输
   for(uint8_t i = 0;i < 8;i++)
    {              
        if(txd&0x80)
                    IIC_SDA_H;
                else
                    IIC_SDA_L;                
        txd<<=1;       
        delay_nns(5);
        IIC_SCL_H;
        delay_nns(5);
        IIC_SCL_L;
        delay_nns(5);
    }            
       IIC_SDA_H;
       IIC_SCL_H;            //当去掉wait_ack时的时候添加
       delay_nns(5);
        IIC_SCL_L;
} 

uint8_t IIC_Read_Byte(unsigned char ack)
{
      uint8_t TData=0,i;
    for(i=0;i<8;i++)
    {
        IIC_SCL_H;
        delay_nns(5);
        TData=TData<<1;
        //if(GPIOB->IDR& GPIO_IDR_IDR7)        //判断SDA是否为高
            if(SDA_READ)
        {
            TData|=0x01;
        }
        IIC_SCL_L;
        delay_nns(5);
    }
        if(!ack)
            IIC_NAck();
        else
            IIC_Ack();

    return TData;
}

void INA226_Constructor(INA226* this)
{
	this->mInitialized = false;
	this->mI2C_Address = INA226_DEFAULT_I2C_ADDRESS;
	this->mConfigRegister = 0;
	this->mCalibrationValue = 0;
	this->mCurrentMicroAmpsPerBit = 0;
	this->mPowerMicroWattPerBit = 0;
}

//----------------------------------------------------------------------------
status INA226_Init(INA226* this, uint8_t aI2C_Address, double aShuntResistor_Ohms, double aMaxCurrent_Amps)
{
	this->mInitialized = false;

	//Check if there's a device (any I2C device) at the specified address.
	CALL_FN( INA226_CheckI2cAddress(aI2C_Address) );

	//Good so far, check that it's an INA226 device at the specified address.
	uint16_t theINA226_ID;
	CALL_FN( INA226_ReadRegister(this,INA226_MANUFACTURER_ID, &theINA226_ID) );
	if(theINA226_ID != INA226_MANUFACTURER_ID_K){
		return INA226_TI_ID_MISMATCH; //Expected to find TI manufacturer ID
	}
	CALL_FN( INA226_ReadRegister(this,INA226_DIE_ID, &theINA226_ID) );
	if( theINA226_ID != INA226_DIE_ID_K){
		return  INA226_DIE_ID_MISMATCH; //Expected to find INA226 device ID
	}

	this->mI2C_Address = aI2C_Address;

	//Reset the INA226 device
	CALL_FN( INA226_WriteRegister(this,INA226_CONFIG, cResetCommand) );

	//Now set our own default configuration (you can redefine this constant in the header, as needed)
	CALL_FN( INA226_WriteRegister(this,INA226_CONFIG, INA226_CONFIG_DEFAULT) );

	//Read back the configuration register and check that it matches
	CALL_FN( INA226_ReadRegister(this,INA226_CONFIG, &(this->mConfigRegister)) );
	if(this->mConfigRegister != INA226_CONFIG_DEFAULT){
		return CONFIG_ERROR;
	}

	//Finally, set up the calibration register - this will also calculate the scaling
	//factors that we must apply to the current and power measurements that we read from
	//the INA226 device.
	CALL_FN( INA226_setupCalibration(this, aShuntResistor_Ohms, aMaxCurrent_Amps) );

	this->mInitialized = true;
	return OK;
}
//----------------------------------------------------------------------------

status INA226_setupCalibration(INA226* this, double aShuntResistor_Ohms, double aMaxCurrent_Amps)
{
	// Calculate a value for Current_LSB that gives us the best resolution
	// for current measurements.  The INA266 current register is 16-bit
	// signed, max positive value is 2^15 -1 = 32767
	// If we can be sure that the current won't be more than aMaxCurrent_Amps then
	// we can calculate the Amps per bit as aMaxCurrent_Amps/32767 (rounded up to
	// to the nearest integer).
	// The value 0.00512 in the calculations below comes from the INA226 spec which
	// provides a definition of the formula that's used to calculate the calibration value.

	double theCurrentLSB = ceil( ( aMaxCurrent_Amps * 1000000.0) / (double)32767.0);
	double theCal = (double)0.00512 /  (aShuntResistor_Ohms * (theCurrentLSB/1000000.0));

	this->mCurrentMicroAmpsPerBit = ((int32_t)theCurrentLSB);
	this->mCalibrationValue = (uint16_t)theCal;
	this->mPowerMicroWattPerBit = this->mCurrentMicroAmpsPerBit * INA226_POWER_LSB_FACTOR;

	return INA226_WriteRegister(this,INA226_CALIBRATION, this->mCalibrationValue);
}
//----------------------------------------------------------------------------
//Check if a device exists at the specified I2C address

status INA226_CheckI2cAddress(uint8_t aI2C_Address)
{

    return OK;
}

//----------------------------------------------------------------------------

status INA226_ReadRegister(INA226* this, uint8_t aRegister, uint16_t* aValue_p)
{
	*aValue_p = 0;
    IIC_Start();
	IIC_Send_Byte(this->mI2C_Address);
    // IIC_Wait_Ack();
	IIC_Send_Byte(aRegister);
    // IIC_Wait_Ack();
	IIC_Stop();

    IIC_Start();
	IIC_Send_Byte(this->mI2C_Address + 1);
    // IIC_Wait_Ack();
    *aValue_p = IIC_Read_Byte(1);
    // IIC_Wait_Ack();
    *aValue_p = *aValue_p<<8 | IIC_Read_Byte(1);
    // IIC_Wait_Ack();
    IIC_Stop();
    return OK;
}

//----------------------------------------------------------------------------
status INA226_WriteRegister(INA226* this, uint8_t aRegister, uint16_t aValue)
{
    IIC_Start();
	IIC_Send_Byte(this->mI2C_Address);
    // IIC_Wait_Ack();
	IIC_Send_Byte(aRegister);
	// IIC_Wait_Ack();
    IIC_Send_Byte((aValue >> 8) & 0xFF);
	// IIC_Wait_Ack();
    IIC_Send_Byte(aValue & 0xFF);
	IIC_Stop();
    return OK;
}
//----------------------------------------------------------------------------
int32_t INA226_GetShuntVoltage_uV(INA226* this)
{
	//The value retrieved from the INA226 for the shunt voltage
	//needs to be multiplied by 2.5 to yield the value in microvolts.
	//As I don't want to use floating point multiplication I will take the value
	//divide it by 2 (shift right) and add that to 2 times the original value
	//(shift left).
	int16_t theRegisterValue=0;
	int32_t theResult;
	INA226_ReadRegister(this,INA226_SHUNT_VOLTAGE, (uint16_t*)&theRegisterValue);
	theResult = (int32_t)theRegisterValue>>1;
	theResult+= (int32_t)theRegisterValue<<1;
	return theResult;
}
//----------------------------------------------------------------------------
int32_t INA226_GetBusVoltage_uV(INA226* this)
{
	uint16_t theRegisterValue=0;
	INA226_ReadRegister(this,INA226_BUS_VOLTAGE, &theRegisterValue);
	return (int32_t)theRegisterValue * INA226_BUS_VOLTAGE_LSB;
}

//----------------------------------------------------------------------------
int32_t INA226_GetCurrent_uA(INA226* this)
{
	int16_t theRegisterValue=0; // signed register, result in mA
	INA226_ReadRegister(this,INA226_CURRENT, (uint16_t*)&theRegisterValue);
	return (int32_t)theRegisterValue * this->mCurrentMicroAmpsPerBit;
}
//----------------------------------------------------------------------------
int32_t INA226_GetPower_uW(INA226* this)
{
	uint16_t theRegisterValue=0;
	int32_t theReturnValue;
	INA226_ReadRegister(this,INA226_POWER, &theRegisterValue);
	theReturnValue = (int32_t)theRegisterValue * this->mPowerMicroWattPerBit;
	return theReturnValue;
}
//----------------------------------------------------------------------------
status INA226_Hibernate(INA226* this)
{
	CHECK_INITIALIZED();
	//Make a most recent copy of the configuration register, which also contains
	//The operating mode (we need a copy of this for when we come out of sleep)
	CALL_FN( INA226_ReadRegister(this,INA226_CONFIG, &(this->mConfigRegister)) );

	//Zero out the operating more, this will put the INA226 into shutdown
	uint16_t theTempConfigValue = this->mConfigRegister & ~(cOperatingModeMask);

	return INA226_WriteRegister(this,INA226_CONFIG, theTempConfigValue);
}
//----------------------------------------------------------------------------
status INA226_Wakeup(INA226* this)
{
	CHECK_INITIALIZED();
	//Write most recent copy of the calibration register - which should restore
	//the most operating mode that was active before hibernation.  Quick check to test if by
	//any chance the last operating mode was a hibernation and in that case set to 
	//ShuntAndBusVoltageContinuous.
	uint16_t theLastOperatingMode = this->mConfigRegister & cOperatingModeMask;
	if(theLastOperatingMode == Shutdown ||
		theLastOperatingMode == 0){
			this->mConfigRegister &= ~cOperatingModeMask;
			this->mConfigRegister |= ShuntAndBusVoltageContinuous;
	}

	return INA226_WriteRegister(this,INA226_CONFIG, this->mConfigRegister);
}
//----------------------------------------------------------------------------
status INA226_SetOperatingMode(INA226* this, enum eOperatingMode aOpMode)
{
	CHECK_INITIALIZED();
	CALL_FN( INA226_ReadRegister(this,INA226_CONFIG, &(this->mConfigRegister)) );

	//Zero out the existing mode then OR in the new mode
	this->mConfigRegister  &= ~(cOperatingModeMask);
	this->mConfigRegister  |= (uint16_t)aOpMode;

	return INA226_WriteRegister(this,INA226_CONFIG, this->mConfigRegister);
}
//----------------------------------------------------------------------------
status  INA226_ConfigureAlertPinTrigger(INA226* this, enum eAlertTrigger aAlertTrigger, int32_t aValue, bool aLatching)
{
	uint16_t theMaskEnableRegister;

	CHECK_INITIALIZED();
	CALL_FN( INA226_ReadRegister(this,INA226_MASK_ENABLE, &theMaskEnableRegister) );

	//Clear the current configuration for the alert pin
	theMaskEnableRegister &= ~ cAlertPinModeMask;
	//...and prepare the new alert configuration (we'll actually set it down below)
	theMaskEnableRegister |= (uint16_t)aAlertTrigger;
	if(aLatching){
		theMaskEnableRegister |= cAlertLatchingMode;
	}

	//We need to convert the value supplied (parameter) for the trigger to an INA226 register value.
	//The supplied value could be a shunt voltage, bus voltage or power reading.  All values are
	//in micro units (i.e. microvolts or microamps).
	//Remember that when we get any reading (voltage, current or power) from the INA226 we convert
	//it from the INA226's internal regisister representation (check the functions above).  We
	//need to do the inverse conversion when providing a value back to the INA226 to act as a trigger
	//value.

	int32_t theAlertValue=0;

	switch(aAlertTrigger){
	case PowerOverLimit:
		//back convert to INA226 representation for power (in microWatts)
		theAlertValue = (aValue / this->mPowerMicroWattPerBit);
		break;
	case ClearTriggers:
	case ConversionReady:
		//not a voltage or a power, so we don't care about the trigger value
		theAlertValue = 0;
		break;
	case ShuntVoltageOverLimit:
	case ShuntVoltageUnderLimit:
		//theAlertValue = ((double)aValue / ((double)(INA226_SHUNT_VOLTAGE_LSB)/1000.0));
		theAlertValue = (aValue<<1)/5; //same as aValue/2.5
		break;
	case BusVoltageOverLimit:
	case BusVoltageUnderLimit:
		theAlertValue = (aValue / INA226_BUS_VOLTAGE_LSB);
		break;
	default:
		return BAD_PARAMETER;
	}


	//before we set the new config for the alert pin, set the value that will trigger the alert
	CALL_FN( INA226_WriteRegister(this,INA226_ALERT_LIMIT, (int16_t)theAlertValue) );
	//Now set the trigger mode.
	return INA226_WriteRegister(this,INA226_MASK_ENABLE, theMaskEnableRegister);
}
//----------------------------------------------------------------------------
//status INA226_ResetAlertPin(INA226* this)
//{
//	CHECK_INITIALIZED();
//	uint16_t theDummyValue;
//	//Reading the Mask/Enable register will reset the alert pin
//	return INA226_ReadRegister(this,INA226_MASK_ENABLE, theDummyValue);
//}
//----------------------------------------------------------------------------
status INA226_ResetAlertPin(INA226* this, enum  eAlertTriggerCause* aAlertTriggerCause_p )
{
	//preset the return parameter in case the function fails
	*aAlertTriggerCause_p = Unknown;
	CHECK_INITIALIZED();

	uint16_t theTriggerCause;
	//Reading the Mask/Enable register will reset the alert pin and provide us with the
	//cause of the alert
	CALL_FN( INA226_ReadRegister(this,INA226_MASK_ENABLE, &theTriggerCause) );

	//Mask just the bit that interests us (cause of the alert)
	theTriggerCause &= cAlertCauseMask;

	//Cast the trigger cause to the return parameter type
	*aAlertTriggerCause_p = theTriggerCause;
	return OK;
}
//----------------------------------------------------------------------------
status INA226_ConfigureVoltageConversionTime(INA226* this, int aIndexToConversionTimeTable)
{
	CHECK_INITIALIZED();

	if(aIndexToConversionTimeTable < 0 || aIndexToConversionTimeTable > cMaxConvTimeTblIdx ){
		return BAD_PARAMETER;
	}

	//Read the configuration register
	CALL_FN( INA226_ReadRegister(this,INA226_CONFIG, &(this->mConfigRegister)) );
	//Clear the current voltage sampling time settings
	this->mConfigRegister &= ~(cBusVoltageConvTimeMask | cShuntVoltageConvTimeMask);
	//Set the new values
	uint16_t theMergedBusAndShuntConvTimeIndicies = 
		((uint16_t)aIndexToConversionTimeTable << cBusVoltConvTimeIdxShift) |
		((uint16_t)aIndexToConversionTimeTable << cShuntVoltConvTimeIdxShift);

	this->mConfigRegister |= theMergedBusAndShuntConvTimeIndicies;

	return INA226_WriteRegister(this,INA226_CONFIG, this->mConfigRegister);
}
//----------------------------------------------------------------------------
status INA226_ConfigureNumSampleAveraging(INA226* this, int aIndexToSampleAverageTable)
{
	CHECK_INITIALIZED();

	if(aIndexToSampleAverageTable < 0 || aIndexToSampleAverageTable > cMaxSampleAvgTblIdx ){
		return BAD_PARAMETER;
	}

	//Read the configuration register
	CALL_FN( INA226_ReadRegister(this,INA226_CONFIG, &(this->mConfigRegister)) );
	//Clear the current averaging value
	this->mConfigRegister &= ~cSampleAvgMask;
	//Set the new value
	this->mConfigRegister |= (aIndexToSampleAverageTable<<cSampleAvgIdxShift);

	return INA226_WriteRegister(this,INA226_CONFIG, this->mConfigRegister);
}
//----------------------------------------------------------------------------
status INA226_Debug_GetConfigRegister(INA226* this, uint16_t* aConfigReg_p)
{
	CHECK_INITIALIZED();
	//Read the configuration register
	return INA226_ReadRegister(this,INA226_CONFIG, aConfigReg_p);
}