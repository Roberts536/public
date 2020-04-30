# Networking Concepts

## DHCP

Notes from the first half of https://www.youtube.com/watch?v=g7mroO_BLD0 

DHCP stands for *Dynamic Host Configuration Protocol*. It's a way to dynamically assign IP addresses to devices on IP networks.

You used to have to assign IP addresses statically, i.e. manually open up the settings and type the IP address in. With DHCP, when you connect to a network the server will give you an IP address.

DHCP is performed by the server - be it a 'proper' server, or the router or ISP's modem in your house.

Note that DHCP does not also perform Domain Name Services (DNS) resolution. They can even be on different servers. Though often the services will talk to one another.

The DHCP server will provide several pieces of information to the client:
* The IP address which the server has assigned to the client
* The subnet mask
* Default gateway (router or modem that allows the computer to talk outside the LAN)
* Addresses of primary and secondary DNS servers

The IP address is the dynamic piece of information. The others are static.

* The DHCP server has a *scope* of IP addresses which it is allowed to give out
* You can set up static IP addresses outside the scope, or use reservations within the scope
