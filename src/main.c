#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <unistd.h>
#include <errno.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *victim_ip, *poissoning_ip, *interface;
    if (argc != 4)
    {
        printf("usage:\t./arp-poison <ip_source> <ip_destination> <interface>\n");
        printf("ex:\t./arp-poison 10.1.1.1 10.1.1.2 eth0\n");
        exit(1);
    }
    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (sock == -1)
    {
        perror("socket()");
        exit(errno);
    }
    return 0;
}
