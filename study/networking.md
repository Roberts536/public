# Networking Concepts

## DHCP

Notes from:
* https://www.youtube.com/watch?v=g7mroO_BLD0 
* https://www.cloudflare.com/learning/dns/what-is-recursive-dns/
* https://ns1.com/resources/dns-types-records-servers-and-queries

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

*Recursive DNS* is where the server communicates with several other (upstream) DNS servers to resolve an address. This is in contrast to *Iterative DNS* in which the client queries each DNS server in turn. RDNSS = recursive DNS server.

There are a few types of DNS records:

* `A` is an Address Mapping Record, which maps a name to an IPv4 address
* `AAAA` is the same for IPv6
* `CNAME` is a Canonical Name, which aliases one hostname for another
* `PTR` is a Reverse look-up pointer record, which is for obtaining a name from an IP address

More here: https://ns1.com/resources/dns-types-records-servers-and-queries

## Default Gateway

From https://www.lifewire.com/what-is-a-default-gateway-817771

The default gateway is the server which passes requests from the local network out into the internet.

The default gateway will also pass requests within the local network. It can tell whether the request's destination is inside or outside the network by looking at the IP address.

There are two types of gateways:
* In home or small business networks, the router will be the default gateway
* Where there is a dial-up connection, a router at the ISP will be the default gateway

Gateways also come in two types based on hardware:
* Router gateways
* Gateway computers, which use two network adapters: one for the local network, and one for the external network

Large organisations also use gateways for their internal subnets.

## Router Advertisement

From https://superuser.com/questions/210809/what-is-the-rationale-behind-router-advertisement
http://tcpipguide.com/free/t_ICMPv6RouterAdvertisementandRouterSolicitationMess.htm

IPv6 (/ICMPv6) router advertisements notify hosts on a network that the router sending the advertisement is their gateway to the internet. Routers send out advertisements on a regular schedule and in response to *Router Solicitation* messages from hosts. In IPv4, the equivalent technique is called *router discovery*. RFC 1256 describes router discovery.

The above process is now incorporated into the *Neighbour Discovery (ND)* protocol. The ND protocol also includes *Neighbour Solicitation* and *Neighbour Advertisements*, which allow hosts on the same network to discover one another.

Servers using the Routing Information Protocol (RIP) use router advertisement to inform other servers about the existence of their subnets. This is to allow routes to be computed between hosts on a network.

## Other Concepts

From Wikipedia.

* A *Proxy auto-config (PAC)* defines how web browsers and other user agents can automatically choose the appropriate proxy server (access method) for fetching a given URL
* The *Web Proxy Auto-Discovery (WPAD) Protocol* is a method used by clients to locate the URL of a PAC file
