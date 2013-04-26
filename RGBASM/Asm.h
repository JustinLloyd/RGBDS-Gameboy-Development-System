/*	asm.h
 *
 *	Contains some assembler-wide defines and externs
 *
 *	Copyright 1997 Carsten Sorensen
 *  Copyright 1999 Otaku No Zoku
 *
 */

#ifndef ASM_H
#define ASM_H

#include	<stdlib.h>
#include	<stdio.h>
#include	"types.h"
#include	"symbol.h"
#include	"localasm.h"
#include	"asmotor.h"

extern	SLONG	nLineNo;
extern	ULONG	g_totalLines ;
extern	ULONG	nPC;
extern	ULONG	nPass;
extern	ULONG	uniqueSectionCount ;								// number of anonymous sections declared with ORG directive
extern	ULONG	g_nIFDepth ;
extern	char	tzCurrentFileName[_MAX_PATH+1];
extern	struct	Section	*pCurrentSection;
extern	struct	sSymbol	*tHashedSymbols[HASHSIZE];
extern	struct	sSymbol	*pPCSymbol;
extern	UBYTE	oDontExpandStrings;

#define MAXMACROARGS	9
#define MAXINCPATHS		16

#endif	//	ASM_H