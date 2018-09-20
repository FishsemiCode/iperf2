/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

#include <nuttx/config.h>
#include <nuttx/net/udp.h>
#include <sys/select.h>

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define if debugging info is desired */
/* #undef DBG_MJZ */

#ifdef CONFIG_NET_PKT
/* AF_PACKET support is available */
#define HAVE_AF_PACKET 1
#endif

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

#ifdef CONFIG_SCHED_ATEXIT
/* Define to 1 if you have the `atexit' function. */
#define HAVE_ATEXIT 1
#endif

/* Define to 1 if you have the `clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

#ifndef CONFIG_DISABLE_SIGNALS
/* Define to 1 if you have the `clock_nanosleep' function. */
#define HAVE_CLOCK_NANOSLEEP 1
#endif

#ifdef CONFIG_NET_IPv6
/* Define to 1 if you have the declaration of `AF_INET6', and to 0 if you
   don't. */
#define HAVE_DECL_AF_INET6 1
#endif

#ifdef CONFIG_SMP
/* Define to 1 if you have the declaration of `CPU_SET', and to 0 if you
   don't. */
#define HAVE_DECL_CPU_SET 1
#endif

/* Define to 1 if you have the declaration of `ENOBUFS', and to 0 if you
   don't. */
#define HAVE_DECL_ENOBUFS 1

/* Define to 1 if you have the declaration of `EWOULDBLOCK', and to 0 if you
   don't. */
#define HAVE_DECL_EWOULDBLOCK 1

/* Define to 1 if you have the declaration of `IPV6_ADD_MEMBERSHIP', and to 0
   if you don't. */
/* #undef HAVE_DECL_IPV6_ADD_MEMBERSHIP */

/* Define to 1 if you have the declaration of `IPV6_MULTICAST_HOPS', and to 0
   if you don't. */
/* #undef HAVE_DECL_IPV6_MULTICAST_HOPS */

/* Define to 1 if you have the declaration of `IPV6_TCLASS', and to 0 if you
   don't. */
/* #undef HAVE_DECL_IPV6_TCLASS */

/* Define to 1 if you have the declaration of `IP_ADD_MEMBERSHIP', and to 0 if
   you don't. */
/* #undef HAVE_DECL_IP_ADD_MEMBERSHIP */

/* Define to 1 if you have the declaration of `MCAST_JOIN_SOURCE_GROUP', and
   to 0 if you don't. */
/* #undef HAVE_DECL_MCAST_JOIN_SOURCE_GROUP */

/* Define to 1 if you have the declaration of `SIGALRM', and to 0 if you
   don't. */
#define HAVE_DECL_SIGALRM 1

#ifdef CONFIG_NET_SOCKOPTS
/* Define to 1 if you have the declaration of `SO_MAX_PACING_RATE', and to 0
   if you don't. */
/* #undef HAVE_DECL_SO_MAX_PACING_RATE */

/* Define to 1 if you have the declaration of `SO_SNDTIMEO', and to 0 if you
   don't. */
#define HAVE_DECL_SO_SNDTIMEO 1

/* Define to 1 if you have the declaration of `SO_TIMESTAMP', and to 0 if you
   don't. */
/* #undef HAVE_DECL_SO_TIMESTAMP */
#endif

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
/* #undef HAVE_DOPRNT */

/* Define if fast sampling for report intervals is desired */
/* #undef HAVE_FASTSAMPLING */

/* Define to 1 if you have the `fork' function. */
/* #undef HAVE_FORK */

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the <ifaddrs.h> header file. */
/* #undef HAVE_IFADDRS_H */

/* Define to 1 if you have the `inet_ntop' function. */
#define HAVE_INET_NTOP 1

/* Define to 1 if you have the `inet_pton' function. */
#define HAVE_INET_PTON 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

#ifdef CONFIG_NET_IPv6
/* Define to enable IPv6 support */
#define HAVE_IPV6 1
#endif

/* Define to enable IPv6 multicast support */
/* #undef HAVE_IPV6_MULTICAST */

/* Define if isochronous traffic option is desired and available */
#define HAVE_ISOCHRONOUS 1

/* Define if Kalman tuning is desired and available */
#define HAVE_KALMAN 1

/* Define to 1 if you have the <libintl.h> header file. */
/* #undef HAVE_LIBINTL_H */

/* Define to 1 if you have the `rt' library (-lrt). */
/* #undef HAVE_LIBRT */

/* Define if libws2_32 exists. */
/* #undef HAVE_LIBWS2_32 */

/* Define to 1 if you have the <linux/filter.h> header file. */
/* #undef HAVE_LINUX_FILTER_H */

/* Define to 1 if you have the <linux/if_packet.h> header file. */
/* #undef HAVE_LINUX_IF_PACKET_H */

/* Define to 1 if you have the <linux/ip.h> header file. */
/* #undef HAVE_LINUX_IP_H */

/* Define to 1 if you have the <linux/udp.h> header file. */
/* #undef HAVE_LINUX_UDP_H */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the `mlockall' function. */
/* #undef HAVE_MLOCKALL */

/* Define to enable multicast support */
/* #undef HAVE_MULTICAST */

#ifndef CONFIG_DISABLE_SIGNALS
/* Define to 1 if you have the `nanosleep' function. */
#define HAVE_NANOSLEEP 1
#endif

#ifdef CONFIG_LIBC_NETDB
/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1
#endif

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <net/ethernet.h> header file. */
#define HAVE_NET_ETHERNET_H 1

/* */
#define HAVE_POSIX_THREAD 1

/* */
/* #undef HAVE_PRINTF_QD */

#ifndef CONFIG_DISABLE_PTHREAD
/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Define to 1 if you have the `pthread_cancel' function. */
#define HAVE_PTHREAD_CANCEL 1
#endif

/* */
#define HAVE_QUAD_SUPPORT 1

/* Define to 1 if you have the `sched_setscheduler' function. */
#define HAVE_SCHED_SETSCHEDULER 1

#ifndef CONFIG_DISABLE_POLL
/* Define to 1 if you have the `select' function. */
#define HAVE_SELECT 1
#endif

/* Define if 64 bit sequence numbers are desired and available */
#define HAVE_SEQNO64b 1

/* Define to 1 if you have the `setitimer' function. */
/* #undef HAVE_SETITIMER */

#ifndef CONFIG_DISABLE_SIGNALS
/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1
#endif

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define to 1 if the system has the type `ssize_t'. */
#define HAVE_SSIZE_T 1

/* Define to enable ssm multicast support */
/* #undef HAVE_SSM_MULTICAST */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if the system has the type `struct group_source_req'. */
/* #undef HAVE_STRUCT_GROUP_SOURCE_REQ */

/* Define to 1 if the system has the type `struct ipv6_mreq'. */
/* #undef HAVE_STRUCT_IPV6_MREQ */

/* Define to 1 if the system has the type `struct ip_mreq'. */
/* #undef HAVE_STRUCT_IP_MREQ */

#ifdef CONFIG_NET_IPv6
/* Define to 1 if the system has the type `struct sockaddr_in6'. */
#define HAVE_STRUCT_SOCKADDR_IN6 1
#endif

/* Define to 1 if `sin6_len' is a member of `struct sockaddr_in6'. */
/* #undef HAVE_STRUCT_SOCKADDR_IN6_SIN6_LEN */

/* Define to 1 if the system has the type `struct sockaddr_storage'. */
#define HAVE_STRUCT_SOCKADDR_STORAGE 1

/* Define to 1 if `tcpi_total_retrans' is a member of `struct tcp_info'. */
/* #undef HAVE_STRUCT_TCP_INFO_TCPI_TOTAL_RETRANS */

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define if udp triggers option is desired and available */
/* #undef HAVE_UDPTRIGGERS */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

#ifndef CONFIG_DISABLE_SIGNALS
/* Define to 1 if you have the `usleep' function. */
#define HAVE_USLEEP 1
#endif

#ifdef CONFIG_ARCH_HAVE_VFORK
/* Define to 1 if you have the `vfork' function. */
#define HAVE_VFORK 1
#endif

/* Define to 1 if you have the <vfork.h> header file. */
/* #undef HAVE_VFORK_H */

/* Define to 1 if you have the `vprintf' function. */
#define HAVE_VPRINTF 1

/* Define if Web100 is desired and available */
/* #undef HAVE_WEB100 */

/* Define if using WIN32 threads */
/* #undef HAVE_WIN32_THREAD */

/* Define to 1 if `fork' works. */
/* #undef HAVE_WORKING_FORK */

#ifdef CONFIG_ARCH_HAVE_VFORK
/* Define to 1 if `vfork' works. */
#define HAVE_WORKING_VFORK 1
#endif

/* Name of package */
#define PACKAGE "iperf"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "Iperf"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "Iperf 2.0.13a"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "iperf"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.0.13a"

/* Define to the necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* Define to the type of arg 1 for `select'. */
#define SELECT_TYPE_ARG1 int

/* Define to the type of args 2, 3 and 4 for `select'. */
#define SELECT_TYPE_ARG234 (fd_set *)

/* Define to the type of arg 5 for `select'. */
#define SELECT_TYPE_ARG5 (struct timeval *)

/* The size of `bool', as computed by sizeof. */
#define SIZEOF_BOOL 0

/* The size of `char', as computed by sizeof. */
/* #undef SIZEOF_CHAR */

/* The size of `int', as computed by sizeof. */
/* #undef SIZEOF_INT */

/* The size of `long', as computed by sizeof. */
/* #undef SIZEOF_LONG */

/* The size of `short', as computed by sizeof. */
/* #undef SIZEOF_SHORT */

/* The size of `void*', as computed by sizeof. */
/* #undef SIZEOF_VOIDP */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define 3rd arg of accept */
#define Socklen_t socklen_t

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* Version number of package */
#define VERSION "2.0.13a"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* */
#define _REENTRANT 1

/* */
/* #undef bool */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* */
/* #undef false */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef pid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to "int" if <sys/types.h> does not define. */
/* #undef ssize_t */

/* */
/* #undef true */

/* Define as `fork' if `vfork' does not work. */
/* #undef vfork */

/* Define udp hdr struct */
#define udphdr udp_hdr_s

/* Define udp check */
#define check udpchksum
