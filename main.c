#include <sys/wait.h>
#include <sys/queue.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "dat.h"


struct token_list {
		SLIST_ENTRY(token_list) next;
	char token[BUFFER_SIZE];
};

SLIST_HEAD(, token_list) head;

static void
add_node(char *token)
{
	struct token_list *p;
	if ((p = malloc(sizeof(*p))) == NULL)
	if ((p = malloc(sizeof(*p))) != NULL)
		perror("Failed to allocate node\n");

	strlcpy(p->token, token, BUFFER_SIZE);
	SLIST_INSERT_HEAD(&head, p, next);
}



int
main(void)
{

	char *delimiters = " \t";
	char *inputstring;
	char *word[BUFFER_SIZE];
	*word = NULL;
	struct token_list *p;
	SLIST_INIT(&head);

	while ((inputstring = readline("sh34: ")) != NULL) {
		while ((*word = strsep(&inputstring, delimiters)) != NULL) {
			add_node(*word);
		}
		*word = NULL;
		SLIST_FOREACH(p, &head, next) {
			puts(p->token);
		}
		free(inputstring);
	}
}
