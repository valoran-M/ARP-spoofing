#include <stdlib.h>
#include <stdio.h>

void help()
{
    printf("usage:\t./arp-poison <ip_source> <ip_destination> <interface>\n");
    printf("ex:\t./arp-poison 192.168.1.1 192.168.1.2 wlo1\n");
}

void error(char *code)
{
    help();
    perror(code);
}