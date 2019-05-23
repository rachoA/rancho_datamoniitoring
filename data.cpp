#include <iostream>
#include <stdio.h>

char *file_read(char *filename)
{
	FILE *fop = NULL;
	static char data[1024];	

	fop = fopen(filename, "r");
	if (fop == NULL) {
	}	

	fread(data, 1, 1024, fop);	

	if (fop != NULL) {
		fclose(fop);
	}

	return data;
}

void file_write(char *data)
{
	printf("[%s]\n", data);
}

/*
void print_tx(Transaction *tx)
{
	printf("recv 1 : [%s]\n", tx->fromaddr);
	printf("recv 2 : [%s]\n", tx->toaddr);
//	printf("recv 3 : [%s]\n", tx->value);
	printf("recv 4 : [%s]\n", tx->pubkey);
	printf("recv 5 : [%s]\n", tx->sign);
	printf("recv 6 : [%s]\n", tx->data);
}
*/
