/* full screen color - Copyleft @Nabe_RMC - re-engineered by cybergrunge.net */
#include "defINT.h"

CSYS objSYS;
void Ini_PT_FSC(void);
void Set_Color( unsigned char );
void Set_FSC_Color( unsigned char );
void AdjustColor( unsigned char );

void setup(){cli(); objSYS.Ini(); sei();}

void loop(){
  Ini_PT_FSC();
  objSYS.delay132( 20 ); 
}

/* colors   24,10,2,16,   9,13,27,23,   8,18,12,2,  24,20,6,10,   9,23,31,17,    25,15,21,31    25,25,25,25,   7,7,7,7 */
void Set_FSC_Color( unsigned char color ){ switch( color ){
  case COL_WHI: UB_Sig1 = 25; UB_Sig2 = 25; UB_Sig3 = 25; UB_Sig4 = 25; break;
  case COL_GRN: UB_Sig1 = 9;  UB_Sig2 = 13; UB_Sig3 = 27; UB_Sig4 = 23; break;
  case COL_BLU: UB_Sig1 = 8;  UB_Sig2 = 18; UB_Sig3 = 12; UB_Sig4 = 2;  break;
  case COL_MAG: UB_Sig1 = 24; UB_Sig2 = 20; UB_Sig3 = 6;  UB_Sig4 = 10; break;     
  case COL_CYN: UB_Sig1 = 9;  UB_Sig2 = 23; UB_Sig3 = 31; UB_Sig4 = 17; break;     
  case COL_YEL: UB_Sig1 = 25; UB_Sig2 = 15; UB_Sig3 = 21; UB_Sig4 = 31; break;     
  case COL_RED: UB_Sig1 = 24; UB_Sig2 = 10; UB_Sig3 = 2;  UB_Sig4 = 16; break; 
  case COL_BLK: UB_Sig1 = 7;  UB_Sig2 = 7;  UB_Sig3 = 7;  UB_Sig4 = 7;  break;
  default:      UB_Sig1 = 25; UB_Sig2 = 25; UB_Sig3 = 25; UB_Sig4 = 25; } }

void Ini_PT_FSC( void ) { cli();
    UB_ModePTN = FSC_MODE;     UB_ModePLS = FRM_OFF;   Set_FSC_Color( COL_GRN );
sei();}
