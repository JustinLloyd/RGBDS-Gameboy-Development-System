#ifndef	MAIN_H
#define	MAIN_H

#include	"types.h"

extern	void	PrintUsage( void );
extern	void	fatalerror( char *s );
extern	char	temptext[1024];
extern	SLONG	fillchar;
extern	char	smartlinkstartsymbol[256];
extern	char	g_identifyBanks ;

enum	eOutputType
{
	OUTPUT_GBROM,
	OUTPUT_PSION2
};

extern	enum	eOutputType	outputtype;

#define k_ROM_BANK_SIZE		0x4000									// # bytes in a gameboy rom bank


#endif