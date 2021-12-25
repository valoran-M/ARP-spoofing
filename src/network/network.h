#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <linux/if_packet.h>

#define ETH_ADD_L 6
#define IP_ADD_L 4
#define ETH_BRODCAST \
    (uint8_t[6]) { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }

/**
 * @brief send arp brodcast packet
 * 
 * @param sock 
 * @param device 
 * @param my_mac_address 
 * @param spoofed_ip_source 
 * @param victim_ip 
 * 
 * @return int error info
 */
int send_packet_to_brodcast(const int sock, struct sockaddr_ll *device,
                            const uint8_t *my_mac_address,
                            const char *spoofed_ip_source, const char *victim_ip);

/**
 * @brief Get the victim response object
 * 
 * @param sock 
 * @param victim_ip 
 * @param victime_mac_adresse 
 * @return int 
 */
int get_victim_response(const int sock, const char *victim_ip, uint8_t *victime_mac_adresse);

#endif /* NETWORK_H */