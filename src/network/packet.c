#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <net/ethernet.h>

#include "network/network.h"
#include "network/packet.h"
#include "utils/utils.h"
#include "utils/debug.h"

void create_ethernet_tram(t_ether_trame *ether, const uint8_t *dest_mac, const uint8_t *src_mac, const p_arp_packet *arp_p)
{
    ether = malloc(sizeof(t_ether_trame));

    memcpy(ether->dest_mac, dest_mac, sizeof(uint8_t) * ETH_ADD_L);
    memcpy(ether->src_mac, src_mac, sizeof(uint8_t) * IP_ADD_L);
    ether->ether_type = htons(ETH_P_ARP);
    memcpy((uint8_t *)&ether->arp_packet, arp_p, sizeof(p_arp_packet));
    return 0;
}

int create_arp_packet(p_arp_packet *arp, const uint16_t opcode,
                        const uint8_t *dest_mac, const char *dest_ip,
                        const uint8_t *src_mac, const char *spoofed_ip)
{
    arp = malloc(sizeof(p_arp_packet));

    arp->hardware_type = htons(1);
    arp->protocol_type = htons(ETH_P_IP);
    arp->hardware_adress_length = ETH_ADD_L;
    arp->protocol_address_length = IP_ADD_L;
    arp->operation = htons(opcode);
    memcpy(&arp->sender_mac, src_mac, sizeof(uint8_t) * ETH_ADD_L);
    memcpy(&arp->taget_mac, dest_mac, sizeof(uint8_t) * ETH_ADD_L);
    if (inet_pton(AF_INET, dest_ip, arp->taget_ip) < 0 ||
        inet_pton(AF_INET, spoofed_ip, arp->sender_ip) < 0)
    {
        error("inet_pton():");
        return -1;
    }

    DEBUG_LOG("create_arp_packet");
    return 0;
}