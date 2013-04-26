#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#include "Main.h"
#include "Dependency.h"
#include "Standard.h"
#include "Assert.h"
#include "Output.h"


	char	*dependencyList[k_MAX_DEPENDENT_FILES] ;

	int	dependentFileCount = 0 ;


void InitDependencyList(void)
	{
	CleanUpDependencyList() ;
	dependentFileCount = 0 ;
	}

		
// find a filename in the dependency list
static int FindFile(char *filename)
	{
	int	i ;

	// for each filename in dependency list
	for (i=0; i<dependentFileCount; i++)
		{
		// if current filename is valid
		if (dependencyList[i])
			{
			// if filename in list == specified filename
			if (!stricmp(dependencyList[i], filename))
				{
				// set return code to true
				// exit function
				return (TRUE) ;
				}

			}

		}

	// set return code to false
	return (FALSE) ;
	}


// add a filename to the dependency list
void AddFileDependency(char *filename)
	{
	int	found ;

	char	*dependentFile ;

	// assert that filename is valid
	Assert(filename!=NULL, "Filename is null") ;
	Assert(*filename!=0, "Filename is empty") ;

	// search current list of filenames
	found = FindFile(filename) ;
	// if filename found
	if (found)
		{
		// exit function
		return ;
		}

	// if dependency list is full
	if (dependentFileCount >= k_MAX_DEPENDENT_FILES)
		{
		// abort program with error
		ErrorFatal("Too many dependent files\n") ;
		}
		
	// allocate memory for filename string
	dependentFile = strdup(filename) ;
	// if failed to allocate memory
	if (!dependentFile)
		{
		// abort program with "out of memory" error
		ErrorFatal("Out of memory!") ;
		}

	// add filename string to dependency list
	dependencyList[dependentFileCount] = dependentFile ;
	// increment number of dependent files
	dependentFileCount++ ;
	}


// output the list of dependent files
void OutputFileDependencies(char *dependencyFile)
	{
	int	i ;

	FILE	*f ;

	// open specified file for append
	f = fopen(dependencyFile, "at") ;
	// if failed to open file
	if (!f)
		{
		// abort program with "failed to open dependency file for writing"
		ErrorFatal("Failed to open dependency file for output\n") ;
		}

	fprintf(f, "%s: %s ", out_GetFileName(), GetSourceFileName()) ;
	// for each filename in dependency list
	for (i=0; i<dependentFileCount; i++)
		{
		// if current entry in dependency list is valid
		if (dependencyList[i])
			{
			// write filename to dependency file
			fprintf(f, "%s ", dependencyList[i]) ;
			}

		}

	fputc('\n', f) ;
	// close dependency file
	fclose (f) ;
	}


// clean up dependency list
void CleanUpDependencyList(void)
	{
	int	i ;

	// for each filename in dependency list
	for (i=0; i<dependentFileCount; i++)
		{
		// if memory is allocated to this filename
		if (dependencyList[i])
			{
			// free allocated memory
			free(dependencyList[i]) ;
			dependencyList[i] = NULL ;
			}

		}

	}
