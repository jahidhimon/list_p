#include <stdio.h>
#include <editline/readline.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	printf("List_P version 0.0.1\n");
	printf("Press Ctrl+c to Exit\n");

	while(1) {
		char* input = readline("list_p > ");

		add_history(input);

		free(input);
	}
	
	return 0;
}
