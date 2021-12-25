#include "network/packet.h"

int create_ethernet_trame(t_ether_trame *ether, const uint8_t *dest_mac, const uint8_t *src_mac, const t_arp_packet *arp_p)
{
    memcpy(&ether->dest_mac, dest_mac, sizeof(uint8_t) * ETH_ADD_L);
    memcpy(&ether->src_mac, src_mac, sizeof(uint8_t) * ETH_ADD_L);

    ether->ether_type = htons(ETH_P_ARP);

    memcpy((uint8_t *)ether + ETH_HEADER_LENGTH, arp_p, sizeof(uint8_t) * ARP_HEADER_LENGTH);
    printf("[+] ETHER trame create\n");

    return 0;
}

int create_arp_packet(t_arp_packet *arp, const uint16_t opcode,
                      const uint8_t *dest_mac, const char *dest_ip,
                      const uint8_t *src_mac, const char *spoofed_ip)
{
    arp->hardware_type = htons(1);
    arp->protocol_type = htons(ETH_P_IP);
    arp->hardware_adress_length = ETH_ADD_L;
    arp->protocol_address_length = IP_ADD_L;
    arp->operation = htons(opcode);
    memcpy(&arp->sender_mac, src_mac, sizeof(uint8_t) * ETH_ADD_L);
    memcpy(&arp->target_mac, dest_mac, sizeof(uint8_t) * ETH_ADD_L);
    if (inet_pton(AF_INET, dest_ip, arp->target_ip) < 0 ||
        inet_pton(AF_INET, spoofed_ip, arp->sender_ip) < 0)
    {
        error("inet_pton():");
        return 1;
    }
    printf("[+] ARP packet create\n");

    return 0;
}