%{
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

%}

%union
{
    char tzSym[MAXSYMLEN+1];
    char tzString[256];
    struct Expression sVal;
    SLONG nConstValue;
}

%type	<sVal>	relocconst
%type	<nConstValue>	const
%type	<nConstValue>	const_3bit
%type	<sVal>	const_8bit
%type	<sVal>	const_16bit
%type	<sVal>	const_PCrel
%type	<nConstValue>	sectiontype

%type	<tzString>	string

%token	<nConstValue>		T_NUMBER
%token	<tzString>	T_STRING

%left	T_OP_LOGICNOT
%left	T_OP_LOGICOR T_OP_LOGICAND T_OP_LOGICEQU
%left	T_OP_LOGICGT T_OP_LOGICLT T_OP_LOGICGE T_OP_LOGICLE T_OP_LOGICNE
%left	T_OP_ADD T_OP_SUB
%left	T_OP_OR T_OP_XOR T_OP_AND
%left	T_OP_SHL T_OP_SHR
%left	T_OP_MUL T_OP_DIV T_OP_MOD
%left	T_OP_NOT
%left	T_OP_DEF
%left	T_OP_BANK
%left	T_OP_SIN
%left	T_OP_COS
%left	T_OP_TAN
%left	T_OP_ASIN
%left	T_OP_ACOS
%left	T_OP_ATAN
%left	T_OP_ATAN2
%left	T_OP_FDIV
%left	T_OP_FMUL

%left	T_OP_STRCMP
%left	T_OP_STRIN
%left	T_OP_STRSUB
%left	T_OP_STRLEN
%left	T_OP_STRCAT
%left	T_OP_STRUPR
%left	T_OP_STRLWR
%left	T_OP_STRTRIM
%left	T_OP_STRLTRIM
%left	T_OP_STRRTRIM

%left	NEG     /* negation--unary minus */

%token	<tzSym> T_LABEL
%token	<tzSym> T_ID
%token	<tzSym> T_POP_EQU
%token	<tzSym> T_POP_SET
%token	<tzSym> T_POP_EQUS

%token	T_POP_INCLUDE T_POP_PRINTF T_POP_PRINTT T_POP_PRINTV T_POP_IF T_POP_ELSE T_POP_ENDC
%token	T_POP_IMPORT T_POP_EXPORT T_POP_GLOBAL
%token	T_POP_DB T_POP_DS T_POP_DW T_POP_DQ
%token	T_POP_SECTION
%token	T_POP_ORG
%token	T_POP_RB
%token	T_POP_RW
%token	T_POP_RQ
%token	T_POP_ALIGN
%token	T_POP_MACRO
%token	T_POP_ENDM
%token	T_POP_RSRESET T_POP_RSSET
%token	T_POP_INCBIN T_POP_REPT
%token	T_POP_SHIFT
%token	T_POP_ENDR
%token	T_POP_FAIL
%token	T_POP_WARN
%token	T_POP_PURGE
%token	T_POP_POPS
%token	T_POP_PUSHS
%token	T_POP_POPO
%token	T_POP_PUSHO
%token	T_POP_OPT
%token	T_SECT_BSS T_SECT_VRAM T_SECT_CODE T_SECT_HOME T_SECT_HRAM

%token	T_Z80_ADC T_Z80_ADD T_Z80_AND
%token	T_Z80_BIT
%token	T_Z80_CALL T_Z80_CCF T_Z80_CP T_Z80_CPL
%token	T_Z80_DAA T_Z80_DEC T_Z80_DI
%token	T_Z80_EI T_Z80_EX
%token	T_Z80_HALT
%token	T_Z80_INC
%token	T_Z80_JP T_Z80_JR
%token	T_Z80_LD
%token	T_Z80_LDI
%token	T_Z80_LDD
%token	T_Z80_LDIO
%token	T_Z80_NOP
%token	T_Z80_OR
%token	T_Z80_POP T_Z80_PUSH
%token	T_Z80_RES T_Z80_RET T_Z80_RETI T_Z80_RST
%token	T_Z80_RL T_Z80_RLA T_Z80_RLC T_Z80_RLCA
%token	T_Z80_RR T_Z80_RRA T_Z80_RRC T_Z80_RRCA
%token	T_Z80_SBC T_Z80_SCF T_Z80_STOP
%token	T_Z80_SLA T_Z80_SRA T_Z80_SRL T_Z80_SUB T_Z80_SWAP
%token	T_Z80_XOR

%token	T_MODE_A T_MODE_B T_MODE_C T_MODE_C_IND T_MODE_D T_MODE_E T_MODE_H T_MODE_L
%token	T_MODE_AF
%token	T_MODE_BC T_MODE_BC_IND
%token	T_MODE_DE T_MODE_DE_IND
%token	T_MODE_SP T_MODE_SP_IND
%token	T_MODE_HL T_MODE_HL_IND T_MODE_HL_INDDEC T_MODE_HL_INDINC
%token	T_CC_NZ T_CC_Z T_CC_NC T_CC_EQ T_CC_NE T_CC_LT

%type	<nConstValue>	reg_r
%type	<nConstValue>	reg_ss
%type	<nConstValue>	reg_rr
%type	<nConstValue>	reg_tt
%type	<nConstValue>	ccode
%type	<sVal>			op_a_n
%type	<nConstValue>	op_a_r
%type	<nConstValue>	op_hl_ss
%type	<sVal>			op_mem_ind
%start asmfile

%%

/********************************************************************
*																	*
* NAME: asmfile														*
*																	*
* This definition handles the definition of a generic source file.	*
*																	*
********************************************************************/

asmfile :
	lines lastline
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: lastline													*
*																	*
* This definition handles the last line in a source file.			*
* test.																*
*																	*
********************************************************************/

lastline :
	/* empty */

	/* is this a line? */
	| line
		{
		/* increment current line number */
		nLineNo++ ;
		/* increment total number of lines */
		g_totalLines++ ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: lines														*
*																	*
* This definition handles the lines in a source file.				*
* test.																*
*																	*
********************************************************************/

lines :
	/* empty */

	/* is this a line? */
	| lines line '\n'
		{
		/* increment current line number */
		nLineNo++ ;
		/* increment total number of lines */
		g_totalLines++ ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: line														*
*																	*
* This definition handles the an individual line in a source file.	*
* test.																*
*																	*
********************************************************************/

line :
	/* empty */

	/* is this a label? */
	| label

	/* is this a label followed by an opcode? */
	| label cpu_command

	/* is this a label followed by a macro? */
	| label macro

	/* is this a label followed by an assembler directive? */
	| label simple_pseudoop

	/* is this an assembler directive? */
	| pseudoop

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: label														*
*																	*
* This definition handles a label, both local and global.			*
*																	*
********************************************************************/

label :
	/* empty */
	/* is this an orphan label? */
	| T_LABEL
		{
		if ($1[0]=='.')
			sym_AddLocalReloc($1) ;
		else
			sym_AddReloc($1) ;
		}

	/* is this a label? */
	| T_LABEL ':'
		{
		/* is the first character a period signifying a local label? */
		if ($1[0]=='.')
			{
			/* add a relocatable local label */
			sym_AddLocalReloc($1) ;
			}
		else
			{
			/* add a relocatable label */
			sym_AddReloc($1) ;
			}

		}

	/* is this an exported label? */
	| T_LABEL ':' ':'
		{
		/* is the first character a period signifying a local label? */
		if ($1[0]=='.')
			{
			/* report an error */
			ErrorReport("Local symbols cannot be exported") ;
			}

		/* add a relocatable label */
		sym_AddReloc($1) ;
		/* export the label */
		sym_Export($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

macro :
	T_ID
		{
		yy_set_state(LEX_STATE_MACROARGS) ;
		}

					macroargs
						{
						yy_set_state(LEX_STATE_NORMAL) ;
						if(!fstk_RunMacro($1))
							{
							ErrorReport("No such macro") ;
							}
		
						}
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

macroargs :
	/* empty */

	/* is this a single macro argument? */
	| macroarg

	/* is this a macro argument followed by more arguments? */
	| macroarg ',' macroargs

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

macroarg :
	/* is this a valid macro argument? */
	T_STRING
		{
		/* add a new macro argument to the list */
		sym_AddNewMacroArg($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

pseudoop :	equ
				|	set
				|	rb
				|	rw
				|	rq
				|	equs
				|	macrodef
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

simple_pseudoop :	include
				|	printf
				|	printt
				|	printv
				|	if
				|	else
				|	endc
				|	import
				|	export
				|	global
				|	db
				|	dw
				|	dq
				|	ds
				|	section
				|	org
				|	rsreset
				|	rsset
				|	incbin
				|	rept
				|	shift
				|	fail
				|	warn
				|	purge
				|	pops
				|	pushs
				|	popo
				|	pusho
				|	opt
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

opt :
	T_POP_OPT
		{
		yy_set_state(LEX_STATE_MACROARGS) ;
		}

	opt_list
		{
		yy_set_state(LEX_STATE_NORMAL) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

opt_list :
	opt_list_entry
	| opt_list_entry ',' opt_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

opt_list_entry :
	T_STRING
		{
		opt_Parse($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

popo :
	T_POP_POPO
		{
		opt_Pop() ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

pusho :
	T_POP_PUSHO
		{
		opt_Push() ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

pops :
	T_POP_POPS
		{
		out_PopSection() ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

pushs :
	T_POP_PUSHS
		{
		out_PushSection() ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

fail :
	T_POP_FAIL string
		{
		ErrorFatal($2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

warn :
	T_POP_WARN string
		{
		ErrorReport($2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

shift :
	T_POP_SHIFT
		{
		sym_ShiftCurrentMacroArgs() ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

rept :
	T_POP_REPT const
		{
		copyrept() ;
		fstk_RunRept($2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

macrodef :
	T_LABEL ':' T_POP_MACRO
		{
		copymacro() ;
		sym_AddMacro($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

equs :
	T_LABEL T_POP_EQUS string
		{
		sym_AddString($1, $3) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

rsset :
	T_POP_RSSET const
		{
		sym_AddSet("_RS", $2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

rsreset :
	T_POP_RSRESET
		{
		sym_AddSet("_RS", 0) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

rq :
	T_LABEL T_POP_RQ const
		{
		sym_AddEqu($1, sym_GetConstantValue("_RS")) ;
		sym_AddSet("_RS", sym_GetConstantValue("_RS") + 4 * $3) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

rw :
	T_LABEL T_POP_RW const
		{
		sym_AddEqu($1, sym_GetConstantValue("_RS")) ;
		sym_AddSet("_RS", sym_GetConstantValue("_RS") + 2 * $3) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

rb :
	T_LABEL T_POP_RB const
		{
		sym_AddEqu($1, sym_GetConstantValue("_RS")) ;
		sym_AddSet("_RS", sym_GetConstantValue("_RS") + $3) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

ds :
	T_POP_DS const
		{
		out_Skip($2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

db :
	T_POP_DB constlist_8bit

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

dw :
	T_POP_DW constlist_16bit

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

dq :
	T_POP_DQ constlist_32bit

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

purge :
	T_POP_PURGE
		{
		oDontExpandStrings=1;
		}
		
	purge_list
		{
		oDontExpandStrings=0;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

purge_list :
	purge_list_entry
	| purge_list_entry ',' purge_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

purge_list_entry :
	T_ID
		{
		sym_Purge($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

import :
	T_POP_IMPORT import_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

import_list :
	import_list_entry
	| import_list_entry ',' import_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

import_list_entry :
	T_ID
		{
		sym_Import($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

export :
	T_POP_EXPORT export_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

export_list :
	export_list_entry
	| export_list_entry ',' export_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

export_list_entry :
	T_ID
		{
		sym_Export($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

global :
	T_POP_GLOBAL global_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

global_list :
	global_list_entry
	| global_list_entry ',' global_list

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

global_list_entry :
	T_ID
		{
		sym_Global($1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

equ :
	T_LABEL T_POP_EQU const
		{
		sym_AddEqu($1, $3) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

set :
	T_LABEL T_POP_SET const
		{
		sym_AddSet($1, $3) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

include :
	T_POP_INCLUDE string
		{
		if (!fstk_RunInclude($2))
			{
			ErrorReport("File not found") ;
			}

		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

incbin :
	T_POP_INCBIN string
		{
		out_BinaryFile($2) ;
		}
	
	| T_POP_INCBIN string ',' const ',' const
		{
		out_BinaryFilePartial($2, $4, $6) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

printt :
	T_POP_PRINTT string
		{
		if (nPass==1)
			{
			printf("%s", $2) ;
			}

		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

printv :
	T_POP_PRINTV const
		{
		if (nPass==1)
			{
			printf("$%lX", $2) ;
			}

		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

printf :
	T_POP_PRINTF const
		{
		if (nPass==1)
			{
			math_Print($2) ;
			}

		}

	/* no more sub-rules */
	;



/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

if :
	T_POP_IF const
		{
		g_nIFDepth++ ;
		if (!$2)
			{
			if_skip_to_else();	/* will continue parsing just after ELSE or just at ENDC keyword */
			}

		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

else :
	/* is this an "ELSE" pseudo-op? */
	T_POP_ELSE
		{
		if_skip_to_endc() ;		/* will continue parsing just at ENDC keyword */
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ENDC														*
*																	*
* This definition closes a conditional IF.							*
*																	*
*																	*
*																	*
********************************************************************/

endc :
	/* is this an "ENDC" pseudo-op? */
	T_POP_ENDC
		{
		/* decrement conditional depth */
		g_nIFDepth-- ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: constlist_8bit												*
*																	*
*																	*
********************************************************************/

const_3bit :
	/* is this a numeric constant? */
	const
		{
		/* is the number in a 3-bit range? */
		if(($1 < 0) || ($1 > 7))
			{
			/* report a range error */
			ErrorReport("Immediate value must be 3-bit") ;
			}
		else
			{
			/* assign a 3-bit number */
			$$=$1&0x7 ;
			}

		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: constlist_8bit												*
*																	*
*																	*
********************************************************************/

constlist_8bit :
	/* is this a single 8-bit number? */
	constlist_8bit_entry
		{
		}

	/* is this a list of 8-bit numbers? */
	| constlist_8bit_entry ',' constlist_8bit
		{
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: constlist_8bit_entry										*
*																	*
* This definition handles a single 8-bit number in a list of 8-bit	*
* numbers.															*
*																	*
********************************************************************/

constlist_8bit_entry :
	/* is this an empty entry? */
		{
		/* output a single byte of "empty" data */
		out_Skip(1) ;
		}

	/* is this an 8-bit number? */
	| const_8bit
		{
		/* output the specified 8-bit number */
		out_RelByte(&$1) ;
		}

	/* is this a string constant? */
	| string
		{
		/* output a string constant as a stream of 8-bit numbers */
		out_String($1) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: constlist_16bit												*
*																	*
*																	*
********************************************************************/

constlist_16bit :
	/* is this a single 16-bit number? */
	constlist_16bit_entry
		{
		}

	/* is this a list of 16-bit numbers? */
	| constlist_16bit_entry ',' constlist_16bit
		{
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: constlist_16bit_entry										*
*																	*
* This definition handles a single 16-bit number in a list of		*
* 16-bit numbers.													*
*																	*
********************************************************************/

constlist_16bit_entry :
	/* is this an empty entry? */
		{
		/* output two bytes of "empty" data */
		out_Skip(2) ;
		}

	/* is this a 16-bit number? */
	| const_16bit
		{
		/* output the specified 16-bit number */
		out_RelWord(&$1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: constlist_32bit												*
*																	*
*																	*
********************************************************************/

constlist_32bit :
	/* is this a single 32-bit number? */
	constlist_32bit_entry
		{
		}

	/* is this a list of 32-bit numbers? */
	| constlist_32bit_entry ',' constlist_32bit
		{
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: constlist_32bit_entry										*
*																	*
* This definition handles a single 32-bit number in a list of		*
* 32-bit numbers.													*
*																	*
********************************************************************/

constlist_32bit_entry :
	/* is this an empty entry? */
		{
		/* output four bytes of "empty" data */
		out_Skip(4) ;
		}

	/* is this a 32-bit number */
	| relocconst
		{
		/* output the specified 32-bit number */
		out_RelLong(&$1) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: const_PCrel													*
*																	*
* This definition handles a PC relative constant.					*
*																	*
********************************************************************/
const_PCrel :
	relocconst
		{
		$$ = $1 ;
		if (!rpn_isPCRelative(&$1))
			{
			ErrorReport("Expression must be PC-relative") ;
			}

		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

const_8bit :
	relocconst
		{
		if ((!rpn_isReloc(&$1)) && (($1.nVal<-128) || ($1.nVal>255)))
			{
			ErrorReport("Expression must be 8-bit") ;
			}
			
		$$=$1;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

const_16bit :
	relocconst
		{
		if ((!rpn_isReloc(&$1)) && (($1.nVal < -32768) || ($1.nVal > 0xFFFF)))
			{
			ErrorReport("Expression must be 16-bit") ;
			}

		$$=$1
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

relocconst :
	T_ID
		{
		rpn_Symbol(&$$,$1) ;
		$$.nVal = sym_GetValue($1);
		}

	| T_NUMBER
		{
		rpn_Number(&$$,$1);
		$$.nVal = $1;
		}
	
	| string
		{
		ULONG r;
		r=str2int($1);
		rpn_Number(&$$,r);
		$$.nVal=r;
		}
	
	| T_OP_LOGICNOT relocconst %prec NEG
		{
		rpn_LOGNOT(&$$,&$2);
		}
	
	| relocconst T_OP_LOGICOR relocconst
		{
		rpn_LOGOR(&$$,&$1,&$3);
		}
	
	| relocconst T_OP_LOGICAND relocconst
		{
		rpn_LOGAND(&$$,&$1,&$3);
		}
	
	| relocconst T_OP_LOGICEQU relocconst
		{
		rpn_LOGEQU(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_LOGICGT relocconst
		{
		rpn_LOGGT(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_LOGICLT relocconst
		{
		rpn_LOGLT(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_LOGICGE relocconst
		{
		rpn_LOGGE(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_LOGICLE relocconst
		{
		rpn_LOGLE(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_LOGICNE relocconst
		{
		rpn_LOGNE(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_ADD relocconst
		{
		rpn_ADD(&$$,&$1,&$3);
		}
	
	| relocconst T_OP_SUB relocconst
		{
		rpn_SUB(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_XOR relocconst
		{
		rpn_XOR(&$$,&$1,&$3);
		}
	
	| relocconst T_OP_OR relocconst
		{
		rpn_OR(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_AND relocconst
		{
		rpn_AND(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_SHL relocconst
		{
		rpn_SHL(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_SHR relocconst
		{
		rpn_SHR(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_MUL relocconst
		{
		rpn_MUL(&$$,&$1,&$3);
		}
	
	| relocconst T_OP_DIV relocconst
		{
		rpn_DIV(&$$,&$1,&$3);
		}
		
	| relocconst T_OP_MOD relocconst
		{
		rpn_MOD(&$$,&$1,&$3);
		}
		
	| T_OP_ADD relocconst %prec NEG
		{
		$$ = $2;
		}
		
	| T_OP_SUB relocconst %prec NEG
		{
		rpn_UNNEG(&$$,&$2);
		}
		
	| T_OP_NOT relocconst %prec NEG
		{
		rpn_UNNOT(&$$,&$2);
		}

	| T_OP_BANK '(' T_ID ')'
		{
		rpn_Bank(&$$,$3); $$.nVal = 0;
		}

	| T_OP_DEF '(' T_ID ')'
		{
		rpn_Number(&$$,sym_isConstDefined($3));
		}
		
	| T_OP_FDIV '(' const ',' const ')'
		{
		rpn_Number(&$$,math_Div($3,$5));
		}
		
	| T_OP_FMUL '(' const ',' const ')'
		{
		rpn_Number(&$$,math_Mul($3,$5));
		}
		
	| T_OP_SIN '(' const ')'
		{
		rpn_Number(&$$,math_Sin($3));
		}
		
	| T_OP_COS '(' const ')'
		{
		rpn_Number(&$$,math_Cos($3));
		}
		
	| T_OP_TAN '(' const ')'
		{
		rpn_Number(&$$,math_Tan($3));
		}
	
	| T_OP_ASIN '(' const ')'			
		{
		rpn_Number(&$$,math_ASin($3));
		}
		
	| T_OP_ACOS '(' const ')'			
		{
		rpn_Number(&$$,math_ACos($3));
		}
	
	| T_OP_ATAN '(' const ')'
		{
		rpn_Number(&$$,math_ATan($3));
		}
	
	| T_OP_ATAN2 '(' const ',' const ')'
		{
		rpn_Number(&$$,math_ATan2($3,$5));
		}
		
	| T_OP_STRCMP '(' string ',' string ')'
		{
		rpn_Number(&$$,strcmp($3,$5));
		}

	| T_OP_STRIN '(' string ',' string ')'
		{
		char	*p;
		if ((p=strstr($3,$5))!=NULL)
			{
			rpn_Number(&$$,p-$3+1);
			}
		else
			{
			rpn_Number(&$$,0);
			}
			
		}

	| T_OP_STRLEN '(' string ')'
		{
		rpn_Number(&$$,strlen($3));
		}
		
	| '(' relocconst ')'
		{
		$$ = $2;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

const :
	T_ID
		{
		$$ = sym_GetConstantValue($1);
		}

	| T_NUMBER
		{
		$$ = $1;
		}

	| string
		{
		$$ = str2int($1);
		}

	| T_OP_LOGICNOT const %prec NEG
		{
		$$ = !$2;
		}

	| const T_OP_LOGICOR const		
		{
		$$ = $1 || $3;
		}

	| const T_OP_LOGICAND const	
		{
		$$ = $1 && $3;
		}

	| const T_OP_LOGICEQU const		
		{
		$$ = $1 == $3;
		}

	| const T_OP_LOGICGT const 		
		{
		$$ = $1 > $3;
		}

	| const T_OP_LOGICLT const		
		{
		$$ = $1 < $3;
		}

	| const T_OP_LOGICGE const 		
		{
		$$ = $1 >= $3;
		}

	| const T_OP_LOGICLE const 		
		{
		$$ = $1 <= $3;
		}

	| const T_OP_LOGICNE const 		
		{
		$$ = $1 != $3;
		}

	| const T_OP_ADD const			
		{
		$$ = $1 + $3;
		}

	| const T_OP_SUB const			
		{
		$$ = $1 - $3;
		}

	| T_ID  T_OP_SUB T_ID				
		{
		$$ = sym_GetDefinedValue($1) - sym_GetDefinedValue($3);
		}

	| const T_OP_XOR const			
		{
		$$ = $1 ^ $3;
		}

	| const T_OP_OR const				
		{
		$$ = $1 | $3;
		}

	| const T_OP_AND const			
		{
		$$ = $1 & $3;
		}

	| const T_OP_SHL const			
		{
		$$ = $1 << $3;
		}

	| const T_OP_SHR const
		{
		$$ = $1 >> $3;
		}

	| const T_OP_MUL const			
		{
		$$ = $1 * $3;
		}

	| const T_OP_DIV const			
		{
		$$ = $1 / $3;
		}

	| const T_OP_MOD const			
		{
		$$ = $1 % $3;
		}

	| T_OP_ADD const %prec NEG		
		{
		$$ = +$2;
		}

	| T_OP_SUB const %prec NEG		
		{
		$$ = -$2;
		}

	| T_OP_NOT const %prec NEG		
		{
		$$ = 0xFFFFFFFF^$2;
		}

	| T_OP_FDIV '(' const ',' const ')'			
		{
		$$ = math_Div($3,$5);
		}

	| T_OP_FMUL '(' const ',' const ')'			
		{
		$$ = math_Mul($3,$5);
		}

	| T_OP_SIN '(' const ')'
		{
		$$ = math_Sin($3);
		}

	| T_OP_COS '(' const ')'
		{
		$$ = math_Cos($3);
		}

	| T_OP_TAN '(' const ')'
		{
		$$ = math_Tan($3);
		}
						
	| T_OP_ASIN '(' const ')'
		{
		$$ = math_ASin($3);
		}

	| T_OP_ACOS '(' const ')'
		{
		$$ = math_ACos($3);
		}

	| T_OP_ATAN '(' const ')'
		{
		$$ = math_ATan($3);
		}

	| T_OP_ATAN2 '(' const ',' const ')'
		{
		$$ = math_ATan2($3,$5);
		}

	| T_OP_DEF '(' T_ID ')'
		{
		$$ = sym_isConstDefined($3);
		}

	| T_OP_STRCMP '(' string ',' string ')'
		{
		$$ = strcmp( $3, $5 );
		}

	|	T_OP_STRIN '(' string ',' string ')'
		{
		char	*p;
  		if( (p=strstr($3,$5))!=NULL )
			{
			$$ = p-$3+1;
			}
		else
			{
			$$ = 0;
			}
		
		}

	| T_OP_STRLEN '(' string ')'
		{
		$$ = strlen($3);
		}

	| '(' const ')'
		{
		$$ = $2;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

string :
	T_STRING
		{
		strcpy($$,$1);
		}

	| T_OP_STRSUB '(' string ',' const ',' const ')'
		{
		strncpy($$,$3+$5-1,$7); 
		$$[$7]=0;
		}

	| T_OP_STRCAT '(' string ',' string ')'
		{
		strcpy($$,$3); 
		strcat($$,$5);
		}

	| T_OP_STRUPR '(' string ')'
		{
		strcpy($$,$3); 
		strupr($$);
		}

	| T_OP_STRLWR '(' string ')'
		{
		strcpy($$,$3); 
		strlwr($$);
		}

	| T_OP_STRTRIM '(' string ')'
		{
		strcpy($$,$3); 
		strtrim($$);
		}

	| T_OP_STRLTRIM '(' string ')'
		{
		strcpy($$,$3); 
		strltrim($$);
		}

	| T_OP_STRRTRIM '(' string ')'
		{
		strcpy($$,$3); 
		strrtrim($$);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: SECTION														*
*																	*
* This definition handles the various forms of the "SECTION"		*
* directive.														*
*																	*
********************************************************************/

section :
	/* is this a plain section type? */
	T_POP_SECTION string ',' sectiontype
		{
		ValidateSectionName($2) ;
		out_NewSection($2,$4);
		}

	/* is this a section type with specified address? */
	| T_POP_SECTION string ',' sectiontype '[' const ']'
		{
		ValidateSectionName($2) ;
		ValidateBankAddress($6) ;
		out_NewAbsSection($2,$4,$6,-1);
		}

/*
	| T_POP_SECTION string ',' sectiontype ',' T_OP_ALIGN '['  ']'
		{
		ValidateSectionName($2) ;
		out_NewSection($2,$4);
		}
*/

	/* is this a section type with specified bank? */	
	| T_POP_SECTION string ',' sectiontype ',' T_OP_BANK '[' const ']'
		{
		ValidateSectionName($2) ;
		if ($4==SECT_CODE)
			{
			ValidateBankNumber($8) ;
			out_NewAbsSection($2,$4,-1,$8);
			}
		else
			{
			ErrorReport( "BANK only allowed for CODE/DATA" );
			}

		}

	/* is this a section type with specified address and bank? */
	| T_POP_SECTION string ',' sectiontype '[' const ']' ',' T_OP_BANK '[' const ']'
		{
		ValidateSectionName($2) ;
		if( $4==SECT_CODE )
			{
			ValidateBankAddress($6) ;
			ValidateBankNumber($11) ;
			out_NewAbsSection($2,$4,$6,$11);
			}
		else
			{
			ErrorReport( "BANK only allowed for CODE/DATA" );
			}

		}
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ORG															*
*																	*
* This definition handles the ORG directive.						*
*																	*
********************************************************************/

org :
	T_POP_ORG '[' const ']' ',' T_OP_BANK '[' const ']'
		{
		char	sectionName[64] ;
					
		ValidateBankAddress($3) ;
		ValidateBankNumber($8) ;
		MakeUniqueSection(sectionName) ;
		out_NewAbsSection(sectionName, SECT_CODE, $3, $8) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: section types												*
*																	*
* This definition handles the various section types in a section	*
* directive.														*
*																	*
********************************************************************/

sectiontype :
	/* is this a BSS section? */
	T_SECT_BSS
		{
		$$=SECT_BSS;
		}
		
	/* is this a VRAM section? */
	| T_SECT_VRAM
		{
		$$=SECT_VRAM;
		}
	
	/* is this a CODE section? */
	| T_SECT_CODE
		{
		$$=SECT_CODE;
		}
	
	/* is this a HOME section? */
	| T_SECT_HOME
		{
		$$=SECT_HOME;
		}
		
	/* is this a HRAM section? */
	| T_SECT_HRAM
		{
		$$=SECT_HRAM;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ELSE														*
*																	*
* This definition handles the "ELSE" directive in a conditional IF	*
* test.																*
*																	*
********************************************************************/

cpu_command :
	z80_adc
	|	z80_add
	|	z80_and
	|	z80_bit
	|	z80_call
	|	z80_ccf
	|	z80_cp
	|	z80_cpl
	|	z80_daa
	|	z80_dec
	|	z80_di
	|	z80_ei
	|	z80_ex
	|	z80_halt
	|	z80_inc
	|	z80_jp
	|	z80_jr
	|	z80_ld
	|	z80_ldd
	|	z80_ldi
	|	z80_ldio
	|	z80_nop
	|	z80_or
	|	z80_pop
	|	z80_push
	|	z80_res
	|	z80_ret
	|	z80_reti
	|	z80_rl
	|	z80_rla
	|	z80_rlc
	|	z80_rlca
	|	z80_rr
	|	z80_rra
	|	z80_rrc
	|	z80_rrca
	|	z80_rst
	|	z80_sbc
	|	z80_scf
	|	z80_set
	|	z80_sla
	|	z80_sra
	|	z80_srl
	|	z80_stop
	|	z80_sub
	|	z80_swap
	|	z80_xor
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ADC															*
*																	*
* This definition handles the Z80 ADC op-code.						*
*																	*
********************************************************************/

z80_adc :
	T_Z80_ADC op_a_n
		{
		out_AbsByte(0xCE);
		out_RelByte(&$2);
		}

	| T_Z80_ADC op_a_r
		{
		out_AbsByte(0x88|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: ADD															*
*																	*
* This definition handles the Z80 ADD op-code.						*
*																	*
********************************************************************/

z80_add :
	T_Z80_ADD op_a_n
		{
		out_AbsByte(0xC6);
		out_RelByte(&$2);
		}
	
	| T_Z80_ADD op_a_r
		{
		out_AbsByte(0x80|$2);
		}
	
	| T_Z80_ADD op_hl_ss
		{
		out_AbsByte(0x09|($2<<4));
		}
		
	| T_Z80_ADD T_MODE_SP comma const_8bit
		{
		out_AbsByte(0xE8);
		out_RelByte(&$4);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_and :
	T_Z80_AND op_a_n
		{
		out_AbsByte(0xE6) ;
		out_RelByte(&$2) ;
		}

	| T_Z80_AND op_a_r
		{
		out_AbsByte(0xA0|$2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_bit :
	T_Z80_BIT const_3bit comma reg_r
		{
		out_AbsByte(0xCB) ;
		out_AbsByte(0x40|($2<<3)|$4) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_call :
	T_Z80_CALL const_16bit
		{
		out_AbsByte(0xCD) ;
		out_RelWord(&$2) ;
		}

	| T_Z80_CALL ccode comma const_16bit
		{
		out_AbsByte(0xC4|($2<<3)) ;
		out_RelWord(&$4) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ccf :
	T_Z80_CCF
		{
		out_AbsByte(0x3F) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_cp :
	T_Z80_CP op_a_n
		{
		out_AbsByte(0xFE) ;
		out_RelByte(&$2) ;
		}

	| T_Z80_CP op_a_r
		{
		out_AbsByte(0xB8|$2) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_cpl :
	T_Z80_CPL
		{
		out_AbsByte(0x2F) ;
		}

	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_daa :
	T_Z80_DAA
		{
		out_AbsByte(0x27) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_dec :
	T_Z80_DEC reg_r
		{
		out_AbsByte(0x05|($2<<3)) ;
		}

	| T_Z80_DEC reg_ss
		{
		out_AbsByte(0x0B|($2<<4)) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_di :
	T_Z80_DI
		{
		out_AbsByte(0xF3) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ei :
	T_Z80_EI
		{
		out_AbsByte(0xFB) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ex :
	T_Z80_EX T_MODE_HL comma T_MODE_SP_IND
		{
		out_AbsByte(0xE3) ;
		}

	| T_Z80_EX T_MODE_SP_IND comma T_MODE_HL
		{
		out_AbsByte(0xE3) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_halt :
	T_Z80_HALT
		{
		out_AbsByte(0x76) ;
		out_AbsByte(0x00) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: z80_inc														*
*																	*
* This definition handles the Z80 INC <register> op-code.			*
*																	*
********************************************************************/

z80_inc :
	T_Z80_INC reg_r
		{
		out_AbsByte(0x04|($2<<3)) ;
		}

	| T_Z80_INC reg_ss
		{
		out_AbsByte(0x03|($2<<4)) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_jp :
	T_Z80_JP const_16bit
		{
		out_AbsByte(0xC3) ;
		out_RelWord(&$2) ;
		}

	| T_Z80_JP ccode comma const_16bit
		{
		out_AbsByte(0xC2|($2<<3)) ;
		out_RelWord(&$4) ;
		}

	| T_Z80_JP T_MODE_HL_IND
		{
		out_AbsByte(0xE9) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_jr :
	T_Z80_JR const_PCrel
		{
		out_AbsByte(0x18) ;
		out_PCRelByte(&$2) ;
		}
		
	| T_Z80_JR ccode comma const_PCrel
		{
		out_AbsByte(0x20|($2<<3)) ;
		out_PCRelByte(&$4) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ldi :
	T_Z80_LDI T_MODE_HL_IND comma T_MODE_A
		{
		out_AbsByte(0x02|(2<<4)) ;
		}

	| T_Z80_LDI T_MODE_A comma T_MODE_HL
		{
		out_AbsByte(0x0A|(2<<4)) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ldd :
	T_Z80_LDD T_MODE_HL_IND comma T_MODE_A
		{
		out_AbsByte(0x02|(3<<4)) ;
		}

	| T_Z80_LDD T_MODE_A comma T_MODE_HL
		{
		out_AbsByte(0x0A|(3<<4)) ;
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ldio :
	T_Z80_LDIO T_MODE_A comma op_mem_ind
		{
		rpn_CheckHRAM(&$4,&$4);
		if ((!rpn_isReloc(&$4)) &&	($4.nVal<0 || ($4.nVal>0xFF && $4.nVal<0xFF00) || $4.nVal>0xFFFF) )
			{
			ErrorReport( "Source must be in the IO/HRAM area" );
			}

						out_AbsByte(0xF0);
						$4.nVal&=0xFF;
						out_RelByte(&$4);
					}
				|	T_Z80_LDIO op_mem_ind comma T_MODE_A
					{
						rpn_CheckHRAM(&$2,&$2);

						if( (!rpn_isReloc(&$2))
						&&	($2.nVal<0 || ($2.nVal>0xFF && $2.nVal<0xFF00) || $2.nVal>0xFFFF) )
						{
							ErrorReport( "Destination must be in the IO/HRAM area" );
						}

						out_AbsByte(0xE0);
						$2.nVal&=0xFF;
						out_RelByte(&$2);
					}
	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld :	z80_ld_mem
				|	z80_ld_cind
				|	z80_ld_rr
				|	z80_ld_ss
				|	z80_ld_hl
				|	z80_ld_sp
				|	z80_ld_r
				|	z80_ld_a
	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_hl :	T_Z80_LD T_MODE_HL comma '[' T_MODE_SP const_8bit ']'
					{ out_AbsByte(0xF8); out_RelByte(&$6); }
				|	T_Z80_LD T_MODE_HL comma const_16bit
					{ out_AbsByte(0x01|(REG_HL<<4)); out_RelWord(&$4) }
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_sp :	T_Z80_LD T_MODE_SP comma T_MODE_HL
					{ out_AbsByte(0xF9); }
				|	T_Z80_LD T_MODE_SP comma const_16bit
					{ out_AbsByte(0x01|(REG_SP<<4)); out_RelWord(&$4) }
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_mem :	T_Z80_LD op_mem_ind comma T_MODE_SP
					{ out_AbsByte(0x08); out_RelWord(&$2); }
				|	T_Z80_LD op_mem_ind comma T_MODE_A
					{
						if( (!rpn_isReloc(&$2)) && $2.nVal>=0xFF00)
						{
							out_AbsByte(0xE0);
							out_AbsByte($2.nVal&0xFF);
						}
						else
						{
							out_AbsByte(0xEA);
							out_RelWord(&$2);
						}
					}
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_cind :	T_Z80_LD T_MODE_C_IND comma T_MODE_A
					{ out_AbsByte(0xE2); }
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_rr :	T_Z80_LD reg_rr comma T_MODE_A
					{ out_AbsByte(0x02|($2<<4)); }
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_r :	T_Z80_LD reg_r comma const_8bit
					{ out_AbsByte(0x06|($2<<3)); out_RelByte(&$4); }
				|	T_Z80_LD reg_r comma reg_r
					{
						if( ($2==REG_HL_IND) && ($4==REG_HL_IND) )
						{
							ErrorReport( "LD (HL),(HL) not allowed" );
						}
						else
							out_AbsByte(0x40|($2<<3)|$4);
					}
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_a :	T_Z80_LD reg_r comma T_MODE_C_IND
					{
						if( $2==REG_A )
							out_AbsByte(0xF2);
						else
						{
							ErrorReport( "Destination operand must be A" );
						}
					}
				|	T_Z80_LD reg_r comma reg_rr
					{
						if( $2==REG_A )
							out_AbsByte(0x0A|($4<<4));
						else
						{
							ErrorReport( "Destination operand must be A" );
						}
					}
				|	T_Z80_LD reg_r comma op_mem_ind
					{
						if( $2==REG_A )
						{
							if( (!rpn_isReloc(&$4)) && $4.nVal>=0xFF00 )
							{
								out_AbsByte(0xF0);
								out_AbsByte($4.nVal&0xFF);
							}
							else
							{
								out_AbsByte(0xFA);
								out_RelWord(&$4);
							}
						}
						else
						{
							ErrorReport( "Destination operand must be A" );
						}
					}
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ld_ss :
	T_Z80_LD reg_ss comma const_16bit
		{
		out_AbsByte(0x01|($2<<4)) ;
		out_RelWord(&$4) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_nop :
	T_Z80_NOP
		{
		out_AbsByte(0x00);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_or :
	T_Z80_OR op_a_n
		{
		out_AbsByte(0xF6);
		out_RelByte(&$2);
		}
	
	| T_Z80_OR op_a_r
		{
		out_AbsByte(0xB0|$2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_pop :
	T_Z80_POP reg_tt
		{
		out_AbsByte(0xC1|($2<<4));
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_push :
	T_Z80_PUSH reg_tt
		{
		out_AbsByte(0xC5|($2<<4));
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_res :
	T_Z80_RES const_3bit comma reg_r
		{
		out_AbsByte(0xCB);
		out_AbsByte(0x80|($2<<3)|$4);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_ret :
	T_Z80_RET
		{
		out_AbsByte(0xC9);
		}
	
	| T_Z80_RET ccode
		{
		out_AbsByte(0xC0|($2<<3));
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_reti :
	T_Z80_RETI
		{
		out_AbsByte(0xD9);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rl :
	T_Z80_RL reg_r
		{
		out_AbsByte(0xCB); out_AbsByte(0x10|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rla :
	T_Z80_RLA
		{
		out_AbsByte(0x17);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rlc :
	T_Z80_RLC reg_r
		{
		out_AbsByte(0xCB);
		out_AbsByte(0x00|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rlca :
	T_Z80_RLCA
		{
		out_AbsByte(0x07);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rr :
	T_Z80_RR reg_r
		{
		out_AbsByte(0xCB);
		out_AbsByte(0x18|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rra :
	T_Z80_RRA
		{
		out_AbsByte(0x1F);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rrc :
	T_Z80_RRC reg_r
		{
		out_AbsByte(0xCB);
		out_AbsByte(0x08|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rrca :
	T_Z80_RRCA
		{
		out_AbsByte(0x0F);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_rst :
	T_Z80_RST const_8bit
		{
		if (rpn_isReloc(&$2))
			{
			ErrorReport("Address for RST must be absolute") ;
			}
		else if (($2.nVal&0x38)!=$2.nVal)
			{
			ErrorReport("Invalid address for RST") ;
			}
		else
			{
			out_AbsByte(0xC7|$2.nVal) ;
			}

		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_sbc :
	T_Z80_SBC op_a_n
		{
		out_AbsByte(0xDE) ;
		out_RelByte(&$2) ;
		}

	| T_Z80_SBC op_a_r
		{
		out_AbsByte(0x98|$2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_scf :
	T_Z80_SCF
		{
		out_AbsByte(0x37);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_set :
	T_POP_SET const_3bit comma reg_r
		{
		out_AbsByte(0xCB) ;
		out_AbsByte(0xC0|($2<<3)|$4) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_sla :
	T_Z80_SLA reg_r
		{
		out_AbsByte(0xCB) ;
		out_AbsByte(0x20|$2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_sra :
	T_Z80_SRA reg_r
		{
		out_AbsByte(0xCB) ;
		out_AbsByte(0x28|$2) ;
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_srl :
	T_Z80_SRL reg_r
		{
		out_AbsByte(0xCB);
		out_AbsByte(0x38|$2);
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_stop :
	T_Z80_STOP
		{
		out_AbsByte(0x10);
		out_AbsByte(0x00);
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_sub :
	T_Z80_SUB op_a_n
		{
		out_AbsByte(0xD6);
		out_RelByte(&$2);
		}
	
	| T_Z80_SUB op_a_r
		{
		out_AbsByte(0x90|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_swap :
	T_Z80_SWAP reg_r
		{
		out_AbsByte(0xCB);
		out_AbsByte(0x30|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

z80_xor :
	T_Z80_XOR op_a_n
		{
		out_AbsByte(0xEE);
		out_RelByte(&$2);
		}

	| T_Z80_XOR op_a_r
		{
		out_AbsByte(0xA8|$2);
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

op_mem_ind :
	'[' const_16bit ']'
		{
		$$ = $2
		}
/*
	| '(' const_16bit ')'
		{
		$$ = $2
		}
*/
	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

op_hl_ss :
	reg_ss
		{
		$$ = $1
		}
	
	| T_MODE_HL comma reg_ss
		{
		$$ = $3
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

op_a_r :
	reg_r
		{
		$$ = $1
		}

	| T_MODE_A comma reg_r
		{
		$$ = $3
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

op_a_n :
	const_8bit
		{
		$$ = $1
		}
	
	| T_MODE_A comma const_8bit
		{
		$$ = $3
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

comma :
	','

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

ccode :
	T_CC_NZ
		{
		$$ = CC_NZ
		}

	| T_CC_Z
		{
		$$ = CC_Z
		}

	| T_CC_NC
		{
		$$ = CC_NC
		}

	| T_MODE_C
		{
		$$ = CC_C
		}

	| T_CC_NE
		{
		$$ = CC_NZ
		}

	| T_CC_EQ
		{
		$$ = CC_Z
		}

	| T_CC_LT
		{
		$$ = CC_C
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

reg_r :
	T_MODE_B
		{
		$$ = REG_B
		}

	| T_MODE_C
		{
		$$ = REG_C
		}

	| T_MODE_D
		{
		$$ = REG_D
		}

	| T_MODE_E
		{
		$$ = REG_E
		}
	
	| T_MODE_H
		{
		$$ = REG_H
		}

	| T_MODE_L
		{
		$$ = REG_L
		}

	| T_MODE_HL_IND
		{
		$$ = REG_HL_IND
		}

	| T_MODE_A
		{
		$$ = REG_A
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

reg_tt :
	T_MODE_BC
		{
		$$ = REG_BC
		}

	| T_MODE_DE
		{
		$$ = REG_DE
		}

	| T_MODE_HL
		{
		$$ = REG_HL
		}

	| T_MODE_AF
		{
		$$ = REG_AF
		}

	/* no more sub-rules */
	;


/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

reg_ss :
	T_MODE_BC
		{
		$$ = REG_BC
		}

	| T_MODE_DE
		{
		$$ = REG_DE
		}

	| T_MODE_HL
		{
		$$ = REG_HL
		}

	| T_MODE_SP
		{
		$$ = REG_SP
		}

	/* no more sub-rules */
	;

/********************************************************************
*																	*
* NAME: AND															*
*																	*
* This definition handles the Z80 AND op-code.						*
*																	*
********************************************************************/

reg_rr :
	T_MODE_BC_IND
		{
		$$ = REG_BC_IND
		}
	
	| T_MODE_DE_IND
		{
		$$ = REG_DE_IND
		}

	| T_MODE_HL_INDINC
		{
		$$ = REG_HL_INDINC
		}

	| T_MODE_HL_INDDEC
		{
		$$ = REG_HL_INDDEC
		}

	/* no more sub-rules */
	;

%%
