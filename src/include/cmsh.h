#define IN_SIZE 1024
#define TOK_SIZE 64
#define DELIM " \t\r\a"

#include "builtin.h"

char *readl(){
	int size = IN_SIZE, pos = 0;
	char *buf = malloc(sizeof(char) * size);
	char c;

	while ((c = getchar()) != '\n'){
		buf[pos] = c;
		pos++;

		if (pos >= size){
			size += IN_SIZE;
			buf = realloc(buf, sizeof(char) * size);
		}
	}
	return buf;
}

char **split(char *in){
	int size = TOK_SIZE, pos = 0;
	char **toks = malloc(sizeof(char *) * size);
	char *tok;

	tok = strtok(in, DELIM);
	while (tok != NULL){
		toks[pos] = tok;
		pos++;

		if (pos >= size){
			size += TOK_SIZE;
			toks = realloc(toks, sizeof(char *) * size);
		}

		tok = strtok(NULL, DELIM);
	}
	toks[pos] = NULL;
	return toks;
}

int start(char **splt){
	pid_t pid, wpid;

	pid = fork();
	if (pid == 0){
		if (execvp(splt[0], splt) == -1){
			perror("[cmsh:error]\n");
		}
	}else{
		wait(NULL);
	}

	return 1;
}

int execs(char **splt){
	for (int i = 0; i < sizeof(builtin_lbls) / sizeof(char *); i++){
		if (strcmp(splt[0], builtin_lbls[i]) == 0){
			return (*func[i])(splt);
		}
	}

	return start(splt);
}