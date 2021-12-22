#include "defSYS.h"
#include "defINT.h"

CINT    objINT;

ISR (TIMER1_CAPT_vect){
  objINT.FitDelay( TCNT1L );      /* 割り込み遅延ばらつきの合わせ込み     Compensation of the variration in delay of interrupt */
    PORTC = 0; 
    objINT.Int_FSC(); 
  } /* -40IRE data    need at V-sync        */

void CINT::Int_FSC( void ){ // Normie version 
SP_FSC( UB_ModePLS, UB_Sig1, UB_Sig2, UB_Sig3, UB_Sig4); 
UH_hline++;
    if( UH_hline == (V_TXT_ST_C-1) ){UB_ModePLS = FRM_ON;}
    else if( UH_hline == V_TXT_END_C-1 ){UB_ModePLS = FRM_OFF;}
    else if( UH_hline == V_SYNC_END ){OCR1A = CRT_OCR1A_HS; UB_ModePLS = FRM_OFF;}
    else if( UH_hline == H_LINE_END ){UH_hline = 0;JobAsy();UB_ModePTN = 6;}
    else if( UH_hline == V_SYNC_START ){OCR1A  = CRT_OCR1A_VS;TCCR1A = CRT_TCCR1A;UB_ModePLS = FRM_VSYNC;} }


//normie stuff
void CINT::JobAsy(){static UB   UBCT_33ms = 0;UBCT_33ms++;if( ( UBCT_33ms %4 ) == 0 ){UBf_132ms_req = 1;}}

void CINT::ClearLineData(){UH_hline = 0;UB_scanline = 0;UB_cg_line = 0;}


