# arp_poisoning

software related to the arp protocol with the libc

![fiole](image/fiole_verte.png)

the arp protocol allows to link the ip address to 
the mac address for that we send an arp 
request which says this ip address has this mac address. 

When a person wants to send a packet to an ip address he 
will look in the arp table and will not pass the mac address. 

So if we send an arp request by changing your IP, the person 
who wants to send a packet to this IP will send it to us.

![schema](image/schema.png)

## package structure
#### arp :

<table style="margin: 0 auto; width: 50em;">
    <tbody>
        <tr>
            <th align="center" width="25%">Octet 1</th>
            <th align="center" width="25%">Octet 2</th>
            <th align="center" width="25%">Octet 3</th>
            <th align="center" width="25%">Octet 4</th>
        </tr>
        <tr>
            <td align="center" colspan="2">Hardware type</td>
            <td align="center" colspan="2">Protocol type</td>
        </tr>
        <tr>
            <td align="center" colspan="1">Hardware Address Length</td>
            <td align="center" colspan="1">Protocol Address Length</td>
            <td align="center" colspan="2">Operation</td>
        </tr>
        <tr>
            <td align="center" colspan="4">Adresse MAC source (octets 1-4)</td>
        </tr>
        <tr>
            <td align="center" colspan="2">Adresse MAC source (octets 5-6)</td>
            <td align="center" colspan="2">Adresse IP source (octets 1-2)</td>
        </tr>
        <tr>
            <td align="center" colspan="2">Adresse IP source (octets 3-4</)</td>
            <td align="center" colspan="2">Adresse MAC destination (octets 1-2)</td>
        </tr>
        <tr>
            <td align="center" colspan="4">Adresse MAC destination (octets 3-6)</td>
        </tr>
        <tr>
            <td align="center" colspan="4">Adresse IP destination (octets 1-4)</td>
        </tr>
    </tbody>
</table>

```c
typedef struct s_arp_packet
{
    uint16_t hardware_type;
    uint16_t protocol_type;
    uint8_t hardware_adress_length;
    uint8_t protocol_address_length;
    uint16_t operation;
    uint8_t sender_mac[ETH_ADD_L];
    uint8_t sender_ip[IP_ADD_L];
    uint8_t target_mac[ETH_ADD_L];
    uint8_t target_ip[IP_ADD_L];
} t_arp_packet;
```

#### Ethernet :

<table style="margin: 0 auto; width: 50em;">
    <tbody>
        <tr>
            <th align="center" width="25%">Octet 1</th>
            <th align="center" width="25%">Octet 2</th>
            <th align="center" width="25%">Octet 3</th>
            <th align="center" width="25%">Octet 4</th>
        </tr>
        <tr>
            <td align="center" colspan="4">Adresse MAC destination (octets 1-4)</td>
        </tr>
        <tr>
            <td align="center" colspan="2">Adresse MAC destination (octets 5-6)</td>
            <td align="center" colspan="2">Adresse MAC source (octets 1-2)</td>
        </tr>
        <tr>
            <td align="center" colspan="4">Adresse MAC source (octets 3-6)</td>
        </tr>
        <tr>
            <td align="center" colspan="2">Protocol type</td>
            <td align="center" colspan="2">Data</td>
        </tr>
        <tr>
            <td align="center" colspan="4">Data</td>
        </tr>
        <tr>
            <td align="center" colspan="4">...</td>
        </tr>
    </tbody>
</table>

```c
typedef struct s_ether_tram
{
    uint8_t dest_mac[ETH_ADD_L];
    uint8_t src_mac[ETH_ADD_L];
    uint16_t ether_type;
    t_arp_packet arp_packet;
} t_ether_tram;
```

## inspired by

- the base : https://gist.github.com/austinmarton/1922600
- SRJanel (https://github.com/SRJanel/arp_poisoning)
- multiple other source code on the internet

## Warning

made for educational purposes to learn how to use raw sockets. I am trying to code protection software