#ifndef OUTPUT_H
#define OUTPUT_H 1

#include "types.h"
#include "rpn.h"

struct Section
{
	char *pzName;
	UBYTE nType;
	ULONG nPC;
	ULONG nOrg;
	ULONG nBank;
	struct Section *pNext;
	struct Patch *pPatches;
	UBYTE *tData;
};

extern void out_PrepPass2(void );
extern char *out_GetFileName(void) ;
extern void out_SetFileName(char *s );
extern void out_NewSection (char *pzName, ULONG secttype);
extern void out_NewAbsSection (char *pzName, ULONG secttype, SLONG org, SLONG bank);
extern void out_AbsByte(int b );
extern void out_RelByte(struct Expression *expr );
extern void out_RelWord(struct Expression *expr );
extern void out_PCRelByte(struct Expression *expr );
extern void out_WriteObject(void );
extern void out_Skip(int skip );
extern void out_BinaryFile(char *s );
extern void out_BinaryFilePartial(char *s, long startPos, long numBytes) ;
extern void out_String(char *s );
extern void out_AbsLong (SLONG b);
extern void out_RelLong (struct Expression *expr);
extern void out_PushSection(void );
extern void out_PopSection(void );
extern void out_AlignTo(int boundary) ;
#endif