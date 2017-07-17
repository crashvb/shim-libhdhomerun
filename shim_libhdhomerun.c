#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <libhdhomerun/hdhomerun.h>

uint32_t hdhomerun_control_get_local_addr(struct hdhomerun_control_sock_t *cs)
{
	const char * shim_libhdhomerun_addr = getenv("SHIM_LIBHDHOMERUN_ADDR");
	if(shim_libhdhomerun_addr == NULL)
	{
		fprintf(stderr, "SHIM_LIBHDHOMERUN_ADDR must be defined!\n");
		exit(1);
	}

	return htonl(inet_addr(shim_libhdhomerun_addr));
}
