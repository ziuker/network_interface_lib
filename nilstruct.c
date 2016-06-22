#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "nilstruct.h"


void nil_struct_init(nil_t *nt, char *src_ipaddr, int src_port, char *dst_ipaddr, int dst_port, char *dev_name, int ttl, int loop, int rcvbuf_size, int sndbuf_size)
{
	memset(nt, 0x00, sizeof(nil_t));

	if(src_ipaddr != NULL)
		nt->src_ip = inet_addr(src_ipaddr);
	if(src_port > 0)
		nt->src_port = src_port;
	else
		nt->src_port = 0;
	
	if(dst_ipaddr != NULL)
		nt->dst_ip = inet_addr(dst_ipaddr);
	if(dst_port > 0)
		nt->dst_port = dst_port;
	else
		nt->dst_port = 0;

	if(dev_name != NULL)
		memcpy(nt->dev_name, dev_name, strlen(dev_name));

	if(ttl > 0)
		nt->ttl = ttl;
	else
		nt->ttl = 0;

	if(loop > 0)
		nt->loop = loop;
	else
		nt->loop = 0;

	if(rcvbuf_size > 0)
		nt->rcvbuf_size = rcvbuf_size;
	else
		nt->rcvbuf_size = 0;

	if(sndbuf_size > 0)
		nt->sndbuf_size = sndbuf_size;
	else
		nt->sndbuf_size = 0;
}

