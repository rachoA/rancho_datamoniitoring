typedef struct config {
	char id[8];
	char ip[16];
	char chainname[16];
	char savedir[1024];
	char binarydir[1024];
} config_t;

void read_conf(config_t *config);
