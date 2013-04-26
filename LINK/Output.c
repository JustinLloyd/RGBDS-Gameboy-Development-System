#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mylink.h"
#include "mapfile.h"
#include "main.h"
#include "assign.h"

char	tzOutname[_MAX_PATH];
BBOOL	oOutput=0;

void writehome( FILE *f )
{
	struct sSection *pSect;
	UBYTE	*mem;

	mem=(UBYTE *)malloc(BankSize[BANK_HOME]) ;
	if (mem)
	{
		if( fillchar!=-1 )
		{
			memset( mem, fillchar, BankSize[BANK_HOME] );
		}
		MapfileInitBank( 0 );

		pSect=pSections;
		while( pSect )
		{
			if( pSect->Type==SECT_HOME )
			{
				memcpy( mem+pSect->nOrg, pSect->pData, pSect->nByteSize );
				MapfileWriteSection( pSect );
			}
			pSect=pSect->pNext;
		}

		MapfileCloseBank( area_Avail(0) );

		fwrite( mem, 1, BankSize[BANK_HOME], f );
		free( mem );
	}
}

void writebank( FILE *f, SLONG bank )
{
	struct sSection *pSect;
	UBYTE	*mem;

	mem=(UBYTE *)malloc(BankSize[bank]) ;
	if (mem)
	{
		if( fillchar!=-1 )
		{
			memset( mem, (UBYTE)(bank), BankSize[bank] );
		}

		if ((g_identifyBanks) && (bank<=k_LAST_ROM_BANK))
			{
			*(mem+BankSize[bank]-1) = (UBYTE)(bank) ;
//			*mem = (UBYTE)(bank) ;
			}

		MapfileInitBank( bank );

		pSect=pSections;
		while( pSect )
		{
			if( pSect->Type==SECT_CODE && pSect->nBank==bank )
			{
				memcpy( mem+pSect->nOrg-k_ROM_BANK_SIZE, pSect->pData, pSect->nByteSize );
				MapfileWriteSection( pSect );
			}
			pSect=pSect->pNext;
		}

		MapfileCloseBank( area_Avail(bank) );

		fwrite( mem, 1, BankSize[bank], f );
		free( mem );
	}
}

void out_Setname( char *tzOutputfile )
{
	strcpy( tzOutname, tzOutputfile );
	oOutput=1;
}

void	GBROM_Output( void )
{
	SLONG i;
	FILE *f;

	f=fopen(tzOutname,"wb") ;
	if (f)
		{
		MapfileHeader() ;
		}

	if (f)
	{
		writehome( f );
		for( i=1; i<=MaxBankUsed; i++ )
			writebank( f, i );

		fclose( f );
	}

	for( i=256; i<MAXBANKS; i++ )
	{
		struct	sSection	*pSect;
		MapfileInitBank( i );
		pSect=pSections;
		while( pSect )
		{
			if( pSect->nBank==i )
			{
				MapfileWriteSection( pSect );
			}
			pSect=pSect->pNext;
		}
		MapfileCloseBank( area_Avail(i) );
	}
}

void	PSION2_Output( void )
{
	FILE *f;

	f=fopen(tzOutname,"wb") ;
	if (f)
	{
		struct sSection *pSect;
		UBYTE	*mem;
		ULONG	size=BankSize[0]-area_Avail(0);
		ULONG	relocpatches;

		fputc( size>>24, f );
		fputc( size>>16, f );
		fputc( size>>8, f );
		fputc( size, f );

		mem=(UBYTE *)malloc(BankSize[0]-area_Avail(0)) ;
		if (mem)
		{
			MapfileInitBank( 0 );

			pSect=pSections;
			while( pSect )
			{
				if( pSect->Type==SECT_CODE )
				{
					memcpy( mem+pSect->nOrg, pSect->pData, pSect->nByteSize );
					MapfileWriteSection( pSect );
				}
				else
				{
					memset( mem+pSect->nOrg, 0, pSect->nByteSize );
				}
				pSect=pSect->pNext;
			}

			MapfileCloseBank( area_Avail(0) );

			fwrite( mem, 1, BankSize[0]-area_Avail(0), f );
			free( mem );
		}

		relocpatches=0;
		pSect=pSections;
		while( pSect )
		{
			struct	sPatch	*pPatch;

			pPatch=pSect->pPatches;

			while( pPatch )
			{
				if( pPatch->oRelocPatch )
				{
					relocpatches+=1;
				}
				pPatch=pPatch->pNext;
			}
			pSect=pSect->pNext;
		}

		fputc( relocpatches>>24, f );
		fputc( relocpatches>>16, f );
		fputc( relocpatches>>8, f );
		fputc( relocpatches, f );

		pSect=pSections;
		while( pSect )
		{
			struct	sPatch	*pPatch;

			pPatch=pSect->pPatches;

			while( pPatch )
			{
				if( pPatch->oRelocPatch )
				{
					ULONG	address;

					address=pPatch->nOffset+pSect->nOrg;
					fputc( address>>24, f );
					fputc( address>>16, f );
					fputc( address>>8, f );
					fputc( address, f );
				}
				pPatch=pPatch->pNext;
			}
			pSect=pSect->pNext;
		}



		fclose( f );
	}
}

void	Output( void )
{
	if( oOutput )
	{
		switch( outputtype )
		{
			case OUTPUT_GBROM:
				GBROM_Output();
				break;
			case OUTPUT_PSION2:
				PSION2_Output();
				break;
		}
	}
}