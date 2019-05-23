#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "conf.h"

char *make_yymmdd(void)
{
	return "201905051457.json";
}

int make_rand_num()
{
        int i;

        srand(time(NULL));

        i = rand() % 10000;

        return i;
}

char *make_filename_yymmdd(config_t config)
{
	static char filename[1024];
	char *yymmdd = NULL;

	yymmdd = make_yymmdd();
	
	memset(filename, 0x00, sizeof(filename));
	snprintf(filename, sizeof(filename), "%s/%s", config.savedir, yymmdd);

	return filename;
}
