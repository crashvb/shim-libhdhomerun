#include <stdio.h>
#include <stdint.h>
#include <libhdhomerun/hdhomerun.h>

//extern LIBTYPE uint32_t hdhomerun_control_get_local_addr(struct hdhomerun_control_sock_t *cs);

int main(int argc, char *argv[])
{
	printf("Getting local address ...\n");
	uint32_t local_addr = hdhomerun_control_get_local_addr(NULL);

	unsigned char bytes[4];
	bytes[0] = local_addr & 0xFF;
	bytes[1] = (local_addr >> 8) & 0xFF;
	bytes[2] = (local_addr >> 16) & 0xFF;
	bytes[3] = (local_addr >> 24) & 0xFF;   
	printf("Got local address: %d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);

	return 0;
}
