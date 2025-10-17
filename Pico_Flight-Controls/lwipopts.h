#ifndef _LWIPOPTS_H
#define _LWIPOPTS_H

// Run lwIP without an RTOS
#define NO_SYS 1

// Enable DHCP, UDP, and TCP support
#define LWIP_DHCP 1
#define LWIP_UDP 1
#define LWIP_TCP 1

// Disable anything that depends on POSIX or errno.h
#define LWIP_SOCKET 0
#define LWIP_NETCONN 0
#define LWIP_STATS       0
#define LWIP_DEBUG       0
#define LWIP_ERRNO_STDINCLUDE 1

// Use newlib's struct timeval to avoid redefinition
#define LWIP_TIMEVAL_PRIVATE 0

// Reduce memory usage for small MCUs
#define MEM_SIZE 1600
#define MEMP_NUM_PBUF 8
#define MEMP_NUM_UDP_PCB 4
#define MEMP_NUM_TCP_PCB 2
#define MEMP_NUM_TCP_SEG 8
#define MEMP_NUM_SYS_TIMEOUT 10

// Enable checksum generation/checking
#define CHECKSUM_GEN_IP 1
#define CHECKSUM_GEN_UDP 1
#define CHECKSUM_GEN_TCP 1
#define CHECKSUM_CHECK_IP 1
#define CHECKSUM_CHECK_UDP 1
#define CHECKSUM_CHECK_TCP 1

#endif /* _LWIPOPTS_H */