#ifndef _LWIPOPTS_H
#define _LWIPOPTS_H

// Run lwIP without an RTOS and keep API usage poll-based.
#define NO_SYS 1
#define SYS_LIGHTWEIGHT_PROT 0

// The Pico W only supports IPv4 when operating as a soft AP. Disable IPv6 to
// conserve RAM and ensure that lwIP configures the DHCP server correctly for
// IPv4-only operation.
#define LWIP_IPV4 1
#define LWIP_IPV6 0

// Enable DHCP (for the onboard server), UDP transport for control packets, and
// TCP for debugging or telemetry endpoints that may be added later.
#define LWIP_DHCP 1
#define DHCP_DOES_ARP_CHECK 0
#define LWIP_UDP 1
#define LWIP_TCP 1

// Expose basic link status callbacks so the CYW43 driver can notify lwIP about
// association and disassociation events while acting as an access point.
#define LWIP_NETIF_STATUS_CALLBACK 1
#define LWIP_NETIF_LINK_CALLBACK 1
#define LWIP_NETIF_EXT_STATUS_CALLBACK 1
#define LWIP_NETIF_HOSTNAME 1

// Disable anything that depends on POSIX or errno.h
#define LWIP_SOCKET 0
#define LWIP_NETCONN 0
#define LWIP_STATS       0
#define LWIP_DEBUG       0
#define LWIP_ERRNO_STDINCLUDE 1

// Use newlib's struct timeval to avoid redefinition
#define LWIP_TIMEVAL_PRIVATE 0

// Allocate enough memory for DHCP server traffic and multiple UDP packets.
#define MEM_ALIGNMENT 4
#define MEM_SIZE 4096
#define MEMP_NUM_PBUF 16
#define MEMP_NUM_UDP_PCB 8
#define MEMP_NUM_TCP_PCB 4
#define MEMP_NUM_TCP_SEG 16
#define MEMP_NUM_SYS_TIMEOUT 16

// Ensure pbufs can hold full Ethernet frames (required by Android clients).
#define PBUF_POOL_SIZE 16
#define PBUF_POOL_BUFSIZE 1536

// Enable checksum generation/checking
#define CHECKSUM_GEN_IP 1
#define CHECKSUM_GEN_UDP 1
#define CHECKSUM_GEN_TCP 1
#define CHECKSUM_CHECK_IP 1
#define CHECKSUM_CHECK_UDP 1
#define CHECKSUM_CHECK_TCP 1

#endif /* _LWIPOPTS_H */
