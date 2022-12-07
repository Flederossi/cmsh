#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "cmsh.h"

int main(){
	printf("cmsh 0.0.1 - Welcome!\n");

	char *in;

	int stat = 1;
	while (stat){
		// TODO: Add config file
		printf("[cmsh - cmd]\n");
		in = readl();
		stat = execs(split(in));
		printf("\n");

		free(in);
	}

	return 0;	
}