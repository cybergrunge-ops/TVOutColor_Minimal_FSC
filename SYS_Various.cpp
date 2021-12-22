/* Copyleft @Nabe_RMC */
#define SYS_INCLUDE
#include "defSYS.h"
#include "defINT.h"

CINT SobjINT;
CSYS::CSYS(){}

void SetVram(){ 
unsigned short line, column, row;   
unsigned short row_top, line_top; 
unsigned short data_row_top; 
unsigned short tmp1, tmp2, tmp3; 
unsigned char  col_evn, col_odd;   
unsigned short i, j, k;
UB_CMD_SetVram = 0; }

void CSYS::Ini(){ // system setup : ports, interrupt, timer
PORTB &= AND_PORTB; DDRB |= OR_DDRB; PORTC   &= AND_PORTC; DDRC |= OR_DDRC; PORTD &= AND_PORTD; DDRD |= OR_DDRD;
TCCR1A = CRT_TCCR1A; TCCR1B = CRT_TCCR1B; OCR1A  = CRT_OCR1A_HS; ICR1   = CRT_ICR1;
TIMSK1 = INI_TIMSK1; TIMSK0 = 0;}

/*  Delay 132ms  ----------------------------------------*/
void CSYS::delay132( unsigned char count ){ while( count != 0 ){ while( SobjINT.Check132ms() == 0 ){ SetVram(); } count--; } }
