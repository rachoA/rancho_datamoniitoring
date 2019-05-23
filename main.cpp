#include <stdio.h>
#include <string.h>

#include "conf.h"
#include "data_collect.h"
#include "data.h"
#include "network.h"
#include "util.h"

void send_mode(void)
{
	config_t config;
	char *filename;
	char *data;

	read_conf(&config);

	filename = make_filename_yymmdd(config);	

	data_collect(config, filename);

	data = file_read(filename);

	send(config, data);
}

void recv_mode(void)
{
	config_t config;
	
	read_conf(&config);

	recv(config);
}

void help_print(char *program) 
{
	printf("Usage : %s [recv,send]\n", program);
	printf("recv mode - %s recv\n", program);
	printf("send mode - %s send\n", program);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		help_print(argv[0]);
		return 0;
	}

	if (strcmp(argv[1], "send") == 0) {
		send_mode();
	} else if (strcmp(argv[1], "recv") == 0){
		recv_mode();
	} else {
		help_print(argv[0]);
	}

	return 0;
}
