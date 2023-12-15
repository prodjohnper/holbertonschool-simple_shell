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
void free_arrays(char **tokens);
void getpath(char **args, char **environ);

#endif /* MAIN_H */
