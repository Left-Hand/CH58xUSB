#pragma once

#include "sys/core/platform.h"


scexpr uint8_t mouse_descr[] = {
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01, 0xA1, 0x00, 0x05, 0x09, 0x19, 0x01, 0x29,
    0x03, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01, 0x95, 0x03, 0x81, 0x02, 0x75, 0x05, 0x95, 0x01,
    0x81, 0x01, 0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x09, 0x38, 0x15, 0x81, 0x25, 0x7f, 0x75,
    0x08, 0x95, 0x03, 0x81, 0x06, 0xC0, 0xC0}; 

scexpr uint8_t keyboard_descr[] = {
    0x05, 0x01, 0x09, 0x06, 0xA1, 0x01, 0x05, 0x07, 0x19, 0xe0, 0x29, 0xe7, 0x15, 0x00, 0x25,
    0x01, 0x75, 0x01, 0x95, 0x08, 0x81, 0x02, 0x95, 0x01, 0x75, 0x08, 0x81, 0x01, 0x95, 0x03,
    0x75, 0x01, 0x05, 0x08, 0x19, 0x01, 0x29, 0x03, 0x91, 0x02, 0x95, 0x05, 0x75, 0x01, 0x91,
    0x01, 0x95, 0x06, 0x75, 0x08, 0x26, 0xff, 0x00, 0x05, 0x07, 0x19, 0x00, 0x29, 0x91, 0x81,
    0x00, 0xC0}; 

scexpr uint8_t joystick_descr[] = {
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x04,        // Usage (Joystick)
    0xA1, 0x01,        // Collection (Application)
    0x05, 0x02,        //   Usage Page (Sim Ctrls)
    0x09, 0xBB,        //   Usage (Throttle)
    0x15, 0x81,        //   Logical Minimum (-127)
    0x25, 0x7F,        //   Logical Maximum (127)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
    0x09, 0x01,        //   Usage (Pointer)
    0xA1, 0x00,        //   Collection (Physical)
    0x09, 0x30,        //     Usage (X)
    0x09, 0x31,        //     Usage (Y)
    0x95, 0x02,        //     Report Count (2)
    0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,              //   End Collection
    0x09, 0x39,        //   Usage (Hat switch)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x03,        //   Logical Maximum (3)
    0x35, 0x00,        //   Physical Minimum (0)
    0x46, 0x0E, 0x01,  //   Physical Maximum (270)
    0x65, 0x04,        //   Unit (System: English Rotation)
    0x55, 0x00,        //   Unit Exponent (0)
    0x75, 0x04,        //   Report Size (4)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (0x01)
    0x29, 0x04,        //   Usage Maximum (0x04)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x35, 0x00,        //   Physical Minimum (0)
    0x45, 0x01,        //   Physical Maximum (1)
    0x95, 0x04,        //   Report Count (4)
    0x75, 0x01,        //   Report Size (1)
    0x64,              //   Unit
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,              // End Collection
};


// scexpr uint8_t touchpad_descr[] = {
// //TOUCH PAD input TLC
//     0x05, 0x0d,                         // USAGE_PAGE (Digitizers)          
//     0x09, 0x05,                         // USAGE (Touch Pad)             
//     0xa1, 0x01,                         // COLLECTION (Application)         
//     0x85, REPORTID_TOUCHPAD,            //   REPORT_ID (Touch pad)              
//     0x09, 0x22,                         //   USAGE (Finger)                 
//     0xa1, 0x02,                         //   COLLECTION (Logical)  
//     0x15, 0x00,                         //       LOGICAL_MINIMUM (0)
//     0x25, 0x01,                         //       LOGICAL_MAXIMUM (1)
//     0x09, 0x47,                         //       USAGE (Confidence) 
//     0x09, 0x42,                         //       USAGE (Tip switch)
//     0x95, 0x02,                         //       REPORT_COUNT (2)
//     0x75, 0x01,                         //       REPORT_SIZE (1)
//     0x81, 0x02,                         //       INPUT (Data,Var,Abs)
//     0x95, 0x01,                         //       REPORT_COUNT (1)
//     0x75, 0x02,                         //       REPORT_SIZE (2)
//     0x25, 0x02,                         //       LOGICAL_MAXIMUM (2)
//     0x09, 0x51,                         //       USAGE (Contact Identifier)
//     0x81, 0x02,                         //       INPUT (Data,Var,Abs)
//     0x75, 0x01,                         //       REPORT_SIZE (1)
//     0x95, 0x04,                         //       REPORT_COUNT (4)             
//     0x81, 0x03,                         //       INPUT (Cnst,Var,Abs)
//     0x05, 0x01,                         //       USAGE_PAGE (Generic Desk..
//     0x15, 0x00,                         //       LOGICAL_MINIMUM (0)
//     0x26, 0xff, 0x0f,                   //       LOGICAL_MAXIMUM (4095)         
//     0x75, 0x10,                         //       REPORT_SIZE (16)             
//     0x55, 0x0e,                         //       UNIT_EXPONENT (-2)           
//     0x65, 0x13,                         //       UNIT(Inch,EngLinear)                  
//     0x09, 0x30,                         //       USAGE (X)                    
//     0x35, 0x00,                         //       PHYSICAL_MINIMUM (0)         
//     0x46, 0x90, 0x01,                   //       PHYSICAL_MAXIMUM (400)
//     0x95, 0x01,                         //       REPORT_COUNT (1)         
//     0x81, 0x02,                         //       INPUT (Data,Var,Abs)         
//     0x46, 0x13, 0x01,                   //       PHYSICAL_MAXIMUM (275)
//     0x09, 0x31,                         //       USAGE (Y)                    
//     0x81, 0x02,                         //       INPUT (Data,Var,Abs)    
//     0xc0,                               //    END_COLLECTION
//     0x55, 0x0C,                         //    UNIT_EXPONENT (-4)           
//     0x66, 0x01, 0x10,                   //    UNIT (Seconds)        
//     0x47, 0xff, 0xff, 0x00, 0x00,      //     PHYSICAL_MAXIMUM (65535)
//     0x27, 0xff, 0xff, 0x00, 0x00,         //  LOGICAL_MAXIMUM (65535) 
//     0x75, 0x10,                           //  REPORT_SIZE (16)             
//     0x95, 0x01,                           //  REPORT_COUNT (1) 
//     0x05, 0x0d,                         //    USAGE_PAGE (Digitizers)
//     0x09, 0x56,                         //    USAGE (Scan Time)    
//     0x81, 0x02,                           //  INPUT (Data,Var,Abs)         
//     0x09, 0x54,                         //    USAGE (Contact count)
//     0x25, 0x7f,                           //  LOGICAL_MAXIMUM (127) 
//     0x95, 0x01,                         //    REPORT_COUNT (1)
//     0x75, 0x08,                         //    REPORT_SIZE (8)    
//     0x81, 0x02,                         //    INPUT (Data,Var,Abs)
//     0x05, 0x09,                         //    USAGE_PAGE (Button)         
//     0x09, 0x01,                         //    USAGE_(Button 1)     
//     0x25, 0x01,                         //    LOGICAL_MAXIMUM (1)          
//     0x75, 0x01,                         //    REPORT_SIZE (1)              
//     0x95, 0x01,                         //    REPORT_COUNT (1)             
//     0x81, 0x02,                         //    INPUT (Data,Var,Abs)
//     0x95, 0x07,                          //   REPORT_COUNT (7)                 
//     0x81, 0x03,                         //    INPUT (Cnst,Var,Abs)
//     0x05, 0x0d,                         //    USAGE_PAGE (Digitizer)
//     0x85, REPORTID_MAX_COUNT,            //   REPORT_ID (Feature)              
//     0x09, 0x55,                         //    USAGE (Contact Count Maximum)
//     0x09, 0x59,                         //    USAGE (Pad TYpe)
//     0x75, 0x04,                         //    REPORT_SIZE (4) 
//     0x95, 0x02,                         //    REPORT_COUNT (2)
//     0x25, 0x0f,                         //    LOGICAL_MAXIMUM (15)
//     0xb1, 0x02,                         //    FEATURE (Data,Var,Abs)
//     0x06, 0x00, 0xff,                   //    USAGE_PAGE (Vendor Defined)
//     0x85, REPORTID_PTPHQA,               //    REPORT_ID (PTPHQA)  
//     0x09, 0xC5,                         //    USAGE (Vendor Usage 0xC5)    
//     0x15, 0x00,                         //    LOGICAL_MINIMUM (0)          
//     0x26, 0xff, 0x00,                   //    LOGICAL_MAXIMUM (0xff) 
//     0x75, 0x08,                         //    REPORT_SIZE (8)             
//     0x96, 0x00, 0x01,                   //    REPORT_COUNT (0x100 (256))             
//     0xb1, 0x02,                         //    FEATURE (Data,Var,Abs)
//     0xc0,                               // END_COLLECTION
//     //CONFIG TLC
//     0x05, 0x0d,                         //    USAGE_PAGE (Digitizer)
//     0x09, 0x0E,                         //    USAGE (Configuration)
//     0xa1, 0x01,                         //   COLLECTION (Application)
//     0x85, REPORTID_FEATURE,             //   REPORT_ID (Feature)              
//     0x09, 0x22,                         //   USAGE (Finger)              
//     0xa1, 0x02,                         //   COLLECTION (logical)     
//     0x09, 0x52,                         //    USAGE (Input Mode)         
//     0x15, 0x00,                         //    LOGICAL_MINIMUM (0)      
//     0x25, 0x0a,                         //    LOGICAL_MAXIMUM (10)
//     0x75, 0x08,                         //    REPORT_SIZE (8)         
//     0x95, 0x01,                         //    REPORT_COUNT (1)         
//     0xb1, 0x02,                         //    FEATURE (Data,Var,Abs    
//     0xc0,                               //   END_COLLECTION
//     0x09, 0x22,                         //   USAGE (Finger)              
//     0xa1, 0x00,                         //   COLLECTION (physical)     
//     0x85, REPORTID_FUNCTION_SWITCH,     //     REPORT_ID (Feature)              
//     0x09, 0x57,                         //     USAGE(Surface switch)
//     0x09, 0x58,                         //     USAGE(Button switch)
//     0x75, 0x01,                         //     REPORT_SIZE (1)
//     0x95, 0x02,                         //     REPORT_COUNT (2)
//     0x25, 0x01,                         //     LOGICAL_MAXIMUM (1)
//     0xb1, 0x02,                         //     FEATURE (Data,Var,Abs)
//     0x95, 0x06,                         //     REPORT_COUNT (6)             
//     0xb1, 0x03,                         //     FEATURE (Cnst,Var,Abs)
//     0xc0,                               //   END_COLLECTION
//     0xc0,                               // END_COLLECTION
//     //MOUSE TLC
//     0x05, 0x01,                         // USAGE_PAGE (Generic Desktop)     
//     0x09, 0x02,                         // USAGE (Mouse)                    
//     0xa1, 0x01,                         // COLLECTION (Application)        
//     0x85, REPORTID_MOUSE,               //   REPORT_ID (Mouse)              
//     0x09, 0x01,                         //   USAGE (Pointer)                
//     0xa1, 0x00,                         //   COLLECTION (Physical)          
//     0x05, 0x09,                         //     USAGE_PAGE (Button)          
//     0x19, 0x01,                         //     USAGE_MINIMUM (Button 1)     
//     0x29, 0x02,                         //     USAGE_MAXIMUM (Button 2)     
//     0x25, 0x01,                         //     LOGICAL_MAXIMUM (1)          
//     0x75, 0x01,                         //     REPORT_SIZE (1)              
//     0x95, 0x02,                         //     REPORT_COUNT (2)             
//     0x81, 0x02,                         //     INPUT (Data,Var,Abs)         
//     0x95, 0x06,                         //     REPORT_COUNT (6)             
//     0x81, 0x03,                         //     INPUT (Cnst,Var,Abs)         
//     0x05, 0x01,                         //     USAGE_PAGE (Generic Desktop) 
//     0x09, 0x30,                         //     USAGE (X)                    
//     0x09, 0x31,                         //     USAGE (Y)                    
//     0x75, 0x10,                         //     REPORT_SIZE (16)             
//     0x95, 0x02,                         //     REPORT_COUNT (2)             
//     0x25, 0x0a,                          //    LOGICAL_MAXIMUM (10)      
//     0x81, 0x06,                         //     INPUT (Data,Var,Rel)         
//     0xc0,                               //   END_COLLECTION                 
//     0xc0,                                //END_COLLECTION
// }