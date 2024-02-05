/*% cc % -Wall -Wextra -g -o test_lex
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void toggle_bool(bool);
void handle_quoted(void);


void
toggle_bool(bool var){
	if (var == false){ var = true;}
	if (var == true){ var = false;}
}

void
handle_quoted(void){
	int c;
	int nc;
	while((c = getchar())!= EOF){
		nc = getchar();
		if (nc == '\''){
			putchar('\'');
			break;
		}
		else { putchar(c); }
	}
	
}


void hadnle_right_redir(void){
	int c;
	while((c = getchar()) != EOF){
		if (c=='>')
			printf(">>\n");
		else
			break;
	}
}

int
main(void){
	int c;
	int nc;
	while((c = getchar()) != EOF){
		switch(c){
		case '>':
			nc = getchar();
			if (nc  == '>'){ printf(">>\n");}
			else if (nc != EOF){ungetc(nc, stdin);}
			putchar('>');
			break;
		case '<':
			nc = getchar();
			if (nc == '<'){ printf("<<\n");}
			else if (nc != EOF){ungetc(nc, stdin);}
			putchar('<');
			break;
		case '|':
			nc = getchar();
			if (nc == '|'){ printf("\n||\n");}
			else if (nc != EOF){ungetc(nc, stdin);}
			break;
		case '\'':
			nc = getchar();
			if (nc == '\''){ printf("\n'\n");}
			else if (nc != EOF)
			{
				ungetc(nc, stdin);
				handle_quoted();
			}
			break;
		case ' ':
			putchar('\n');
			break;
		case '\t':
			putchar('\n');
			break;
			

			/* Handle simple word */
		default:
			putchar(c);
			break;
		}
	}

}

