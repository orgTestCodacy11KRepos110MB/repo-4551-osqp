#ifndef GLOB_OPTS_H
#define GLOB_OPTS_H

/*
   Define OSQP compiler flags
 */

// cmake generated compiler flags
#include "osqp_configure.h"

/* DATA CUSTOMIZATIONS (depending on memory manager)-----------------------   */

/* We do not need memory allocation functions if EMBEDDED is enabled */
# ifndef EMBEDDED
#  ifdef OSQP_CUSTOM_MEMORY
/* Use user-provided memory management functions */
#    include OSQP_CUSTOM_MEMORY
#  else
/* If no custom memory allocator defined, use standard library functions.  */
#   include <stdlib.h>
#   define c_malloc  malloc
#   define c_calloc  calloc
#   define c_free    free
#   define c_realloc realloc
#  endif
# endif /* end ifndef EMBEDDED */


/* Use customized operations */

# ifndef c_absval
#  define c_absval(x) (((x) < 0) ? -(x) : (x))
# endif /* ifndef c_absval */

# ifndef c_max
#  define c_max(a, b) (((a) > (b)) ? (a) : (b))
# endif /* ifndef c_max */

# ifndef c_min
#  define c_min(a, b) (((a) < (b)) ? (a) : (b))
# endif /* ifndef c_min */

// Round x to the nearest multiple of N
# ifndef c_roundmultiple
#  define c_roundmultiple(x, N) ((x) + .5 * (N)-c_fmod((x) + .5 * (N), (N)))
# endif /* ifndef c_roundmultiple */


/* Use customized functions -----------------------------------------------   */

# if EMBEDDED != 1

#  include <math.h>
#  ifndef DFLOAT // Doubles
#   define c_sqrt sqrt
#   define c_fmod fmod
#  else          // Floats
#   define c_sqrt sqrtf
#   define c_fmod fmodf
#  endif /* ifndef DFLOAT */

# endif // end EMBEDDED

#endif /* ifndef GLOB_OPTS_H */
