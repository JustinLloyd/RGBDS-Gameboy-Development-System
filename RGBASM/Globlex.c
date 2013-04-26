#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "standard.h"
#include "Assert.h"
#include "asm.h"
#include "symbol.h"
#include "rpn.h"
#include "asmy_tab.h"
#include "symbol.h"
#include "main.h"
#include "lexer.h"


#define k_RADIX_BINARY	2
#define k_RADIX_GFX		4
#define k_RADIX_OCTAL	8
#define k_RADIX_DECIMAL	10
#define k_RADIX_HEX		16


UBYTE	oDontExpandStrings=0;
SLONG	nGBGfxID=-1;
SLONG	nBinaryID=-1;


SLONG DecimalCharToDigit(char ch)
	{
    if ((ch >= '0') && (ch <= '9'))
		{
		return (ch - '0') ;
		}

	return (0) ;
	}


SLONG HexCharToDigit(char ch)
	{
    if ((ch >= 'a') && (ch <= 'f'))
		{
		return (ch - 'a' + 10) ;
		}

    if ((ch >= 'A') && (ch <= 'F'))
		{
		return (ch - 'A' + 10) ;
		}

    if ((ch >= '0') && (ch <= '9'))
		{
		return (ch - '0') ;
		}

    return (0) ;
	}


SLONG BinaryCharToDigit(char ch)
	{
	SLONG	i;

	for (i=0; i<=1; i++)
		{
		if (CurrentOptions.binary[i] == ch)
			{
			return (i) ;
			}

		}

    return (0) ;
	}


int GfxCharToDigit(char ch)
	{
	int	i ;

	for (i=0; i<=3; i++)
		{
		if (CurrentOptions.gbgfx[i]==ch)
			{
			return (i) ;
			}
	
		}

    return (0) ;
	}


char IsBinaryDigit(char digit)
	{
	if ((digit == CurrentOptions.binary[0]) || (digit == CurrentOptions.binary[1]))
		{
		return (TRUE) ;
		}

	return (FALSE) ;
	}


char IsGfxDigit(char digit)
	{
	if ((digit >= '0') && (digit <= '1'))
		{
		return (TRUE) ;
		}

	return (FALSE) ;
	}


char IsOctalDigit(char digit)
	{
	if ((digit >= '0') && (digit <= '7'))
		{
		return (TRUE) ;
		}

	return (FALSE) ;
	}


char IsDecimalDigit(char digit)
	{
	if ((digit >= '0') && (digit <= '9'))
		{
		return (TRUE) ;
		}

	return (FALSE) ;
	}


char IsHexDigit(char digit)
	{
	if ((digit >= '0') && (digit <= '9'))
		{
		return (TRUE) ;
		}

	if ((digit >= 'A') && (digit <= 'F'))
		{
		return (TRUE) ;
		}

	if ((digit >= 'a') && (digit <= 'f'))
		{
		return (TRUE) ;
		}

	return (FALSE) ;
	}







/********************************************************************
*																	*
* NAME: ascii2bin													*
*																	*
* This function converts an ASCII string to a binary number.		*
*																	*
********************************************************************/
/*
SLONG ascii2bin(char *s)
	{
    SLONG	radix ;
    SLONG   result ;
	x2bin	convertfunc ;

	int	numberLen ;

	char	*numberText ;
	char	*numberChar ;
	char	formatChar ;

	radix = 10 ;
	result = 0 ;
	convertfunc = char2bin ;
	numberLen = strlen(s) ;
	Assert(numberLen > 0, "Length of number is <= 0") ;
	numberText = malloc(numberLen + 1) ;
	if (!numberText)
		{
		// abort program with "out of memory" error
		ErrorFatal("Out of memory!") ;
		}

	// if number representation option is zilog
	if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_ZILOG)
		{
		// get format identifier
		formatChar = s[numberLen - 1] ;
		// if format is a digit
		if (isdigit(formatChar))
			{
			// copy string without format identifier
			strcpy(numberText, s) ;
			}
		else
			{
			// copy string without format identifier
			strncpy(numberText, s, numberLen - 1) ;
			// deicde number base specified
			switch (formatChar)
				{
				// hex number?
				case 'h' :
					radix = 16 ;
					convertfunc = char2bin ;
					break ;

				// octal number?
				case 'o' :
					radix = 8 ;
					convertfunc = char2bin ;
					break ;

				case '`' :
					radix = 4 ;
					convertfunc = gbgfx2bin ;
					break ;

				case 'b' :
					radix = 2 ;
					convertfunc = binary2bin ;
					break ;

				default :
					ErrorReport("Illegally formatted number") ;
					break ;

				}

			}

		}
	// else if number representation is rgbds
	else if (CurrentOptions.numberFormat ==k_NUMBER_FORMAT_RGBDS)
		{
		// get format identifier
		formatChar = (char)(tolower(s[0])) ;
		// if format is a digit
		if (isdigit(formatChar))
			{
			// copy entire string as is
			strcpy(numberText, s) ;
			}
		else
			{
			// copy string without format identifier
			strcpy(numberText, s + 1) ;
			// determine number base specified
			switch (formatChar)
				{
				// hex number?
				case '$' :
					radix = 16 ;
					convertfunc = char2bin ;
					break ;

				// octal number?
				case '&' :
				case '@' :
					radix = 8 ;
					convertfunc = char2bin ;
					break ;

				case '`' :
					radix = 4 ;
					convertfunc = gbgfx2bin ;
					break ;

				case '%' :
					radix = 2 ;
					convertfunc = binary2bin ;
					break ;

				default :
					ErrorReport ("Illegally formatted number") ;
					break ;

				}

			}

		}

	numberChar = numberText ;
    if (radix == 4)
	    {
		SLONG	c;

		while (*numberChar != '\0')
			{
		    c = convertfunc (*numberChar++);
		    result = result * 2 + ((c & 1) << 8) + ((c & 2) >> 1);
			}

		}
    else
		{
		while (*numberChar != '\0')
			{
		    result = result * radix + convertfunc (*numberChar++);
			}
    
		}

	free(numberText) ;

    return (result) ;
	}
*/


ULONG   ParseFixedPoint (char *s, ULONG size)
{
    char    dest[256];
    ULONG   i = 0,
            dot = 0;

    while (size && dot != 2)
    {
		if (s[i] == '.')
		    dot += 1;

		if (dot < 2)
		{
		    dest[i] = s[i];
		    size -= 1;
		    i += 1;
		}
    }

    dest[i] = 0;

    yyunputbytes (size);

    yylval.nConstValue = (SLONG) (atof (s) * 65536);

    return (1);
}


char IsValidHexNumber(char format, char *number, SLONG *value)
	{
	char	digits[k_MAX_STRING_LEN] ;

	SLONG	result ;

	int	endPos ;
	int	i ;

	Assert(((format == k_NUMBER_FORMAT_ZILOG) || (format == k_NUMBER_FORMAT_RGBDS)), "Illegally specified number format") ;
	Assert(number != NULL, "NULL number string supplied") ;
	Assert(strlen(number) > 1, "Empty number string supplied") ;
	*value = 0 ;
	if (format == k_NUMBER_FORMAT_RGBDS)
		{
		if (number[0] != '$')
			{
			return (FALSE) ;
			}

		strcpy(digits, number + 1) ;
		}
	else if (format == k_NUMBER_FORMAT_ZILOG)
		{
		endPos = strlen(number) - 1 ;
		if (tolower(number[endPos]) != 'h')
			{
			return (FALSE) ;
			}

		strcpy(digits, number) ;
		digits[endPos] = 0 ;
		}

	result = 0 ;
	for (i=0; digits[i]; i++)
		{
		if (!IsHexDigit(digits[i]))
			{
			return (FALSE) ;
			}

	    result = result * k_RADIX_HEX + HexCharToDigit(digits[i]) ;
		}

	*value = result ;

	return (TRUE) ;
	}


char IsValidOctalNumber(char format, char *number, SLONG *value)
	{
	char	digits[k_MAX_STRING_LEN] ;

	SLONG	result ;

	int	endPos ;
	int	i ;

	Assert(((format == k_NUMBER_FORMAT_ZILOG) || (format == k_NUMBER_FORMAT_RGBDS)), "Illegally specified number format") ;
	Assert(number != NULL, "NULL number string supplied") ;
	Assert(strlen(number) > 1, "Empty number string supplied") ;
	*value = 0 ;
	if (format == k_NUMBER_FORMAT_RGBDS)
		{
		if (number[0] != '&')
			{
			return (FALSE) ;
			}

		strcpy(digits, number + 1) ;
		}
	else if (format == k_NUMBER_FORMAT_ZILOG)
		{
		endPos = strlen(number) - 1 ;
		if (tolower(number[endPos]) != 'o')
			{
			return (FALSE) ;
			}

		strcpy(digits, number) ;
		digits[endPos] = 0 ;
		}

	result = 0 ;
	for (i=0; digits[i]; i++)
		{
		if (!IsOctalDigit(digits[i]))
			{
			return (FALSE) ;
			}

	    result = result * k_RADIX_OCTAL + DecimalCharToDigit(digits[i]) ;
		}

	*value = result ;

	return (TRUE) ;
	}


char IsValidDecimalNumber(char format, char *number, SLONG *value)
	{
	int	i ;

	SLONG	result ;

	Assert(((format == k_NUMBER_FORMAT_ZILOG) || (format == k_NUMBER_FORMAT_RGBDS)), "Illegally specified number format") ;
	Assert(number != NULL, "NULL number string supplied") ;
//	Assert(strlen(number) > 1, "Empty number string supplied") ;
	*value = 0 ;
	result = 0 ;
	for (i=0; number[i]; i++)
		{
		if (!IsDecimalDigit(number[i]))
			{
			return (FALSE) ;
			}

	    result = result * k_RADIX_DECIMAL + DecimalCharToDigit(number[i]) ;
		}

	*value = result ;

	return (TRUE) ;
	}


char IsValidBinaryNumber(char format, char *number, SLONG *value)
	{
	char	digits[k_MAX_STRING_LEN] ;

	SLONG	result ;

	int	endPos ;
	int	i ;

	Assert(((format == k_NUMBER_FORMAT_ZILOG) || (format == k_NUMBER_FORMAT_RGBDS)), "Illegally specified number format") ;
	Assert(number != NULL, "NULL number string supplied") ;
	Assert(strlen(number) > 1, "Empty number string supplied") ;
	*value = 0 ;
	if (format == k_NUMBER_FORMAT_RGBDS)
		{
		if (number[0] != '%')
			{
			return (FALSE) ;
			}

		strcpy(digits, number + 1) ;
		}
	else if (format == k_NUMBER_FORMAT_ZILOG)
		{
		endPos = strlen(number) - 1 ;
		if (tolower(number[endPos]) != 'b')
			{
			return (FALSE) ;
			}

		strcpy(digits, number) ;
		digits[endPos] = 0 ;
		}

	result = 0 ;
	for (i=0; digits[i]; i++)
		{
		if (!IsBinaryDigit(digits[i]))
			{
			return (FALSE) ;
			}

	    result = result * k_RADIX_BINARY + BinaryCharToDigit(digits[i]) ;
		}

	*value = result ;

	return (TRUE) ;
	}


char IsValidGfxNumber(char format, char *number, SLONG *value)
	{
	char	digits[k_MAX_STRING_LEN] ;

	SLONG	result ;

	int	digitValue ;
	int	endPos ;
	int	i ;

	Assert(((format == k_NUMBER_FORMAT_ZILOG) || (format == k_NUMBER_FORMAT_RGBDS)), "Illegally specified number format") ;
	Assert(number != NULL, "NULL number string supplied") ;
	Assert(strlen(number) > 1, "Empty number string supplied") ;
	*value = 0 ;
	if (format == k_NUMBER_FORMAT_RGBDS)
		{
		if (number[0] != '`')
			{
			return (FALSE) ;
			}

		strcpy(digits, number + 1) ;
		}
	else if (format == k_NUMBER_FORMAT_ZILOG)
		{
		endPos = strlen(number) - 1 ;
		if (tolower(number[endPos]) != 'g')
			{
			return (FALSE) ;
			}

		strcpy(digits, number) ;
		digits[endPos] = 0 ;
		}

	result = 0 ;
	for (i=0; digits[i]; i++)
		{
		if (!IsGfxDigit(digits[i]))
			{
			return (FALSE) ;
			}

	    digitValue = GfxCharToDigit(digits[i]) ;
	    result = result * k_RADIX_BINARY + ((digitValue & 1) << 8) + ((digitValue & 2) >> 1) ;
		}

	*value = result ;

	return (TRUE) ;
	}


/********************************************************************
*																	*
* NAME: ParseNumber													*
*																	*
* This function parses an integer number that is formatted			*
* according to its specified type, e.g. a hex number, a binary		*
* number, etc. It determines which format the number is in based	*
* on an identifier at the start or end of the number. If no			*
* identifier is given then the number is assumed to be decimal.		*
*																	*
********************************************************************/

// Parse an integer number
// Verify that it is correctly formatted
ULONG ParseNumber(char *s, ULONG size)
	{
    char	number[k_MAX_STRING_LEN] ;								// copy of parsed token

	SLONG	numberValue ;											// value of parsed number if valid

    strncpy(number, s, size) ;
    number[size] = 0 ;
	if (IsValidDecimalNumber(CurrentOptions.numberFormat, number, &numberValue))
		{
		yylval.nConstValue = numberValue ;

		return (TRUE) ;
		}
	else if (IsValidHexNumber(CurrentOptions.numberFormat, number, &numberValue))
		{
		yylval.nConstValue = numberValue ;

		return (TRUE) ;
		}
	else if (IsValidOctalNumber(CurrentOptions.numberFormat, number, &numberValue))
		{
		yylval.nConstValue = numberValue ;

		return (TRUE) ;
		}
	else if (IsValidBinaryNumber(CurrentOptions.numberFormat, number, &numberValue))
		{
		yylval.nConstValue = numberValue ;

		return (TRUE) ;
		}
	else if (IsValidGfxNumber(CurrentOptions.numberFormat, number, &numberValue))
		{
		yylval.nConstValue = numberValue ;

		return (TRUE) ;
		}

	ErrorReport("Illegally formatted number") ;

    return (TRUE) ;
	}


ULONG   ParseSymbol (char *src, ULONG size)
{
    char    dest[MAXSYMLEN + 1];
    int     copied = 0,
            size_backup = size;

    while (size && copied < MAXSYMLEN)
    {
		if (*src == '\\')
		{
		    char   *marg;

		    src += 1;
		    size -= 1;

		    if (*src == '@')
				marg = sym_FindMacroArg (-1);
		    else if (*src >= '0' && *src <= '9')
				marg = sym_FindMacroArg (*src);
		    else
			{
				ErrorFatal ("Malformed ID");
				return(0);
			}

		    src += 1;
		    size -= 1;

		    if (marg)
		    {
				while (*marg)
				    dest[copied++] = *marg++;
		    }
		}
		else
		{
		    dest[copied++] = *src++;
		    size -= 1;
		}
    }

    if (copied > MAXSYMLEN)
		ErrorFatal ("Symbol too long");

    dest[copied] = 0;

    if (oDontExpandStrings==0
	&&	sym_isString(dest) )
    {
		char	*s;

		yyskipbytes(size_backup );
		yyunputstr(s=sym_GetStringValue(dest) );

		while(*s )
		{
			if (*s++=='\n' )
			{
				nLineNo-=1;
			}
		}
		return (0);
    }
    else
    {
		strcpy(yylval.tzString, dest );
		return (1);
    }
}

ULONG   PutMacroArg (char *src, ULONG size)
{
	char	*s;

    yyskipbytes (size);
	if ((s=sym_FindMacroArg (src[1] - '0'))!=NULL )
	{
    	yyunputstr(s);
	}
	else
	{
		ErrorReport("Macro argument not defined" );
	}
    return (0);
}

ULONG   PutUniqueArg (char *src, ULONG size)
{
	src=src;
    yyskipbytes (size);
    yyunputstr (sym_FindMacroArg (-1));
    return (0);
}

enum
{
    T_LEX_MACROARG = 3000,
    T_LEX_MACROUNIQUE
};

extern struct sLexInitString localstrings[];

struct sLexInitString staticstrings[] =
{
    "||", T_OP_LOGICOR,
    "&&", T_OP_LOGICAND,
    "==", T_OP_LOGICEQU,
    ">", T_OP_LOGICGT,
    "<", T_OP_LOGICLT,
    ">=", T_OP_LOGICGE,
    "<=", T_OP_LOGICLE,
    "!=", T_OP_LOGICNE,
    "!", T_OP_LOGICNOT,
    "|", T_OP_OR,
    "^", T_OP_XOR,
    "&", T_OP_AND,
    "<<", T_OP_SHL,
    ">>", T_OP_SHR,
    "+", T_OP_ADD,
    "-", T_OP_SUB,
    "*", T_OP_MUL,
    "/", T_OP_DIV,
    "%", T_OP_MOD,
    "~", T_OP_NOT,

    "def", T_OP_DEF,

    "bank", T_OP_BANK,

    "div", T_OP_FDIV,
    "mul", T_OP_FMUL,
    "sin", T_OP_SIN,
    "cos", T_OP_COS,
    "tan", T_OP_TAN,
    "asin", T_OP_ASIN,
    "acos", T_OP_ACOS,
    "atan", T_OP_ATAN,
    "atan2", T_OP_ATAN2,

    "strcmp", T_OP_STRCMP,
    "strin", T_OP_STRIN,
    "strsub", T_OP_STRSUB,
    "strlen", T_OP_STRLEN,
    "strcat", T_OP_STRCAT,
    "strupr", T_OP_STRUPR,
    "strlwr", T_OP_STRLWR,
	"strtrim", T_OP_STRTRIM,
	"strltrim", T_OP_STRLTRIM,
	"strrtrim", T_OP_STRRTRIM,

    "include", T_POP_INCLUDE,
    "printt", T_POP_PRINTT,
    "printv", T_POP_PRINTV,
    "printf", T_POP_PRINTF,
    "export", T_POP_EXPORT,
    "xdef", T_POP_EXPORT,
    "import", T_POP_IMPORT,
    "xref", T_POP_IMPORT,
    "global", T_POP_GLOBAL,
    "ds", T_POP_DS,
	"align", T_POP_ALIGN,
    NAME_DB, T_POP_DB,
    NAME_DW, T_POP_DW,
	NAME_DQ, T_POP_DQ,
/*
#ifdef	NAME_DL
    NAME_DL, T_POP_DL,
#endif
*/
    "section", T_POP_SECTION,
	"org", T_POP_ORG,
	"purge", T_POP_PURGE,

    "rsreset", T_POP_RSRESET,
    "rsset", T_POP_RSSET,

    "incbin", T_POP_INCBIN,

    "fail", T_POP_FAIL,
    "warn", T_POP_WARN,

    "macro", T_POP_MACRO,
    "endm", T_POP_ENDM,		//      Not needed but we have it here just to protect the name
	"shift", T_POP_SHIFT,

    "rept", T_POP_REPT,
    "endr", T_POP_ENDR,		//      Not needed but we have it here just to protect the name

    "if", T_POP_IF,
    "else", T_POP_ELSE,
    "endc", T_POP_ENDC,

    "bss", T_SECT_BSS,
#if	defined(GAMEBOY) || defined(PCENGINE)
    "vram", T_SECT_VRAM,
#endif
    "code", T_SECT_CODE,
    "data", T_SECT_CODE,
#ifdef GAMEBOY
    "home", T_SECT_HOME,
    "hram", T_SECT_HRAM,
#endif

    NAME_RB, T_POP_RB,
    NAME_RW, T_POP_RW,
	NAME_RQ, T_POP_RQ,
/*
#ifdef	NAME_RL
    NAME_RL, T_POP_RL,
#endif
*/
    "equ", T_POP_EQU,
    "equs", T_POP_EQUS,

    "set", T_POP_SET,
    "=", T_POP_SET,

	"pushs", T_POP_PUSHS,
	"pops", T_POP_POPS,
	"pusho", T_POP_PUSHO,
	"popo", T_POP_POPO,

	"opt", T_POP_OPT,

    NULL, 0
};

struct sLexFloat tNumberToken =
{
    ParseNumber,
    T_NUMBER
};

struct sLexFloat tFixedPointToken =
{
    ParseFixedPoint,
    T_NUMBER
};

struct sLexFloat tIDToken =
{
    ParseSymbol,
    T_ID
};

struct sLexFloat tMacroArgToken =
{
    PutMacroArg,
    T_LEX_MACROARG
};

struct sLexFloat tMacroUniqueToken =
{
    PutUniqueArg,
    T_LEX_MACROUNIQUE
};

void    setuplex (void)
{
    ULONG   id;

    lex_Init ();
    lex_AddStrings (staticstrings);
    lex_AddStrings (localstrings);

    //      Macro arguments

    id = lex_FloatAlloc (&tMacroArgToken);
    lex_FloatAddFirstRange (id, '\\', '\\');
    lex_FloatAddSecondRange (id, '0', '9');
    id = lex_FloatAlloc (&tMacroUniqueToken);
    lex_FloatAddFirstRange (id, '\\', '\\');
    lex_FloatAddSecondRange (id, '@', '@');

    //      Decimal constants

    id = lex_FloatAlloc (&tNumberToken);
    lex_FloatAddFirstRange (id, '0', '9');
    lex_FloatAddSecondRange (id, '0', '9');
    lex_FloatAddRange (id, '0', '9');

    // binary constants
	if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_ZILOG)
		{
	    nBinaryID = id = lex_FloatAlloc(&tNumberToken);
		lex_FloatAddFirstRange(id, CurrentOptions.binary[0], CurrentOptions.binary[0]);
		lex_FloatAddFirstRange(id, CurrentOptions.binary[1], CurrentOptions.binary[1]);
		lex_FloatAddSecondRange(id, CurrentOptions.binary[0], CurrentOptions.binary[0]);
		lex_FloatAddSecondRange(id, CurrentOptions.binary[1], CurrentOptions.binary[1]);
		lex_FloatAddSecondRange(id, 'B', 'B') ;
		lex_FloatAddSecondRange(id, 'b', 'b') ;
		lex_FloatAddRange(id, CurrentOptions.binary[0], CurrentOptions.binary[0]);
		lex_FloatAddRange(id, CurrentOptions.binary[1], CurrentOptions.binary[1]);
		lex_FloatAddRange(id, 'B', 'B') ;
		lex_FloatAddRange(id, 'b', 'b') ;
		}
	else if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_RGBDS)
		{
	    nBinaryID = id = lex_FloatAlloc (&tNumberToken);
		lex_FloatAddFirstRange (id, '%', '%');
		lex_FloatAddSecondRange (id, CurrentOptions.binary[0], CurrentOptions.binary[0]);
		lex_FloatAddSecondRange (id, CurrentOptions.binary[1], CurrentOptions.binary[1]);
		lex_FloatAddRange (id, CurrentOptions.binary[0], CurrentOptions.binary[0]);
		lex_FloatAddRange (id, CurrentOptions.binary[1], CurrentOptions.binary[1]);
		}

    // octal constants
	if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_ZILOG)
		{
	    id = lex_FloatAlloc(&tNumberToken) ;
		lex_FloatAddFirstRange(id, '0', '7');
		lex_FloatAddSecondRange(id, '0', '7');
		lex_FloatAddSecondRange(id, 'O', 'O') ;
		lex_FloatAddSecondRange(id, 'o', 'o') ;
		lex_FloatAddRange(id, '0', '7');
		lex_FloatAddRange(id, 'O', 'O') ;
		lex_FloatAddRange(id, 'o', 'o') ;
		}
	else if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_RGBDS)
		{
	    id = lex_FloatAlloc (&tNumberToken);
		lex_FloatAddFirstRange (id, '&', '&');
		lex_FloatAddSecondRange (id, '0', '7');
		lex_FloatAddRange (id, '0', '7');
		}

    //      Gameboy gfx constants
	if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_ZILOG)
		{
		nGBGfxID = id = lex_FloatAlloc(&tNumberToken) ;
		lex_FloatAddFirstRange(id, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0]) ;
		lex_FloatAddFirstRange(id, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1]) ;
		lex_FloatAddFirstRange(id, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2]) ;
		lex_FloatAddFirstRange(id, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3]) ;
		lex_FloatAddRange(id, 'G', 'G') ;
		lex_FloatAddRange(id, 'g', 'g') ;
		}
	else if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_RGBDS)
		{
		nGBGfxID = id = lex_FloatAlloc(&tNumberToken) ;
		lex_FloatAddFirstRange(id, '`', '`') ;
		lex_FloatAddSecondRange(id, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0]) ;
		lex_FloatAddSecondRange(id, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1]) ;
		lex_FloatAddSecondRange(id, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2]) ;
		lex_FloatAddSecondRange(id, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2]) ;
		lex_FloatAddRange(id, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3]) ;
		}


    // hex constants
	if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_ZILOG)
		{
		id = lex_FloatAlloc(&tNumberToken) ;
		lex_FloatAddFirstRange(id, '0', '9') ;
		lex_FloatAddFirstRange(id, 'A', 'F') ;
		lex_FloatAddFirstRange(id, 'a', 'f') ;
		lex_FloatAddSecondRange(id, '0', '9') ;
		lex_FloatAddSecondRange(id, 'A', 'F') ;
		lex_FloatAddSecondRange(id, 'a', 'f') ;
		lex_FloatAddSecondRange(id, 'h', 'h') ;
		lex_FloatAddSecondRange(id, 'H', 'H') ;
		lex_FloatAddRange(id, '0', '9') ;
		lex_FloatAddRange(id, 'A', 'F') ;
		lex_FloatAddRange(id, 'a', 'f') ;
		lex_FloatAddRange(id, 'h', 'h') ;
		lex_FloatAddRange(id, 'H', 'H') ;
		}
	else if (CurrentOptions.numberFormat == k_NUMBER_FORMAT_RGBDS)
		{
		id = lex_FloatAlloc(&tNumberToken) ;
		lex_FloatAddFirstRange(id, '$', '$') ;
		lex_FloatAddSecondRange(id, '0', '9') ;
		lex_FloatAddSecondRange(id, 'A', 'F') ;
		lex_FloatAddSecondRange(id, 'a', 'f') ;
		lex_FloatAddRange(id, '0', '9') ;
		lex_FloatAddRange(id, 'A', 'F') ;
		lex_FloatAddRange(id, 'a', 'f') ;
		}

    //      ID's

    id = lex_FloatAlloc(&tIDToken);
    lex_FloatAddFirstRange(id, 'a', 'z');
    lex_FloatAddFirstRange(id, 'A', 'Z');
    lex_FloatAddFirstRange(id, '_', '_');
    lex_FloatAddSecondRange(id, 'a', 'z');
    lex_FloatAddSecondRange(id, 'A', 'Z');
    lex_FloatAddSecondRange(id, '0', '9');
    lex_FloatAddSecondRange(id, '_', '_');
    lex_FloatAddSecondRange(id, '\\', '\\');
    lex_FloatAddSecondRange(id, '@', '@');
    lex_FloatAddSecondRange(id, '#', '#');
    lex_FloatAddRange(id, 'a', 'z');
    lex_FloatAddRange(id, 'A', 'Z');
    lex_FloatAddRange(id, '0', '9');
    lex_FloatAddRange(id, '_', '_');
    lex_FloatAddRange(id, '\\', '\\');
    lex_FloatAddRange(id, '@', '@');
    lex_FloatAddRange(id, '#', '#');

    //      Local ID

    id = lex_FloatAlloc(&tIDToken);
    lex_FloatAddFirstRange(id, '.', '.');
    lex_FloatAddSecondRange(id, 'a', 'z');
    lex_FloatAddSecondRange(id, 'A', 'Z');
    lex_FloatAddSecondRange(id, '_', '_');
    lex_FloatAddRange(id, 'a', 'z');
    lex_FloatAddRange(id, 'A', 'Z');
    lex_FloatAddRange(id, '0', '9');
    lex_FloatAddRange(id, '_', '_');
    lex_FloatAddRange(id, '\\', '\\');
    lex_FloatAddRange(id, '@', '@');
    lex_FloatAddRange(id, '#', '#');

    //      @ ID

    id = lex_FloatAlloc(&tIDToken);
    lex_FloatAddFirstRange(id, '@', '@');

    //      Fixed point constants

    id = lex_FloatAlloc(&tFixedPointToken);
    lex_FloatAddFirstRange(id, '.', '.');
    lex_FloatAddFirstRange(id, '0', '9');
    lex_FloatAddSecondRange(id, '.', '.');
    lex_FloatAddSecondRange(id, '0', '9');
    lex_FloatAddRange(id, '.', '.');
    lex_FloatAddRange(id, '0', '9');

}