/*
 * RGBFix : Perform various tasks on a Gameboy image-file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>


#include "asmotor.h"


#define k_MAX_STRING_LEN	256
#define k_MAX_CART_TITLE_LEN	16
#define k_ROM_BANK_SIZE		16384

typedef unsigned char UBYTE ;


/*
 * Option defines
 *
 */

#define OPTF_DEBUG			0x0001L
#define OPTF_PAD			0x0002L
#define OPTF_VALIDATE		0x0004L
#define OPTF_TITLE			0x0008L
#define OPTF_TRUNCATE		0x0010L
#define OPTF_GBC_COMPAT		0x0020L
#define OPTF_GBC_ONLY		0x0040L
#define OPTF_RAM_SIZE		0x0080L
#define OPTF_MBC_TYPE		0x0100L
#define OPTF_QUIET			0x0200L


unsigned long ulOptions;



/*
 * Misc. variables
 *
 */

	unsigned char NintendoChar[48] =
		{
		0xCE,0xED,0x66,0x66,0xCC,0x0D,0x00,0x0B,0x03,0x73,0x00,0x83,0x00,0x0C,0x00,0x0D,
		0x00,0x08,0x11,0x1F,0x88,0x89,0x00,0x0E,0xDC,0xCC,0x6E,0xE6,0xDD,0xDD,0xD9,0x99,
		0xBB,0xBB,0x67,0x63,0x6E,0x0E,0xEC,0xCC,0xDD,0xDC,0x99,0x9F,0xBB,0xB9,0x33,0x3E
		} ;




/*
 * Misc. routines
 *
 */

void PrintOption(char *option, char *info)
	{
	printf("\t%s\t%s\n", option, info) ;
	}


void PrintUsage(void)
	{
	printf("RGBFix v" RGBFIX_VERSION " (part of ASMotor " ASMOTOR_VERSION ")\n") ;
	printf("Usage: rgbfix [options] image[.gb]\n") ;
	printf("Options:\n") ;
	PrintOption("-h", "This text") ;
	PrintOption("-d", "Debug: Don't change image") ;
	PrintOption("-q", "Quiet\t\tSuppress all output except errors") ;
	PrintOption("-m[<hex value>]", "Change RAM size of cartridge") ;
	PrintOption("-p[<hex value>]", "Pad image to valid size\n\t\t\tPads to 32/64/128/256/512kB as appropriate\t\t\tAn optional hexadecimal pad value can be supplied") ;
	PrintOption("-r", "Truncate image to valid size\n\t\t\tTruncates to 32/64/128/256/512kB as appropriate") ;
	PrintOption("-t<name>", "Change cartridge title field (16 characters)") ;
	PrintOption("-v", "Validate header\n\t\t\tCorrects - Nintendo Character Area (0x0104)\n\t\t\t\t - ROM type (0x0147)\n\t\t\t\t - ROM size (0x0148)\n\t\t\t\t - Checksums (0x014D-0x014F)") ;
	PrintOption("-b<hex value]", "Set MBC type") ;
	PrintOption("-c", "Set Colour GameBoy compatible (0x80) flag (0x0143)") ;
	PrintOption("-o", "Set Colour GameBoy only (0xC0) flag (0x143)") ;
	exit(0) ;
	}

void FatalError(char *s)
	{
	printf("\n***ERROR: %s\n\n", s) ;
	PrintUsage() ;
	}


void MessageReport(char *msg, ...)
	{
	char	constructedMessage[k_MAX_STRING_LEN] ;

	va_list	params ;

	if (!(ulOptions & OPTF_QUIET))
		{
		va_start(params, msg) ;
		vsprintf(constructedMessage, msg, params) ;
		va_end(params) ;
		printf("%s", constructedMessage) ;
		}

	}


long int FileSize(FILE *f)
	{
	long prevpos;
	long r;

	prevpos=ftell(f) ;
	fflush(f) ;
	fseek(f, 0, SEEK_END) ;
	r=ftell(f) ;
	fseek(f, prevpos, SEEK_SET) ;
	return(r) ;
	}


int FileExists(char *s)
	{
	FILE *f ;

	if ((f=fopen(s,"rb")) != NULL)
		{
		fclose(f) ;
		return(1) ;
		}
	else
		{
		return (0) ;
		}

	}


void DescribeMBCType(UBYTE mbcType)
	{
	struct
		{
		short	m_type ;
		char	*m_description ;
		} mbcList[] = {	{ 0x00, "No MBC -- ROM Only" },
						{ 0x01, "MBC 0x01 -- ROM Only" },
						{ 0x02, "MBC 0x01 -- ROM & RAM" },
						{ 0x03, "MBC 0x01 -- ROM & RAM & Battery" },
						{ 0x05, "MBC 0x02 -- ROM Only" },
						{ 0x06, "MBC 0x02 -- ROM & Battery" },
						{ 0x08, "ROM & RAM" },
						{ 0x09, "ROM & RAM & Battery" },
						{ 0x0B, "MMM01 -- ROM Only" },
						{ 0x0C, "MMM01 -- ROM & RAM" },
						{ 0x0D, "MMM01 -- ROM & RAM & Battery" },
						{ 0x0F, "MBC 0x03 -- ROM & Timer & Battery" },
						{ 0x10, "MBC 0x03 -- ROM & RAM & Timer & Battery" },
						{ 0x11, "MBC 0x03 -- ROM Only" },
						{ 0x12, "MBC 0x03 -- ROM & RAM" },
						{ 0x13, "MBC 0x03 -- ROM & RAM & Battery" },
						{ 0x15, "MBC 0x04 -- ROM Only" },
						{ 0x16, "MBC 0x04 -- ROM & RAM" },
						{ 0x17, "MBC 0x04 -- ROM & RAM & Battery" },
						{ 0x19, "MBC 0x05 -- ROM Only" },
						{ 0x1A, "MBC 0x05 -- ROM & RAM" },
						{ 0x1B, "MBC 0x05 -- ROM & RAM & Battery" },
						{ 0x1C, "MBC 0x05 -- ROM & Rumble" },
						{ 0x1D, "MBC 0x05 -- ROM & RAM & Rumble" },
						{ 0x1E, "MBC 0x05 -- ROM & RAM & Battery & Rumble" },
						{ 0xFC, "Pocket Camera" },
						{ 0xFD, "Bandai TAMA5" },
						{ 0xFE, "HuC 3" },
						{ 0xFF, "HuC 1 -- ROM & RAM & Battery" },
						{ -1, NULL } }	;

	char	mbcDescription[k_MAX_STRING_LEN] ;

	int	i ;

	for (i=0; (mbcList[i].m_type!=-1) && (mbcList[i].m_type!=mbcType); i++) ;
	
	if (mbcList[i].m_type==-1)
		{
		strcpy(mbcDescription, "Unknown") ;
		}
	else
		{
		strcpy(mbcDescription, mbcList[i].m_description) ;
		}

	MessageReport("\t\t%s\n", mbcDescription) ;
	}


UBYTE Hex8BitOptionParam(const char *paramString)
	{
	unsigned	char	paramValue ;

	int	paramLen ;

	int	scanResult ;

	int	i ;

	// debug assert
	if (!paramString)
		{
		FatalError("NULL parameter passed\n") ;
		}

	// if param length < 1 digit or param length > 2 digits
	paramLen = strlen(paramString) ;
	if ((paramLen!=1) && (paramLen!=2))
		{
		// report fatal error
		FatalError("Value must be an 8-bit unsigned integer for option\n") ;
		}

	for (i=0; i<paramLen; i++)
		{
		if (!(isdigit(paramString[i]) || ((tolower(paramString[i]) >= 'a') && (tolower(paramString[i]) <= 'z'))))
			{
			FatalError("Value is not a valid 8-bit hexadecimal number for option\n") ;
			}

		}

	scanResult = sscanf(paramString, "%lx", &paramValue) ;
	if ((scanResult != EOF) && (scanResult != 1))
		{
		FatalError("Not a valid hexadecimal number for option\n") ;
		}

	return (paramValue) ;
	}


/*
 * Das main
 *
 */

int main(int argc, char *argv[])
	{
	int	argn = 1 ;
	
	char	filename[512] ;
	char	cartname[k_MAX_STRING_LEN] ;
	char	padValueString[k_MAX_STRING_LEN] ;
	char	ramSizeString[k_MAX_STRING_LEN] ;
	char	mbcTypeString[k_MAX_STRING_LEN] ;

	UBYTE	padValue ;
	UBYTE	ramSize = 0 ;
	UBYTE	mbcType = 0 ;

	FILE *f;

	ulOptions = 0 ;

	if ((--argc)==0)
		{
		PrintUsage() ;
		}

	while (*argv[argn]=='-')
		{
		argc-=1 ;
		switch (argv[argn++][1])
			{
			case '?' :
			case 'h' :
				PrintUsage() ;
				break ;

			case 'd' :
				ulOptions|=OPTF_DEBUG ;
				break ;

			case 'p' :
				strncpy(padValueString, argv[argn-1]+2, k_MAX_STRING_LEN-1) ;
				ulOptions|=OPTF_PAD ;
				break ;

			case 'r' :
				ulOptions|=OPTF_TRUNCATE ;
				break ;

			case 'v' :
				ulOptions|=OPTF_VALIDATE ;
				break ;

			case 't' :
				strncpy(cartname, argv[argn-1]+2, k_MAX_CART_TITLE_LEN) ;
				ulOptions|=OPTF_TITLE ;
				break ;

			case 'b' :
				strncpy(mbcTypeString, argv[argn-1]+2, k_MAX_STRING_LEN-1) ;
				ulOptions|=OPTF_MBC_TYPE ;
				break ;

			case 'm' :
				strncpy(ramSizeString, argv[argn-1]+2, k_MAX_STRING_LEN-1) ;
				ulOptions|=OPTF_RAM_SIZE ;
				break ;

			case 'c' :
				ulOptions|=OPTF_GBC_COMPAT ;
				break ;
			
			case 'o' :
				ulOptions|=OPTF_GBC_ONLY ;
				break ;

			case 'q' :
				ulOptions |= OPTF_QUIET ;
				if (argc == 0)
					{
					PrintUsage() ;
					}

				break ;

			}
	
		}


	if ((ulOptions&OPTF_GBC_ONLY) && (ulOptions&OPTF_GBC_COMPAT))
		{
		FatalError("Cannot be both GameBoy Colour Only and GameBoy Colour Compatible") ;
		}

	strcpy(filename, argv[argn++]) ;
	
	// if ram size was specified
	if (ulOptions & OPTF_RAM_SIZE)
		{
		if (strlen(ramSizeString)>0)
			{
			ramSize = Hex8BitOptionParam(ramSizeString) ;
			}
		else
			{
			FatalError("Ram Size must be specified") ;
			}

		}

	// if mbc type was specified
	if (ulOptions & OPTF_MBC_TYPE)
		{
		if (strlen(mbcTypeString)>0)
			{
			mbcType = Hex8BitOptionParam(mbcTypeString) ;
			}
		else
			{
			FatalError("MBC Type must be specified") ;
			}

		}

	// if pad value was specified
	if ((ulOptions & OPTF_PAD) && (strlen(padValueString)>0))
		{
		padValue = Hex8BitOptionParam(padValueString) ;
		}
	else
		{
		padValue = 0 ;
		}

	if (!FileExists(filename))
		{
		strcat(filename, ".gb") ;
		}

	if ((f=fopen(filename,"rb+")) != NULL)
		{
		/*
		 * -d (Debug) option code
		 *
		 */

		if (ulOptions&OPTF_DEBUG)
			{
			MessageReport("-d (Debug) option enabled...\n") ;
			}

		/*
		 * -p (Pad) option code
		 *
		 */

		if (ulOptions&OPTF_PAD)
			{
			UBYTE	padData[k_ROM_BANK_SIZE] ;

			long	padSize,
					bytesToAdd ;

			long	currentImageSize,
					padImageTo ;

			long	bytesAdded = 0 ;

			memset(padData, padValue, k_ROM_BANK_SIZE) ;
			currentImageSize = FileSize(f) ;
			padImageTo = 0x8000L ;
			while (currentImageSize > padImageTo)
				{
				padImageTo *= 2 ;
				}

			padSize = padImageTo - currentImageSize ;
			MessageReport("Padding to %ldKBytes with pad value %d\n", padImageTo/1024, padValue) ;
			// while file size < required image size
			if (padSize>0)
				{
				// flush message output
				fflush(stdout) ;
				// move to end of file
				fseek(f, 0, SEEK_END) ;
				while (padSize>0)
					{
					bytesToAdd = min(padSize, k_ROM_BANK_SIZE) ;
					if ((ulOptions&OPTF_DEBUG)==0)
						{
						fwrite(padData, sizeof(UBYTE), bytesToAdd, f) ;
						}

					bytesAdded += bytesToAdd ;
					padSize -= bytesToAdd ;
					}

				fflush(f) ;

				MessageReport("\tAdded %ld bytes\n", bytesAdded) ;
				}
			else
				{
				MessageReport("\tNo padding needed\n") ;
				}

			}

		/*
		 * -r (Truncate) option code
		 *
		 */

		if (ulOptions&OPTF_TRUNCATE)
			{
			long size, padto;
			char tempfile[512];
			FILE *tf;

			size=FileSize(f) ;
			padto=256*32768;
			while (size<padto)
				{
				padto/=2;
				}

			MessageReport("Truncating to %ldkB:\n", padto/1024) ;

			tmpnam(tempfile) ;

			if ((ulOptions&OPTF_DEBUG)==0)
				{
				if ((tf=fopen(tempfile,"wb"))!=NULL)
					{
					fseek(f, 0, SEEK_SET) ;
					while (padto--)
						{
						fputc(fgetc(f), tf) ;
						}

					fclose(f) ;
					fclose(tf) ;
					remove(filename) ;
					rename(tempfile, filename) ;
					f=fopen(filename, "rb+") ;
					}

				}

			}

		/*
		 * -t (Set carttitle) option code
		 *
		 */

		if (ulOptions&OPTF_TITLE)
			{
			MessageReport("Setting cartridge title:\n") ;
			if ((ulOptions&OPTF_DEBUG)==0)
				{
				fflush(f) ;
				fseek(f, 0x0134L, SEEK_SET) ;
				fwrite(cartname, 16, 1, f) ;
				fflush(f) ;
				}

			MessageReport("\tTitle set to %s\n", cartname) ;
			}

		/*
		 * -c (Set Colour GameBoy compatible) option code
		 *
		 */

		if (ulOptions&OPTF_GBC_COMPAT)
			{
			MessageReport("Setting Colour GameBoy compatible mode\n") ;
			if ((ulOptions&OPTF_DEBUG)==0)
				{
				fflush(f) ;
				fseek(f, 0x0143L, SEEK_SET) ;
				fputc(0x80, f) ;
				fflush(f) ;
				}

			MessageReport("\tColour GameBoy compatible mode set\n") ;
			}


		/*
		 * -o (Set Colour GameBoy only) option code
		 *
		 */

		if (ulOptions&OPTF_GBC_ONLY)
			{
			MessageReport("Setting Colour GameBoy only mode\n") ;
			if ((ulOptions&OPTF_DEBUG)==0)
				{
				fflush(f) ;
				fseek(f, 0x0143L, SEEK_SET) ;
				fputc(0xC0, f) ;
				fflush(f) ;
				}

			MessageReport("\tColour GameBoy only mode set\n") ;
			}


		/*
		 * -b (Set MBC Type) option code
		 *
		 */

		if (ulOptions&OPTF_MBC_TYPE)
			{
			MessageReport("Setting MBC Type\n") ;
			if ((ulOptions&OPTF_DEBUG)==0)
				{
				fflush(f) ;
				fseek(f, 0x0147L, SEEK_SET) ;
				fputc(mbcType, f) ;
				fflush(f) ;
				}

			MessageReport("\tMBC Type set to 0x%X\n", mbcType) ;
			DescribeMBCType(mbcType) ;
			}

		/*
		 * -m (Set RAM Size) option code
		 *
		 */

		if (ulOptions&OPTF_RAM_SIZE)
			{
			MessageReport("Setting RAM Size\n") ;
			if ((ulOptions&OPTF_DEBUG)==0)
				{
				fflush(f) ;
				fseek(f, 0x0149L, SEEK_SET) ;
				fputc(ramSize, f) ;
				fflush(f) ;
				}

			MessageReport("\tRAM Size set to 0x%X\n", ramSize) ;
			}

		/*
		 * -v (Validate header) option code
		 *
		 */

		if (ulOptions&OPTF_VALIDATE)
			{
			long i, byteschanged=0;
			long cartromsize, calcromsize=0, filesize;
			long carttype;
			unsigned short cartchecksum=0, calcchecksum=0;
			unsigned char cartcompchecksum=0, calccompchecksum=0;
			int ch;

			MessageReport("Validating header:\n") ;
			fflush(stdout) ;

			/* Nintendo Character Area */

			fflush(f) ;
			fseek(f, 0x0104L, SEEK_SET) ;

			for (i=0; i<48; i+=1)
				{
				int ch;

				ch=fgetc(f) ;
				if (ch==EOF)
					{
					ch=0x00 ;
					}

				if (ch!=NintendoChar[i])
					{
					byteschanged+=1;

					if ((ulOptions&OPTF_DEBUG)==0)
						{
						fseek(f, -1, SEEK_CUR) ;
						fputc(NintendoChar[i], f) ;
						fflush(f) ;
						}
				
					}
			
				}

			fflush(f) ;

			if (byteschanged)
				{
				MessageReport("\tChanged %ld bytes in the Nintendo Character Area\n", byteschanged) ;
				}
			else
				{
				MessageReport("\tNintendo Character Area is OK\n") ;
				}

			/* ROM size */

			fflush(f) ;
			fseek(f, 0x0148L, SEEK_SET) ;
			cartromsize=fgetc(f) ;
			if (cartromsize==EOF)
				{
				cartromsize=0x00;
				}

			filesize=FileSize(f) ;
			while (filesize>(0x8000L<<calcromsize))
				{
				calcromsize+=1;
				}

			if (calcromsize!=cartromsize)
				{
				if ((ulOptions&OPTF_DEBUG)==0)
					{
					fseek(f, -1, SEEK_CUR) ;
					fputc(calcromsize, f) ;
					fflush(f) ;
					}

				MessageReport("\tChanged ROM size byte from 0x%02lX (%ldkB) to 0x%02lX (%ldkB)\n",
							cartromsize, (0x8000L<<cartromsize)/1024,
							calcromsize, (0x8000L<<calcromsize)/1024) ;
				}
			else
				{
				MessageReport("\tROM size byte is OK\n") ;
				}

			/* Cartridge type */

			fflush(f) ;
			fseek(f, 0x0147L, SEEK_SET) ;
			carttype=fgetc(f) ;
			if (carttype==EOF)
				{
				carttype=0x00;
				}

			if (FileSize(f)>0x8000L)
				{
				/* carttype byte must != 0x00 */
				if (carttype==0x00)
					{
					if ((ulOptions&OPTF_DEBUG)==0)
						{
						fseek(f, -1, SEEK_CUR) ;
						fputc(0x01, f) ;
						fflush(f) ;
						}

					MessageReport("\tCartridge type byte changed to 0x01\n") ;
					}
				else
					{
					MessageReport("\tCartridge type byte is OK\n") ;
					}

				}
			else
				{
				/* carttype byte can be anything? */
				MessageReport("\tCartridge type byte is OK\n") ;
				}

			/* Checksum */

			fflush(f) ;
			fseek(f, 0, SEEK_SET) ;

			for(i=0; i<(0x8000L<<calcromsize) ; i+=1)
				{
				ch=fgetc(f) ;
				if (ch==EOF)
					{
					ch=0;
					}

				if (i<0x0134L)
					{
					calcchecksum += (unsigned short)(ch) ;
					}
				else if (i<0x014DL)
					{
					calccompchecksum+=ch;
					calcchecksum+=ch;
					}
				else if (i==0x014DL)
					{
					cartcompchecksum=(unsigned char)(ch) ;
					}
				else if (i==0x014EL)
					{
					cartchecksum=ch<<8;
					}
				else if (i==0x014FL)
					{
					cartchecksum|=ch;
					}
				else
					{
					calcchecksum += (unsigned short)(ch) ;
					}

				}

			calccompchecksum = (unsigned char)(0xE7-calccompchecksum) ;
			calcchecksum += (unsigned short)(calccompchecksum) ;

			if (cartchecksum!=calcchecksum)
				{
				fflush(f) ;
				fseek(f, 0x014EL, SEEK_SET) ;
				if ((ulOptions&OPTF_DEBUG)==0)
					{
					fputc(calcchecksum>>8, f) ;
					fputc(calcchecksum&0xFF, f) ;
					}

				fflush(f) ;
				MessageReport("\tChecksum changed from 0x%04lX to 0x%04lX\n", (long)cartchecksum, (long)calcchecksum) ;
				}
			else
				{
				MessageReport("\tChecksum is OK\n") ;
				}

			if (cartcompchecksum!=calccompchecksum)
				{
				fflush(f) ;
				fseek(f, 0x014DL, SEEK_SET) ;
				if ((ulOptions&OPTF_DEBUG)==0)
					{
 					fputc(calccompchecksum, f) ;
					}

				fflush(f) ;
				MessageReport("\tCompChecksum changed from 0x%02lX to 0x%02lX\n", (long)cartcompchecksum, (long)calccompchecksum) ;
				}
			else
				{
				MessageReport("\tCompChecksum is OK\n") ;
				}

			}
		
		fclose(f) ;
		}
	else
		{
		FatalError("Unable to open file") ;
		}

	return(0) ;
	}