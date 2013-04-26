#ifndef	SYMBOL_H
#define	SYMBOL_H

#include	"types.h"

void	sym_Init( void );
void	sym_CreateSymbol( char *tzName, SLONG nValue, SLONG nBank );
SLONG	sym_GetValue( char *tzName );
SLONG	sym_GetBank( char *tzName );

#endif