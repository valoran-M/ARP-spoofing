#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/ip.h>
#include <net/if_arp.h>

#include "network/interface.h"
#include "utils/debug.h"
#include "utils/utils.h"

int get_my_mac_adresse(const int sock, const char *interface, uint8_t *my_mac)
{
    DEBUG_LOG("get my mac adresse");

    struct ifreq ifreq_c;
    memset(&ifreq_c, 0, sizeof(ifreq_c));
    strncpy(ifreq_c.ifr_name, interface, IFNAMSIZ - 1);

    if ((ioctl(sock, SIOCGIFHWADDR, &ifreq_c)) < 0)
    {
        error("ioctl():");
        return -1;
    }
    return 0;
}