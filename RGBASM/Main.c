/*
 * RGBAsm - MAIN.C
 *
 * INCLUDES
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#include "symbol.h"
#include "fstack.h"
#include "output.h"
#include "main.h"
#include "Assert.h"
#include "Dependency.h"


int     yyparse (void) ;
void    setuplex (void) ;

#ifdef	AMIGA
__near long __stack = 65536L ;

#endif

/*
 * RGBAsm - MAIN.C
 *
 * VARIABLES
 *
 */

clock_t nStartClock,
        nEndClock ;

	SLONG	nLineNo ;

	ULONG	g_totalLines ;

	ULONG	nPass,
		uniqueSectionCount,											// number of anonymous sections declared with ORG directive
        nPC,
        g_nIFDepth,
        nErrors ;

static	char   *tzMainfile ;

extern int yydebug ;

/*
 * RGBAsm - MAIN.C
 *
 * Option stack
 *
 */

struct	sOptions	DefaultOptions ;
struct	sOptions	CurrentOptions ;

struct	sOptionStackEntry
	{
	struct	sOptions  			Options ;
	struct	sOptionStackEntry	*pNext ;
	} ;

struct	sOptionStackEntry		*pOptionStack=NULL ;

void	opt_SetCurrentOptions(struct sOptions *pOpt )
	{
	if (nGBGfxID!=-1 )
		{
		lex_FloatDeleteRange(nGBGfxID, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0] ) ;
		lex_FloatDeleteRange(nGBGfxID, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1] ) ;
		lex_FloatDeleteRange(nGBGfxID, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2] ) ;
		lex_FloatDeleteRange(nGBGfxID, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3] ) ;
		lex_FloatDeleteSecondRange(nGBGfxID, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0] ) ;
		lex_FloatDeleteSecondRange(nGBGfxID, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1] ) ;
		lex_FloatDeleteSecondRange(nGBGfxID, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2] ) ;
		lex_FloatDeleteSecondRange(nGBGfxID, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3] ) ;
		}

	if (nBinaryID!=-1 )
		{
		lex_FloatDeleteRange(nBinaryID, CurrentOptions.binary[0], CurrentOptions.binary[0] ) ;
		lex_FloatDeleteRange(nBinaryID, CurrentOptions.binary[1], CurrentOptions.binary[1] ) ;
		lex_FloatDeleteSecondRange(nBinaryID, CurrentOptions.binary[0], CurrentOptions.binary[0] ) ;
		lex_FloatDeleteSecondRange(nBinaryID, CurrentOptions.binary[1], CurrentOptions.binary[1] ) ;
		}

	CurrentOptions = *pOpt ;

	if (nGBGfxID!=-1 )
		{
		lex_FloatAddRange(nGBGfxID, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0] ) ;
		lex_FloatAddRange(nGBGfxID, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1] ) ;
		lex_FloatAddRange(nGBGfxID, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2] ) ;
		lex_FloatAddRange(nGBGfxID, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3] ) ;
		lex_FloatAddSecondRange(nGBGfxID, CurrentOptions.gbgfx[0], CurrentOptions.gbgfx[0] ) ;
		lex_FloatAddSecondRange(nGBGfxID, CurrentOptions.gbgfx[1], CurrentOptions.gbgfx[1] ) ;
		lex_FloatAddSecondRange(nGBGfxID, CurrentOptions.gbgfx[2], CurrentOptions.gbgfx[2] ) ;
		lex_FloatAddSecondRange(nGBGfxID, CurrentOptions.gbgfx[3], CurrentOptions.gbgfx[3] ) ;
		}

	if (nBinaryID!=-1 )
		{
		lex_FloatAddRange(nBinaryID, CurrentOptions.binary[0], CurrentOptions.binary[0] ) ;
		lex_FloatAddRange(nBinaryID, CurrentOptions.binary[1], CurrentOptions.binary[1] ) ;
		lex_FloatAddSecondRange(nBinaryID, CurrentOptions.binary[0], CurrentOptions.binary[0] ) ;
		lex_FloatAddSecondRange(nBinaryID, CurrentOptions.binary[1], CurrentOptions.binary[1] ) ;
		}

	}


void	opt_Parse(char *s )
	{
	struct	sOptions	newopt ;

	Assert(s!=NULL, "Null option specified") ;

	newopt=CurrentOptions ;

	switch (s[0])
		{
		case 'd' :
			newopt.produceDependencies = TRUE ;
			strncpy(newopt.dependencyFile, &(s[1]), k_MAX_STRING_LEN) ;
			break ;

		case 'e':
			switch (s[1] )
				{
				case 'b':
					newopt.endian=ASM_BIG_ENDIAN ;
					MessageReport("*WARNING*\t :\n\tEndianness forced to BIG for destination CPU\n" ) ;
					break ;
				case 'l':
					newopt.endian=ASM_LITTLE_ENDIAN ;
					MessageReport("*WARNING*\t :\n\tEndianness forced to LITTLE for destination CPU\n" ) ;
					break ;
				default:
					ErrorFatal("Argument to option -e must be 'b' or 'l'") ;

				}
			break ;
		case 'g':
			if (strlen(&s[1])==4 )
				{
				newopt.gbgfx[0]=s[1] ;
				newopt.gbgfx[1]=s[2] ;
				newopt.gbgfx[2]=s[3] ;
				newopt.gbgfx[3]=s[4] ;
				}
			else
				{
				ErrorFatal("*ERROR*\t :\n\tMust specify exactly 4 characters for option 'g'\n" ) ;
				}
			break ;
		case 'r':
				switch (s[1])
					{
					case 'd' :
						newopt.outputFormat = k_ERROR_OUTPUT_DEVSTUDIO ;
						break ;

					case 'r' :
						newopt.outputFormat = k_ERROR_OUTPUT_RGBDS ;
						break ;

					default :
						ErrorFatal("*ERROR*\t :\nArgument to option -r must be 'd' or 'n'\n") ;

					}

			break ;
		case 'n':
			switch (s[1])
				{
				case 'r' :
					newopt.numberFormat = k_NUMBER_FORMAT_RGBDS ;
					break ;

				case 'z' :
					newopt.numberFormat = k_NUMBER_FORMAT_ZILOG ;
					break ;

				default :
					ErrorFatal("*ERROR*\t :\nArgument to option -n must be 'r' or 'z'\n") ;

				}

			break ;
		case 'b':
			if (strlen(&s[1])==2 )
				{
				newopt.binary[0]=s[1] ;
				newopt.binary[1]=s[2] ;
				}
			else
				{
				ErrorFatal("*ERROR*\t :\n\tMust specify exactly 2 characters for option 'b'\n" ) ;
				}
			break ;
		case 'z':
			if (strlen(&s[1])<=2 )
				{
				if (strcmp(&s[1],"?")==0 )
					{
					newopt.fillchar=-1 ;
					}
				else
					{
					int	result ;

					result=sscanf(&s[1], "%lx", &newopt.fillchar ) ;
					if (!((result==EOF) || (result==1)) )
						{
						ErrorFatal("*ERROR*\t :\n\tInvalid argument for option 'z'\n" ) ;
						}
					}
				}
			else
				{
				ErrorFatal("*ERROR*\t :\n\tInvalid argument for option 'z'\n" ) ;
				}
			break ;
		case 'q' :
			newopt.isQuiet = TRUE ;
			break ;

		default:
			ErrorFatal("Unknown option" ) ;
			break ;
		}

	opt_SetCurrentOptions(&newopt ) ;
	}

void	opt_Push(void )
	{
	struct	sOptionStackEntry	*pOpt ;

	if ((pOpt=(struct sOptionStackEntry *)malloc(sizeof(struct sOptionStackEntry)))!=NULL )
		{
		pOpt->Options=CurrentOptions ;
		pOpt->pNext=pOptionStack ;
		pOptionStack=pOpt ;
		}
	else
		ErrorFatal("No memory for option stack" ) ;
	}

void	opt_Pop(void )
	{
	if (pOptionStack )
		{
		struct	sOptionStackEntry	*pOpt ;

		pOpt=pOptionStack ;
		opt_SetCurrentOptions(&(pOpt->Options) ) ;
		pOptionStack=pOpt->pNext ;
		free(pOpt ) ;
		}
	else
		ErrorFatal("No entries in the option stack" ) ;
	}

/*
 * RGBAsm - MAIN.C
 *
 * Error handling
 *
 */

void ErrorReport(char *msg, ...)
	{
	char	constructedMessage[k_MAX_STRING_LEN] ;

	va_list	params ;

	va_start(params, msg) ;
	vsprintf(constructedMessage, msg, params) ;
	va_end(params) ;

	if (CurrentOptions.outputFormat==k_ERROR_OUTPUT_RGBDS)
		{
	    printf("*ERROR*\t") ;
		fstk_Dump() ;
		printf(" :\n\t%s\n", constructedMessage) ;
		}
	else if (CurrentOptions.outputFormat==k_ERROR_OUTPUT_DEVSTUDIO)
		{
		fstk_Dump() ;
		printf(" : *ERROR* : ") ;
		printf(" %s\n", constructedMessage) ;
		}

	nErrors++ ;
	}

void ErrorFatal(char *msg, ...)
	{
	char	constructedMessage[k_MAX_STRING_LEN] ;

	va_list	params ;

	va_start(params, msg) ;
	vsprintf(constructedMessage, msg, params) ;
	va_end(params) ;

    ErrorReport(constructedMessage) ;
    exit(5) ;
	}


void MessageReport(char *msg, ...)
	{
	char	constructedMessage[k_MAX_STRING_LEN] ;

	va_list	params ;

	if (!CurrentOptions.isQuiet)
		{
		va_start(params, msg) ;
		vsprintf(constructedMessage, msg, params) ;
		va_end(params) ;
		printf("%s", constructedMessage) ;
		}

	}
/*
void MessageOutput(char *msg, ...)
	{
	char	constructedMessage[k_MAX_STRING_LEN] ;

	va_list	params ;

	va_start(params, msg) ;
	vsprintf(constructedMessage, msg, params) ;
	va_end(params) ;

	if (!CurrentOptions.isQuiet)
		{
		printf("%s", constructedMessage) ;
		}

	}
*/

void PrintOption(char *option, char *info)
	{
	printf("\t%s\t%s\n", option, info) ;
	}

/*
 * RGBAsm - MAIN.C
 *
 * Help text
 *
 */

void PrintUsage(void)
	{
    printf(APPNAME " v" ASM_VERSION " (part of ASMotor " ASMOTOR_VERSION ")\n\n") ;
	printf("Usage: " EXENAME " [options] asmfile\n") ;
    printf("Options:\n") ;
	PrintOption("-h", "This text") ;
	PrintOption("-i<path>", "Extra include path") ;
    PrintOption("-o<file>", "Write objectoutput to <file>") ;
    PrintOption("-e(l|b)", "Change endianness (CAUTION!)") ;
    PrintOption("-g<ASCI>", "Change the four characters used for Gameboy graphics\n\t\t\tconstants (default is 0123)") ;
    PrintOption("-b<AS>", "Change the two characters used for binary constants\n\t\t\t(default is 01)") ;
    PrintOption("-z<hx>", "Set the byte value (hex format) used for uninitialised\n\t\t\tdata (default is ? for random)") ;
	PrintOption("-r(r|d)", "Output errors & warnings in\n\t\t\t(r) RGBDS format or\n\t\t\t(d) Microsoft DevStudio format") ;
	PrintOption("-d<file>", "Append file dependency information to specified file") ;
	PrintOption("-n(r|z)", "Set the number format\n\t\t\t(r) RGBDS number format or\n\t\t\t(n) Zilog number format") ;
	PrintOption("-q", "Execute quietly (suppress all text except errors") ;
    exit(0) ;
	}


const char *GetSourceFileName(void)
	{
	return (tzMainfile) ;
	}

/*
 * RGBAsm - MAIN.C
 *
 * main
 *
 */

int main(int argc, char *argv[])
	{
    int     argn = 1 ;

    argc -= 1 ;

    if (argc == 0)
	PrintUsage() ;

    /* yydebug=1 ; */
	DefaultOptions.outputFormat = k_ERROR_OUTPUT_RGBDS ;
	DefaultOptions.endian=ASM_DEFAULT_ENDIAN ;
	DefaultOptions.gbgfx[0]='0' ;
	DefaultOptions.gbgfx[1]='1' ;
	DefaultOptions.gbgfx[2]='2' ;
	DefaultOptions.gbgfx[3]='3' ;
	DefaultOptions.binary[0]='0' ;
	DefaultOptions.binary[1]='1' ;
	DefaultOptions.fillchar=-1 ;	//	fill uninitialised data with random values
	DefaultOptions.produceDependencies = FALSE ;
	DefaultOptions.numberFormat = k_NUMBER_FORMAT_RGBDS ;
	DefaultOptions.isQuiet = FALSE ;

	opt_SetCurrentOptions(&DefaultOptions ) ;

	while(argv[argn][0] == '-' && argc)
		{
		switch(argv[argn][1])
			{
		    case 'h':
				PrintUsage() ;
				break ;
		    case 'i':
				fstk_AddIncludePath(&(argv[argn][2])) ;
				break ;
		    case 'o':
				out_SetFileName(&(argv[argn][2])) ;
				break ;
			case 'd' :
			case 'r' :
		    case 'e':
			case 'g':
			case 'b':
			case 'n':
			case 'z':
			case 'q':
				opt_Parse(&argv[argn][1] ) ;
				break ;

		    default:
				ErrorFatal("*ERROR*\t :\n\tUnknown option '%c'\n", argv[argn][1]) ;
				break ;
			}
		argn += 1 ;
		argc -= 1  ;
		}

	DefaultOptions=CurrentOptions  ;

    /*tzMainfile=argv[argn++]  ;
     * argc-=1  ; */
    tzMainfile = argv[argn]  ;

    setuplex ()   ;

    MessageReport("Assembling %s\n", tzMainfile)   ;

    nStartClock = clock ()   ;

    nLineNo = 1  ;
    g_totalLines = 0  ;
    g_nIFDepth = 0  ;
    nPC = 0  ;
    nPass = 1  ;
	uniqueSectionCount=0 ;
    nErrors = 0 ;
    sym_PrepPass1 () ;
    if (fstk_Init (tzMainfile))
		{
		MessageReport("Pass 1...\n") ;
		yy_set_state(LEX_STATE_NORMAL ) ;
		opt_SetCurrentOptions(&DefaultOptions ) ;
		InitDependencyList() ;
		if (yyparse () == 0 && nErrors == 0)
			{
			if (DefaultOptions.produceDependencies)
				{
				OutputFileDependencies(CurrentOptions.dependencyFile) ;
				}

		    if (g_nIFDepth == 0)
				{
				InitDependencyList() ;
				g_totalLines = 0 ;
				nLineNo = 1 ;
				g_nIFDepth = 0 ;
				nPC = 0 ;
				nPass = 2 ;
				uniqueSectionCount=0 ;
				nErrors = 0 ;
				sym_PrepPass2 () ;
				out_PrepPass2 () ;
				fstk_Init (tzMainfile) ;
				yy_set_state(LEX_STATE_NORMAL ) ;
				opt_SetCurrentOptions(&DefaultOptions ) ;

				MessageReport("Pass 2...\n") ;
				if (yyparse () == 0 && nErrors == 0)
					{
				    double  timespent ;

				    nEndClock = clock () ;
				    timespent = ((double) (nEndClock - nStartClock)) / (double) CLOCKS_PER_SEC ;
				    MessageReport("Success! %ld lines in %d.%02d seconds ", g_totalLines, (int) timespent, ((int) (timespent * 100.0)) % 100) ;
				    if (timespent == 0)
						{
						MessageReport("(INFINITY lines/minute)\n") ;
						}
				    else
						{
						MessageReport("(%d lines/minute)\n", (int) (60 / timespent * g_totalLines)) ;
						}

				    out_WriteObject () ;
					}
				else
					{
				    ErrorFatal("Assembly aborted in pass 2 (%ld errors)!\n", nErrors) ;
				    //sym_PrintSymbolTable() ;
					}

				}
		    else
				{
				ErrorFatal("*ERROR*\t:\tUnterminated IF construct (%ld levels)!\n", g_nIFDepth) ;
				}

			}
		else
			{
		    ErrorFatal("Assembly aborted in pass 1 (%ld errors)!\n", nErrors) ;
			}

		}
    else
		{
		ErrorFatal("File '%s' not found\n", tzMainfile) ;
		}

    return (0) ;
	}