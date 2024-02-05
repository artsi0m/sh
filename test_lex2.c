/*% cc % -Wall -Wextra -g -o #
 */
#include <stdio.h>
#include <stdbool.h>

bool quoted;

void toggle_bool(bool var){
	var = (var == true) ?  false : true;
}


void
lex_handle_apostrophe(int nc){
	if (nc == '\'' && quoted == true){
		putchar('\'');
	}
	else {
		toggle_bool(quoted);
	}

}

void
lex_handle_blank(int nc){
	if (nc != '\t' && nc != ' ' && quoted != true)
		putchar('\n');
}
		

void
lex(char string[]){
	int c;
	int nc;

	extern bool quoted;
	quoted = false;
	for (c=string[0], nc=string[1]; /* Todo: handle empty */
	     nc != '\0'; c++, nc++){
		
		switch(c){
		case '\'':
			lex_handle_apostrophe(nc);
			break;
		case ' ':
			lex_handle_blank(nc);
			break;
		case '\t':
			lex_handle_blank(nc);
			break;
		default:
			putchar(c);
			break;
		}
	}
	
}


int
main(void){
	char test_string1[]="date";
	char test_string2[]="cat /lib/news/build";
	char test_string3[]="who >user.names";
	char test_string4[]="who >>user.name";
	char test_string5[]="wc <file";
	char test_string6[]="who | wc";
	char test_string7[]="who; date";
	char test_string8[]="rm -r junk || echo rm failed!";

	lex(test_string1);
	lex(test_string2);
	lex(test_string3);
	lex(test_string4);
	lex(test_string5);
	lex(test_string6);
	lex(test_string7);
	lex(test_string8);

}
