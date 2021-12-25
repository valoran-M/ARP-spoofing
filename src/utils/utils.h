#ifndef UTILS_H

#include <stdio.h>

#define PRINT_MAC_ADDRESS(X) fprintf(stdout, "MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", \
                                     X[0],                                                   \
                                     X[1],                                                   \
                                     X[2],                                                   \
                                     X[3],                                                   \
                                     X[4],                                                   \
                                     X[5]);
#define PRINT_IP_ADDRESS(X) fprintf(stdout, "IP address: %02d.%02d.%02d.%02d\n", \
                                    X[0],                                        \
                                    X[1],                                        \
                                    X[2],                                        \
                                    X[3]);

/**
 * @brief display help message
 *
 */
void help();

/**
 * @brief display error
 *
 * @param code
 */
void error(char *code);

#endif /* UTILS_H */