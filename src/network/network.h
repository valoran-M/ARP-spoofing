#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <linux/if_packet.h>

#define ETH_ADD_L 6
#define IP_ADD_L 4
#define ETH_BRODCAST \
    (uint8_t[6]) { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }

/**
 * @brief send arp packet in brodcast
 *
 * @param sock
 * @param device
 * @param my_mac_address
 * @param victim_mac_address
 * @param spoofed_ip_source
 * @param victim_ip
 */
void send_packet_to_brodcast(const int sock, struct sockaddr_ll *device,
                             const uint8_t *my_mac_address, const uint8_t *victim_mac_address,
                             const char *spoofed_ip_source, const char *victim_ip);

#endif /* NETWORK_H */