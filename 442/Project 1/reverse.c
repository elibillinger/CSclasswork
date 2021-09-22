#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *input = fopen(argv[1],"r");
	if(input == NULL){
		fprintf(stderr,"error: cannot open file '%s' ",argv[1]);
	}
	size_t size = 120; //need to change later
	char *line = malloc(sizeof(char)*size);
	
	while(getline(&line, &size, input) != -1){
		printf("%s",line);
	}
	fclose(input);
	free(line);
	return 0;
}
