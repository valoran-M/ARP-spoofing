#ifndef UTILS_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define ETH_ADD_L 6
#define IP_ADD_L 4
#define ETH_BRODCAST \
    (uint8_t[6]) { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }
    
#define ETH_HEADER_LENGTH 14
#define ARP_HEADER_LENGTH 28
#define SEND_TIME 1

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