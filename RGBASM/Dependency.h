#ifndef __DEPENDENCY_H__
#define __DEPENDENCY_H__

#define k_MAX_DEPENDENT_FILES	10000

extern void AddFileDependency(char *filename) ;
extern void OutputFileDependencies(char *dependencyFile) ;
extern void CleanUpDependencyList(void) ;
extern void InitDependencyList(void) ;

#endif // __DEPENDENCY_H__
