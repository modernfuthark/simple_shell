#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global Environment Variable */
extern char **environ;

/* Main Functions */
int execute(char *file, char **args);
int paths(char **args);

/* Bultin Functions */
int bi_exit(char **args);
int bi_cd(char **args);
int bi_env(char **args);
int biFinder(char **args);

/* String Functions */
int _strcmp(char *s1, char *s2);
int _putchar(char c);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **tokenize(char *full);

#endif
