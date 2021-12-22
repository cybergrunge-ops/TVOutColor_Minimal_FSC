/* Copyleft @Nabe_RMC ==*/
#define INT_INCLUDE
#include "defINT.h"

CINT::CINT(){Ini();} //this is initialize
unsigned char CINT::UBf_132ms_req = 0; //ugh idk

void CINT::Ini( void ){ //this is a function
    int i,k;
    UB_ModePTN = 0;
    UB_ModePLS = FRM_OFF;
    UH_hline = 0;
    UB_scanline = 0;
    UB_cg_line = 0;
    UB_row = 0;
    UH_AddrDataNow = 0;
    UBf_132ms_req = 0; 
}
unsigned char CINT::Check132ms(){
    if( UBf_132ms_req ==0 ){return( 0 );}
    else{ UBf_132ms_req =0; return( 1 );} }
