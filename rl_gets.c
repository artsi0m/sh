#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "fns.h"

char *
rl_gets(const char *prompt)
{
        char *line_read;
        line_read = NULL;

        line_read = readline(prompt);

        if (line_read && *line_read) {
                add_history(line_read);
        }
        return line_read;
}
