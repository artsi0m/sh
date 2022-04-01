#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

size_t buffer_size = 1024;
char *delimiters = " \t";

int
main(int argc, char *argv[])
{

	extern size_t buffer_size;
	extern char *delimiters;
	char *inputstring;
	char *word[buffer_size];

	*word = NULL;

	while ((inputstring = readline("sh34: ")) != NULL) {
 		 /* Memory leak may appear hear */
		while ((*word = strsep(&inputstring, delimiters)) != NULL) {
			puts(*word);
		}
		*word = NULL;
		free(inputstring);
	}
}
