#include <stdlib.h>

#include "Assert.h"


void Assert(const int condition, const char *msg)
	{
	if (!condition)
		{
		perror(msg) ;
		abort() ;
		}

	}
