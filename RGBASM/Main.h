#ifndef	MAIN_H
#define	MAIN_H

#include "Types.h"
#include "Standard.h"


enum ERROR_OUTPUT
	{
	k_ERROR_OUTPUT_RGBDS,
	k_ERROR_OUTPUT_DEVSTUDIO,
	} ;

enum NUMBER_FORMAT
	{
	k_NUMBER_FORMAT_ZILOG,
	k_NUMBER_FORMAT_RGBDS,
	} ;

struct	sOptions
	{
	unsigned char	outputFormat ;
	unsigned char	produceDependencies ;
	unsigned char	numberFormat ;
	unsigned char	isQuiet ;

	ULONG	endian;
	char	gbgfx[4];
	char	binary[2];
	SLONG	fillchar;	//	-1 == random
	char	dependencyFile[k_MAX_STRING_LEN] ;
	} ;

extern	char	*tzNewMacro;
extern	ULONG	ulNewMacroSize;
extern	SLONG	nGBGfxID;
extern	SLONG	nBinaryID;

extern	struct	sOptions	DefaultOptions;
extern	struct	sOptions	CurrentOptions;
extern	void	opt_Push(void );
extern	void	opt_Pop(void );
extern	void	opt_Parse(char *s );
extern const char *GetSourceFileName(void) ;

void ErrorFatal(char *msg, ...) ;
void ErrorReport(char *msg, ...) ;
void MessageReport(char *msg, ...) ;

#define	YY_FATAL_ERROR ErrorFatal

#ifdef	YYLMAX
#undef	YYLMAX
#endif
#define YYLMAX 65536

#define k_ROM_BANK_START_ADDRESS	((long)(0x0000))
#define k_ROM_BANK_END_ADDRESS		((long)(0xFFFF))
#define k_ROM_BANK_MIN				((short)(0))
#define k_ROM_BANK_MAX				((short)(255))

#endif