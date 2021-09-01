﻿/*
 * FONT1.h
 *
 * Created: 1/9/2021 12:32:32
 *  Author: Nicolás
 */ 


#ifndef FONT1_H_
#define FONT1_H_

#include <AVR/pgmspace.h>

const unsigned char	ASCII20[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	// Char 032 ( )
const unsigned char	ASCII21[] PROGMEM= {0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x00};	// Char 033 (!)
const unsigned char	ASCII22[] PROGMEM= {0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00};	// Char 034 (")
const unsigned char	ASCII23[] PROGMEM= {0x0A, 0x0A, 0x1F, 0x0A, 0x1F, 0x0A, 0x0A, 0x00};	// Char 035 (#)
const unsigned char	ASCII24[] PROGMEM= {0x04, 0x0F, 0x14, 0x0E, 0x05, 0x1E, 0x04, 0x00};	// Char 036 ($)
const unsigned char	ASCII25[] PROGMEM= {0x18, 0x19, 0x02, 0x04, 0x08, 0x13, 0x03, 0x00};	// Char 037 (%)
const unsigned char	ASCII26[] PROGMEM= {0x0C, 0x12, 0x14, 0x08, 0x15, 0x12, 0x0D, 0x00};	// Char 038 (&)
const unsigned char	ASCII27[] PROGMEM= {0x0C, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00};	// Char 039 (')
const unsigned char	ASCII28[] PROGMEM= {0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02, 0x00};	// Char 040 (()
const unsigned char	ASCII29[] PROGMEM= {0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08, 0x00};	// Char 041 ())
const unsigned char	ASCII2A[] PROGMEM= {0x00, 0x04, 0x15, 0x0E, 0x15, 0x04, 0x00, 0x00};	// Char 042 (*)
const unsigned char	ASCII2B[] PROGMEM= {0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00, 0x00};	// Char 043 (+)
const unsigned char	ASCII2C[] PROGMEM= {0x00, 0x00, 0x00, 0x00, 0x0C, 0x04, 0x08, 0x00};	// Char 044 (,)
const unsigned char	ASCII2D[] PROGMEM= {0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00};	// Char 045 (-)
const unsigned char	ASCII2E[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00};	// Char 046 (.)
const unsigned char	ASCII2F[] PROGMEM= {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x00, 0x00};	// Char 047 (/)
const unsigned char	ASCII30[] PROGMEM= {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E, 0x00};	// Char 048 (0)
const unsigned char	ASCII31[] PROGMEM= {0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00};	// Char 049 (1)
const unsigned char	ASCII32[] PROGMEM= {0x0E, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F, 0x00};	// Char 050 (2)
const unsigned char	ASCII33[] PROGMEM= {0x1F, 0x02, 0x04, 0x02, 0x01, 0x11, 0x0E, 0x00};	// Char 051 (3)
const unsigned char	ASCII34[] PROGMEM= {0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02, 0x00};	// Char 052 (4)
const unsigned char	ASCII35[] PROGMEM= {0x1F, 0x10, 0x1E, 0x01, 0x01, 0x11, 0x0E, 0x00};	// Char 053 (5)
const unsigned char	ASCII36[] PROGMEM= {0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E, 0x00};	// Char 054 (6)
const unsigned char	ASCII37[] PROGMEM= {0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08, 0x00};	// Char 055 (7)
const unsigned char	ASCII38[] PROGMEM= {0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E, 0x00};	// Char 056 (8)
const unsigned char	ASCII39[] PROGMEM= {0x0E, 0x11, 0x11, 0x0F, 0x01, 0x02, 0x0C, 0x00};	// Char 057 (9)
const unsigned char	ASCII3A[] PROGMEM= {0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00};	// Char 058 (:)
const unsigned char	ASCII3B[] PROGMEM= {0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x04, 0x08, 0x00};	// Char 059 (;)
const unsigned char	ASCII3C[] PROGMEM= {0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02, 0x00};	// Char 060 (<)
const unsigned char	ASCII3D[] PROGMEM= {0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x00};	// Char 061 (=)
const unsigned char	ASCII3E[] PROGMEM= {0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x00};	// Char 062 (>)
const unsigned char	ASCII3F[] PROGMEM= {0x0E, 0x11, 0x01, 0x02, 0x04, 0x00, 0x04, 0x00};	// Char 063 (?)
const unsigned char	ASCII40[] PROGMEM= {0x0E, 0x11, 0x01, 0x0D, 0x15, 0x15, 0x0E, 0x00};	// Char 064 (@)
const unsigned char	ASCII41[] PROGMEM= {0x0E, 0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x00};	// Char 065 (A)
const unsigned char	ASCII42[] PROGMEM= {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E, 0x00};	// Char 066 (B)
const unsigned char	ASCII43[] PROGMEM= {0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E, 0x00};	// Char 067 (C)
const unsigned char	ASCII44[] PROGMEM= {0x1C, 0x12, 0x11, 0x11, 0x11, 0x12, 0x1C, 0x00};	// Char 068 (D)
const unsigned char	ASCII45[] PROGMEM= {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F, 0x00};	// Char 069 (E)
const unsigned char	ASCII46[] PROGMEM= {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10, 0x00};	// Char 070 (F)
const unsigned char	ASCII47[] PROGMEM= {0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0F, 0x00};	// Char 071 (G)
const unsigned char	ASCII48[] PROGMEM= {0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x00};	// Char 072 (H)
const unsigned char	ASCII49[] PROGMEM= {0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00};	// Char 073 (I)
const unsigned char	ASCII4A[] PROGMEM= {0x07, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0C, 0x00};	// Char 074 (J)
const unsigned char	ASCII4B[] PROGMEM= {0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11, 0x00};	// Char 075 (K)
const unsigned char	ASCII4C[] PROGMEM= {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F, 0x00};	// Char 076 (L)
const unsigned char	ASCII4D[] PROGMEM= {0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11, 0x00};	// Char 077 (M)
const unsigned char	ASCII4E[] PROGMEM= {0x11, 0x19, 0x15, 0x13, 0x11, 0x11, 0x11, 0x00};	// Char 078 (N)
const unsigned char	ASCII4F[] PROGMEM= {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00};	// Char 079 (O)
const unsigned char	ASCII50[] PROGMEM= {0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10, 0x00};	// Char 080 (P)
const unsigned char	ASCII51[] PROGMEM= {0x0E, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0D, 0x00};	// Char 081 (Q)
const unsigned char	ASCII52[] PROGMEM= {0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11, 0x00};	// Char 082 (R)
const unsigned char	ASCII53[] PROGMEM= {0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E, 0x00};	// Char 083 (S)
const unsigned char	ASCII54[] PROGMEM= {0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00};	// Char 084 (T)
const unsigned char	ASCII55[] PROGMEM= {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00};	// Char 085 (U)
const unsigned char	ASCII56[] PROGMEM= {0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04, 0x00};	// Char 086 (V)
const unsigned char	ASCII57[] PROGMEM= {0x11, 0x11, 0x11, 0x15, 0x15, 0x14, 0x0A, 0x00};	// Char 087 (W)
const unsigned char	ASCII58[] PROGMEM= {0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11, 0x00};	// Char 088 (X)
const unsigned char	ASCII59[] PROGMEM= {0x11, 0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x00};	// Char 089 (Y)
const unsigned char	ASCII5A[] PROGMEM= {0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F, 0x00};	// Char 090 (Z)
const unsigned char	ASCII5B[] PROGMEM= {0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E, 0x00};	// Char 091 ([)
const unsigned char	ASCII5C[] PROGMEM= {0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00};	// Char 092 (\)
const unsigned char	ASCII5D[] PROGMEM= {0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E, 0x00};	// Char 093 (])
const unsigned char	ASCII5E[] PROGMEM= {0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00};	// Char 094 (^)
const unsigned char	ASCII5F[] PROGMEM= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00};	// Char 095 (_)
const unsigned char	ASCII60[] PROGMEM= {0x10, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00};	// Char 096 (`)
const unsigned char	ASCII61[] PROGMEM= {0x00, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x00};	// Char 097 (a)
const unsigned char	ASCII62[] PROGMEM= {0x10, 0x10, 0x10, 0x16, 0x19, 0x11, 0x1E, 0x00};	// Char 098 (b)
const unsigned char	ASCII63[] PROGMEM= {0x00, 0x00, 0x0E, 0x10, 0x10, 0x11, 0x0E, 0x00};	// Char 099 (c)
const unsigned char	ASCII64[] PROGMEM= {0x01, 0x01, 0x01, 0x0D, 0x13, 0x11, 0x0F, 0x00};	// Char 100 (d)
const unsigned char	ASCII65[] PROGMEM= {0x00, 0x00, 0x0E, 0x11, 0x1F, 0x10, 0x0E, 0x00};	// Char 101 (e)
const unsigned char	ASCII66[] PROGMEM= {0x06, 0x09, 0x08, 0x1C, 0x08, 0x08, 0x08, 0x00};	// Char 102 (f)
const unsigned char	ASCII67[] PROGMEM= {0x00, 0x0F, 0x11, 0x11, 0x0F, 0x01, 0x0E, 0x00};	// Char 103 (g)
const unsigned char	ASCII68[] PROGMEM= {0x10, 0x10, 0x16, 0x19, 0x11, 0x11, 0x11, 0x00};	// Char 104 (h)
const unsigned char	ASCII69[] PROGMEM= {0x00, 0x00, 0x04, 0x00, 0x04, 0x04, 0x04, 0x00};	// Char 105 (i)
const unsigned char	ASCII6A[] PROGMEM= {0x02, 0x00, 0x06, 0x02, 0x02, 0x12, 0x0C, 0x00};	// Char 106 (j)
const unsigned char	ASCII6B[] PROGMEM= {0x10, 0x10, 0x12, 0x14, 0x18, 0x14, 0x12, 0x00};	// Char 107 (k)
const unsigned char	ASCII6C[] PROGMEM= {0x0C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00};	// Char 108 (l)
const unsigned char	ASCII6D[] PROGMEM= {0x00, 0x00, 0x1A, 0x15, 0x15, 0x11, 0x11, 0x00};	// Char 109 (m)
const unsigned char	ASCII6E[] PROGMEM= {0x00, 0x00, 0x16, 0x19, 0x11, 0x11, 0x11, 0x00};	// Char 110 (n)
const unsigned char	ASCII6F[] PROGMEM= {0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00};	// Char 111 (o)
const unsigned char	ASCII70[] PROGMEM= {0x00, 0x00, 0x1E, 0x11, 0x1E, 0x10, 0x10, 0x00};	// Char 112 (p)
const unsigned char	ASCII71[] PROGMEM= {0x00, 0x00, 0x0D, 0x13, 0x0F, 0x01, 0x01, 0x00};	// Char 113 (q)
const unsigned char	ASCII72[] PROGMEM= {0x00, 0x00, 0x16, 0x19, 0x10, 0x10, 0x10, 0x00};	// Char 114 (r)
const unsigned char	ASCII73[] PROGMEM= {0x00, 0x00, 0x0E, 0x10, 0x0E, 0x01, 0x1E, 0x00};	// Char 115 (s)
const unsigned char	ASCII74[] PROGMEM= {0x08, 0x08, 0x1C, 0x08, 0x08, 0x09, 0x06, 0x00};	// Char 116 (t)
const unsigned char	ASCII75[] PROGMEM= {0x00, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0D, 0x00};	// Char 117 (u)
const unsigned char	ASCII76[] PROGMEM= {0x00, 0x00, 0x11, 0x11, 0x11, 0x0A, 0x04, 0x00};	// Char 118 (v)
const unsigned char	ASCII77[] PROGMEM= {0x00, 0x00, 0x11, 0x11, 0x11, 0x15, 0x0A, 0x00};	// Char 119 (w)
const unsigned char	ASCII78[] PROGMEM= {0x00, 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00};	// Char 120 (x)
const unsigned char	ASCII79[] PROGMEM= {0x00, 0x00, 0x11, 0x11, 0x0F, 0x01, 0x0E, 0x00};	// Char 121 (y)
const unsigned char	ASCII7A[] PROGMEM= {0x00, 0x00, 0x1F, 0x02, 0x04, 0x08, 0x1F, 0x00};	// Char 122 (z)
const unsigned char	ASCII7B[] PROGMEM= {0x02, 0x04, 0x04, 0x08, 0x04, 0x04, 0x02, 0x00};	// Char 123 ({)
const unsigned char	ASCII7C[] PROGMEM= {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00};	// Char 124 (|)
const unsigned char	ASCII7D[] PROGMEM= {0x08, 0x04, 0x04, 0x02, 0x04, 0x04, 0x08, 0x00};	// Char 125 (})
const unsigned char	ASCII7E[] PROGMEM= {0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00, 0x00};	// Char 126 (>)
const unsigned char	ASCII7F[] PROGMEM= {0x00, 0x04, 0x08, 0x1F, 0x08, 0x04, 0x00, 0x00};	// Char 127 (<)

const unsigned char * const ROMCHAR[] PROGMEM = {ASCII20, ASCII21, ASCII22, ASCII23, ASCII24, ASCII25, ASCII26, ASCII27,
												ASCII28, ASCII29, ASCII2A, ASCII2B, ASCII2C, ASCII2D, ASCII2E, ASCII2F,
												ASCII30, ASCII31, ASCII32, ASCII33, ASCII34, ASCII35, ASCII36, ASCII37,
												ASCII38, ASCII39, ASCII3A, ASCII3B, ASCII3C, ASCII3D, ASCII3E, ASCII3F,
												ASCII40, ASCII41, ASCII42, ASCII43, ASCII44, ASCII45, ASCII46, ASCII47,
												ASCII48, ASCII49, ASCII4A, ASCII4B, ASCII4C, ASCII4D, ASCII4E, ASCII4F,
												ASCII50, ASCII51, ASCII52, ASCII53, ASCII54, ASCII55, ASCII56, ASCII57,
												ASCII58, ASCII59, ASCII5A, ASCII5B, ASCII5C, ASCII5D, ASCII5E, ASCII5F,
												ASCII60, ASCII61, ASCII62, ASCII63, ASCII64, ASCII65, ASCII66, ASCII67,
												ASCII68, ASCII69, ASCII6A, ASCII6B, ASCII6C, ASCII6D, ASCII6E, ASCII6F,
												ASCII70, ASCII71, ASCII72, ASCII73, ASCII74, ASCII75, ASCII76, ASCII77,
												ASCII78, ASCII79, ASCII7A, ASCII7B, ASCII7C, ASCII7D, ASCII7E, ASCII7F};






#endif /* FONT1_H_ */