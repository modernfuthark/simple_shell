#include "shell.h"

/**
 * tokenize - Tokenize a string
 * @full: Full string
 * Return: 2d array of tokenized string
 */
char **tokenize(char *full)
{
	char **final = NULL;
	char *token;
	int i = 0;

	final = malloc(sizeof(char *) * (_strlen(full) + 1));
	if (!final)
		return (NULL);

	token = strtok(full, " \n");
	while (token)
	{
		final[i] = token;
		i++;

		token = strtok(NULL, " \n\v\r\a\t");
	}
	final[i] = NULL;
	return (final);
}

/**
 * main - Main entry point AND loop
 * @ac: Argument count
 * @av: Arguments
 * Return: status (0 on success, 1 on error)
 */
int main(int ac, char *av[])
{
	char *buffer = NULL;
	char **args = NULL;
	size_t bufsize = 1024;
	int status = 1;

	while (status)
	{
		buffer = malloc(sizeof(char *) * bufsize + 1);
		if (buffer == NULL)
			return (1);
		if (isatty(STDIN_FILENO))
		{
			_putchar('$');
			_putchar(' ');
		}
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(buffer);
			return (0);
		}
		if (_strcmp(buffer, "\n") != 0)
		{
			if (ac <= 2)
			{
				args = tokenize(buffer);
				status = biFinder(args);
				free(args);
			}
			else
				status = biFinder(av);
		}
		free(buffer);
	}
	return (0);
}
