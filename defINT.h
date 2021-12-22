/* Copyleft @Nabe_RMC-------- mostly left this alone except got rid of nabe's typedefs that confused me-*/
#ifdef      INT_INCLUDE
#define     INT_EXT 
#else
#define     INT_EXT extern
#endif

#ifndef     COMMON_H
#include    "nabe_common.h"
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


