#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

#include "cmsh.h"

#define VER "0.0.1"

int main(){
	printf("cmsh %s - Welcome %s!\n", VER, getenv("USER"));

	char *in;
	char dir[1024];
	time_t temp;
	struct tm *currtime;
	int h, m, s;

	int stat = 1;
	while (stat){
		// TODO: Add config file
		getcwd(dir, sizeof(dir));
		
		temp = time(NULL);
		currtime = localtime(&temp);
		h = currtime->tm_hour;
		m = currtime->tm_min;
		s = currtime->tm_sec;
		
		printf("╔╡ cmsh %s ╞╡ %s ╞╡ %d:%d:%d ╞═╡ %s │\n╚» ", VER, getenv("USER"), h, m, s, dir);
		in = readl();
		stat = execs(split(in));
		printf("\n");

		free(in);
	}

	return 0;	
}