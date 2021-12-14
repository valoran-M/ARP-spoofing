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

#define PKTLEN sizeof(struct ether_header) + sizeof(struct ether_arp)

void help()
{
    printf("usage:\t./arp-poison <ip_source> <ip_destination> <interface>\n");
    printf("ex:\t./arp-poison 192.168.1.1 192.168.1.2 wlo1\n");
}

int main(int argc, char const *argv[])
{
    char packet[PKTLEN];
    struct sockaddr_ll device;
    int sock;

    sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (sock < 0)
    {
        fprintf(stderr, "socket() \n\t -> %s\n", strerror(errno));
        exit(errno);
    }

    return 0;
}
