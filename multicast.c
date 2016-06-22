#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "nilstruct.h"


int	nil_create_multicast_recv(nil_t	*mul)
{
	int					reuse_addr = 1;
	char				msg[128];
	struct ip_mreq		mreq;
	struct sockaddr_in	srv;

	
	if ((mul->fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket");
		return -1;
	}

	if(setsockopt(mul->fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) < 0)
    {  
        sprintf(msg, "[%s] reuse addr", __FUNCTION__);
		perror(msg);
		return -1;
    }

	memset(&srv, 0x00, sizeof(srv));
	srv.sin_family = AF_INET;
	srv.sin_addr.s_addr = htonl(INADDR_ANY);
	srv.sin_port = htons(mul->src_port);
	
	
	if (bind(mul->fd, (struct sockaddr *)&srv, sizeof(srv)) < 0)
	{
		
		sprintf(msg, "[%s] bind", __FUNCTION__);
		perror(msg);
		return -1;
	}
	
	mreq.imr_multiaddr.s_addr = mul->src_ip;
	if(mul->dst_ip == 0x00)
		mreq.imr_interface.s_addr = htonl(INADDR_ANY);
	else
		mreq.imr_interface.s_addr = htonl(mul->dst_ip);
	
	if (setsockopt(mul->fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0)
	{
		sprintf(msg, "[%s] add membership", __FUNCTION__);
		perror(msg);
		return -1;
	}

	return 0;
}


