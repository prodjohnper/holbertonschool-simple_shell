#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char **tokenizer(char *line_str);
void command(char *line_str);
void tok_free(char **tokens);

#endif /* MAIN_H */
