#include <stdio.h>

static char input[2048];

int main(int argc, char** argv) {
	printf("List_P version 0.0.1\n");
	printf("Press Ctrl+c to Exit\n");

	while(1) {
		fputs("list_p > ", stdout);
		scanf("%[^\n]s", input);
		fprintf(stdout, "No you're a %s", input);
	}
	
	return 0;
}
