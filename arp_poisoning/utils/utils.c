#include "utils/utils.h"

void help()
{
    printf("usage:\t./arp-poison <spoofed_ip> <ip_destination> <interface>\n");
    printf("ex:\t./arp-poison 192.168.1.1 192.168.1.2 wlo1\n");
}

void error(char *code)
{
    perror(code);
}