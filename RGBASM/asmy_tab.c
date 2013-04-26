
/*  A Bison parser, made from .\asmy.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	T_NUMBER	258
#define	T_STRING	259
#define	T_OP_LOGICNOT	260
#define	T_OP_LOGICOR	261
#define	T_OP_LOGICAND	262
#define	T_OP_LOGICEQU	263
#define	T_OP_LOGICGT	264
#define	T_OP_LOGICLT	265
#define	T_OP_LOGICGE	266
#define	T_OP_LOGICLE	267
#define	T_OP_LOGICNE	268
#define	T_OP_ADD	269
#define	T_OP_SUB	270
#define	T_OP_OR	271
#define	T_OP_XOR	272
#define	T_OP_AND	273
#define	T_OP_SHL	274
#define	T_OP_SHR	275
#define	T_OP_MUL	276
#define	T_OP_DIV	277
#define	T_OP_MOD	278
#define	T_OP_NOT	279
#define	T_OP_DEF	280
#define	T_OP_BANK	281
#define	T_OP_SIN	282
#define	T_OP_COS	283
#define	T_OP_TAN	284
#define	T_OP_ASIN	285
#define	T_OP_ACOS	286
#define	T_OP_ATAN	287
#define	T_OP_ATAN2	288
#define	T_OP_FDIV	289
#define	T_OP_FMUL	290
#define	T_OP_STRCMP	291
#define	T_OP_STRIN	292
#define	T_OP_STRSUB	293
#define	T_OP_STRLEN	294
#define	T_OP_STRCAT	295
#define	T_OP_STRUPR	296
#define	T_OP_STRLWR	297
#define	T_OP_STRTRIM	298
#define	T_OP_STRLTRIM	299
#define	T_OP_STRRTRIM	300
#define	NEG	301
#define	T_LABEL	302
#define	T_ID	303
#define	T_POP_EQU	304
#define	T_POP_SET	305
#define	T_POP_EQUS	306
#define	T_POP_INCLUDE	307
#define	T_POP_PRINTF	308
#define	T_POP_PRINTT	309
#define	T_POP_PRINTV	310
#define	T_POP_IF	311
#define	T_POP_ELSE	312
#define	T_POP_ENDC	313
#define	T_POP_IMPORT	314
#define	T_POP_EXPORT	315
#define	T_POP_GLOBAL	316
#define	T_POP_DB	317
#define	T_POP_DS	318
#define	T_POP_DW	319
#define	T_POP_DQ	320
#define	T_POP_SECTION	321
#define	T_POP_ORG	322
#define	T_POP_RB	323
#define	T_POP_RW	324
#define	T_POP_RQ	325
#define	T_POP_ALIGN	326
#define	T_POP_MACRO	327
#define	T_POP_ENDM	328
#define	T_POP_RSRESET	329
#define	T_POP_RSSET	330
#define	T_POP_INCBIN	331
#define	T_POP_REPT	332
#define	T_POP_SHIFT	333
#define	T_POP_ENDR	334
#define	T_POP_FAIL	335
#define	T_POP_WARN	336
#define	T_POP_PURGE	337
#define	T_POP_POPS	338
#define	T_POP_PUSHS	339
#define	T_POP_POPO	340
#define	T_POP_PUSHO	341
#define	T_POP_OPT	342
#define	T_SECT_BSS	343
#define	T_SECT_VRAM	344
#define	T_SECT_CODE	345
#define	T_SECT_HOME	346
#define	T_SECT_HRAM	347
#define	T_Z80_ADC	348
#define	T_Z80_ADD	349
#define	T_Z80_AND	350
#define	T_Z80_BIT	351
#define	T_Z80_CALL	352
#define	T_Z80_CCF	353
#define	T_Z80_CP	354
#define	T_Z80_CPL	355
#define	T_Z80_DAA	356
#define	T_Z80_DEC	357
#define	T_Z80_DI	358
#define	T_Z80_EI	359
#define	T_Z80_EX	360
#define	T_Z80_HALT	361
#define	T_Z80_INC	362
#define	T_Z80_JP	363
#define	T_Z80_JR	364
#define	T_Z80_LD	365
#define	T_Z80_LDI	366
#define	T_Z80_LDD	367
#define	T_Z80_LDIO	368
#define	T_Z80_NOP	369
#define	T_Z80_OR	370
#define	T_Z80_POP	371
#define	T_Z80_PUSH	372
#define	T_Z80_RES	373
#define	T_Z80_RET	374
#define	T_Z80_RETI	375
#define	T_Z80_RST	376
#define	T_Z80_RL	377
#define	T_Z80_RLA	378
#define	T_Z80_RLC	379
#define	T_Z80_RLCA	380
#define	T_Z80_RR	381
#define	T_Z80_RRA	382
#define	T_Z80_RRC	383
#define	T_Z80_RRCA	384
#define	T_Z80_SBC	385
#define	T_Z80_SCF	386
#define	T_Z80_STOP	387
#define	T_Z80_SLA	388
#define	T_Z80_SRA	389
#define	T_Z80_SRL	390
#define	T_Z80_SUB	391
#define	T_Z80_SWAP	392
#define	T_Z80_XOR	393
#define	T_MODE_A	394
#define	T_MODE_B	395
#define	T_MODE_C	396
#define	T_MODE_C_IND	397
#define	T_MODE_D	398
#define	T_MODE_E	399
#define	T_MODE_H	400
#define	T_MODE_L	401
#define	T_MODE_AF	402
#define	T_MODE_BC	403
#define	T_MODE_BC_IND	404
#define	T_MODE_DE	405
#define	T_MODE_DE_IND	406
#define	T_MODE_SP	407
#define	T_MODE_SP_IND	408
#define	T_MODE_HL	409
#define	T_MODE_HL_IND	410
#define	T_MODE_HL_INDDEC	411
#define	T_MODE_HL_INDINC	412
#define	T_CC_NZ	413
#define	T_CC_Z	414
#define	T_CC_NC	415
#define	T_CC_EQ	416
#define	T_CC_NE	417
#define	T_CC_LT	418

#line 1 ".\asmy.y"

#include "symbol.h"
#include "asm.h"
#include "output.h"
#include "mylink.h"
#include "fstack.h"
#include "mymath.h"
#include "rpn.h"
#include "main.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include	<ctype.h>

char	*tzNewMacro;
ULONG	ulNewMacroSize;

ULONG	symvaluetostring( char *dest, char *sym )
{
	if( sym_isString(sym) )
		strcpy( dest, sym_GetStringValue(sym) );
	else
		sprintf( dest, "$%lX", sym_GetConstantValue(sym) );

	return( strlen(dest) );
}

ULONG	str2int( char *s )
{
	ULONG r=0;
	while( *s )
	{
		r<<=8;
		r|=(UBYTE)(*s++);
	}
	return( r );
}

ULONG	isWhiteSpace( char s )
{
	return( s==' ' || s=='\t' || s=='\0' || s=='\n' );
}

ULONG	isRept( char *s )
{
	return( (strnicmp(s,"REPT",4)==0) && isWhiteSpace(*(s-1)) && isWhiteSpace(s[4]) );
}

ULONG	isEndr( char *s )
{
	return( (strnicmp(s,"Endr",4)==0) && isWhiteSpace(*(s-1)) && isWhiteSpace(s[4]) );
}

void	copyrept( void )
{
	SLONG	level=1, len, instring=0;
	char	*src=pCurrentBuffer->pBuffer;

	while( *src && level )
	{
		if( instring==0 )
		{
			if( isRept(src) )
			{
				level+=1;
				src+=4;
			}
			else if( isEndr(src) )
			{
				level-=1;
				src+=4;
			}
			else
			{
				if( *src=='\"' )
					instring=1;
				src+=1;
			}
		}
		else
		{
			if( *src=='\\' )
			{
				src+=2;
			}
			else if( *src=='\"' )
			{
				src+=1;
				instring=0;
			}
			else
			{
				src+=1;
			}
		}
	}

	len=src-pCurrentBuffer->pBuffer-4;

	src=pCurrentBuffer->pBuffer;
	ulNewMacroSize=len;

	if( (tzNewMacro=(char *)malloc(ulNewMacroSize+1))!=NULL )
	{
		ULONG i;

		tzNewMacro[ulNewMacroSize]=0;
		for( i=0; i<ulNewMacroSize; i+=1 )
		{
			if( (tzNewMacro[i]=src[i])=='\n' )
				nLineNo+=1;
		}
	}
	else
		ErrorFatal( "No mem for REPT block" );

	yyskipbytes( ulNewMacroSize+4 );

}

ULONG	isMacro( char *s )
{
	return( (strnicmp(s,"MACRO",4)==0) && isWhiteSpace(*(s-1)) && isWhiteSpace(s[5]) );
}

ULONG	isEndm( char *s )
{
	return( (strnicmp(s,"Endm",4)==0) && isWhiteSpace(*(s-1)) && isWhiteSpace(s[4]) );
}

void	copymacro( void )
{
	SLONG	level=1, len, instring=0;
	char	*src=pCurrentBuffer->pBuffer;

	while( *src && level )
	{
		if( instring==0 )
		{
			if( isMacro(src) )
			{
				level+=1;
				src+=4;
			}
			else if( isEndm(src) )
			{
				level-=1;
				src+=4;
			}
			else
			{
				if( *src=='\"' )
					instring=1;
				src+=1;
			}
		}
		else
		{
			if( *src=='\\' )
			{
				src+=2;
			}
			else if( *src=='\"' )
			{
				src+=1;
				instring=0;
			}
			else
			{
				src+=1;
			}
		}
	}

	len=src-pCurrentBuffer->pBuffer-4;

	src=pCurrentBuffer->pBuffer;
	ulNewMacroSize=len;

	if( (tzNewMacro=(char *)malloc(ulNewMacroSize+2))!=NULL )
	{
		ULONG i;

		tzNewMacro[ulNewMacroSize]='\n';
		tzNewMacro[ulNewMacroSize+1]=0;
		for( i=0; i<ulNewMacroSize; i+=1 )
		{
			if( (tzNewMacro[i]=src[i])=='\n' )
				nLineNo+=1;
		}
	}
	else
		ErrorFatal( "No mem for MACRO definition" );

	yyskipbytes( ulNewMacroSize+4 );
}

ULONG	isIf( char *s )
{
	return( (strnicmp(s,"If",2)==0) && isWhiteSpace(*(s-1)) && isWhiteSpace(s[2]) );
}

ULONG	isElse( char *s )
{
	return( (strnicmp(s,"Else",4)==0) && isWhiteSpace(*(s-1)) && isWhiteSpace(s[4]) );
}

ULONG	isEndc( char *s )
{
	return( (strnicmp(s,"Endc",4)==0) && isWhiteSpace(*(s-1)) && isWhiteSpace(s[4]) );
}

void	if_skip_to_else( void )
{
	SLONG	level=1, len, instring=0;
	char	*src=pCurrentBuffer->pBuffer;

	while( *src && level )
	{
		if( *src=='\n' )
			nLineNo+=1;

		if( instring==0 )
		{
			if( isIf(src) )
			{
				level+=1;
				src+=2;
			}
			else if( level==1 && isElse(src) )
			{
				level-=1;
				src+=4;
			}
			else if( isEndc(src) )
			{
				level-=1;
				if( level!=0 )
					src+=4;
			}
			else
			{
				if( *src=='\"' )
					instring=1;
				src+=1;
			}
		}
		else
		{
			if( *src=='\\' )
			{
				src+=2;
			}
			else if( *src=='\"' )
			{
				src+=1;
				instring=0;
			}
			else
			{
				src+=1;
			}
		}
	}

	len=src-pCurrentBuffer->pBuffer;

	yyskipbytes( len );
	yyunput( '\n' );
	nLineNo-=1;
}

void	if_skip_to_endc( void )
{
	SLONG	level=1, len, instring=0;
	char	*src=pCurrentBuffer->pBuffer;

	while( *src && level )
	{
		if( *src=='\n' )
			nLineNo+=1;

		if( instring==0 )
		{
			if( isIf(src) )
			{
				level+=1;
				src+=2;
			}
			else if( isEndc(src) )
			{
				level-=1;
				if( level!=0 )
					src+=4;
			}
			else
			{
				if( *src=='\"' )
					instring=1;
				src+=1;
			}
		}
		else
		{
			if( *src=='\\' )
			{
				src+=2;
			}
			else if( *src=='\"' )
			{
				src+=1;
				instring=0;
			}
			else
			{
				src+=1;
			}
		}
	}

	len=src-pCurrentBuffer->pBuffer;

	yyskipbytes( len );
	yyunput( '\n' );
	nLineNo-=1;
}


#ifdef	PCENGINE
ULONG	ZP( struct Expression *expr )
{
	return( (!rpn_isReloc(expr)) && (expr->nVal>0x1FFF) && (expr->nVal<0x2100) );
}

void	out_ZPByte( struct Expression *expr )
{
	if( rpn_isReloc(expr) )
	{
		rpn_CheckZP(expr,expr);
		out_RelByte(expr);
	}
	else
	{
		if( ZP(expr) )
			out_AbsByte(expr->nVal-0x2000);
		else
			ErrorFatal( "Value not in zeropage");
	}
}
#endif


#line 355 ".\asmy.y"
typedef union
{
    char tzSym[MAXSYMLEN+1];
    char tzString[256];
    struct Expression sVal;
    SLONG nConstValue;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		712
#define	YYFLAG		-32768
#define	YYNTBASE	171

#define YYTRANSLATE(x) ((unsigned)(x) <= 418 ? yytranslate[x] : 310)

static const short yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,   164,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,   167,
   168,     2,     2,   166,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,   165,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
   169,     2,   170,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     4,     6,     7,    11,    12,    14,    17,    20,
    23,    25,    26,    28,    31,    35,    36,    40,    41,    43,
    47,    49,    51,    53,    55,    57,    59,    61,    63,    65,
    67,    69,    71,    73,    75,    77,    79,    81,    83,    85,
    87,    89,    91,    93,    95,    97,    99,   101,   103,   105,
   107,   109,   111,   113,   115,   117,   119,   121,   122,   126,
   128,   132,   134,   136,   138,   140,   142,   145,   148,   150,
   153,   157,   161,   164,   166,   170,   174,   178,   181,   184,
   187,   190,   191,   195,   197,   201,   203,   206,   208,   212,
   214,   217,   219,   223,   225,   228,   230,   234,   236,   240,
   244,   247,   250,   257,   260,   263,   266,   269,   271,   273,
   275,   277,   281,   282,   284,   286,   288,   292,   293,   295,
   297,   301,   302,   304,   306,   308,   310,   312,   314,   316,
   319,   323,   327,   331,   335,   339,   343,   347,   351,   355,
   359,   363,   367,   371,   375,   379,   383,   387,   391,   394,
   397,   400,   405,   410,   417,   424,   429,   434,   439,   444,
   449,   454,   461,   468,   475,   480,   484,   486,   488,   490,
   493,   497,   501,   505,   509,   513,   517,   521,   525,   529,
   533,   537,   541,   545,   549,   553,   557,   561,   565,   569,
   572,   575,   578,   585,   592,   597,   602,   607,   612,   617,
   622,   629,   634,   641,   648,   653,   657,   659,   668,   675,
   680,   685,   690,   695,   700,   705,   713,   723,   736,   746,
   748,   750,   752,   754,   756,   758,   760,   762,   764,   766,
   768,   770,   772,   774,   776,   778,   780,   782,   784,   786,
   788,   790,   792,   794,   796,   798,   800,   802,   804,   806,
   808,   810,   812,   814,   816,   818,   820,   822,   824,   826,
   828,   830,   832,   834,   836,   838,   840,   842,   844,   846,
   848,   850,   853,   856,   859,   862,   865,   870,   873,   876,
   881,   884,   889,   891,   894,   897,   899,   901,   904,   907,
   909,   911,   916,   921,   923,   926,   929,   932,   937,   940,
   943,   948,   953,   958,   963,   968,   973,   978,   980,   982,
   984,   986,   988,   990,   992,   994,  1002,  1007,  1012,  1017,
  1022,  1027,  1032,  1037,  1042,  1047,  1052,  1057,  1062,  1067,
  1069,  1072,  1075,  1078,  1081,  1086,  1088,  1091,  1093,  1096,
  1098,  1101,  1103,  1106,  1108,  1111,  1113,  1116,  1119,  1122,
  1124,  1129,  1132,  1135,  1138,  1140,  1143,  1146,  1149,  1152,
  1155,  1159,  1161,  1165,  1167,  1171,  1173,  1177,  1179,  1181,
  1183,  1185,  1187,  1189,  1191,  1193,  1195,  1197,  1199,  1201,
  1203,  1205,  1207,  1209,  1211,  1213,  1215,  1217,  1219,  1221,
  1223,  1225,  1227,  1229,  1231
};

static const short yyrhs[] = {   173,
   172,     0,     0,   174,     0,     0,   173,   174,   164,     0,
     0,   175,     0,   175,   244,     0,   175,   176,     0,   175,
   181,     0,   180,     0,     0,    47,     0,    47,   165,     0,
    47,   165,   165,     0,     0,    48,   177,   178,     0,     0,
   179,     0,   179,   166,   178,     0,     4,     0,   218,     0,
   219,     0,   200,     0,   199,     0,   198,     0,   195,     0,
   194,     0,   220,     0,   224,     0,   222,     0,   223,     0,
   225,     0,   226,     0,   227,     0,   209,     0,   212,     0,
   215,     0,   202,     0,   203,     0,   204,     0,   201,     0,
   241,     0,   242,     0,   197,     0,   196,     0,   221,     0,
   193,     0,   192,     0,   190,     0,   191,     0,   205,     0,
   188,     0,   189,     0,   186,     0,   187,     0,   182,     0,
     0,    87,   183,   184,     0,   185,     0,   185,   166,   184,
     0,     4,     0,    85,     0,    86,     0,    83,     0,    84,
     0,    80,   240,     0,    81,   240,     0,    78,     0,    77,
   239,     0,    47,   165,    72,     0,    47,    51,   240,     0,
    75,   239,     0,    74,     0,    47,    70,   239,     0,    47,
    69,   239,     0,    47,    68,   239,     0,    63,   239,     0,
    62,   229,     0,    64,   231,     0,    65,   233,     0,     0,
    82,   206,   207,     0,   208,     0,   208,   166,   207,     0,
    48,     0,    59,   210,     0,   211,     0,   211,   166,   210,
     0,    48,     0,    60,   213,     0,   214,     0,   214,   166,
   213,     0,    48,     0,    61,   216,     0,   217,     0,   217,
   166,   216,     0,    48,     0,    47,    49,   239,     0,    47,
    50,   239,     0,    52,   240,     0,    76,   240,     0,    76,
   240,   166,   239,   166,   239,     0,    54,   240,     0,    55,
   239,     0,    53,   239,     0,    56,   239,     0,    57,     0,
    58,     0,   239,     0,   230,     0,   230,   166,   229,     0,
     0,   236,     0,   240,     0,   232,     0,   232,   166,   231,
     0,     0,   237,     0,   234,     0,   234,   166,   233,     0,
     0,   238,     0,   238,     0,   238,     0,   238,     0,    48,
     0,     3,     0,   240,     0,     5,   238,     0,   238,     6,
   238,     0,   238,     7,   238,     0,   238,     8,   238,     0,
   238,     9,   238,     0,   238,    10,   238,     0,   238,    11,
   238,     0,   238,    12,   238,     0,   238,    13,   238,     0,
   238,    14,   238,     0,   238,    15,   238,     0,   238,    17,
   238,     0,   238,    16,   238,     0,   238,    18,   238,     0,
   238,    19,   238,     0,   238,    20,   238,     0,   238,    21,
   238,     0,   238,    22,   238,     0,   238,    23,   238,     0,
    14,   238,     0,    15,   238,     0,    24,   238,     0,    26,
   167,    48,   168,     0,    25,   167,    48,   168,     0,    34,
   167,   239,   166,   239,   168,     0,    35,   167,   239,   166,
   239,   168,     0,    27,   167,   239,   168,     0,    28,   167,
   239,   168,     0,    29,   167,   239,   168,     0,    30,   167,
   239,   168,     0,    31,   167,   239,   168,     0,    32,   167,
   239,   168,     0,    33,   167,   239,   166,   239,   168,     0,
    36,   167,   240,   166,   240,   168,     0,    37,   167,   240,
   166,   240,   168,     0,    39,   167,   240,   168,     0,   167,
   238,   168,     0,    48,     0,     3,     0,   240,     0,     5,
   239,     0,   239,     6,   239,     0,   239,     7,   239,     0,
   239,     8,   239,     0,   239,     9,   239,     0,   239,    10,
   239,     0,   239,    11,   239,     0,   239,    12,   239,     0,
   239,    13,   239,     0,   239,    14,   239,     0,   239,    15,
   239,     0,    48,    15,    48,     0,   239,    17,   239,     0,
   239,    16,   239,     0,   239,    18,   239,     0,   239,    19,
   239,     0,   239,    20,   239,     0,   239,    21,   239,     0,
   239,    22,   239,     0,   239,    23,   239,     0,    14,   239,
     0,    15,   239,     0,    24,   239,     0,    34,   167,   239,
   166,   239,   168,     0,    35,   167,   239,   166,   239,   168,
     0,    27,   167,   239,   168,     0,    28,   167,   239,   168,
     0,    29,   167,   239,   168,     0,    30,   167,   239,   168,
     0,    31,   167,   239,   168,     0,    32,   167,   239,   168,
     0,    33,   167,   239,   166,   239,   168,     0,    25,   167,
    48,   168,     0,    36,   167,   240,   166,   240,   168,     0,
    37,   167,   240,   166,   240,   168,     0,    39,   167,   240,
   168,     0,   167,   239,   168,     0,     4,     0,    38,   167,
   240,   166,   239,   166,   239,   168,     0,    40,   167,   240,
   166,   240,   168,     0,    41,   167,   240,   168,     0,    42,
   167,   240,   168,     0,    43,   167,   240,   168,     0,    44,
   167,   240,   168,     0,    45,   167,   240,   168,     0,    66,
   240,   166,   243,     0,    66,   240,   166,   243,   169,   239,
   170,     0,    66,   240,   166,   243,   166,    26,   169,   239,
   170,     0,    66,   240,   166,   243,   169,   239,   170,   166,
    26,   169,   239,   170,     0,    67,   169,   239,   170,   166,
    26,   169,   239,   170,     0,    88,     0,    89,     0,    90,
     0,    91,     0,    92,     0,   245,     0,   246,     0,   247,
     0,   248,     0,   249,     0,   250,     0,   251,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,   258,     0,   259,     0,   260,     0,   261,     0,   265,
     0,   263,     0,   262,     0,   264,     0,   274,     0,   275,
     0,   276,     0,   277,     0,   278,     0,   279,     0,   280,
     0,   281,     0,   282,     0,   283,     0,   284,     0,   285,
     0,   286,     0,   287,     0,   288,     0,   289,     0,   290,
     0,   291,     0,   292,     0,   293,     0,   294,     0,   295,
     0,   296,     0,   297,     0,   298,     0,   299,     0,    93,
   303,     0,    93,   302,     0,    94,   303,     0,    94,   302,
     0,    94,   301,     0,    94,   152,   304,   236,     0,    95,
   303,     0,    95,   302,     0,    96,   228,   304,   306,     0,
    97,   237,     0,    97,   305,   304,   237,     0,    98,     0,
    99,   303,     0,    99,   302,     0,   100,     0,   101,     0,
   102,   306,     0,   102,   308,     0,   103,     0,   104,     0,
   105,   154,   304,   153,     0,   105,   153,   304,   154,     0,
   106,     0,   107,   306,     0,   107,   308,     0,   108,   237,
     0,   108,   305,   304,   237,     0,   108,   155,     0,   109,
   235,     0,   109,   305,   304,   235,     0,   111,   155,   304,
   139,     0,   111,   139,   304,   154,     0,   112,   155,   304,
   139,     0,   112,   139,   304,   154,     0,   113,   139,   304,
   300,     0,   113,   300,   304,   139,     0,   268,     0,   269,
     0,   270,     0,   273,     0,   266,     0,   267,     0,   271,
     0,   272,     0,   110,   154,   304,   169,   152,   236,   170,
     0,   110,   154,   304,   237,     0,   110,   152,   304,   154,
     0,   110,   152,   304,   237,     0,   110,   300,   304,   152,
     0,   110,   300,   304,   139,     0,   110,   142,   304,   139,
     0,   110,   309,   304,   139,     0,   110,   306,   304,   236,
     0,   110,   306,   304,   306,     0,   110,   306,   304,   142,
     0,   110,   306,   304,   309,     0,   110,   306,   304,   300,
     0,   110,   308,   304,   237,     0,   114,     0,   115,   303,
     0,   115,   302,     0,   116,   307,     0,   117,   307,     0,
   118,   228,   304,   306,     0,   119,     0,   119,   305,     0,
   120,     0,   122,   306,     0,   123,     0,   124,   306,     0,
   125,     0,   126,   306,     0,   127,     0,   128,   306,     0,
   129,     0,   121,   236,     0,   130,   303,     0,   130,   302,
     0,   131,     0,    50,   228,   304,   306,     0,   133,   306,
     0,   134,   306,     0,   135,   306,     0,   132,     0,   136,
   303,     0,   136,   302,     0,   137,   306,     0,   138,   303,
     0,   138,   302,     0,   169,   237,   170,     0,   308,     0,
   154,   304,   308,     0,   306,     0,   139,   304,   306,     0,
   236,     0,   139,   304,   236,     0,   166,     0,   158,     0,
   159,     0,   160,     0,   141,     0,   162,     0,   161,     0,
   163,     0,   140,     0,   141,     0,   143,     0,   144,     0,
   145,     0,   146,     0,   155,     0,   139,     0,   148,     0,
   150,     0,   154,     0,   147,     0,   148,     0,   150,     0,
   154,     0,   152,     0,   149,     0,   151,     0,   157,     0,
   156,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   491,   506,   510,   531,   535,   556,   560,   563,   566,   569,
   572,   586,   589,   598,   615,   643,   650,   671,   675,   678,
   693,   714,   715,   716,   717,   718,   719,   720,   734,   735,
   736,   737,   738,   739,   740,   741,   742,   743,   744,   745,
   746,   747,   748,   749,   750,   751,   752,   753,   754,   755,
   756,   757,   758,   759,   760,   761,   762,   776,   783,   800,
   802,   817,   836,   855,   874,   893,   912,   931,   950,   969,
   989,  1009,  1028,  1047,  1066,  1086,  1106,  1126,  1145,  1161,
  1177,  1193,  1200,  1217,  1219,  1234,  1253,  1269,  1271,  1286,
  1305,  1321,  1323,  1338,  1357,  1373,  1375,  1390,  1409,  1428,
  1447,  1470,  1476,  1494,  1517,  1540,  1564,  1588,  1609,  1628,
  1657,  1664,  1681,  1689,  1696,  1712,  1719,  1736,  1744,  1761,
  1768,  1785,  1793,  1810,  1833,  1856,  1880,  1887,  1893,  1901,
  1906,  1911,  1916,  1921,  1926,  1931,  1936,  1941,  1946,  1951,
  1956,  1961,  1966,  1971,  1976,  1981,  1986,  1991,  1996,  2001,
  2006,  2011,  2016,  2021,  2026,  2031,  2036,  2041,  2046,  2051,
  2056,  2061,  2066,  2071,  2085,  2090,  2107,  2113,  2118,  2123,
  2128,  2133,  2138,  2143,  2148,  2153,  2158,  2163,  2168,  2173,
  2178,  2183,  2188,  2193,  2198,  2203,  2208,  2213,  2218,  2223,
  2228,  2233,  2238,  2243,  2248,  2253,  2258,  2263,  2268,  2273,
  2278,  2283,  2288,  2293,  2307,  2312,  2329,  2335,  2341,  2347,
  2353,  2359,  2365,  2371,  2390,  2399,  2415,  2431,  2458,  2482,
  2490,  2496,  2502,  2508,  2526,  2528,  2529,  2530,  2531,  2532,
  2533,  2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,  2542,
  2543,  2544,  2545,  2546,  2547,  2548,  2549,  2550,  2551,  2552,
  2553,  2554,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,
  2563,  2564,  2565,  2566,  2567,  2568,  2569,  2570,  2571,  2572,
  2573,  2586,  2593,  2610,  2617,  2622,  2627,  2645,  2652,  2669,
  2688,  2695,  2713,  2730,  2737,  2753,  2769,  2786,  2792,  2808,
  2825,  2842,  2848,  2864,  2882,  2888,  2904,  2911,  2917,  2933,
  2940,  2957,  2963,  2979,  2985,  3001,  3014,  3039,  3040,  3041,
  3042,  3043,  3044,  3045,  3046,  3058,  3060,  3074,  3076,  3090,
  3092,  3117,  3131,  3145,  3147,  3168,  3177,  3186,  3218,  3237,
  3255,  3262,  3279,  3297,  3315,  3334,  3340,  3357,  3375,  3393,
  3411,  3430,  3448,  3467,  3485,  3504,  3522,  3552,  3559,  3576,
  3594,  3613,  3632,  3651,  3669,  3687,  3694,  3711,  3730,  3737,
  3754,  3777,  3783,  3800,  3806,  3823,  3829,  3846,  3861,  3867,
  3872,  3877,  3882,  3887,  3892,  3909,  3915,  3920,  3925,  3930,
  3935,  3940,  3945,  3962,  3968,  3973,  3978,  3995,  4001,  4006,
  4011,  4027,  4033,  4038,  4043
};

static const char * const yytname[] = {   "$","error","$undefined.","T_NUMBER",
"T_STRING","T_OP_LOGICNOT","T_OP_LOGICOR","T_OP_LOGICAND","T_OP_LOGICEQU","T_OP_LOGICGT",
"T_OP_LOGICLT","T_OP_LOGICGE","T_OP_LOGICLE","T_OP_LOGICNE","T_OP_ADD","T_OP_SUB",
"T_OP_OR","T_OP_XOR","T_OP_AND","T_OP_SHL","T_OP_SHR","T_OP_MUL","T_OP_DIV",
"T_OP_MOD","T_OP_NOT","T_OP_DEF","T_OP_BANK","T_OP_SIN","T_OP_COS","T_OP_TAN",
"T_OP_ASIN","T_OP_ACOS","T_OP_ATAN","T_OP_ATAN2","T_OP_FDIV","T_OP_FMUL","T_OP_STRCMP",
"T_OP_STRIN","T_OP_STRSUB","T_OP_STRLEN","T_OP_STRCAT","T_OP_STRUPR","T_OP_STRLWR",
"T_OP_STRTRIM","T_OP_STRLTRIM","T_OP_STRRTRIM","NEG","T_LABEL","T_ID","T_POP_EQU",
"T_POP_SET","T_POP_EQUS","T_POP_INCLUDE","T_POP_PRINTF","T_POP_PRINTT","T_POP_PRINTV",
"T_POP_IF","T_POP_ELSE","T_POP_ENDC","T_POP_IMPORT","T_POP_EXPORT","T_POP_GLOBAL",
"T_POP_DB","T_POP_DS","T_POP_DW","T_POP_DQ","T_POP_SECTION","T_POP_ORG","T_POP_RB",
"T_POP_RW","T_POP_RQ","T_POP_ALIGN","T_POP_MACRO","T_POP_ENDM","T_POP_RSRESET",
"T_POP_RSSET","T_POP_INCBIN","T_POP_REPT","T_POP_SHIFT","T_POP_ENDR","T_POP_FAIL",
"T_POP_WARN","T_POP_PURGE","T_POP_POPS","T_POP_PUSHS","T_POP_POPO","T_POP_PUSHO",
"T_POP_OPT","T_SECT_BSS","T_SECT_VRAM","T_SECT_CODE","T_SECT_HOME","T_SECT_HRAM",
"T_Z80_ADC","T_Z80_ADD","T_Z80_AND","T_Z80_BIT","T_Z80_CALL","T_Z80_CCF","T_Z80_CP",
"T_Z80_CPL","T_Z80_DAA","T_Z80_DEC","T_Z80_DI","T_Z80_EI","T_Z80_EX","T_Z80_HALT",
"T_Z80_INC","T_Z80_JP","T_Z80_JR","T_Z80_LD","T_Z80_LDI","T_Z80_LDD","T_Z80_LDIO",
"T_Z80_NOP","T_Z80_OR","T_Z80_POP","T_Z80_PUSH","T_Z80_RES","T_Z80_RET","T_Z80_RETI",
"T_Z80_RST","T_Z80_RL","T_Z80_RLA","T_Z80_RLC","T_Z80_RLCA","T_Z80_RR","T_Z80_RRA",
"T_Z80_RRC","T_Z80_RRCA","T_Z80_SBC","T_Z80_SCF","T_Z80_STOP","T_Z80_SLA","T_Z80_SRA",
"T_Z80_SRL","T_Z80_SUB","T_Z80_SWAP","T_Z80_XOR","T_MODE_A","T_MODE_B","T_MODE_C",
"T_MODE_C_IND","T_MODE_D","T_MODE_E","T_MODE_H","T_MODE_L","T_MODE_AF","T_MODE_BC",
"T_MODE_BC_IND","T_MODE_DE","T_MODE_DE_IND","T_MODE_SP","T_MODE_SP_IND","T_MODE_HL",
"T_MODE_HL_IND","T_MODE_HL_INDDEC","T_MODE_HL_INDINC","T_CC_NZ","T_CC_Z","T_CC_NC",
"T_CC_EQ","T_CC_NE","T_CC_LT","'\\n'","':'","','","'('","')'","'['","']'","asmfile",
"lastline","lines","line","label","macro","@1","macroargs","macroarg","pseudoop",
"simple_pseudoop","opt","@2","opt_list","opt_list_entry","popo","pusho","pops",
"pushs","fail","warn","shift","rept","macrodef","equs","rsset","rsreset","rq",
"rw","rb","ds","db","dw","dq","purge","@3","purge_list","purge_list_entry","import",
"import_list","import_list_entry","export","export_list","export_list_entry",
"global","global_list","global_list_entry","equ","set","include","incbin","printt",
"printv","printf","if","else","endc","const_3bit","constlist_8bit","constlist_8bit_entry",
"constlist_16bit","constlist_16bit_entry","constlist_32bit","constlist_32bit_entry",
"const_PCrel","const_8bit","const_16bit","relocconst","const","string","section",
"org","sectiontype","cpu_command","z80_adc","z80_add","z80_and","z80_bit","z80_call",
"z80_ccf","z80_cp","z80_cpl","z80_daa","z80_dec","z80_di","z80_ei","z80_ex",
"z80_halt","z80_inc","z80_jp","z80_jr","z80_ldi","z80_ldd","z80_ldio","z80_ld",
"z80_ld_hl","z80_ld_sp","z80_ld_mem","z80_ld_cind","z80_ld_rr","z80_ld_r","z80_ld_a",
"z80_ld_ss","z80_nop","z80_or","z80_pop","z80_push","z80_res","z80_ret","z80_reti",
"z80_rl","z80_rla","z80_rlc","z80_rlca","z80_rr","z80_rra","z80_rrc","z80_rrca",
"z80_rst","z80_sbc","z80_scf","z80_set","z80_sla","z80_sra","z80_srl","z80_stop",
"z80_sub","z80_swap","z80_xor","op_mem_ind","op_hl_ss","op_a_r","op_a_n","comma",
"ccode","reg_r","reg_tt","reg_ss","reg_rr",""
};
#endif

static const short yyr1[] = {     0,
   171,   172,   172,   173,   173,   174,   174,   174,   174,   174,
   174,   175,   175,   175,   175,   177,   176,   178,   178,   178,
   179,   180,   180,   180,   180,   180,   180,   180,   181,   181,
   181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
   181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
   181,   181,   181,   181,   181,   181,   181,   183,   182,   184,
   184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
   194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
   204,   206,   205,   207,   207,   208,   209,   210,   210,   211,
   212,   213,   213,   214,   215,   216,   216,   217,   218,   219,
   220,   221,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   229,   230,   230,   230,   231,   231,   232,   232,   233,
   233,   234,   234,   235,   236,   237,   238,   238,   238,   238,
   238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
   238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
   238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
   238,   238,   238,   238,   238,   238,   239,   239,   239,   239,
   239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
   239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
   239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
   239,   239,   239,   239,   239,   239,   240,   240,   240,   240,
   240,   240,   240,   240,   241,   241,   241,   241,   242,   243,
   243,   243,   243,   243,   244,   244,   244,   244,   244,   244,
   244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
   244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
   244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
   244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
   244,   245,   245,   246,   246,   246,   246,   247,   247,   248,
   249,   249,   250,   251,   251,   252,   253,   254,   254,   255,
   256,   257,   257,   258,   259,   259,   260,   260,   260,   261,
   261,   262,   262,   263,   263,   264,   264,   265,   265,   265,
   265,   265,   265,   265,   265,   266,   266,   267,   267,   268,
   268,   269,   270,   271,   271,   272,   272,   272,   273,   274,
   275,   275,   276,   277,   278,   279,   279,   280,   281,   282,
   283,   284,   285,   286,   287,   288,   289,   290,   290,   291,
   292,   293,   294,   295,   296,   297,   297,   298,   299,   299,
   300,   301,   301,   302,   302,   303,   303,   304,   305,   305,
   305,   305,   305,   305,   305,   306,   306,   306,   306,   306,
   306,   306,   306,   307,   307,   307,   307,   308,   308,   308,
   308,   309,   309,   309,   309
};

static const short yyr2[] = {     0,
     2,     0,     1,     0,     3,     0,     1,     2,     2,     2,
     1,     0,     1,     2,     3,     0,     3,     0,     1,     3,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
     3,     1,     1,     1,     1,     1,     2,     2,     1,     2,
     3,     3,     2,     1,     3,     3,     3,     2,     2,     2,
     2,     0,     3,     1,     3,     1,     2,     1,     3,     1,
     2,     1,     3,     1,     2,     1,     3,     1,     3,     3,
     2,     2,     6,     2,     2,     2,     2,     1,     1,     1,
     1,     3,     0,     1,     1,     1,     3,     0,     1,     1,
     3,     0,     1,     1,     1,     1,     1,     1,     1,     2,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
     2,     4,     4,     6,     6,     4,     4,     4,     4,     4,
     4,     6,     6,     6,     4,     3,     1,     1,     1,     2,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
     2,     2,     6,     6,     4,     4,     4,     4,     4,     4,
     6,     4,     6,     6,     4,     3,     1,     8,     6,     4,
     4,     4,     4,     4,     4,     7,     9,    12,     9,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     2,     2,     2,     2,     2,     4,     2,     2,     4,
     2,     4,     1,     2,     2,     1,     1,     2,     2,     1,
     1,     4,     4,     1,     2,     2,     2,     4,     2,     2,
     4,     4,     4,     4,     4,     4,     4,     1,     1,     1,
     1,     1,     1,     1,     1,     7,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
     2,     2,     2,     2,     4,     1,     2,     1,     2,     1,
     2,     1,     2,     1,     2,     1,     2,     2,     2,     1,
     4,     2,     2,     2,     1,     2,     2,     2,     2,     2,
     3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1
};

static const short yydefact[] = {     4,
    12,    13,     1,     3,     7,    11,    28,    27,    26,    25,
    24,    22,    23,     0,     0,     0,     0,     0,     0,    14,
     5,    16,     0,     0,     0,     0,     0,     0,   108,   109,
     0,     0,     0,   113,     0,   118,   122,     0,     0,    74,
     0,     0,     0,    69,     0,     0,    82,    65,    66,    63,
    64,    58,     0,     0,     0,     0,     0,   283,     0,   286,
   287,     0,   290,   291,     0,   294,     0,     0,     0,     0,
     0,     0,     0,   330,     0,     0,     0,     0,   336,   338,
     0,     0,   340,     0,   342,     0,   344,     0,   346,     0,
   350,   355,     0,     0,     0,     0,     0,     0,     9,    10,
    57,    55,    56,    53,    54,    50,    51,    49,    48,    46,
    45,    42,    39,    40,    41,    52,    36,    37,    38,    29,
    47,    31,    32,    30,    33,    34,    35,    43,    44,     8,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   244,   243,   245,
   242,   312,   313,   308,   309,   310,   314,   315,   311,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
   267,   268,   269,   270,   271,   168,   207,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   167,     0,    99,   169,   100,    72,    77,    76,    75,
    71,    15,    18,     0,   110,   101,   106,   104,   105,   107,
    90,    87,    88,    94,    91,    92,    98,    95,    96,   128,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
    79,   111,   114,   125,   129,    78,    80,   116,   119,   126,
   129,    81,   120,   123,     0,     0,    73,   102,    70,    67,
    68,     0,     0,   383,   376,   377,   378,   379,   380,   381,
   382,   366,   273,   272,   364,   388,   389,   391,   390,   276,
   275,   274,   362,   279,   278,     0,   372,   369,   370,   371,
   374,   373,   375,   281,     0,   285,   284,   383,   391,   390,
   288,   289,     0,     0,   295,   296,   299,   297,     0,   300,
   124,     0,     0,   392,   393,     0,     0,   395,   394,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   332,   331,   387,   384,   385,   386,   333,   334,     0,   337,
   347,   339,   341,   343,   345,   349,   348,   352,   353,   354,
   357,   356,   358,   360,   359,   170,   190,   191,   192,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
    17,    19,   368,     0,     0,     0,     0,   130,   149,   150,
   151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   118,   122,     0,     0,     0,
    86,    83,    84,    62,    59,    60,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   181,   206,   171,   172,   173,   174,   175,   176,   177,   178,
   179,   180,   183,   182,   184,   185,   186,   187,   188,   189,
    18,   351,    89,    93,    97,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
   112,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   142,   141,   143,   144,   145,   146,   147,   148,   117,
   121,   220,   221,   222,   223,   224,   215,     0,     0,     0,
     0,   367,   365,   277,   363,   280,   282,   293,   292,   298,
   301,   322,   318,   319,     0,   317,   361,   321,   320,   326,
   324,   328,   325,   327,   329,   323,   303,   302,   305,   304,
   306,   307,   335,   202,   195,   196,   197,   198,   199,   200,
     0,     0,     0,     0,     0,     0,   205,     0,   210,   211,
   212,   213,   214,    20,   153,   152,   156,   157,   158,   159,
   160,   161,     0,     0,     0,     0,     0,   165,     0,     0,
     0,     0,    85,    61,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   103,     0,   201,   193,   194,   203,   204,     0,   209,   162,
   154,   155,   163,   164,     0,   216,     0,   316,     0,     0,
     0,     0,   208,   217,     0,   219,     0,     0,   218,     0,
     0,     0
};

static const short yydefgoto[] = {   710,
     3,     1,     4,     5,    99,   223,   421,   422,     6,   100,
   101,   283,   475,   476,   102,   103,   104,   105,   106,   107,
   108,   109,     7,     8,   110,   111,     9,    10,    11,   112,
   113,   114,   115,   116,   282,   472,   473,   117,   232,   233,
   118,   235,   236,   119,   238,   239,    12,    13,   120,   121,
   122,   123,   124,   125,   126,   127,   224,   261,   262,   267,
   268,   272,   273,   330,   292,   269,   264,   225,   215,   128,
   129,   587,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   341,   300,
   293,   294,   424,   315,   295,   357,   303,   344
};

static const short yypact[] = {-32768,
     7,   -10,-32768,  -148,  2293,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,  1380,  1380,   100,  1380,  1380,  1380,   -66,
-32768,-32768,  1380,   100,  1380,   100,  1380,  1380,-32768,-32768,
   -30,   -25,   -12,  1334,  1380,  1334,  1334,   100,  -159,-32768,
  1380,   100,  1380,-32768,   100,   100,-32768,-32768,-32768,-32768,
-32768,-32768,   885,   731,   885,  1380,  1138,-32768,   885,-32768,
-32768,   196,-32768,-32768,   -98,-32768,   196,   931,  1138,   124,
  -120,   -91,  -131,-32768,   885,   -27,   -27,  1380,  -116,-32768,
  1334,   -38,-32768,   -38,-32768,   -38,-32768,   -38,-32768,   885,
-32768,-32768,   -38,   -38,   -38,   885,   -38,   885,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1380,  1380,  1380,
  1380,  -105,  -104,  -101,   -83,   -82,   -76,   -56,   -55,   -53,
   -52,   -48,   -43,   -37,   -35,   -34,   -11,    -8,    -6,    -4,
     0,   114,  1380,  2264,-32768,  2264,-32768,  2264,  2264,  2264,
-32768,-32768,   164,   -31,  2264,-32768,  2264,-32768,  2264,  2264,
-32768,-32768,     3,-32768,-32768,     6,-32768,-32768,    13,-32768,
  1334,  1334,  1334,  1334,    11,    21,    23,    27,    28,    34,
    57,    58,    93,    94,   104,   110,   125,   132,-32768,  1334,
-32768,    14,-32768,  2426,    20,  2264,-32768,   168,-32768,  2426,
-32768,-32768,   172,  2426,   177,  1380,  2264,   210,  2264,-32768,
-32768,    70,   287,   -31,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -31,   -31,-32768,
-32768,-32768,-32768,-32768,-32768,   -31,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   -31,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   -31,   -31,-32768,-32768,-32768,-32768,   -31,-32768,
  2426,   -31,   -31,-32768,-32768,   -31,   -31,-32768,-32768,  1334,
   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -31,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   329,
  1380,  1380,  1380,  1380,  1380,  1380,  1380,  1380,  1380,   100,
   100,   100,   100,   100,   100,   100,   100,   100,   100,   330,
   992,  1380,  1380,  1380,  1380,  1380,  1380,  1380,  1380,  1380,
  1380,  1380,  1380,  1380,  1380,  1380,  1380,  1380,  1380,-32768,
-32768,   213,-32768,   -38,   -30,   -25,   -12,-32768,-32768,-32768,
-32768,   332,   334,  1380,  1380,  1380,  1380,  1380,  1380,  1380,
  1380,  1380,   100,   100,   100,  1047,  1334,  1334,  1334,  1334,
  1334,  1334,  1334,  1334,  1334,  1334,  1334,  1334,  1334,  1334,
  1334,  1334,  1334,  1334,  1334,  1334,  1334,   -19,   236,  1380,
-32768,-32768,   217,-32768,-32768,   219,  1092,  1334,    12,   -38,
  1334,   230,   233,  1334,  1334,   248,  1288,   178,   246,  -130,
   685,  1334,   278,   264,   280,   276,   311,   282,   314,   -38,
   286,  1182,  1450,  1468,  1496,  1514,  1542,  2039,  2057,  2085,
   289,   291,   292,   293,   294,   295,   297,   309,   310,   312,
-32768,-32768,   218,   218,   218,   306,   306,   306,   306,   306,
   131,   131,   267,   267,   267,    59,    59,-32768,-32768,-32768,
   164,-32768,-32768,-32768,-32768,   313,   315,  1560,  1578,  1631,
  1677,  1741,  1759,  2103,  2138,  2156,   298,   316,   319,-32768,
-32768,   343,   343,   343,   453,   453,   453,   453,   453,   391,
   391,   275,   275,   275,    67,    67,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  -154,   344,  2174,    70,
   287,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   327,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  1380,  1380,  1380,   100,   100,  1380,-32768,   100,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,  1380,  1380,  1380,   100,   100,-32768,   436,  1380,
   483,  1380,-32768,-32768,  1334,  1794,  1812,  1840,   345,   346,
  2218,   347,  1858,  1876,  1922,   348,   349,   342,   296,   351,
  2264,   353,-32768,-32768,-32768,-32768,-32768,  1380,-32768,-32768,
-32768,-32768,-32768,-32768,  1380,   355,  1380,-32768,  1975,   643,
   486,   774,-32768,-32768,   361,-32768,  1380,   974,-32768,   524,
   531,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    -7,-32768,-32768,-32768,
-32768,-32768,   -33,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -54,-32768,-32768,   134,-32768,
-32768,   109,-32768,-32768,   130,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   -26,   113,-32768,    95,
-32768,    96,-32768,    77,   -32,   -40,    89,   -14,    41,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -49,-32768,
   -22,    38,   928,   -18,   103,   487,   -36,    74
};


#define	YYLAST		2449


static const short yytable[] = {   214,
   216,   263,   218,   219,   220,   221,    -2,   349,   608,   276,
   227,   659,   229,   230,   660,    21,   314,   231,   345,  -115,
   266,   609,   234,   350,   307,   322,   277,   328,   279,   306,
   326,   301,   304,   343,   346,   237,   316,   340,    14,    15,
    16,   308,   309,   310,   311,   312,   313,   347,   361,   329,
   332,   359,   351,     2,   323,   324,   217,    17,    18,    19,
   360,   380,   381,   348,   226,   382,   228,   366,   582,   583,
   584,   585,   586,   371,   265,   374,   271,   271,   275,   417,
   418,   419,   278,   383,   384,   280,   281,   463,   464,   465,
   385,   302,   305,   271,   271,   271,   317,   271,   222,   271,
   318,   285,   286,   187,   287,   288,   289,   290,   271,   271,
   386,   387,   352,   388,   389,   271,   291,   471,   390,   353,
   354,   271,   355,   391,   270,   274,   356,   367,   400,   392,
   271,   393,   394,   372,   423,   375,   271,   204,   271,   206,
   207,   208,   209,   210,   211,   270,   412,   413,   414,   415,
   416,   417,   418,   419,    20,   395,   270,   331,   396,   296,
   397,   297,   398,   319,   321,   320,   399,   420,   425,   325,
    -6,   426,   342,   376,   377,   378,   379,   432,   427,   447,
   240,   187,   241,  -115,   362,  -115,   363,   433,   364,   434,
   365,   242,   243,   435,   436,   368,   369,   370,   401,   373,
   437,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,   204,   258,   206,   207,   208,
   209,   210,   211,   438,   439,   259,   405,   406,   407,   408,
   409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
   419,   402,   403,   404,   405,   406,   407,   408,   409,   410,
   411,   412,   413,   414,   415,   416,   417,   418,   419,   440,
   441,   469,   318,   285,   286,   333,   287,   288,   289,   290,
   442,   296,   334,   297,   335,   336,   443,   337,   291,   338,
   339,   271,   271,   271,   271,   415,   416,   417,   418,   419,
   474,   444,   340,   461,   462,   463,   464,   465,   445,   489,
   271,   402,   403,   404,   405,   406,   407,   408,   409,   410,
   411,   412,   413,   414,   415,   416,   417,   418,   419,   410,
   411,   412,   413,   414,   415,   416,   417,   418,   419,   428,
   429,   430,   431,   466,   318,   285,   286,   467,   287,   288,
   289,   290,   468,   296,   260,   297,   605,   319,   446,   320,
   291,   451,   452,   453,   454,   455,   456,   457,   458,   459,
   460,   461,   462,   463,   464,   465,   502,   503,   504,   505,
   506,   507,   508,   509,   510,   470,   501,   521,   541,   546,
   271,   547,   590,   598,   591,   599,   602,   523,   524,   525,
   526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
   536,   537,   538,   539,   540,   588,   458,   459,   460,   461,
   462,   463,   464,   465,   263,   607,   616,   617,   618,   548,
   549,   550,   551,   552,   553,   554,   555,   556,   270,   619,
   511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
   597,   612,   595,   600,   592,   594,   604,   606,   621,   620,
   340,   615,   622,   624,   634,   589,   635,   636,   611,   638,
   637,   678,   639,   656,   640,   696,   456,   457,   458,   459,
   460,   461,   462,   463,   464,   465,   641,   642,   665,   643,
   645,   657,   646,   557,   558,   559,   658,   265,   271,   271,
   271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
   271,   271,   271,   271,   271,   271,   271,   271,   680,   661,
   695,   705,   686,   687,   689,   693,   694,   271,   271,   697,
   701,   271,   698,   711,   271,   271,   542,   271,   271,   707,
   712,   271,   271,   644,   544,   663,   562,   563,   564,   565,
   566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
   576,   577,   578,   579,   270,   274,   545,   664,   543,   561,
   580,   601,   581,   358,   614,     0,     0,     0,     0,   270,
     0,     0,   270,   331,     0,   270,   270,     0,     0,   593,
   270,     0,   596,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   613,     0,     0,     0,     0,     0,     0,
     0,     0,   623,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   666,   667,   668,     0,
     0,   671,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   682,     0,     0,     0,     0,     0,   673,   674,
   675,     0,     0,     0,     0,   679,     0,   681,   402,   403,
   404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
   414,   415,   416,   417,   418,   419,     0,     0,     0,     0,
     0,     0,     0,   699,   669,   670,     0,     0,   672,     0,
   700,     0,   702,     0,     0,     0,     0,   240,   187,   241,
     0,     0,   708,     0,     0,     0,   676,   677,   242,   243,
     0,     0,     0,     0,     0,   271,     0,     0,   244,   245,
   246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
   256,   257,   204,   258,   206,   207,   208,   209,   210,   211,
     0,     0,   259,   240,   187,   241,     0,     0,     0,     0,
     0,     0,     0,     0,   242,   243,     0,     0,     0,     0,
     0,     0,     0,     0,   244,   245,   246,   247,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   257,   204,   258,
   206,   207,   208,   209,   210,   211,     0,     0,   259,   402,
   403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
   413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   704,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   318,   285,   286,   610,   287,   288,   289,
   290,     0,     0,   334,     0,   335,     0,     0,     0,   291,
   338,   339,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   340,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
   285,   286,     0,   287,   288,   289,   290,     0,   296,     0,
   297,     0,   298,     0,   299,   291,     0,   240,   187,   241,
     0,     0,     0,     0,     0,     0,     0,   260,   242,   243,
     0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
   246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
   256,   257,   204,   258,   206,   207,   208,   209,   210,   211,
     0,     0,   259,   240,   187,   241,     0,     0,     0,     0,
     0,     0,     0,   706,   242,   243,     0,     0,     0,     0,
     0,     0,     0,     0,   244,   245,   246,   247,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   257,   204,   258,
   206,   207,   208,   209,   210,   211,     0,     0,   259,   402,
   403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
   413,   414,   415,   416,   417,   418,   419,   402,   403,   404,
   405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
   415,   416,   417,   418,   419,     0,     0,     0,     0,     0,
     0,     0,     0,   284,   285,   286,     0,   287,   288,   289,
   290,     0,     0,     0,     0,     0,     0,     0,     0,   291,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   260,   448,   449,   450,   451,   452,   453,   454,   455,
   456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     0,   307,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   327,     0,     0,   308,   309,
   310,   311,   312,   313,   240,   187,   241,   260,     0,     0,
     0,     0,     0,     0,     0,   242,   243,     0,     0,     0,
     0,     0,     0,     0,     0,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,   204,
   258,   206,   207,   208,   209,   210,   211,     0,     0,   259,
   240,   187,   241,   709,     0,     0,     0,     0,     0,     0,
     0,   242,   243,     0,     0,     0,     0,     0,     0,   522,
     0,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,   204,   258,   206,   207,   208,
   209,   210,   211,     0,     0,   259,     0,   402,   403,   404,
   405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
   415,   416,   417,   418,   419,     0,     0,     0,     0,     0,
     0,   477,     0,     0,   560,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   478,   479,     0,     0,     0,
   318,   285,   286,   480,   287,   288,   289,   290,     0,     0,
     0,     0,   481,     0,     0,     0,   291,     0,     0,     0,
   482,   483,     0,     0,     0,     0,   484,     0,   260,   485,
   486,     0,     0,   487,   488,     0,     0,     0,   490,   491,
   492,   493,   494,   495,   496,   497,   498,   499,   307,     0,
     0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
   240,   187,   241,     0,     0,   308,   309,   310,   311,   312,
   313,   242,   243,     0,   260,     0,     0,     0,     0,     0,
     0,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,   204,   258,   206,   207,   208,
   209,   210,   211,     0,     0,   259,   240,   187,   241,     0,
     0,     0,     0,     0,     0,     0,     0,   242,   243,   625,
     0,     0,     0,     0,     0,     0,     0,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,   204,   258,   206,   207,   208,   209,   210,   211,     0,
     0,   259,   186,   187,   188,     0,     0,     0,     0,     0,
     0,     0,     0,   189,   190,     0,     0,     0,     0,     0,
     0,     0,     0,   191,   192,     0,   193,   194,   195,   196,
   197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
   207,   208,   209,   210,   211,     0,     0,   212,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   260,   402,   403,   404,   405,   406,
   407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
   417,   418,   419,   402,   403,   404,   405,   406,   407,   408,
   409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
   419,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   260,   402,   403,   404,   405,   406,   407,   408,   409,   410,
   411,   412,   413,   414,   415,   416,   417,   418,   419,   402,
   403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
   413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   213,   402,   403,   404,
   405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
   415,   416,   417,   418,   419,   402,   403,   404,   405,   406,
   407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
   417,   418,   419,   402,   403,   404,   405,   406,   407,   408,
   409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
   419,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   626,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   627,   402,   403,   404,   405,
   406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
   416,   417,   418,   419,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   628,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   629,   402,   403,   404,   405,   406,   407,   408,   409,
   410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   647,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   648,   402,   403,   404,   405,
   406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
   416,   417,   418,   419,   402,   403,   404,   405,   406,   407,
   408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
   418,   419,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   649,   402,
   403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
   413,   414,   415,   416,   417,   418,   419,   402,   403,   404,
   405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
   415,   416,   417,   418,   419,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   650,   402,   403,   404,   405,   406,
   407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
   417,   418,   419,   402,   403,   404,   405,   406,   407,   408,
   409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
   419,   402,   403,   404,   405,   406,   407,   408,   409,   410,
   411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   651,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   652,   402,   403,   404,
   405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
   415,   416,   417,   418,   419,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   683,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   684,
   402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
   412,   413,   414,   415,   416,   417,   418,   419,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   685,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   690,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   691,   402,   403,   404,   405,   406,   407,
   408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
   418,   419,   402,   403,   404,   405,   406,   407,   408,   409,
   410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   692,
   402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
   412,   413,   414,   415,   416,   417,   418,   419,   402,   403,
   404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
   414,   415,   416,   417,   418,   419,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   703,   402,   403,   404,   405,   406,   407,   408,
   409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
   419,   402,   403,   404,   405,   406,   407,   408,   409,   410,
   411,   412,   413,   414,   415,   416,   417,   418,   419,   402,
   403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
   413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
     0,     0,     0,     0,   631,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   632,   402,   403,   404,   405,   406,   407,   408,
   409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
   419,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   653,   402,
   403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
   413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   654,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   655,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   662,
    22,     0,    23,     0,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     0,     0,     0,     0,     0,     0,    40,    41,    42,    43,
    44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
     0,     0,     0,   688,     0,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,   448,   449,   450,   451,   452,   453,   454,   455,   456,
   457,   458,   459,   460,   461,   462,   463,   464,   465
};

static const short yycheck[] = {    14,
    15,    34,    17,    18,    19,    72,     0,   139,   139,   169,
    25,   166,    27,    28,   169,   164,    57,    48,   139,     0,
    35,   152,    48,    73,   141,    62,    41,    68,    43,    56,
    67,    54,    55,    70,   155,    48,    59,   169,    49,    50,
    51,   158,   159,   160,   161,   162,   163,   139,    81,    68,
    69,    78,    75,    47,   153,   154,    16,    68,    69,    70,
    79,   167,   167,   155,    24,   167,    26,    90,    88,    89,
    90,    91,    92,    96,    34,    98,    36,    37,    38,    21,
    22,    23,    42,   167,   167,    45,    46,    21,    22,    23,
   167,    54,    55,    53,    54,    55,    59,    57,   165,    59,
   139,   140,   141,     4,   143,   144,   145,   146,    68,    69,
   167,   167,    75,   167,   167,    75,   155,    48,   167,   147,
   148,    81,   150,   167,    36,    37,   154,    90,    15,   167,
    90,   167,   167,    96,   166,    98,    96,    38,    98,    40,
    41,    42,    43,    44,    45,    57,    16,    17,    18,    19,
    20,    21,    22,    23,   165,   167,    68,    69,   167,   148,
   167,   150,   167,   152,    62,   154,   167,     4,   166,    67,
   164,   166,    70,   188,   189,   190,   191,   167,   166,   166,
     3,     4,     5,   164,    82,   166,    84,   167,    86,   167,
    88,    14,    15,   167,   167,    93,    94,    95,   213,    97,
   167,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,   167,   167,    48,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,   167,
   167,   276,   139,   140,   141,   142,   143,   144,   145,   146,
   167,   148,   149,   150,   151,   152,   167,   154,   155,   156,
   157,   241,   242,   243,   244,    19,    20,    21,    22,    23,
     4,   167,   169,    19,    20,    21,    22,    23,   167,   340,
   260,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,   241,
   242,   243,   244,   166,   139,   140,   141,   166,   143,   144,
   145,   146,   166,   148,   167,   150,   169,   152,   260,   154,
   155,     9,    10,    11,    12,    13,    14,    15,    16,    17,
    18,    19,    20,    21,    22,    23,   381,   382,   383,   384,
   385,   386,   387,   388,   389,   166,    48,    48,   166,    48,
   340,    48,   166,   154,   166,   153,   139,   402,   403,   404,
   405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
   415,   416,   417,   418,   419,   170,    16,    17,    18,    19,
    20,    21,    22,    23,   447,   170,   139,   154,   139,   434,
   435,   436,   437,   438,   439,   440,   441,   442,   340,   154,
   390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
   481,   491,   479,   484,   477,   478,   487,   488,   498,   139,
   169,   492,   139,   168,   166,   470,   166,   166,   491,   166,
   168,    26,   168,   166,   168,   170,    14,    15,    16,    17,
    18,    19,    20,    21,    22,    23,   168,   168,   152,   168,
   168,   166,   168,   443,   444,   445,   168,   447,   448,   449,
   450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
   460,   461,   462,   463,   464,   465,   466,   467,    26,   166,
   169,    26,   168,   168,   168,   168,   168,   477,   478,   169,
   166,   481,   170,     0,   484,   485,   424,   487,   488,   169,
     0,   491,   492,   541,   426,   590,   448,   449,   450,   451,
   452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
   462,   463,   464,   465,   466,   467,   427,   591,   425,   447,
   466,   485,   467,    77,   491,    -1,    -1,    -1,    -1,   481,
    -1,    -1,   484,   485,    -1,   487,   488,    -1,    -1,   477,
   492,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   631,   632,   633,    -1,
    -1,   636,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   665,    -1,    -1,    -1,    -1,    -1,   653,   654,
   655,    -1,    -1,    -1,    -1,   660,    -1,   662,     6,     7,
     8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   688,   634,   635,    -1,    -1,   638,    -1,
   695,    -1,   697,    -1,    -1,    -1,    -1,     3,     4,     5,
    -1,    -1,   707,    -1,    -1,    -1,   656,   657,    14,    15,
    -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    -1,    -1,    48,     3,     4,     5,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    -1,    -1,    48,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   145,
   146,    -1,    -1,   149,    -1,   151,    -1,    -1,    -1,   155,
   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
   140,   141,    -1,   143,   144,   145,   146,    -1,   148,    -1,
   150,    -1,   152,    -1,   154,   155,    -1,     3,     4,     5,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    14,    15,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    -1,    -1,    48,     3,     4,     5,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   170,    14,    15,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    -1,    -1,    48,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,     6,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   139,   140,   141,    -1,   143,   144,   145,
   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   167,     6,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,   158,   159,
   160,   161,   162,   163,     3,     4,     5,   167,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    -1,    -1,    48,
     3,     4,     5,   170,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,   168,
    -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    -1,    -1,    48,    -1,     6,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   298,   299,    -1,    -1,    -1,
   139,   140,   141,   306,   143,   144,   145,   146,    -1,    -1,
    -1,    -1,   315,    -1,    -1,    -1,   155,    -1,    -1,    -1,
   323,   324,    -1,    -1,    -1,    -1,   329,    -1,   167,   332,
   333,    -1,    -1,   336,   337,    -1,    -1,    -1,   341,   342,
   343,   344,   345,   346,   347,   348,   349,   350,   141,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,
     3,     4,     5,    -1,    -1,   158,   159,   160,   161,   162,
   163,    14,    15,    -1,   167,    -1,    -1,    -1,    -1,    -1,
    -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    -1,    -1,    48,     3,     4,     5,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,   168,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
    -1,    48,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   167,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   167,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   167,     6,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    19,    20,    21,    22,    23,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   168,     6,     7,     8,     9,
    10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   168,     6,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   168,     6,     7,     8,     9,
    10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,    21,    22,    23,     6,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,     6,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   168,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   168,     6,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   168,     6,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,     6,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,     6,     7,
     8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   168,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   166,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
    48,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
    78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
    -1,    -1,    -1,   166,    -1,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void __yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = (short)(yystate);

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  ErrorReport("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 511 ".\asmy.y"
{
		/* increment current line number */
		nLineNo++ ;
		/* increment total number of lines */
		g_totalLines++ ;
		;
    break;}
case 5:
#line 536 ".\asmy.y"
{
		/* increment current line number */
		nLineNo++ ;
		/* increment total number of lines */
		g_totalLines++ ;
		;
    break;}
case 13:
#line 590 ".\asmy.y"
{
		if (yyvsp[0].tzSym[0]=='.')
			sym_AddLocalReloc(yyvsp[0].tzSym) ;
		else
			sym_AddReloc(yyvsp[0].tzSym) ;
		;
    break;}
case 14:
#line 599 ".\asmy.y"
{
		/* is the first character a period signifying a local label? */
		if (yyvsp[-1].tzSym[0]=='.')
			{
			/* add a relocatable local label */
			sym_AddLocalReloc(yyvsp[-1].tzSym) ;
			}
		else
			{
			/* add a relocatable label */
			sym_AddReloc(yyvsp[-1].tzSym) ;
			}

		;
    break;}
case 15:
#line 616 ".\asmy.y"
{
		/* is the first character a period signifying a local label? */
		if (yyvsp[-2].tzSym[0]=='.')
			{
			/* report an error */
			ErrorReport("Local symbols cannot be exported") ;
			}

		/* add a relocatable label */
		sym_AddReloc(yyvsp[-2].tzSym) ;
		/* export the label */
		sym_Export(yyvsp[-2].tzSym) ;
		;
    break;}
case 16:
#line 645 ".\asmy.y"
{
		yy_set_state(LEX_STATE_MACROARGS) ;
		;
    break;}
case 17:
#line 650 ".\asmy.y"
{
						yy_set_state(LEX_STATE_NORMAL) ;
						if(!fstk_RunMacro(yyvsp[-2].tzSym))
							{
							ErrorReport("No such macro") ;
							}
		
						;
    break;}
case 21:
#line 696 ".\asmy.y"
{
		/* add a new macro argument to the list */
		sym_AddNewMacroArg(yyvsp[0].tzString) ;
		;
    break;}
case 58:
#line 778 ".\asmy.y"
{
		yy_set_state(LEX_STATE_MACROARGS) ;
		;
    break;}
case 59:
#line 783 ".\asmy.y"
{
		yy_set_state(LEX_STATE_NORMAL) ;
		;
    break;}
case 62:
#line 819 ".\asmy.y"
{
		opt_Parse(yyvsp[0].tzString) ;
		;
    break;}
case 63:
#line 838 ".\asmy.y"
{
		opt_Pop() ;
		;
    break;}
case 64:
#line 857 ".\asmy.y"
{
		opt_Push() ;
		;
    break;}
case 65:
#line 876 ".\asmy.y"
{
		out_PopSection() ;
		;
    break;}
case 66:
#line 895 ".\asmy.y"
{
		out_PushSection() ;
		;
    break;}
case 67:
#line 914 ".\asmy.y"
{
		ErrorFatal(yyvsp[0].tzString) ;
		;
    break;}
case 68:
#line 933 ".\asmy.y"
{
		ErrorReport(yyvsp[0].tzString) ;
		;
    break;}
case 69:
#line 952 ".\asmy.y"
{
		sym_ShiftCurrentMacroArgs() ;
		;
    break;}
case 70:
#line 971 ".\asmy.y"
{
		copyrept() ;
		fstk_RunRept(yyvsp[0].nConstValue) ;
		;
    break;}
case 71:
#line 991 ".\asmy.y"
{
		copymacro() ;
		sym_AddMacro(yyvsp[-2].tzSym) ;
		;
    break;}
case 72:
#line 1011 ".\asmy.y"
{
		sym_AddString(yyvsp[-2].tzSym, yyvsp[0].tzString) ;
		;
    break;}
case 73:
#line 1030 ".\asmy.y"
{
		sym_AddSet("_RS", yyvsp[0].nConstValue) ;
		;
    break;}
case 74:
#line 1049 ".\asmy.y"
{
		sym_AddSet("_RS", 0) ;
		;
    break;}
case 75:
#line 1068 ".\asmy.y"
{
		sym_AddEqu(yyvsp[-2].tzSym, sym_GetConstantValue("_RS")) ;
		sym_AddSet("_RS", sym_GetConstantValue("_RS") + 4 * yyvsp[0].nConstValue) ;
		;
    break;}
case 76:
#line 1088 ".\asmy.y"
{
		sym_AddEqu(yyvsp[-2].tzSym, sym_GetConstantValue("_RS")) ;
		sym_AddSet("_RS", sym_GetConstantValue("_RS") + 2 * yyvsp[0].nConstValue) ;
		;
    break;}
case 77:
#line 1108 ".\asmy.y"
{
		sym_AddEqu(yyvsp[-2].tzSym, sym_GetConstantValue("_RS")) ;
		sym_AddSet("_RS", sym_GetConstantValue("_RS") + yyvsp[0].nConstValue) ;
		;
    break;}
case 78:
#line 1128 ".\asmy.y"
{
		out_Skip(yyvsp[0].nConstValue) ;
		;
    break;}
case 82:
#line 1195 ".\asmy.y"
{
		oDontExpandStrings=1;
		;
    break;}
case 83:
#line 1200 ".\asmy.y"
{
		oDontExpandStrings=0;
		;
    break;}
case 86:
#line 1236 ".\asmy.y"
{
		sym_Purge(yyvsp[0].tzSym) ;
		;
    break;}
case 90:
#line 1288 ".\asmy.y"
{
		sym_Import(yyvsp[0].tzSym) ;
		;
    break;}
case 94:
#line 1340 ".\asmy.y"
{
		sym_Export(yyvsp[0].tzSym) ;
		;
    break;}
case 98:
#line 1392 ".\asmy.y"
{
		sym_Global(yyvsp[0].tzSym) ;
		;
    break;}
case 99:
#line 1411 ".\asmy.y"
{
		sym_AddEqu(yyvsp[-2].tzSym, yyvsp[0].nConstValue) ;
		;
    break;}
case 100:
#line 1430 ".\asmy.y"
{
		sym_AddSet(yyvsp[-2].tzSym, yyvsp[0].nConstValue) ;
		;
    break;}
case 101:
#line 1449 ".\asmy.y"
{
		if (!fstk_RunInclude(yyvsp[0].tzString))
			{
			ErrorReport("File not found") ;
			}

		;
    break;}
case 102:
#line 1472 ".\asmy.y"
{
		out_BinaryFile(yyvsp[0].tzString) ;
		;
    break;}
case 103:
#line 1477 ".\asmy.y"
{
		out_BinaryFilePartial(yyvsp[-4].tzString, yyvsp[-2].nConstValue, yyvsp[0].nConstValue) ;
		;
    break;}
case 104:
#line 1496 ".\asmy.y"
{
		if (nPass==1)
			{
			printf("%s", yyvsp[0].tzString) ;
			}

		;
    break;}
case 105:
#line 1519 ".\asmy.y"
{
		if (nPass==1)
			{
			printf("$%lX", yyvsp[0].nConstValue) ;
			}

		;
    break;}
case 106:
#line 1542 ".\asmy.y"
{
		if (nPass==1)
			{
			math_Print(yyvsp[0].nConstValue) ;
			}

		;
    break;}
case 107:
#line 1566 ".\asmy.y"
{
		g_nIFDepth++ ;
		if (!yyvsp[0].nConstValue)
			{
			if_skip_to_else();	/* will continue parsing just after ELSE or just at ENDC keyword */
			}

		;
    break;}
case 108:
#line 1591 ".\asmy.y"
{
		if_skip_to_endc() ;		/* will continue parsing just at ENDC keyword */
		;
    break;}
case 109:
#line 1612 ".\asmy.y"
{
		/* decrement conditional depth */
		g_nIFDepth-- ;
		;
    break;}
case 110:
#line 1631 ".\asmy.y"
{
		/* is the number in a 3-bit range? */
		if((yyvsp[0].nConstValue < 0) || (yyvsp[0].nConstValue > 7))
			{
			/* report a range error */
			ErrorReport("Immediate value must be 3-bit") ;
			}
		else
			{
			/* assign a 3-bit number */
			yyval.nConstValue=yyvsp[0].nConstValue&0x7 ;
			}

		;
    break;}
case 111:
#line 1660 ".\asmy.y"
{
		;
    break;}
case 112:
#line 1665 ".\asmy.y"
{
		;
    break;}
case 113:
#line 1683 ".\asmy.y"
{
		/* output a single byte of "empty" data */
		out_Skip(1) ;
		;
    break;}
case 114:
#line 1690 ".\asmy.y"
{
		/* output the specified 8-bit number */
		out_RelByte(&yyvsp[0].sVal) ;
		;
    break;}
case 115:
#line 1697 ".\asmy.y"
{
		/* output a string constant as a stream of 8-bit numbers */
		out_String(yyvsp[0].tzString) ;
		;
    break;}
case 116:
#line 1715 ".\asmy.y"
{
		;
    break;}
case 117:
#line 1720 ".\asmy.y"
{
		;
    break;}
case 118:
#line 1738 ".\asmy.y"
{
		/* output two bytes of "empty" data */
		out_Skip(2) ;
		;
    break;}
case 119:
#line 1745 ".\asmy.y"
{
		/* output the specified 16-bit number */
		out_RelWord(&yyvsp[0].sVal) ;
		;
    break;}
case 120:
#line 1764 ".\asmy.y"
{
		;
    break;}
case 121:
#line 1769 ".\asmy.y"
{
		;
    break;}
case 122:
#line 1787 ".\asmy.y"
{
		/* output four bytes of "empty" data */
		out_Skip(4) ;
		;
    break;}
case 123:
#line 1794 ".\asmy.y"
{
		/* output the specified 32-bit number */
		out_RelLong(&yyvsp[0].sVal) ;
		;
    break;}
case 124:
#line 1812 ".\asmy.y"
{
		yyval.sVal = yyvsp[0].sVal ;
		if (!rpn_isPCRelative(&yyvsp[0].sVal))
			{
			ErrorReport("Expression must be PC-relative") ;
			}

		;
    break;}
case 125:
#line 1835 ".\asmy.y"
{
		if ((!rpn_isReloc(&yyvsp[0].sVal)) && ((yyvsp[0].sVal.nVal<-128) || (yyvsp[0].sVal.nVal>255)))
			{
			ErrorReport("Expression must be 8-bit") ;
			}
			
		yyval.sVal=yyvsp[0].sVal;
		;
    break;}
case 126:
#line 1858 ".\asmy.y"
{
		if ((!rpn_isReloc(&yyvsp[0].sVal)) && ((yyvsp[0].sVal.nVal < -32768) || (yyvsp[0].sVal.nVal > 0xFFFF)))
			{
			ErrorReport("Expression must be 16-bit") ;
			}

		yyval.sVal=yyvsp[0].sVal
		;
    break;}
case 127:
#line 1882 ".\asmy.y"
{
		rpn_Symbol(&yyval.sVal,yyvsp[0].tzSym) ;
		yyval.sVal.nVal = sym_GetValue(yyvsp[0].tzSym);
		;
    break;}
case 128:
#line 1888 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,yyvsp[0].nConstValue);
		yyval.sVal.nVal = yyvsp[0].nConstValue;
		;
    break;}
case 129:
#line 1894 ".\asmy.y"
{
		ULONG r;
		r=str2int(yyvsp[0].tzString);
		rpn_Number(&yyval.sVal,r);
		yyval.sVal.nVal=r;
		;
    break;}
case 130:
#line 1902 ".\asmy.y"
{
		rpn_LOGNOT(&yyval.sVal,&yyvsp[0].sVal);
		;
    break;}
case 131:
#line 1907 ".\asmy.y"
{
		rpn_LOGOR(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 132:
#line 1912 ".\asmy.y"
{
		rpn_LOGAND(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 133:
#line 1917 ".\asmy.y"
{
		rpn_LOGEQU(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 134:
#line 1922 ".\asmy.y"
{
		rpn_LOGGT(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 135:
#line 1927 ".\asmy.y"
{
		rpn_LOGLT(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 136:
#line 1932 ".\asmy.y"
{
		rpn_LOGGE(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 137:
#line 1937 ".\asmy.y"
{
		rpn_LOGLE(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 138:
#line 1942 ".\asmy.y"
{
		rpn_LOGNE(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 139:
#line 1947 ".\asmy.y"
{
		rpn_ADD(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 140:
#line 1952 ".\asmy.y"
{
		rpn_SUB(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 141:
#line 1957 ".\asmy.y"
{
		rpn_XOR(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 142:
#line 1962 ".\asmy.y"
{
		rpn_OR(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 143:
#line 1967 ".\asmy.y"
{
		rpn_AND(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 144:
#line 1972 ".\asmy.y"
{
		rpn_SHL(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 145:
#line 1977 ".\asmy.y"
{
		rpn_SHR(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 146:
#line 1982 ".\asmy.y"
{
		rpn_MUL(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 147:
#line 1987 ".\asmy.y"
{
		rpn_DIV(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 148:
#line 1992 ".\asmy.y"
{
		rpn_MOD(&yyval.sVal,&yyvsp[-2].sVal,&yyvsp[0].sVal);
		;
    break;}
case 149:
#line 1997 ".\asmy.y"
{
		yyval.sVal = yyvsp[0].sVal;
		;
    break;}
case 150:
#line 2002 ".\asmy.y"
{
		rpn_UNNEG(&yyval.sVal,&yyvsp[0].sVal);
		;
    break;}
case 151:
#line 2007 ".\asmy.y"
{
		rpn_UNNOT(&yyval.sVal,&yyvsp[0].sVal);
		;
    break;}
case 152:
#line 2012 ".\asmy.y"
{
		rpn_Bank(&yyval.sVal,yyvsp[-1].tzSym); yyval.sVal.nVal = 0;
		;
    break;}
case 153:
#line 2017 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,sym_isConstDefined(yyvsp[-1].tzSym));
		;
    break;}
case 154:
#line 2022 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_Div(yyvsp[-3].nConstValue,yyvsp[-1].nConstValue));
		;
    break;}
case 155:
#line 2027 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_Mul(yyvsp[-3].nConstValue,yyvsp[-1].nConstValue));
		;
    break;}
case 156:
#line 2032 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_Sin(yyvsp[-1].nConstValue));
		;
    break;}
case 157:
#line 2037 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_Cos(yyvsp[-1].nConstValue));
		;
    break;}
case 158:
#line 2042 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_Tan(yyvsp[-1].nConstValue));
		;
    break;}
case 159:
#line 2047 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_ASin(yyvsp[-1].nConstValue));
		;
    break;}
case 160:
#line 2052 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_ACos(yyvsp[-1].nConstValue));
		;
    break;}
case 161:
#line 2057 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_ATan(yyvsp[-1].nConstValue));
		;
    break;}
case 162:
#line 2062 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,math_ATan2(yyvsp[-3].nConstValue,yyvsp[-1].nConstValue));
		;
    break;}
case 163:
#line 2067 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,strcmp(yyvsp[-3].tzString,yyvsp[-1].tzString));
		;
    break;}
case 164:
#line 2072 ".\asmy.y"
{
		char	*p;
		if ((p=strstr(yyvsp[-3].tzString,yyvsp[-1].tzString))!=NULL)
			{
			rpn_Number(&yyval.sVal,p-yyvsp[-3].tzString+1);
			}
		else
			{
			rpn_Number(&yyval.sVal,0);
			}
			
		;
    break;}
case 165:
#line 2086 ".\asmy.y"
{
		rpn_Number(&yyval.sVal,strlen(yyvsp[-1].tzString));
		;
    break;}
case 166:
#line 2091 ".\asmy.y"
{
		yyval.sVal = yyvsp[-1].sVal;
		;
    break;}
case 167:
#line 2109 ".\asmy.y"
{
		yyval.nConstValue = sym_GetConstantValue(yyvsp[0].tzSym);
		;
    break;}
case 168:
#line 2114 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[0].nConstValue;
		;
    break;}
case 169:
#line 2119 ".\asmy.y"
{
		yyval.nConstValue = str2int(yyvsp[0].tzString);
		;
    break;}
case 170:
#line 2124 ".\asmy.y"
{
		yyval.nConstValue = !yyvsp[0].nConstValue;
		;
    break;}
case 171:
#line 2129 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue || yyvsp[0].nConstValue;
		;
    break;}
case 172:
#line 2134 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue && yyvsp[0].nConstValue;
		;
    break;}
case 173:
#line 2139 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue == yyvsp[0].nConstValue;
		;
    break;}
case 174:
#line 2144 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue > yyvsp[0].nConstValue;
		;
    break;}
case 175:
#line 2149 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue < yyvsp[0].nConstValue;
		;
    break;}
case 176:
#line 2154 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue >= yyvsp[0].nConstValue;
		;
    break;}
case 177:
#line 2159 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue <= yyvsp[0].nConstValue;
		;
    break;}
case 178:
#line 2164 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue != yyvsp[0].nConstValue;
		;
    break;}
case 179:
#line 2169 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue + yyvsp[0].nConstValue;
		;
    break;}
case 180:
#line 2174 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue - yyvsp[0].nConstValue;
		;
    break;}
case 181:
#line 2179 ".\asmy.y"
{
		yyval.nConstValue = sym_GetDefinedValue(yyvsp[-2].tzSym) - sym_GetDefinedValue(yyvsp[0].tzSym);
		;
    break;}
case 182:
#line 2184 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue ^ yyvsp[0].nConstValue;
		;
    break;}
case 183:
#line 2189 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue | yyvsp[0].nConstValue;
		;
    break;}
case 184:
#line 2194 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue & yyvsp[0].nConstValue;
		;
    break;}
case 185:
#line 2199 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue << yyvsp[0].nConstValue;
		;
    break;}
case 186:
#line 2204 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue >> yyvsp[0].nConstValue;
		;
    break;}
case 187:
#line 2209 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue * yyvsp[0].nConstValue;
		;
    break;}
case 188:
#line 2214 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue / yyvsp[0].nConstValue;
		;
    break;}
case 189:
#line 2219 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-2].nConstValue % yyvsp[0].nConstValue;
		;
    break;}
case 190:
#line 2224 ".\asmy.y"
{
		yyval.nConstValue = +yyvsp[0].nConstValue;
		;
    break;}
case 191:
#line 2229 ".\asmy.y"
{
		yyval.nConstValue = -yyvsp[0].nConstValue;
		;
    break;}
case 192:
#line 2234 ".\asmy.y"
{
		yyval.nConstValue = 0xFFFFFFFF^yyvsp[0].nConstValue;
		;
    break;}
case 193:
#line 2239 ".\asmy.y"
{
		yyval.nConstValue = math_Div(yyvsp[-3].nConstValue,yyvsp[-1].nConstValue);
		;
    break;}
case 194:
#line 2244 ".\asmy.y"
{
		yyval.nConstValue = math_Mul(yyvsp[-3].nConstValue,yyvsp[-1].nConstValue);
		;
    break;}
case 195:
#line 2249 ".\asmy.y"
{
		yyval.nConstValue = math_Sin(yyvsp[-1].nConstValue);
		;
    break;}
case 196:
#line 2254 ".\asmy.y"
{
		yyval.nConstValue = math_Cos(yyvsp[-1].nConstValue);
		;
    break;}
case 197:
#line 2259 ".\asmy.y"
{
		yyval.nConstValue = math_Tan(yyvsp[-1].nConstValue);
		;
    break;}
case 198:
#line 2264 ".\asmy.y"
{
		yyval.nConstValue = math_ASin(yyvsp[-1].nConstValue);
		;
    break;}
case 199:
#line 2269 ".\asmy.y"
{
		yyval.nConstValue = math_ACos(yyvsp[-1].nConstValue);
		;
    break;}
case 200:
#line 2274 ".\asmy.y"
{
		yyval.nConstValue = math_ATan(yyvsp[-1].nConstValue);
		;
    break;}
case 201:
#line 2279 ".\asmy.y"
{
		yyval.nConstValue = math_ATan2(yyvsp[-3].nConstValue,yyvsp[-1].nConstValue);
		;
    break;}
case 202:
#line 2284 ".\asmy.y"
{
		yyval.nConstValue = sym_isConstDefined(yyvsp[-1].tzSym);
		;
    break;}
case 203:
#line 2289 ".\asmy.y"
{
		yyval.nConstValue = strcmp( yyvsp[-3].tzString, yyvsp[-1].tzString );
		;
    break;}
case 204:
#line 2294 ".\asmy.y"
{
		char	*p;
  		if( (p=strstr(yyvsp[-3].tzString,yyvsp[-1].tzString))!=NULL )
			{
			yyval.nConstValue = p-yyvsp[-3].tzString+1;
			}
		else
			{
			yyval.nConstValue = 0;
			}
		
		;
    break;}
case 205:
#line 2308 ".\asmy.y"
{
		yyval.nConstValue = strlen(yyvsp[-1].tzString);
		;
    break;}
case 206:
#line 2313 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[-1].nConstValue;
		;
    break;}
case 207:
#line 2331 ".\asmy.y"
{
		strcpy(yyval.tzString,yyvsp[0].tzString);
		;
    break;}
case 208:
#line 2336 ".\asmy.y"
{
		strncpy(yyval.tzString,yyvsp[-5].tzString+yyvsp[-3].nConstValue-1,yyvsp[-1].nConstValue); 
		yyval.tzString[yyvsp[-1].nConstValue]=0;
		;
    break;}
case 209:
#line 2342 ".\asmy.y"
{
		strcpy(yyval.tzString,yyvsp[-3].tzString); 
		strcat(yyval.tzString,yyvsp[-1].tzString);
		;
    break;}
case 210:
#line 2348 ".\asmy.y"
{
		strcpy(yyval.tzString,yyvsp[-1].tzString); 
		strupr(yyval.tzString);
		;
    break;}
case 211:
#line 2354 ".\asmy.y"
{
		strcpy(yyval.tzString,yyvsp[-1].tzString); 
		strlwr(yyval.tzString);
		;
    break;}
case 212:
#line 2360 ".\asmy.y"
{
		strcpy(yyval.tzString,yyvsp[-1].tzString); 
		strtrim(yyval.tzString);
		;
    break;}
case 213:
#line 2366 ".\asmy.y"
{
		strcpy(yyval.tzString,yyvsp[-1].tzString); 
		strltrim(yyval.tzString);
		;
    break;}
case 214:
#line 2372 ".\asmy.y"
{
		strcpy(yyval.tzString,yyvsp[-1].tzString); 
		strrtrim(yyval.tzString);
		;
    break;}
case 215:
#line 2393 ".\asmy.y"
{
		ValidateSectionName(yyvsp[-2].tzString) ;
		out_NewSection(yyvsp[-2].tzString,yyvsp[0].nConstValue);
		;
    break;}
case 216:
#line 2400 ".\asmy.y"
{
		ValidateSectionName(yyvsp[-5].tzString) ;
		ValidateBankAddress(yyvsp[-1].nConstValue) ;
		out_NewAbsSection(yyvsp[-5].tzString,yyvsp[-3].nConstValue,yyvsp[-1].nConstValue,-1);
		;
    break;}
case 217:
#line 2416 ".\asmy.y"
{
		ValidateSectionName(yyvsp[-7].tzString) ;
		if (yyvsp[-5].nConstValue==SECT_CODE)
			{
			ValidateBankNumber(yyvsp[-1].nConstValue) ;
			out_NewAbsSection(yyvsp[-7].tzString,yyvsp[-5].nConstValue,-1,yyvsp[-1].nConstValue);
			}
		else
			{
			ErrorReport( "BANK only allowed for CODE/DATA" );
			}

		;
    break;}
case 218:
#line 2432 ".\asmy.y"
{
		ValidateSectionName(yyvsp[-10].tzString) ;
		if( yyvsp[-8].nConstValue==SECT_CODE )
			{
			ValidateBankAddress(yyvsp[-6].nConstValue) ;
			ValidateBankNumber(yyvsp[-1].nConstValue) ;
			out_NewAbsSection(yyvsp[-10].tzString,yyvsp[-8].nConstValue,yyvsp[-6].nConstValue,yyvsp[-1].nConstValue);
			}
		else
			{
			ErrorReport( "BANK only allowed for CODE/DATA" );
			}

		;
    break;}
case 219:
#line 2460 ".\asmy.y"
{
		char	sectionName[64] ;
					
		ValidateBankAddress(yyvsp[-6].nConstValue) ;
		ValidateBankNumber(yyvsp[-1].nConstValue) ;
		MakeUniqueSection(sectionName) ;
		out_NewAbsSection(sectionName, SECT_CODE, yyvsp[-6].nConstValue, yyvsp[-1].nConstValue) ;
		;
    break;}
case 220:
#line 2485 ".\asmy.y"
{
		yyval.nConstValue=SECT_BSS;
		;
    break;}
case 221:
#line 2491 ".\asmy.y"
{
		yyval.nConstValue=SECT_VRAM;
		;
    break;}
case 222:
#line 2497 ".\asmy.y"
{
		yyval.nConstValue=SECT_CODE;
		;
    break;}
case 223:
#line 2503 ".\asmy.y"
{
		yyval.nConstValue=SECT_HOME;
		;
    break;}
case 224:
#line 2509 ".\asmy.y"
{
		yyval.nConstValue=SECT_HRAM;
		;
    break;}
case 272:
#line 2588 ".\asmy.y"
{
		out_AbsByte(0xCE);
		out_RelByte(&yyvsp[0].sVal);
		;
    break;}
case 273:
#line 2594 ".\asmy.y"
{
		out_AbsByte(0x88|yyvsp[0].nConstValue);
		;
    break;}
case 274:
#line 2612 ".\asmy.y"
{
		out_AbsByte(0xC6);
		out_RelByte(&yyvsp[0].sVal);
		;
    break;}
case 275:
#line 2618 ".\asmy.y"
{
		out_AbsByte(0x80|yyvsp[0].nConstValue);
		;
    break;}
case 276:
#line 2623 ".\asmy.y"
{
		out_AbsByte(0x09|(yyvsp[0].nConstValue<<4));
		;
    break;}
case 277:
#line 2628 ".\asmy.y"
{
		out_AbsByte(0xE8);
		out_RelByte(&yyvsp[0].sVal);
		;
    break;}
case 278:
#line 2647 ".\asmy.y"
{
		out_AbsByte(0xE6) ;
		out_RelByte(&yyvsp[0].sVal) ;
		;
    break;}
case 279:
#line 2653 ".\asmy.y"
{
		out_AbsByte(0xA0|yyvsp[0].nConstValue) ;
		;
    break;}
case 280:
#line 2671 ".\asmy.y"
{
		out_AbsByte(0xCB) ;
		out_AbsByte(0x40|(yyvsp[-2].nConstValue<<3)|yyvsp[0].nConstValue) ;
		;
    break;}
case 281:
#line 2690 ".\asmy.y"
{
		out_AbsByte(0xCD) ;
		out_RelWord(&yyvsp[0].sVal) ;
		;
    break;}
case 282:
#line 2696 ".\asmy.y"
{
		out_AbsByte(0xC4|(yyvsp[-2].nConstValue<<3)) ;
		out_RelWord(&yyvsp[0].sVal) ;
		;
    break;}
case 283:
#line 2715 ".\asmy.y"
{
		out_AbsByte(0x3F) ;
		;
    break;}
case 284:
#line 2732 ".\asmy.y"
{
		out_AbsByte(0xFE) ;
		out_RelByte(&yyvsp[0].sVal) ;
		;
    break;}
case 285:
#line 2738 ".\asmy.y"
{
		out_AbsByte(0xB8|yyvsp[0].nConstValue) ;
		;
    break;}
case 286:
#line 2755 ".\asmy.y"
{
		out_AbsByte(0x2F) ;
		;
    break;}
case 287:
#line 2771 ".\asmy.y"
{
		out_AbsByte(0x27) ;
		;
    break;}
case 288:
#line 2788 ".\asmy.y"
{
		out_AbsByte(0x05|(yyvsp[0].nConstValue<<3)) ;
		;
    break;}
case 289:
#line 2793 ".\asmy.y"
{
		out_AbsByte(0x0B|(yyvsp[0].nConstValue<<4)) ;
		;
    break;}
case 290:
#line 2810 ".\asmy.y"
{
		out_AbsByte(0xF3) ;
		;
    break;}
case 291:
#line 2827 ".\asmy.y"
{
		out_AbsByte(0xFB) ;
		;
    break;}
case 292:
#line 2844 ".\asmy.y"
{
		out_AbsByte(0xE3) ;
		;
    break;}
case 293:
#line 2849 ".\asmy.y"
{
		out_AbsByte(0xE3) ;
		;
    break;}
case 294:
#line 2866 ".\asmy.y"
{
		out_AbsByte(0x76) ;
		out_AbsByte(0x00) ;
		;
    break;}
case 295:
#line 2884 ".\asmy.y"
{
		out_AbsByte(0x04|(yyvsp[0].nConstValue<<3)) ;
		;
    break;}
case 296:
#line 2889 ".\asmy.y"
{
		out_AbsByte(0x03|(yyvsp[0].nConstValue<<4)) ;
		;
    break;}
case 297:
#line 2906 ".\asmy.y"
{
		out_AbsByte(0xC3) ;
		out_RelWord(&yyvsp[0].sVal) ;
		;
    break;}
case 298:
#line 2912 ".\asmy.y"
{
		out_AbsByte(0xC2|(yyvsp[-2].nConstValue<<3)) ;
		out_RelWord(&yyvsp[0].sVal) ;
		;
    break;}
case 299:
#line 2918 ".\asmy.y"
{
		out_AbsByte(0xE9) ;
		;
    break;}
case 300:
#line 2935 ".\asmy.y"
{
		out_AbsByte(0x18) ;
		out_PCRelByte(&yyvsp[0].sVal) ;
		;
    break;}
case 301:
#line 2941 ".\asmy.y"
{
		out_AbsByte(0x20|(yyvsp[-2].nConstValue<<3)) ;
		out_PCRelByte(&yyvsp[0].sVal) ;
		;
    break;}
case 302:
#line 2959 ".\asmy.y"
{
		out_AbsByte(0x02|(2<<4)) ;
		;
    break;}
case 303:
#line 2964 ".\asmy.y"
{
		out_AbsByte(0x0A|(2<<4)) ;
		;
    break;}
case 304:
#line 2981 ".\asmy.y"
{
		out_AbsByte(0x02|(3<<4)) ;
		;
    break;}
case 305:
#line 2986 ".\asmy.y"
{
		out_AbsByte(0x0A|(3<<4)) ;
		;
    break;}
case 306:
#line 3003 ".\asmy.y"
{
		rpn_CheckHRAM(&yyvsp[0].sVal,&yyvsp[0].sVal);
		if ((!rpn_isReloc(&yyvsp[0].sVal)) &&	(yyvsp[0].sVal.nVal<0 || (yyvsp[0].sVal.nVal>0xFF && yyvsp[0].sVal.nVal<0xFF00) || yyvsp[0].sVal.nVal>0xFFFF) )
			{
			ErrorReport( "Source must be in the IO/HRAM area" );
			}

						out_AbsByte(0xF0);
						yyvsp[0].sVal.nVal&=0xFF;
						out_RelByte(&yyvsp[0].sVal);
					;
    break;}
case 307:
#line 3015 ".\asmy.y"
{
						rpn_CheckHRAM(&yyvsp[-2].sVal,&yyvsp[-2].sVal);

						if( (!rpn_isReloc(&yyvsp[-2].sVal))
						&&	(yyvsp[-2].sVal.nVal<0 || (yyvsp[-2].sVal.nVal>0xFF && yyvsp[-2].sVal.nVal<0xFF00) || yyvsp[-2].sVal.nVal>0xFFFF) )
						{
							ErrorReport( "Destination must be in the IO/HRAM area" );
						}

						out_AbsByte(0xE0);
						yyvsp[-2].sVal.nVal&=0xFF;
						out_RelByte(&yyvsp[-2].sVal);
					;
    break;}
case 316:
#line 3059 ".\asmy.y"
{ out_AbsByte(0xF8); out_RelByte(&yyvsp[-1].sVal); ;
    break;}
case 317:
#line 3061 ".\asmy.y"
{ out_AbsByte(0x01|(REG_HL<<4)); out_RelWord(&yyvsp[0].sVal) ;
    break;}
case 318:
#line 3075 ".\asmy.y"
{ out_AbsByte(0xF9); ;
    break;}
case 319:
#line 3077 ".\asmy.y"
{ out_AbsByte(0x01|(REG_SP<<4)); out_RelWord(&yyvsp[0].sVal) ;
    break;}
case 320:
#line 3091 ".\asmy.y"
{ out_AbsByte(0x08); out_RelWord(&yyvsp[-2].sVal); ;
    break;}
case 321:
#line 3093 ".\asmy.y"
{
						if( (!rpn_isReloc(&yyvsp[-2].sVal)) && yyvsp[-2].sVal.nVal>=0xFF00)
						{
							out_AbsByte(0xE0);
							out_AbsByte(yyvsp[-2].sVal.nVal&0xFF);
						}
						else
						{
							out_AbsByte(0xEA);
							out_RelWord(&yyvsp[-2].sVal);
						}
					;
    break;}
case 322:
#line 3118 ".\asmy.y"
{ out_AbsByte(0xE2); ;
    break;}
case 323:
#line 3132 ".\asmy.y"
{ out_AbsByte(0x02|(yyvsp[-2].nConstValue<<4)); ;
    break;}
case 324:
#line 3146 ".\asmy.y"
{ out_AbsByte(0x06|(yyvsp[-2].nConstValue<<3)); out_RelByte(&yyvsp[0].sVal); ;
    break;}
case 325:
#line 3148 ".\asmy.y"
{
						if( (yyvsp[-2].nConstValue==REG_HL_IND) && (yyvsp[0].nConstValue==REG_HL_IND) )
						{
							ErrorReport( "LD (HL),(HL) not allowed" );
						}
						else
							out_AbsByte(0x40|(yyvsp[-2].nConstValue<<3)|yyvsp[0].nConstValue);
					;
    break;}
case 326:
#line 3169 ".\asmy.y"
{
						if( yyvsp[-2].nConstValue==REG_A )
							out_AbsByte(0xF2);
						else
						{
							ErrorReport( "Destination operand must be A" );
						}
					;
    break;}
case 327:
#line 3178 ".\asmy.y"
{
						if( yyvsp[-2].nConstValue==REG_A )
							out_AbsByte(0x0A|(yyvsp[0].nConstValue<<4));
						else
						{
							ErrorReport( "Destination operand must be A" );
						}
					;
    break;}
case 328:
#line 3187 ".\asmy.y"
{
						if( yyvsp[-2].nConstValue==REG_A )
						{
							if( (!rpn_isReloc(&yyvsp[0].sVal)) && yyvsp[0].sVal.nVal>=0xFF00 )
							{
								out_AbsByte(0xF0);
								out_AbsByte(yyvsp[0].sVal.nVal&0xFF);
							}
							else
							{
								out_AbsByte(0xFA);
								out_RelWord(&yyvsp[0].sVal);
							}
						}
						else
						{
							ErrorReport( "Destination operand must be A" );
						}
					;
    break;}
case 329:
#line 3220 ".\asmy.y"
{
		out_AbsByte(0x01|(yyvsp[-2].nConstValue<<4)) ;
		out_RelWord(&yyvsp[0].sVal) ;
		;
    break;}
case 330:
#line 3239 ".\asmy.y"
{
		out_AbsByte(0x00);
		;
    break;}
case 331:
#line 3257 ".\asmy.y"
{
		out_AbsByte(0xF6);
		out_RelByte(&yyvsp[0].sVal);
		;
    break;}
case 332:
#line 3263 ".\asmy.y"
{
		out_AbsByte(0xB0|yyvsp[0].nConstValue) ;
		;
    break;}
case 333:
#line 3281 ".\asmy.y"
{
		out_AbsByte(0xC1|(yyvsp[0].nConstValue<<4));
		;
    break;}
case 334:
#line 3299 ".\asmy.y"
{
		out_AbsByte(0xC5|(yyvsp[0].nConstValue<<4));
		;
    break;}
case 335:
#line 3317 ".\asmy.y"
{
		out_AbsByte(0xCB);
		out_AbsByte(0x80|(yyvsp[-2].nConstValue<<3)|yyvsp[0].nConstValue);
		;
    break;}
case 336:
#line 3336 ".\asmy.y"
{
		out_AbsByte(0xC9);
		;
    break;}
case 337:
#line 3341 ".\asmy.y"
{
		out_AbsByte(0xC0|(yyvsp[0].nConstValue<<3));
		;
    break;}
case 338:
#line 3359 ".\asmy.y"
{
		out_AbsByte(0xD9);
		;
    break;}
case 339:
#line 3377 ".\asmy.y"
{
		out_AbsByte(0xCB); out_AbsByte(0x10|yyvsp[0].nConstValue);
		;
    break;}
case 340:
#line 3395 ".\asmy.y"
{
		out_AbsByte(0x17);
		;
    break;}
case 341:
#line 3413 ".\asmy.y"
{
		out_AbsByte(0xCB);
		out_AbsByte(0x00|yyvsp[0].nConstValue);
		;
    break;}
case 342:
#line 3432 ".\asmy.y"
{
		out_AbsByte(0x07);
		;
    break;}
case 343:
#line 3450 ".\asmy.y"
{
		out_AbsByte(0xCB);
		out_AbsByte(0x18|yyvsp[0].nConstValue);
		;
    break;}
case 344:
#line 3469 ".\asmy.y"
{
		out_AbsByte(0x1F);
		;
    break;}
case 345:
#line 3487 ".\asmy.y"
{
		out_AbsByte(0xCB);
		out_AbsByte(0x08|yyvsp[0].nConstValue);
		;
    break;}
case 346:
#line 3506 ".\asmy.y"
{
		out_AbsByte(0x0F);
		;
    break;}
case 347:
#line 3524 ".\asmy.y"
{
		if (rpn_isReloc(&yyvsp[0].sVal))
			{
			ErrorReport("Address for RST must be absolute") ;
			}
		else if ((yyvsp[0].sVal.nVal&0x38)!=yyvsp[0].sVal.nVal)
			{
			ErrorReport("Invalid address for RST") ;
			}
		else
			{
			out_AbsByte(0xC7|yyvsp[0].sVal.nVal) ;
			}

		;
    break;}
case 348:
#line 3554 ".\asmy.y"
{
		out_AbsByte(0xDE) ;
		out_RelByte(&yyvsp[0].sVal) ;
		;
    break;}
case 349:
#line 3560 ".\asmy.y"
{
		out_AbsByte(0x98|yyvsp[0].nConstValue) ;
		;
    break;}
case 350:
#line 3578 ".\asmy.y"
{
		out_AbsByte(0x37);
		;
    break;}
case 351:
#line 3596 ".\asmy.y"
{
		out_AbsByte(0xCB) ;
		out_AbsByte(0xC0|(yyvsp[-2].nConstValue<<3)|yyvsp[0].nConstValue) ;
		;
    break;}
case 352:
#line 3615 ".\asmy.y"
{
		out_AbsByte(0xCB) ;
		out_AbsByte(0x20|yyvsp[0].nConstValue) ;
		;
    break;}
case 353:
#line 3634 ".\asmy.y"
{
		out_AbsByte(0xCB) ;
		out_AbsByte(0x28|yyvsp[0].nConstValue) ;
		;
    break;}
case 354:
#line 3653 ".\asmy.y"
{
		out_AbsByte(0xCB);
		out_AbsByte(0x38|yyvsp[0].nConstValue);
		;
    break;}
case 355:
#line 3671 ".\asmy.y"
{
		out_AbsByte(0x10);
		out_AbsByte(0x00);
		;
    break;}
case 356:
#line 3689 ".\asmy.y"
{
		out_AbsByte(0xD6);
		out_RelByte(&yyvsp[0].sVal);
		;
    break;}
case 357:
#line 3695 ".\asmy.y"
{
		out_AbsByte(0x90|yyvsp[0].nConstValue);
		;
    break;}
case 358:
#line 3713 ".\asmy.y"
{
		out_AbsByte(0xCB);
		out_AbsByte(0x30|yyvsp[0].nConstValue);
		;
    break;}
case 359:
#line 3732 ".\asmy.y"
{
		out_AbsByte(0xEE);
		out_RelByte(&yyvsp[0].sVal);
		;
    break;}
case 360:
#line 3738 ".\asmy.y"
{
		out_AbsByte(0xA8|yyvsp[0].nConstValue);
		;
    break;}
case 361:
#line 3756 ".\asmy.y"
{
		yyval.sVal = yyvsp[-1].sVal
		;
    break;}
case 362:
#line 3779 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[0].nConstValue
		;
    break;}
case 363:
#line 3784 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[0].nConstValue
		;
    break;}
case 364:
#line 3802 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[0].nConstValue
		;
    break;}
case 365:
#line 3807 ".\asmy.y"
{
		yyval.nConstValue = yyvsp[0].nConstValue
		;
    break;}
case 366:
#line 3825 ".\asmy.y"
{
		yyval.sVal = yyvsp[0].sVal
		;
    break;}
case 367:
#line 3830 ".\asmy.y"
{
		yyval.sVal = yyvsp[0].sVal
		;
    break;}
case 369:
#line 3863 ".\asmy.y"
{
		yyval.nConstValue = CC_NZ
		;
    break;}
case 370:
#line 3868 ".\asmy.y"
{
		yyval.nConstValue = CC_Z
		;
    break;}
case 371:
#line 3873 ".\asmy.y"
{
		yyval.nConstValue = CC_NC
		;
    break;}
case 372:
#line 3878 ".\asmy.y"
{
		yyval.nConstValue = CC_C
		;
    break;}
case 373:
#line 3883 ".\asmy.y"
{
		yyval.nConstValue = CC_NZ
		;
    break;}
case 374:
#line 3888 ".\asmy.y"
{
		yyval.nConstValue = CC_Z
		;
    break;}
case 375:
#line 3893 ".\asmy.y"
{
		yyval.nConstValue = CC_C
		;
    break;}
case 376:
#line 3911 ".\asmy.y"
{
		yyval.nConstValue = REG_B
		;
    break;}
case 377:
#line 3916 ".\asmy.y"
{
		yyval.nConstValue = REG_C
		;
    break;}
case 378:
#line 3921 ".\asmy.y"
{
		yyval.nConstValue = REG_D
		;
    break;}
case 379:
#line 3926 ".\asmy.y"
{
		yyval.nConstValue = REG_E
		;
    break;}
case 380:
#line 3931 ".\asmy.y"
{
		yyval.nConstValue = REG_H
		;
    break;}
case 381:
#line 3936 ".\asmy.y"
{
		yyval.nConstValue = REG_L
		;
    break;}
case 382:
#line 3941 ".\asmy.y"
{
		yyval.nConstValue = REG_HL_IND
		;
    break;}
case 383:
#line 3946 ".\asmy.y"
{
		yyval.nConstValue = REG_A
		;
    break;}
case 384:
#line 3964 ".\asmy.y"
{
		yyval.nConstValue = REG_BC
		;
    break;}
case 385:
#line 3969 ".\asmy.y"
{
		yyval.nConstValue = REG_DE
		;
    break;}
case 386:
#line 3974 ".\asmy.y"
{
		yyval.nConstValue = REG_HL
		;
    break;}
case 387:
#line 3979 ".\asmy.y"
{
		yyval.nConstValue = REG_AF
		;
    break;}
case 388:
#line 3997 ".\asmy.y"
{
		yyval.nConstValue = REG_BC
		;
    break;}
case 389:
#line 4002 ".\asmy.y"
{
		yyval.nConstValue = REG_DE
		;
    break;}
case 390:
#line 4007 ".\asmy.y"
{
		yyval.nConstValue = REG_HL
		;
    break;}
case 391:
#line 4012 ".\asmy.y"
{
		yyval.nConstValue = REG_SP
		;
    break;}
case 392:
#line 4029 ".\asmy.y"
{
		yyval.nConstValue = REG_BC_IND
		;
    break;}
case 393:
#line 4034 ".\asmy.y"
{
		yyval.nConstValue = REG_DE_IND
		;
    break;}
case 394:
#line 4039 ".\asmy.y"
{
		yyval.nConstValue = REG_HL_INDINC
		;
    break;}
case 395:
#line 4044 ".\asmy.y"
{
		yyval.nConstValue = REG_HL_INDDEC
		;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      ErrorReport(msg);
	      free(msg);
	    }
	  else
	    ErrorReport ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	ErrorReport("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 4051 ".\asmy.y"

