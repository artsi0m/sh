#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *delimiters = " \t";

int
main(int argc, char *argv[])
{

	char *inputstring;
	extern char *delimiters;
	char *word[BUFFER_SIZE];

	*word = NULL;

   inputstring = *argv; 
	 inputstring = strndup("cat file | grep line", BUFFER_SIZE);
   
  
	while ((*word = strsep(&inputstring, delimiters)) != NULL) {
		puts(*word);
	}
  
}
