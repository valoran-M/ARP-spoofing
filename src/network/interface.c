#include "network/interface.h"

int get_my_mac_adresse(const int sock, const char *interface, uint8_t *my_mac)
{
    struct ifreq ifreq_c;
    memset(&ifreq_c, 0, sizeof(ifreq_c));
    strncpy(ifreq_c.ifr_name, interface, IFNAMSIZ - 1);

    if ((ioctl(sock, SIOCGIFHWADDR, &ifreq_c)) < 0)
    {
        error("ioctl():");
        return 1;
    }
    memcpy(my_mac, ifreq_c.ifr_hwaddr.sa_data, sizeof(uint8_t) * ETH_ADD_L);

    printf("[+] Your MAC adress :");
    PRINT_MAC_ADDRESS(my_mac);
    return 0;
}

int setup_sockaddr(struct sockaddr_ll *device, const char *interface)
{
    memset(device, 0, sizeof(device));
    device->sll_ifindex = if_nametoindex(interface);
    if (device->sll_ifindex == 0)
    {
        error("if_nameto_index():");
        return 1;
    }
    printf("[+] Index : %d from interface %s\n", device->sll_ifindex, interface);
    device->sll_halen = ETH_ALEN;
    return 0;
}