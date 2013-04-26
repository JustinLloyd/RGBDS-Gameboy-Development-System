#ifndef	ASSIGN_H
#define	ASSIGN_H

#include	"types.h"

enum	eBankDefine
{
	BANK_HOME=0,
	BANK_BSS=256,
	BANK_VRAM,
	BANK_HRAM
};

#define k_LAST_ROM_BANK		255
#define	MAXBANKS	259

extern	SLONG	area_Avail( SLONG bank );
extern	void	AssignSections( void );
extern	void	CreateSymbolTable( void );
extern	SLONG	MaxBankUsed;
extern	SLONG	BankSize[MAXBANKS];

#endif