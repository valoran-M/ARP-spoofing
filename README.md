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

### arp

<tbody>
    <tr>
        <td>
            <table class="wikitable" style="margin: 0 auto; text-align: center; width: 50em;">
                <tbody>
                    <tr>
                        <th colspan="1">+
                        </th>
                        <th colspan="8" width="25%">Bits 0 - 7
                        </th>
                        <th colspan="8" width="25%">8 - 15
                        </th>
                        <th colspan="16" width="50%">16 - 31
                        </th>
                    </tr>
                    <tr>
                        <th>0
                        </th>
                        <td colspan="16"><span class="lang-en" lang="en"><i>Hardware type</i></span>
                        </td>
                        <td colspan="16"><span class="lang-en" lang="en"><i>Protocol type</i></span>
                        </td>
                    </tr>
                    <tr>
                        <th>32
                        </th>
                        <td colspan="8"><span class="lang-en" lang="en"><i>Hardware Address Length</i></span>
                        </td>
                        <td colspan="8"><span class="lang-en" lang="en"><i>Protocol Address Length</i></span>
                        </td>
                        <td colspan="16"><span class="lang-en" lang="en"><i>Operation</i></span>
                        </td>
                    </tr>
                    <tr>
                        <th>64
                        </th>
                        <td colspan="32"><span class="lang-en" lang="en"><i>Sender Hardware Address</i></span>
                        </td>
                    </tr>
                    <tr>
                        <th>?
                        </th>
                        <td colspan="32"><span class="lang-en" lang="en"><i>Sender Protocol Address</i></span>
                        </td>
                    </tr>
                    <tr>
                        <th>?
                        </th>
                        <td colspan="32"><span class="lang-en" lang="en"><i>Target Hardware Address</i></span>
                        </td>
                    </tr>
                    <tr>
                        <th>?
                        </th>
                        <td colspan="32"><span class="lang-en" lang="en"><i>Target Protocol Address</i></span>
                        </td>
                    </tr>
                </tbody>
            </table>
        </td>
    </tr>
</tbody>
</table>



## inspired by

- the base : https://gist.github.com/austinmarton/1922600
- SRJanel (https://github.com/SRJanel/arp_poisoning)
- multiple other source code on the internet

## Warning

made for educational purposes to learn how to use raw sockets. I am trying to code protection software