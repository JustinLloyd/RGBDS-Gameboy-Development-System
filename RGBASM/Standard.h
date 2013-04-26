#ifndef __STANDARD_H__
#define __STANDARD_H__

#ifndef FALSE
#define FALSE	0
#endif

#ifndef TRUE
#define TRUE	1
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL	0
#else
#define NULL	((void *)0)
#endif
#endif

#define k_END_OF_STRING		0
#define k_MAX_STRING_LEN	256

#endif // __STANDARD_H__