/* Copyright (C) 2010 Masami Watanabe---------------------------------------*/
#ifndef COMMON_H
#define COMMON_H


#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

typedef signed   char       SB;             /* signed    8bit               */
typedef unsigned char       UB;             /* unsigned  8bit               */

typedef signed   short      SH;             /* siged    16bit               */
typedef unsigned short      UH;             /* unsigned 16bit               */

typedef signed   long       SW;             /* signed   32bit               */
typedef unsigned long       UW;             /* unsined  32bit               */

typedef unsigned char       BL;             /* boolean                      */

#define ON      1
#define OFF     0
#define ERROR   (-1)
#define EOF	(-1)
#endif 
