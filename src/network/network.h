#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>

#define ETH_ADD_L 6
#define IP_ADD_L 4
#define ETH_BRODCAST \
    (uint8_t[6]) { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }

#endif /* NETWORK_H */