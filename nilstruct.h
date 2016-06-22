#ifndef	__NILSTRUCT_H__
#define	__NILSTRUCT_H__



#ifndef	__UINT_8_16_32__
#define	__UINT_8_16_32__

#define	uint8	unsigned char
#define	uint16	unsigned short
#define	uint32	unsigned int

#endif



typedef struct NIL_T {
	int				fd;

	uint32			src_ip;
	int				src_port;
	
	uint32			dst_ip;
	int				dst_port;

	char			dev_name[16];

	int				ttl;
	int				loop;

	int				rcvbuf_size;
	int				sndbuf_size;
}nil_t;



void nil_struct_init(nil_t *nt, char *src_ipaddr, int src_port, char *dst_ipaddr, int dst_port, char *dev_name, int ttl, int loop, int rcvbuf_size, int sndbuf_size);

#endif