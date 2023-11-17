#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

extern char **environ;


#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 1024

void builtsin(char **cmd_args, char *getline_val);

char *my_getline(void);
char *my_strtok(char *s, const char *delim);
char *_getenv(char *env_name);
char *nint_getline(void);



int printfd(FILE *stream, const char *format, ...);
int _printfh(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);

void pr_int(int value);
int err_print(char c);
void pr_int(int value);




#endif
