#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>

#include "network/network.h"
#include "utils/utils.h"

typedef struct s_arp_packet
{
    uint16_t hardware_type;
    uint16_t protocol_type;
    uint8_t hardware_adress_length;
    uint8_t protocol_address_length;
    uint16_t operation;
    uint8_t sender_mac[ETH_ADD_L];
    uint8_t sender_ip[IP_ADD_L];
    uint8_t target_mac[ETH_ADD_L];
    uint8_t target_ip[IP_ADD_L];
} t_arp_packet;

typedef struct s_ether_trame
{
    uint8_t dest_mac[ETH_ADD_L];
    uint8_t src_mac[ETH_ADD_L];
    uint16_t ether_type;
} t_ether_trame;

/**
 * @brief Create a ethernet tram object
 *
 * @see /src/network/packet.c
 *
 * @param t_ether_trame*
 * @param code
 * @param dest_mac
 * @param src_mac
 *
 * @return int error info
 */
int create_ethernet_trame(t_ether_trame *ether,
                          const uint8_t *dest_mac, const uint8_t *src_mac,
                          const t_arp_packet *arp_p);

/**
 * @brief Create a arp packet object
 *
 * @see /src/network/packet.c
 *
 * @param t_arp_packet*
 * @param opcode arp code
 * @param dest_mac
 * @param dest_ip
 * @param src_mac
 * @param spoofed_ip
 *
 * @return int error info
 */
int create_arp_packet(t_arp_packet *arp, const uint16_t opcode,
                      const uint8_t *dest_mac, const char *dest_ip,
                      const uint8_t *src_mac, const char *spoofed_ip);

#endif /* PACKET_H */