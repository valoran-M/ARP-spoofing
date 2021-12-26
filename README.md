# arp_poisoning

software related to the arp protocol with the libc

![fiole](image/fiole_verte.png)

## explanation

the arp protocol allows to link the ip address to 
the mac address for that we send an arp 
request which says this ip address has this mac address. 

When a person wants to send a packet to an ip address he 
will look in the arp table and will not pass the mac address. 

So if we send an arp request by changing your IP, the person 
who wants to send a packet to this IP will send it to us.

![schema](image/schema.png)

## inspired by

### arp poisoning

- the base : https://gist.github.com/austinmarton/1922600
- SRJanel (https://github.com/SRJanel/arp_poisoning)
- multiple other source code on the internet

### arp render

- in development

## Warning

made for educational purposes to learn how to use raw sockets. I am trying to code protection software