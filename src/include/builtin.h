int exit(char **splt);

char *labels[] = {
	"exit"
}

int builtin_count(){
	return sizeof(labels) / sizeof(char *);
}

int (*func[]) (char **) = {
	&exit
}

int exit(char **splt){
	return 1;
}