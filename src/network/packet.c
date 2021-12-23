#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <net/ethernet.h>

#include "network.h"
#include "packet.h"

t_ether_packet *create_ethernet_tram(const uint8_t *dest_mac, const uint8_t *src_mac, const p_arp_packet *arp_p)
{
    t_ether_packet *ether;
    ether = malloc(sizeof(t_ether_packet));

    memcpy(ether->dest_mac, dest_mac, sizeof(uint8_t) * ETH_ADD_L);
    memcpy(ether->src_mac, src_mac, sizeof(uint8_t) * IP_ADD_L);
    ether->ether_type = htons(ETH_P_ARP);
    memcpy((uint8_t *)&ether->arp_packet, arp_p, sizeof(p_arp_packet));
    return ether;
}

p_arp_packet *create_arp_packet(const uint16_t opcode,
                                const uint8_t *dest_mac, const char *dest_ip,
                                const uint8_t *src_mac, const char *spoofed_ip)
{
    p_arp_packet *arp;
    arp = malloc(sizeof(p_arp_packet));

    arp->hardware_type = htons(1);
    arp->protocol_type = htons(ETH_P_IP);
    arp->hardware_adress_length = ETH_ADD_L;
    arp->protocol_address_length = IP_ADD_L;
    arp->operation = htons(opcode);
    memcpy(&arp->sender_mac, src_mac, sizeof(uint8_t) * ETH_ADD_L);
    memcpy(&arp->taget_mac, dest_mac, sizeof(uint8_t) * ETH_ADD_L);
    
}