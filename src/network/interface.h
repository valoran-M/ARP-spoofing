#ifndef INTERFACE_H
#define INTERFACE_H

#include <linux/if_packet.h>

/**
 * @brief Get the my mac adresse object
 * 
 * @param sock 
 * @param interface 
 * @param my_mac 
 * @return int 
 */
int get_my_mac_adresse(const int sock, const char *interface, uint8_t *my_mac);

/**
 * @brief Set up device object
 *
 * @param device
 * @param interface
 * @return int
 */
int setup_sockaddr(struct sockaddr_ll *device, const char *interface);

#endif /* INTERFACE_H */
