#ifndef __ARPACKDEF_H__
#define __ARPACKDEF_H__

/* arpackdef.h must be included only by C/C++, not by F77/F90. */

#define INTERFACE64 1

#if INTERFACE64
#include <stdint.h> /* Include this header for int64_t, uint64_t definition. */
#define a_int    int64_t
#define a_uint  uint64_t
#else
#define a_int            int
#define a_uint  unsigned int
#endif

#endif
