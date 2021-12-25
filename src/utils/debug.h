#ifndef DEBUG_H

#ifdef DEBUG_MODE

#include <stdio.h>

#define DEBUG_LOG                                                             \
    {                                                                         \
        fprintf(stderr, "=> %s %s line %d : ", __FILE__, __func__, __LINE__); \
        fprintf(stderr, "\n");                                                \
    }
#else

#define DEBUG_LOG

#endif /* DEBUG_MODE */

#endif /* DEBUG_H */