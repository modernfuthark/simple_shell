#include "shell.h"

/**
 * execute - Fork and execute a file
 * @file: File path
 * @args: Arguments
 * Return: 1 on success
 */
int execute(char *file, char **args)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("hsh");
		return (1);
	}
	if (child == 0)
	{
		if (execve(file, args, environ) == -1)
			perror("hsh");
	}
	else
	{
		wait(&status);
	}
	return (1);
}
