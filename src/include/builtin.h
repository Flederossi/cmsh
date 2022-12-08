char *builtin_lbls[] = {
	"cd",
	"exit"
};

int cd_cmsh(char **splt){
	if (splt[1] != NULL){
		if (chdir(splt[1]) != 0){
			perror("[cmsh:error]\n");
		}
	}

	return 1;
}

int exit_cmsh(char **splt){
	return 0;
}

int (*func[]) (char **) = {
	&cd_cmsh,
	&exit_cmsh
};