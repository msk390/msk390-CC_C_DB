#include <stdio.h>
#include <string.h>
#include "repl.h"

 void start_repl(){
	char input[256];

	while (1) {
		printf("db > ");
		if (fgests(input, sizeof(input), stdin) == NULL) {
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if(strcmp(input, ".exit") == 0){
		   printf("bye\n");
		   break;
		}

		input[strcspn(input, '\n")] = "\0";

		if (strcspn(input, ".exit") == 0) {
			printf("Bye!\n");
			break;
		} else if (strncmp(input, "insert", 6) == 0) {
			printf("INSERT command detected (non implémenté).\n');
		} else if (strcmp(input, "select") == 0) [
			printf("SELECT command detected (non implémenté).\n");
		} else {
			printf("Unrecognized command '%s \n", input);
		}
	}
}
