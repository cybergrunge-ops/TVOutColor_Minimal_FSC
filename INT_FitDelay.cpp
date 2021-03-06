#include "defINT.h"

void CINT::FitDelay( unsigned char UBdelay_time )
{   __asm__ __volatile__(       //          29      28      27      26      25      24      23      22  
        "cpi    %0,49\n\t"      // [1]      [1/1]   [1/1]   [1/1]   [1/1]   [1/1]   [1/1]   [1/1]   [1/1]
        "breq   L49\n\t"        // [1/2]    [2/3]   [1/2]   [1/2]   [1/2]   [1/2]   [1/2]   [1/2]   [1/2]
        "cpi    %0,48\n\t"      // [1]              [1/3]   [1/3]   [1/3]   [1/3]   [1/3]   [1/3]   [1/3]
        "breq   L48\n\t"        // [1/2]            [2/5]   [1/4]   [1/4]   [1/4]   [1/4]   [1/4]   [1/4]
        "cpi    %0,47\n\t"      // [1]                      [1/5]   [1/5]   [1/5]   [1/5]   [1/5]   [1/5]
        "breq   L47\n\t"        // [1/2]                    [2/7]   [1/6]   [1/6]   [1/6]   [1/6]   [1/6]
        "cpi    %0,46\n\t"      // [1]                              [1/7]   [1/7]   [1/7]   [1/7]   [1/7]
        "breq   L46\n\t"        // [1/2]                            [2/9]   [1/8]   [1/8]   [1/8]   [1/8]
        "cpi    %0,45\n\t"      // [1]                                      [1/9]   [1/9]   [1/9]   [1/9]
        "breq   L45\n\t"        // [1/2]                                    [2/11]  [1/10]  [1/10]  [1/10]
        "cpi    %0,44\n\t"      // [1]                                              [1/11]  [1/11]  [1/11]
        "breq   L44\n\t"        // [1/2]                                            [2/13]  [1/12]  [1/12]
        "cpi    %0,43\n\t"      // [1]                                                      [1/13]  [1/13]
        "breq   L43\n\t"        // [1/2]                                                    [2/15]  [1/14]
        "cpi    %0,42\n\t"      // [1]                                                              [1/15]
        "breq   L42\n\t"        // [1/2]                                                            [2/17]
        
        "L49:\n\t"
        "nop\n\t"               // +8       +3=11
        "L48:\n\t"              //          +29=40
        "nop\n\t"               // +7               +5=12
        "L47:\n\t"              //                  +28=40
        "nop\n\t"               // +6                       +7=13
        "L46:\n\t"              //                          +27=40
        "nop\n\t"               // +5                               +9=14
        "L45:\n\t"              //                                  +26=40
        "nop\n\t"               // +4                                       +11=15
        "L44:\n\t"              //                                          +25=40
        "nop\n\t"               // +3                                               +13=16
        "L43:\n\t"              //                                                  +24=40
        "nop\n\t"               // +2                                                       +15=17
        "L42:\n\t"              //                                                          +23=40
        "nop\n\t"               // +1                                                               +17=18
                                //                                                                  +22=40
        
        :                       // ???????????????????????????????????????????????????
        : "r"(UBdelay_time)     // ?????????????????????????????????????????????C??????
        :                       // ?????????????????????
                                // ?????????????????????????????????????????????????????????????????????????????????
                                // ???????????????????????????????????????????????????
    );

}
    
    
    
