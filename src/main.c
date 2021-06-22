#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <arpa/inet.h>
#include <net/if.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <netinet/if_ether.h>
#include <signal.h>

void help()
{
    printf("usage:\t./arp-poison <ip_source> <ip_destination> <interface>\n");
    printf("ex:\t./arp-poison 192.168.1.1 192.168.1.2 wlo1\n");
}

int main(int argc, char const *argv[])
{
    char *ip_src, *ip_dest, *interface;
    uint8_t *my_mac_address, *victim_mac_address;
    struct sockaddr_ll device;
    int sock;

    if (argc != 4)
        help(), exit(1);

    strcpy(ip_src, argv[1]), strcpy(ip_dest, argv[2]), strcpy(interface, argv[3]);

    if ((sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP))) < 0)
        perror("socket()"), exit(errno);

    return 0;
}
