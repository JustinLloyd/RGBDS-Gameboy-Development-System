#include <stdlib.h>

#include "ErrorMsg.h"


ErrorMsg::ErrorMsg(void)
	{
	m_errorCount = 0 ;
	m_warningCount = 0 ;
	}


void ErrorMsg::Error(int errMsgNum)
	{
/*
	if (g_clOptions.OutputFormat()==k_ERROR_OUTPUT_RGBDS)
		{
	    printf("*ERROR*\t") ;
		fstk_Dump() ;
		printf(" :\n\t%s\n", s) ;
		}
	else if (g_clOptions.OutputFormat()==k_ERROR_OUTPUT_DEVSTUDIO)
		{
		fstk_Dump() ;
		printf(" : *ERROR* : ") ;
		printf(" %s\n", s) ;
		}
*/
	m_errorCount++ ;
	}


void ErrorMsg::Fatal(int errMsgNum)
	{
	m_errorCount++ ;
	exit(1) ;
	}


void ErrorMsg::Warning(int errMsgNum)
	{
	m_warningCount++ ;
	}
