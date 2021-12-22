/* Copyleft @Nabe_RMC-------- mostly left this alone except got rid of nabe's typedefs that confused me-*/
#ifdef      INT_INCLUDE
#define     INT_EXT 
#else
#define     INT_EXT extern
#endif

#define FL_COL_MAX          ( COL_MAX *2 )
#define FL_COL_MAX_TXT      ( COL_MAX_TXT *2 )
#define FL_COL_MAX_BLK      ( COL_MAX_BLK *2 )
#define COL_MAX             12      /* number of characters per line        */
#define COL_MAX_TXT         10
#define COL_MAX_BLK         12
#define ROW_MAX             10      /* display number of lines available    */
#define ROW_MAX_TXT         12
#define ROW_MAX_BLK         20
#define LINE_MAX_TXT        10      /* 5*7 font line space = LINE_MAX -7-1  */
#define CG_LINE_MAX_TXT     14
#define TXT_SIZE_TXT        ( ROW_MAX_TXT * FL_COL_MAX_TXT )
#define TXT_SIZE_BLK        ( ROW_MAX_BLK * FL_COL_MAX_BLK )
#if ( TXT_SIZE_TXT > TXT_SIZE_BLK )
#define TXT_SIZE    TXT_SIZE_TXT
#else
#define TXT_SIZE    TXT_SIZE_BLK
#endif
INT_EXT unsigned char  vram_data[TXT_SIZE];
#define LINE_SIZE_TXT       ( COL_MAX_TXT*8  * ROW_MAX_TXT )
#define LINE_SIZE_BLK       ( FL_COL_MAX_BLK * ROW_MAX_BLK )

#if ( LINE_SIZE_TXT > LINE_SIZE_BLK )
#define LINE_SIZE   LINE_SIZE_TXT
#else
#define LINE_SIZE   LINE_SIZE_BLK
#endif

INT_EXT unsigned char vram_line[LINE_SIZE];

#define FRM_OFF             0       /* only H-Sync                          */
#define FRM_ON              1       /* Display Frame line                   */
#define FRM_VSYNC           2       /* V-Sync line                          */
#define FSC_MODE            0x06
#define V_SYNC_START        4
#define V_SYNC_END          7
#define V_BLANK             20
#define V_FRM_TOP           60
#define V_FRM_END           220
#define H_LINE_END          262
#define V_TXT_END       ( V_FRM_TOP + LINE_MAX_TXT * ROW_MAX_TXT )
#define V_START_VRAM    ( V_TXT_END )
#define V_TXT_START_B   ( V_FRM_TOP )
#define V_TXT_END_B     ( V_TXT_START_B + CG_LINE_MAX_TXT * ROW_MAX_TXT )
#define V_TXT_ST_C      ( V_FRM_TOP )
#define V_TXT_END_C     ( V_FRM_TOP + 8 * ROW_MAX_BLK -1 )
INT_EXT unsigned char  UB_CMD_SetVram;
INT_EXT unsigned char  UB_ModePLS;
INT_EXT unsigned char  UB_ModePTN;
INT_EXT unsigned char  UB_ModePTN_BF;
INT_EXT unsigned char  UB_Sig1;
INT_EXT unsigned char  UB_Sig2;
INT_EXT unsigned char  UB_Sig3;
INT_EXT unsigned char  UB_Sig4;
INT_EXT unsigned char  UB_Color;
INT_EXT unsigned char  UB_ColorN[ROW_MAX_BLK]; 
INT_EXT unsigned char  UB_ColorN_ODD[ROW_MAX_BLK];
INT_EXT unsigned short UH_AddrData_n;
INT_EXT unsigned short UH_AddrData_n_ODD;
INT_EXT unsigned short UH_AddrDataNow;
INT_EXT unsigned short UH_AddrDataNow_ODD;

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#define CRT_TCCR1A      0xC2        /* inv.,fast PWM            1100_xx10B  */
#define CRT_TCCR1A_P    0x02        /* cut OC1-normal Port out  0000_xx10B  */
#define CRT_TCCR1B      0x19        /* non divide               xx-1_1001B  */
                                    /* WGM 13 12 11 10                      */
                                    /*      1  1  1  0 - high PWM           */
#define CRT_TCCR1C      0x00        /* initial value            00--_----B  */
#define CRT_TCNT1       0x0000      /* initial value  0000_0000_0000_0000B  */
#define CRT_OCR1B       0x0000      /* initial value  0000_0000_0000_0000B  */
#define XTAL1431818

#ifdef XTAL1431818
#define CRT_ICR1        907        /* 4*227-1,(1/14.318MHz)*(907+1)=63.416us*/
#define CRT_OCR1A_HS    67         /* (1/14.31818MHz)×67 = 4.679us         */
#define CRT_OCR1A_VS    (907- 67)
#else
#define CRT_ICR1        1017        /* (1/16MHz) × (1017+1) = 63.625us     */
#define CRT_OCR1A_HS    75          /* (1/16MHz)×75 = 4.6875us             */
#define CRT_OCR1A_VS    (1017- 75)
#endif
#define P_LED1_ON       asm volatile("cbi 0x05,5"::)    /* PORTB.5          */
#define P_LED1_OFF      asm volatile("sbi 0x05,5"::)
#define P_DBG1_ON       asm volatile("cbi 0x0B,2"::)    /* PORTD.2          */
#define P_DBG1_OFF      asm volatile("sbi 0x0B,2"::)
#define P_DBG2_ON       asm volatile("cbi 0x0B,7"::)    /* PORTD.7          */
#define P_DBG2_OFF      asm volatile("sbi 0x0B,7"::)
/* --- in/out/data ---------------------------------------------------------*/
#define INI_DDRB    0x22        /*                              0010_0010B  */
#define OR_DDRB     0x22        /*                              0010_0010B  */
#define INI_PORTB   0x00        /*                              0000_0000B  */
#define AND_PORTB   0xDD        /*                              1101_1101B  */
#define INI_DDRC    0x1F        /*                              0001_1111B  */
#define OR_DDRC     0x1F        /*                              0001_1111B  */
#define INI_PORTC   0x00        /*                              0000_0000B  */
#define AND_PORTC   0           /*                              1110_0000B  */
#define INI_DDRD    0x8C        /*                              1000_1100B  */
#define OR_DDRD     0x84        /*                              1000_0100B  */
#define INI_PORTD   0x00        /*                              0000_0000B  */
#define AND_PORTD   0x7B        /*                              0111_1011B  */
#define COL_WHI     0
#define COL_GRN     1
#define COL_BLU     2
#define COL_MAG     3
#define COL_CYN     4
#define COL_YEL     5
#define COL_RED     6
#define COL_BLK     7
#define CLM FL_COL_MAX_BLK
/* ----- interrupt ---------------------------------------------------------*/
#define INI_TIMSK1  0x20    /* Timer/Counter1 Interrupt Mask Register       */
                            /* enable ICE1                      0010_0000B  */
#define ON      1
#define OFF     0
#define ERROR   (-1)
#define EOF	(-1)

class CINT{ 
  public: CINT();                         /* constructor for initializing         */
    void Ini();
    void ExecFunc(unsigned char);
    void FitDelay(unsigned char);
    void JobAsy();
    unsigned char Check132ms();
    void Int_FSC();
    void SP_FSC( unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    void ClearLineData();
private:
    unsigned char UH_TCNT1;
    unsigned char UH_hline;
    unsigned char UB_hline;
    unsigned char UB_hline_ovf;
    unsigned char UB_scanline;
    unsigned char UB_row;
    unsigned char UB_cg_line;
    static unsigned char UBf_132ms_req;
};

class CSYS{
public:
    CSYS();
    void Ini();
    void delay132(unsigned char);
    void IniUART();
private:
    static void IniPort();
    static void IniTimer();
    static void IniINT();
};
