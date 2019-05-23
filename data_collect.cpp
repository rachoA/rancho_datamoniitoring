#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "conf.h"
#include "util.h"

void data_collect(config_t config, char *filename)
{
	FILE *fop = NULL;
	FILE *pop = NULL;
	char cmd[1024];
	char buff[1024];

	memset(cmd, 0x00, sizeof(cmd));
	snprintf(cmd, sizeof(cmd), "%s/hdac-cli %s getinfo",
			config.binarydir, config.chainname);

	printf("%s\n", cmd);

	pop = popen(cmd, "r");
	if (pop == NULL) {
	}
	fop = fopen(filename, "w");
	if (fop == NULL) {
	}

	while( fgets( buff, 1024, pop) ) {
		printf( "%s", buff);
		fputs( buff, fop);
	}

	if (pop != NULL) {
		pclose(pop);
	}

	if (fop != NULL) {
		fclose(fop);
	}
}

