#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
	 inputstring = strndup("cat file | grep line", buffer_size);
  
  /* Memory leak may appear hear */
	while ((*word = strsep(&inputstring, delimiters)) != NULL) {
		puts(*word);
	}
  
  free(inputstring);
}
