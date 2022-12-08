int exit_cmsh(char **splt);

char *labels[] = {
	"exit"
};

int builtin_count(){
	return sizeof(labels) / sizeof(char *);
}

int (*func[]) (char **) = {
	&exit_cmsh
};

int exit_cmsh(char **splt){
	return 0;
}