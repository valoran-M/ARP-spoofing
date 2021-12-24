#ifndef DEBUG_H

#ifdef DEBUG_MODE

#define DEBUG_LOG(x)                                                    \
    {                                                                   \
        fprintf(stderr, "%s %s line %d", __FILE__, __func__, __LINE__); \
        fprintf(stderr, args);                                          \
        fprintf(stderr, "\n");                                          \
    }
#else

#define DEBUG_LOG(x)

#endif /* DEBUG_MODE */

#endif /* DEBUG_H */