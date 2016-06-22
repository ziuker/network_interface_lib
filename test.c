#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


#include "nilstruct.h"


extern int	nil_create_multicast_recv(nil_t	*mul);

void printbuf(unsigned char *buf, int len)
{
	int i;
	
	printf("     ");
	for(i = 0; i < 32; i++)
	{
		if(i%4 == 0 && i%32 != 0)
			printf("  ");
		printf(" %2d",i);
	}
	
	for(i = 0; i < len; i++)
	{
		if(i%32 == 0)
		{
			printf("\n");
			printf("%4d: ", i);
		}
		if(i%4 == 0 && i%32 != 0)
			printf("  ");
		printf("%02X ", buf[i]);
	}
	
	printf("\n\n");	
}


int main(void)
{
	int					ret;
	int					len_addr;
	uint8				buffer[1024];
	nil_t				nt;
	struct sockaddr_in	mul_server;

	nil_struct_init(&nt, "229.0.0.3", 8888, NULL, 0, NULL, 0, 0, 0, 0);

	nil_create_multicast_recv(&nt);

	len_addr = sizeof(mul_server);
	while(1)
	{
		ret = recvfrom(nt.fd, buffer, sizeof(buffer), 0, (struct sockaddr *) &mul_server,(socklen_t*)&len_addr);
		printf("ret = %d\n", ret);
		printbuf(buffer, ret);
	}
	
	return 0;
}

