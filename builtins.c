#include "shell.h"

/**
 * bi_exit - Exit builtin command
 * @args: Unusued
 * Return: always 0, to exit the initial loop
 */
int bi_exit(char **args)
{
	(void)args;

	return (0);
}

/**
 * bi_cd - Change directories
 * @args: Arguments
 * Return: always 1, to coninue the loop
 */
int bi_cd(char **args)
{
	(void)args;

	return (1);
}

/**
 * bi_env - Print the environment
 * @args: Unused
 * Return: always 1, to continue the loop
 */
int bi_env(char **args)
{
	int i, j;

	(void)args;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);
		_putchar('\n');
	}

	return (1);
}

/**
 * biFinder - Find builtin commands
 * @args: Arguments
 * Return: status of Builtin function OR executable
 */
int biFinder(char **args)
{
	int status = 1, i;
	char *list[] = {"env", "exit", "cd"};

	int (*funcs[])(char **) = {
		&bi_env,
		&bi_exit,
		&bi_cd,
	};

	for (i = 0; i < 3; i++)
	{
		if (_strcmp(args[0], list[i]) == 0)
		{
			status = (*funcs[i])(args);
			return (status);
		}
	}

	return (paths(args));
}
