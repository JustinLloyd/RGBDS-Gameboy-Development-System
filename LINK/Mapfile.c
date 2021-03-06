#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asmotor.h"
#include "main.h"
#include "mylink.h"
#include "assign.h"

FILE	*mf=NULL;
FILE	*sf=NULL;
SLONG	currentbank=0;
SLONG	sfbank;

void	SetMapfileName( char *name )
	{
	mf=fopen(name,"wt") ;
	if (mf)
		{
		return;
		}
	else
		{
		fatalerror( "Unable to open mapfile for writing" );
		}

	}

void	SetSymfileName( char *name )
	{
	sf=fopen(name,"wt") ;
	if (sf)
		{
		fprintf( sf, ";File generated by xLink v" LINK_VERSION "\n\n" );
		return;
		}
	else
		{
		fatalerror( "Unable to open symfile for writing" );
		}

	}

void	CloseMapfile( void )
	{
	if( mf )
		{
		fclose( mf );
		mf=NULL;
		}

	if( sf )
		{
		fclose( sf );
		sf=NULL;
		}

	}

void MapfileHeader()
	{
	if (mf)
		{
		fprintf(mf, "Map file produced by xLink v" LINK_VERSION " (part of ASMotor " ASMOTOR_VERSION ")\n\n") ;
		if (g_identifyBanks)
			{
			fprintf(mf, "Banks are identified by a unique number at 0x7FFF\n\n") ;
			}

		}

	}

void	MapfileInitBank( SLONG bank )
	{
	if( mf )
		{
		currentbank=bank;
		if( bank==0 )
			{
			fprintf( mf, "Bank #0 (HOME):\n" );
			}
		else if( bank<=255 )
			{
			fprintf( mf, "Bank #%d:\n", bank );
			}
		else if( bank==BANK_BSS )
			{
			fprintf( mf, "BSS:\n" );
			}
		else if( bank==BANK_HRAM )
			{
			fprintf( mf, "HRAM:\n" );
			}
		else if( bank==BANK_VRAM )
			{
			fprintf( mf, "VRAM:\n" );
			}

		}

	if( sf )
		{
		sfbank=(bank>=1&&bank<=255)?bank:0;
		}

	}

void	MapfileWriteSection( struct sSection *pSect )
	{
	if( mf || sf )
		{
		SLONG	i;

		fprintf( mf, "  SECTION: $%04X-$%04X ($%04X bytes)\n", pSect->nOrg, pSect->nOrg+pSect->nByteSize-1, pSect->nByteSize );

		for( i=0; i<pSect->nNumberOfSymbols; i+=1 )
			{
			struct	sSymbol	*pSym;
			pSym=pSect->tSymbols[i];
			if( (pSym->pSection==pSect) && (pSym->Type!=SYM_IMPORT) )
				{
				if( mf )
					{
					fprintf( mf, "           $%04X = %s\n", pSym->nOffset+pSect->nOrg, pSym->pzName );
					}

				if( sf )
					{
					fprintf( sf, "%02X:%04X %s\n", sfbank, pSym->nOffset+pSect->nOrg, pSym->pzName );
					}

				}

			}

		}

	}

void	MapfileCloseBank( SLONG slack )
	{
	if( mf )
		{
		if( slack==BankSize[currentbank] )
			{
			if ((g_identifyBanks) && (currentbank<=k_LAST_ROM_BANK))
				{
				fprintf(mf, "  EMPTY (last byte is used to identify rom bank)\n\n") ;
				}
			else
				{
				fprintf( mf, "  EMPTY\n\n" );
				}

			}
		else
			{
			if ((g_identifyBanks) && (currentbank<=k_LAST_ROM_BANK))
				{
				fprintf( mf, "    SLACK: $%04X bytes (last byte is used to identify rom bank)\n\n", slack );
				}
			else
				{
				fprintf( mf, "    SLACK: $%04X bytes\n\n", slack );
				}

			}
	
		}

	}