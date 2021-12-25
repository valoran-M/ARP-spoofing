#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <signal.h>
#include <net/if_arp.h>
#include <netinet/ip.h>
#include <linux/if_packet.h>

#include "network/packet.h"
#include "utils/utils.h"

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
 * @param victim_mac_address
 * @return int
 */
int get_victim_response(const int sock, const char *victim_ip, uint8_t *victim_mac_address);

/**
 * @brief send arp request
 * 
 * @param sock 
 * @param device 
 * @param my_mac_address 
 * @param spoofed_ip 
 * @param victim_mac_adres 
 * @param victim_ip 
 * @return int 
 */
int repeated_sending(int sock, struct sockaddr_ll *device,
                     const uint8_t *my_mac_address, const char *spoofed_ip,
                     const uint8_t *victim_mac_adres, const char *victim_ip);

#endif /* NETWORK_H */