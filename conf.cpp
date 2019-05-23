#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conf.h"

void config_check(config_t *config, char *key, char *value)
{
	if (strcmp(key, "ID") == 0) {
		memset(config->id, 0x00, sizeof(config->id));
		snprintf(config->id, sizeof(config->id), "%s", value);
	} else if (strcmp(key, "ip") == 0) {
		memset(config->ip, 0x00, sizeof(config->ip));
		snprintf(config->ip, sizeof(config->ip), "%s", value);
	} else if (strcmp(key, "savedirectory") == 0) {
		memset(config->savedir, 0x00, sizeof(config->savedir));
		snprintf(config->savedir, sizeof(config->savedir), "%s", value);
	} else if (strcmp(key, "chainname") == 0) {
		memset(config->chainname, 0x00, sizeof(config->chainname));
		snprintf(config->chainname, sizeof(config->chainname), "%s", value);
	} else if (strcmp(key, "binarydirectory") == 0) {
		memset(config->binarydir, 0x00, sizeof(config->binarydir));
		snprintf(config->binarydir, sizeof(config->binarydir), "%s", value);
	} else {
		printf("not found key[%s], value[%s]\n", key, value);
	}
}

void read_conf(config_t *config)
{
	FILE *fp_sour;
	char buf[1024];
	char *front;
	char *back;
	int flen = 0;
	int blen = 0;
	int buf_len = 0;
	char *key;
	char *value;

	fp_sour = fopen( "./data_collect.conf", "r");
	if (fp_sour == NULL) {
		return;
	}

	while(fgets( buf, 1024, fp_sour) != NULL) {

		front = strchr(buf, '=');
		if (front == NULL) {
			continue;
		}

		back = strchr(front, '\n');
		if (back == NULL) {
			continue;
		}

		flen = strlen(front);
		blen = strlen(back);
		buf_len = strlen(buf);

		key = (char*)malloc(sizeof(char)*(buf_len - flen));
		if (key == NULL) {
			continue;
		}
		memset(key, 0x00, sizeof(char)*(buf_len - flen));
		snprintf(key, sizeof(char)*(buf_len - flen) + 1, "%s", buf);

		value = (char*)malloc(sizeof(char)*(flen - blen));
		if (value == NULL) {
			continue;
		}
		memset(value, 0x00, sizeof(char)*(flen - blen));
		snprintf(value, sizeof(char)*(flen - blen), "%s", front + 1);

		printf("[%s]-[%s]\n", key, value);

		config_check(config, key, value);
	}

	fclose(fp_sour);
}
