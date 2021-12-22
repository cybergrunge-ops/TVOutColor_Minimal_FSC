/* NabeRMC's original FullScreenColor with asm notes and renamed macros by cybergrunge.net 2021 */
#include "defINT.h"
#include "defColor.h"

//reminder: unsigned char is 8 bits of data like this: 0000 0000 , it represents data between 0 and 255
void CINT::SP_FSC( unsigned char Mode, unsigned char Sig0, unsigned char Sig90, unsigned char Sig180, unsigned char Sig270 ){ 
__asm__ __volatile(
        "mov r25,%0\n\t"        // mov: store mode(%0 operand) in r25
        "mov r24,%1\n\t"        // mov: store 0deg(%1 operand) in r24
        "cpi r25,2\n\t"  // cpi: compare mode with 2
        "brne NOTV\n\t"  // brne: if mode !=2 , keep going
        "jmp VSYNC\n\t"  // jmp: if mode==2, do VSYNC
"NOTV:"
        "ldi r26,7\n\t"         /* ldi: put 7 in r26 - Nabe:COLBST0    | 7 is the 0 IRE reference for video. binary is 0111  - - - | -*/
        "out 0x08,r18\n\t"      // output 0IRE                         |   1
        "ldi r27,3\n\t"         // ldi: put 3  in r27 - Nabe:COLBST1   |   2
        "ldi r30,7\n\t"         // ldi: put 7  in r30 - Nabe:COLBST2   |   3
        "ldi r31,11\n\t"        // ldi: put 11 in r31 - Nabe:COLBST3   |   4
        "mov r23,%2\n\t"        // r23: Sig_90deg                      |   5
        "mov r22,%3\n\t"        // r22: Sig_180deg                     |   6
        "mov r21,%4\n\t"        // r21: Sig_270deg                     |   7
//   "nop \n\t"              //                                     |   8
//   "nop \n\t"              //   probly for debugging timing       |   9
        "cbi 0x0B,2\n\t"        // Nabe:for debug trigger PORTD.2      |   8,9

    //color burst = 9 cycles of outputting r18 r19 r20 r21 to 0x08 - these registers are also used by SetCol
OutBurst OutBurst OutBurst OutBurst OutBurst OutBurst OutBurst OutBurst OutBurst

        "out 0x08,r26\n\t"      // 0IRE                                     |   1        
        "ldi r20,6\n\t"         // load immediate 6 into r20                |   2

"BP_LOOP:"                      // for Back Porch delay            cybergrunge says: i still don't get what front and back porch are really
        "dec r20\n\t"           // 1cycle                                  ||
        "brne BP_LOOP\n\t"      // 1/2      (1+2)*5+(1+1)=17               ||   19
        "ldi r26,7\n\t"         /* ldi: put 7 in r26 - Nabe:COLBST0         | 7 is the 0 IRE reference for video. binary is 0111  - - - | -*/
        "cpi r25,0\n\t"         // r25:Mode         1cycle                  |   21
        "brne DISP\n\t"         //if display frame  1cycle/2cycle           |   22/23
        "jmp EXIT\n\t"          //out of frame then exit

"DISP:"
        "nop \n\t"              //                                          |   24
        OutBlack                //                                          |   25
        OutBlack
        OutBlack
        OutBlack
        OutBlack
        OutBlack // probably more timing debug
        OutBlack // if timing is off try commenting or uncommenting
        OutBlack // some of these until the timing is right
        OutBlack
//      OutBlack
        "nop \n\t"
        "nop \n\t"
        "sbi 0x0B,2\n\t"        // for debug trigger PORTD.2
        
        OutColor  //outcolor macro outputs r24, r23, r22, r21 to 0x08
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        OutColor
        
"EXIT:" 

"EXIT2:"    //unused?
        "out 0x08,r26\n\t"      // 0IRE
"VSYNC:"  //same as EXIT?

        : // no output operands used
        : "r"(Mode) ,"r"(Sig0) ,"r"(Sig90),"r"(Sig180) ,"r"(Sig270) //input operands
        : // no clobber list used
    );
}



