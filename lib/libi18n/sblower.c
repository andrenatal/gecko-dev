/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
/*	sblower.c		*/
/*
	This function contain the singlebyte to lower table which need to implement function in
	intlcomp.c.
	None of the function in this file should be made public
	The interface function is INTL_GetSingleByteToLowerMap() and it should only be called 
	inside libi18n
*/
#include "intlpriv.h"
#include "pintlcmp.h"

/*	
	lower_lookup_ascii  map 
		0x41-0x5a to 0x61-0x7a
*/
MODULE_PRIVATE unsigned char lower_lookup_ascii[128]={
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
	0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
};
#ifndef XP_MAC
/*	
	lower_lookup_latin1 map 
	(2) 0xc0-0xd6 to 0xe0-0xf6
	(3) 0xd8-0xde to 0xf8-0xfe
*/
PRIVATE unsigned char lower_lookup_latin1[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xd7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
/*	
	lower_lookup_latin2  map 
	(2) 0xa1 to 0xb1
	(3) 0xa3 to 0xb3
	(4) 0xa5-0xa6 to 0xb5-0xb6
	(5) 0xa9-0xac to 0xb9-0xbc
	(6) 0xae-0xaf to 0xbe-0xbf
	(7) 0xc0-0xd6 to 0xe0-0xf6
	(8) 0xd8-0xde to 0xf8-0xfe
*/
PRIVATE unsigned char lower_lookup_latin2[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xb1, 0xa2, 0xb3, 0xa4, 0xb5, 0xb6, 0xa7, 0xa8, 0xb9, 0xba, 0xbb, 0xbc, 0xad, 0xbe, 0xbf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xd7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
/*	
	lower_lookup_macicelandic map 
		0x80 to 0x8a
		0x81-0x83 to 0x8c-0x8e
		0x84 to 0x96
		0x85 to 0x9a
		0x86 to 0x9f
		0xa0 to 0xe0
		0xae-0xaf to 0xbe-0xbf
		0xcb to 0x88
		0xcc to 0x8b
		0xcd to 0x9b
		0xce to 0xcf
		0xd9 to 0xd8
		0xdc to 0xdd
		0xde to 0xdf
		0xe5 to 0x89
		0xe6 to 0x90
		0xe7 to 0x87
		0xe8 to 0x91
		0xe9 to 0x8f
		0xea to 0x92
		0xeb to 0x94
		0xec to 0x95
		0xed to 0x93
		0xee to 0x97
		0xef to 0x99
		0xf1 to 0x98
		0xf2 to 0x9c
		0xf3 to 0x9e
		0xf4 to 0x9d
*/
#else /* ifndef XP_MAC */
PRIVATE unsigned char lower_lookup_macicelandic[128]={
	0x8a, 0x8c, 0x8d, 0x8e, 0x96, 0x9a, 0x9f, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xe0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xbe, 0xbf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0x88, 0x8b, 0x9b, 0xcf, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd8, 0xda, 0xdb, 0xdd, 0xdd, 0xdf, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0x89, 0x90, 0x87, 0x91, 0x8f, 0x92, 0x94, 0x95, 0x93, 0x97, 0x99,
	0xf0, 0x98, 0x9c, 0x9e, 0x9d, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
/*	
	lower_lookup_macce  map 
			0x80 to 0x8a
			0x81 to 0x82
			0x83 to 0x8e
			0x84 to 0x88
			0x85 to 0x9a
			0x86 to 0x9f
			0x89 to 0x8b
			0x8c to 0x8d
			0x8f to 0x90
			0x91 to 0x93
			0x94 to 0x95
			0x96 to 0x98
			0x9d to 0x9e
			0xa2 to 0xab
			0xaf to 0xb0
			0xb1 to 0xb4
			0xb5 to 0xfa
			0xb9 to 0xba
			0xbb to 0xbc
			0xbd to 0xbe
			0xbf to 0xc0
			0xc1 to 0xc4
			0xc5 to 0xcb
			0xcc to 0xce
			0xcd to 0x9b
			0xcf to 0xd8
			0xd9 to 0xda
			0xdb to 0xde
			0xdf to 0xe0
			0xe1 to 0xe4
			0xe5 to 0xe6
			0xe7 to 0x87
			0xe8 to 0xe9
			0xea to 0x92
			0xeb to 0xec
			0xed to 0xf0
			0xee to 0x97
			0xef to 0x99
			0xf1 to 0xf3
			0xf2 to 0x9c
			0xf4 to 0xf5
			0xf6 to 0xf7
			0xf8 to 0xf9
			0xfb to 0xfd
			0xfc to 0xb8
			0xfe to 0xae
*/
PRIVATE unsigned char lower_lookup_macce[128]={
	0x8a, 0x82, 0x82, 0x8e, 0x88, 0x9a, 0x9f, 0x87, 0x88, 0x8b, 0x8a, 0x8b, 0x8d, 0x8d, 0x8e, 0x90,
	0x90, 0x93, 0x92, 0x93, 0x95, 0x95, 0x98, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xab, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xae, 0xae, 0xb0,
	0xb0, 0xb4, 0xb2, 0xb3, 0xb4, 0xfa, 0xb6, 0xb7, 0xb8, 0xba, 0xba, 0xbc, 0xbc, 0xbe, 0xbe, 0xc0,
	0xc0, 0xc4, 0xc2, 0xc3, 0xc4, 0xcb, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xce, 0x9b, 0xce, 0xd8,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xda, 0xda, 0xde, 0xdc, 0xdd, 0xde, 0xe0,
	0xe0, 0xe4, 0xe2, 0xe3, 0xe4, 0xe6, 0xe6, 0x87, 0xe9, 0xe9, 0x92, 0xec, 0xec, 0xf0, 0x97, 0x99,
	0xf0, 0xf3, 0x9c, 0xf3, 0xf5, 0xf5, 0xf7, 0xf7, 0xf9, 0xf9, 0xfa, 0xfd, 0xb8, 0xfd, 0xae, 0xff
};
#endif /* ifndef XP_MAC */

#ifndef XP_UNIX
/*	
	lower_lookup_jis0201  map 
		0xa7-0xab to 0xb1-0xb5
		0xac-0xae to 0xd4-0xd6
		0xaf to 0xc2
*/
PRIVATE unsigned char lower_lookup_jis0201[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xd4, 0xd5, 0xd6, 0xc2,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif

#ifdef XP_MAC
/*
	lower_lookup_mac_cyrillic
		0x80-0x9e to 0xe0-0xfe		A - YU
		0x9F	  to 0xDF			YA
		0xA7	  to 0xb4			BYELORUSSIAN-UKRAINIAN I
		0xAb	  to 0xAC			DJE
		0xae	  to 0xaf			gje
		0xb7	  to 0xc0			je
		0xb8	  to 0xb9			ie
		0xba	  to 0xbb			yi
		0xbc	  to 0xbc			lje
		0xbd	  to 0xbd			nje
		0xc1	  to 0xcf			dze
		0xcb	  to 0xcc			tshe
		0xcd	  to 0xce			kje
		0xd8	  to 0xd9			short u
		0xda	  to 0xdb			dzhe
		0xdd	  to 0xde			dzhe
*/
PRIVATE unsigned char lower_lookup_mac_cyrillic[128]={
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xdf,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xb4, 0xa8, 0xa9, 0xaa, 0xac, 0xac, 0xad, 0xaf, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xc0, 0xb9, 0xb9, 0xbb, 0xbb, 0xbd, 0xbd, 0xbf, 0xbf,
	0xc0, 0xcf, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcc, 0xcc, 0xce, 0xce, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd9, 0xd9, 0xdb, 0xdb, 0xdc, 0xde, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif
#ifdef XP_UNIX
/*	
	lower_lookup_8859_5  map 
		0xa1-0xac to 0xf1-0xfc
		0xae-0xaf to 0xfe-0xff
		0xb0-0xcf to 0xd0-0xef
*/
PRIVATE unsigned char lower_lookup_8859_5[128]={
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xad, 0xfe, 0xff,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif
#if defined(XP_WIN) || defined(XP_OS2) || defined(XP_UNIX)
/*	
	lower_lookup_cp1251  map 
		0x80		 0x90
		0x81		 0x83
		0x8a		 0x9a
		0x8c-0x8f	 0x9c-0x9f
		0xa1		 0xa2
		0xa3		 0xbc
		0xa5		 0xb4
		0xa8		 0xb8
		0xaa		 0xba
		0xaf		 0xbf
		0xb2		 0xb3
		0xbd		 0xbe
*/
PRIVATE unsigned char lower_lookup_cp1251[128]={
	0x90, 0x83, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x9a, 0x8b, 0x9c, 0x9d, 0x9e, 0x9f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa2, 0xa2, 0xbc, 0xa4, 0xb4, 0xa6, 0xa7, 0xb8, 0xa9, 0xba, 0xab, 0xac, 0xad, 0xae, 0xbf,
	0xb0, 0xb1, 0xb3, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbe, 0xbe, 0xbf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif
#ifdef XP_MAC
/*	
	lower_lookup_mac_greek  map 
		0x80		to	0x8a
		0x8e		to 	0x8e
		0x85		to 	0x9a
		0x86		to 	0x9f
		0xa1		to 	0xe7
		0xa2		to 	0xe4
		0xa3		to 	0xf5
		0xa4		to 	0xec
		0xa5		to 	0xea
		0xa6		to 	0xf0
		0xaa		to 	0xf3
		0xab		to 	0xfb
		0xb0		to 	0xe1		
		0xb5		to 	0xe2
		0xb6		to 	0xe5
		0xb7		to 	0xfa
		0xb8		to 	0xe8
		0xb9		to 	0xe9
		0xba		to 	0xeb
		0xbb		to 	0xed
		0xbc		to 	0xe6
		0xbd		to 	0xfc
		0xbe		to 	0xe3
		0xbf		to 	0xf6		
		0xc1		to	0xee
		0xc3		to	0xef
		0xc4		to	0xf2
		0xc6		to	0xf4		
		0xcb		to	0xf9
		0xcc		to	0xf8
		0xcd		to	0xc0
		0xce		to	0xdb

		0xd7-0xd9	to	0xdc-0xde
		0xda		to	0xe0
		0xdf		to	0xf1
		
		
*/
PRIVATE unsigned char lower_lookup_mac_greek[128]={
	0x8a, 0x81, 0x82, 0x8e, 0x84, 0x9a, 0x9f, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xe7, 0xe4, 0xf5, 0xec, 0xea, 0xf0, 0xa7, 0xa8, 0xa9, 0xf3, 0xfb, 0xac, 0xad, 0xae, 0xaf,
	0xe1, 0xb1, 0xb2, 0xb3, 0xb4, 0xe2, 0xe5, 0xfa, 0xe8, 0xe9, 0xeb, 0xed, 0xe6, 0xfc, 0xe3, 0xf6,
	0xc0, 0xee, 0xc2, 0xef, 0xf2, 0xc5, 0xf4, 0xc7, 0xc8, 0xc9, 0xca, 0xf9, 0xf8, 0xc0, 0xdb, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xdc, 0xdd, 0xde, 0xe0, 0xdb, 0xdc, 0xdd, 0xde, 0xf1,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif
#ifdef XP_UNIX
/*	
	lower_lookup_8859_7  map 
		0xb6	  to 0xdc
		0xb8-0xba to 0xdd-0xdf
		0xbc	  to 0xfc
		0xbe-0xbf to 0xfd-0xfe
		0xc1-0xdb to 0xe1-0xfb
*/
PRIVATE unsigned char lower_lookup_8859_7[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xdc, 0xb7, 0xdd, 0xde, 0xdf, 0xbb, 0xfc, 0xbd, 0xfd, 0xfe,
	0xc0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif
#if defined(XP_WIN) || defined(XP_OS2)
/*	
	( The differences in these two table. I am not saying the difference between these two codeset)
		is 0xb6 and 0xa2
	lower_lookup_cp1253  map 
		0xa2	  to 0xdc
		0xb8-0xba to 0xdd-0xdf
		0xbc	  to 0xfc
		0xbe-0xbf to 0xfd-0xfe
		0xc1-0xdb to 0xe1-0xfb

*/
PRIVATE unsigned char lower_lookup_cp1253[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xdc, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xdd, 0xde, 0xdf, 0xbb, 0xfc, 0xbd, 0xfd, 0xfe,
	0xc0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xdc, 0xdd, 0xde, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif

#if defined(XP_WIN) || defined(XP_OS2)
/*
	lower_lookup_cp1250  map 
	
*/
PRIVATE unsigned char lower_lookup_cp1250[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x9a, 0x8b, 0x9c, 0x9d, 0x9e, 0x9f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xb3, 0xa4, 0xb9, 0xa6, 0xa7, 0xa8, 0xa9, 0xba, 0xab, 0xac, 0xad, 0xae, 0xbf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbe, 0xbd, 0xbe, 0xbf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xd7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif
#ifndef XP_MAC
/*
	lower_lookup_8859_9  map 
	
	PROBLEM!!!!! Need more information !!!!
	Currently I map 0xdd to 0xfd for tolower
	0xDD is LATIN CAPITAL LETTER I WITH DOT ABOVE
	0xFD is LATIN SMALL LETTER DOTLESS I
	
	Should I do that ?
	
*/
PRIVATE unsigned char lower_lookup_8859_9[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x9a, 0x8b, 0x9c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0xff,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xd7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#else
/*
	lower_lookup_mac_turkish  map 
	PROBLEM!!!!! Need more information !!!!
	Currently I map 0xdc to 0xdd for tolower
	0xDC is LATIN CAPITAL LETTER I WITH DOT ABOVE
	0xDD is LATIN SMALL LETTER DOTLESS I
	
	Should I do that ?
*/
PRIVATE unsigned char lower_lookup_mac_turkish[128]={
	0x8a, 0x8c, 0x8d, 0x8e, 0x96, 0x9a, 0x9f, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xbe, 0xbf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0x88, 0xcb, 0x9b, 0xcf, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd8, 0xdb, 0xdb, 0xdd, 0xdd, 0xdf, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0x89, 0x90, 0x87, 0x91, 0x8f, 0x92, 0x94, 0x95, 0x93, 0x97, 0x99,
	0xf0, 0x98, 0x9c, 0x9e, 0x9d, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif
/*
	lower_lookup_koi8_r  map 
*/
PRIVATE unsigned char lower_lookup_koi8_r[128]={
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb1, 0xa3, 0xa4, 0xb5, 0xa6, 0xa7, 0xb8, 0xb9, 0xba, 0xbb, 0xbd, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf
};
/*
 *     lower_lookup_koi8_u map 
 */
PRIVATE unsigned char lower_lookup_koi8_u[128]={
       0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
       0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
       0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
       0xb0, 0xb1, 0xb2, 0xa3, 0xa4, 0xb5, 0xa6, 0xa7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xad, 0xbe, 0xbf,
       0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
       0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
       0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
       0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf
};

#ifdef XP_OS2
/*
 * Lowercase for ibm850
 */
PRIVATE unsigned char lower_cp850[128] = {
	0x87, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x84, 0x86, 
	0x82, 0x91, 0x91, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x94, 0x81, 0x9b, 0x9c, 0x9b, 0x9e, 0x9f, 
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa4, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xa0, 0x83, 0x85, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc6, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 
	0xd0, 0xd0, 0x88, 0x89, 0x8a, 0xd5, 0xa1, 0x8c, 0x8b, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0x8d, 0xdf, 
	0xa2, 0xe1, 0x93, 0x95, 0xe4, 0xe4, 0xe6, 0xe7, 0xe7, 0xa3, 0x96, 0x97, 0xec, 0xec, 0xee, 0xef, 
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff, 
};

/*
 * Lowercase for ibm852
 */
PRIVATE unsigned char lower_cp852[128] = {
	0x87, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8b, 0x8b, 0x8c, 0xab, 0x84, 0x86, 
	0x82, 0x92, 0x92, 0x93, 0x94, 0x96, 0x96, 0x98, 0x98, 0x94, 0x81, 0x9c, 0x9c, 0x88, 0x9e, 0x9f, 
	0xa0, 0xa1, 0xa2, 0xa3, 0xa5, 0xa5, 0xa7, 0xa7, 0xa9, 0xa9, 0x7f, 0xab, 0x9f, 0xad, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xa0, 0x83, 0xd8, 0xad, 0xb9, 0xba, 0xbb, 0xbc, 0xbe, 0xbe, 0xbf, 
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc7, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 
	0xd0, 0xd0, 0xd4, 0x89, 0xd4, 0xe5, 0xa1, 0x8c, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xee, 0x85, 0xdf, 
	0xa2, 0xe1, 0x93, 0xe4, 0xe4, 0xe5, 0xe7, 0xe7, 0xea, 0xa3, 0xea, 0xfb, 0xec, 0xec, 0xee, 0xef, 
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfd, 0xfd, 0xfe, 0xff, 
};

/*
 * Lowercase for ibm855
 */
PRIVATE unsigned char lower_cp855[128] = {
	0x80, 0x80, 0x82, 0x82, 0x84, 0x84, 0x86, 0x86, 0x88, 0x88, 0x8a, 0x8a, 0x8c, 0x8c, 0x8e, 0x8e, 
	0x90, 0x90, 0x92, 0x92, 0x94, 0x94, 0x96, 0x96, 0x98, 0x98, 0x9a, 0x9a, 0x9c, 0x9c, 0x9e, 0x9e, 
	0xa0, 0xa0, 0xa2, 0xa2, 0xa4, 0xa4, 0xa6, 0xa6, 0xa8, 0xa8, 0xaa, 0xaa, 0xac, 0xac, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb5, 0xb7, 0xb7, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbd, 0xbf, 
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc6, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 
	0xd0, 0xd0, 0xd2, 0xd2, 0xd4, 0xd4, 0xd6, 0xd6, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xd8, 0xde, 0xdf, 
	0xde, 0xe1, 0xe1, 0xe3, 0xe3, 0xe5, 0xe5, 0xe7, 0xe7, 0xe9, 0xe9, 0xeb, 0xeb, 0xed, 0xed, 0xef, 
	0xf0, 0xf1, 0xf1, 0xf3, 0xf3, 0xf5, 0xf5, 0xf7, 0xf7, 0xf9, 0xf9, 0xfb, 0xfb, 0xfd, 0xfe, 0xff, };

/*
 * Lowercase for ibm857
 */
PRIVATE unsigned char lower_cp857[128] = {
	0x87, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x84, 0x86, 
	0x82, 0x91, 0x91, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x94, 0x81, 0x9b, 0x9c, 0x9b, 0x9f, 0x9f, 
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa4, 0xa7, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xa0, 0x83, 0x85, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc6, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 
	0xd0, 0xd1, 0x88, 0x89, 0x8a, 0x7f, 0xa1, 0x8c, 0x8b, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xec, 0xdf, 
	0xa2, 0xe1, 0x93, 0x95, 0xe4, 0xe4, 0xe6, 0x7f, 0xe8, 0xa3, 0x96, 0x97, 0xec, 0xed, 0xee, 0xef, 
	0xf0, 0xf1, 0x7f, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff, };

/*
 * Lowercase for ibm862
 */
PRIVATE unsigned char lower_cp862[128] = {
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa4, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 
	0xe0, 0xe1, 0x7f, 0xe3, 0xe5, 0xe5, 0xe6, 0xe7, 0xed, 0x7f, 0x7f, 0xeb, 0xec, 0xed, 0xee, 0xef, 
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff, 
};


/*
 * Lowercase for ibm864
 */
PRIVATE unsigned char lower_cp864[128] = {
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x7f, 0x7f, 0x9d, 0x9e, 0x9f, 
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0x7f, 0x7f, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0x7f, };


/*
 * Lowercase for ibm866
 */
PRIVATE unsigned char lower_cp866[128] = {
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 
	0xf1, 0xf1, 0xf3, 0xf3, 0xf5, 0xf5, 0xf7, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff, };

/*
 * Lowercase for windows-1257
 */
PRIVATE unsigned char lower_cp1257[128] = {
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 
	0xa0, 0x1a, 0xa2, 0xa3, 0xa4, 0x1a, 0xa6, 0xa7, 0xb8, 0xa9, 0xba, 0xab, 0xac, 0xad, 0xae, 0xbf, 
	0xb0, 0xb1, 0xb2, 0xb3, 0x1a, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xd7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xdf, 
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0x1a, };


/*
 * Lowercase for macroman
 */
PRIVATE unsigned char lower_macroman[128] = {
	0x8a, 0x8c, 0x8d, 0x8e, 0x96, 0x9a, 0x9f, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xe0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xbe, 0xbf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0x88, 0x8b, 0x9b, 0xcf, 0xcf,
	0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd8, 0xda, 0xdb, 0xdd, 0xdd, 0xdf, 0xdf,
	0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0x89, 0x90, 0x87, 0x91, 0x8f, 0x92, 0x94, 0x95, 0x93, 0x97, 0x99,
	0xf0, 0x98, 0x9c, 0x9e, 0x9d, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
#endif

/* 
  ToLower translation for Armenian (ArmSCII-8):

    0x80..0xB1  -  unchanged
    0xB2..0xFE  -  set the lower bit
*/

PRIVATE unsigned char lower_armscii8[128] = {
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 
	0xb0, 0xb1, 0xb3, 0xb3, 0xb5, 0xb5, 0xb7, 0xb7, 0xb9, 0xb9, 0xbb, 0xbb, 0xbd, 0xbd, 0xbf, 0xbf, 
	0xc0, 0xc1, 0xc3, 0xc3, 0xc5, 0xc5, 0xc7, 0xc7, 0xc9, 0xc9, 0xcb, 0xcb, 0xcd, 0xcd, 0xcf, 0xcf, 
	0xd0, 0xd1, 0xd3, 0xd3, 0xd5, 0xd5, 0xd7, 0xd7, 0xd9, 0xd9, 0xdb, 0xdb, 0xdd, 0xdd, 0xdf, 0xdf, 
	0xe0, 0xe1, 0xe3, 0xe3, 0xe5, 0xe5, 0xe7, 0xe7, 0xe9, 0xe9, 0xeb, 0xeb, 0xed, 0xed, 0xef, 0xef, 
	0xf0, 0xf1, 0xf3, 0xf3, 0xf5, 0xf5, 0xf7, 0xf7, 0xf9, 0xf9, 0xfb, 0xfb, 0xfd, 0xfd, 0xff, 0x7f };


MODULE_PRIVATE unsigned char *INTL_GetSingleByteToLowerMap(int16 csid)
{
	switch(csid)
	{
#ifdef XP_MAC
		case CS_MAC_ROMAN:
			return lower_lookup_macicelandic;
		case CS_MAC_CE:
			return lower_lookup_macce;
		case CS_MAC_CYRILLIC:
			return lower_lookup_mac_cyrillic;
		case CS_MAC_GREEK:
			return lower_lookup_mac_greek;
		case CS_MAC_TURKISH:	
			return lower_lookup_mac_turkish;
		case CS_SJIS:
			return lower_lookup_jis0201;
#endif
#if defined(XP_WIN) || defined(XP_OS2)
		case CS_LATIN1:
			return lower_lookup_latin1;
		case CS_CP_1250:	
			return lower_lookup_cp1250;
		case CS_CP_1251:
			return lower_lookup_cp1251;
		case CS_CP_1253:
			return lower_lookup_cp1253;
#ifdef XP_OS2
		case CS_CP_1254:
#endif
		case CS_8859_9:	
			return lower_lookup_8859_9;
		case CS_SJIS:
			return lower_lookup_jis0201;
#ifdef XP_OS2
		case CS_CP_850:
			return lower_cp850;
		case CS_CP_852:
			return lower_cp852;
		case CS_CP_855:
			return lower_cp855;
		case CS_CP_857:
			return lower_cp857;
		case CS_CP_862:
			return lower_cp862;
		case CS_CP_864:
			return lower_cp864;
		case CS_CP_866:
			return lower_cp866;
		case CS_CP_1257:
			return lower_cp1257;
		case CS_MAC_ROMAN:
			return lower_macroman;
#endif
#endif
#ifdef XP_UNIX
		case CS_LATIN1:
			return lower_lookup_latin1;
		case CS_LATIN2:
			return lower_lookup_latin2;
		case CS_8859_5:
			return lower_lookup_8859_5;
		case CS_8859_7:
			return lower_lookup_8859_7;
		case CS_8859_9:	
			return lower_lookup_8859_9;
		case CS_CP_1251:
			return lower_lookup_cp1251;
#endif	
		case CS_KOI8_R:
			return lower_lookup_koi8_r;
		case CS_KOI8_U:
			return lower_lookup_koi8_u;
		case CS_ARMSCII8:
			return lower_armscii8;

		/* currently, return the ascii table. We should supply table for this csid later */
		
		case CS_8859_3:	
		case CS_8859_4:		
		case CS_8859_6:
		case CS_8859_8:
		case CS_SYMBOL:
		case CS_DINGBATS:
		case CS_TIS620:
		case CS_JISX0201:
		
		/* use the ascii table */
		case CS_DEFAULT:
		case CS_ASCII:
		case CS_BIG5:		
		case CS_CNS_8BIT:		
		case CS_GB_8BIT:	
		case CS_KSC_8BIT:	
		default:
			return lower_lookup_ascii;
	}
}




