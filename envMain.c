#include "shell.h"

/**
 * getPath - Get the index of the PATH variable (save Betty space)
 * Return: Index of PATH
 */
int getPath(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (environ[i][0] == 'P' && environ[i][3] == 'H')
			break;
	}

	return (i);
}

/**
 * paths - Handle the environment variable PATH and search for file
 * @args: Arguments
 * Return: 0 on error, 1 on success
 */
int paths(char **args)
{
	int finder = 0, found = 0;
	char *newCommand = NULL, *paths = NULL, *temp = NULL, *token = NULL;

	newCommand = malloc(_strlen(args[0]) + 2);
	if (!newCommand)
		return (0);

	newCommand[0] = '/';
	newCommand[1] = '\0';
	_strcat(newCommand, args[0]);

	finder = getPath();
	paths = malloc(sizeof(char) * (_strlen(environ[finder]) + 1));
	if (!paths)
		return (0);
	_strcpy(paths, environ[finder]);
	token = strtok(paths, ":");
	while (token)
	{
		temp = malloc(sizeof(char *) * (_strlen(token) + _strlen(newCommand) + 1));
		if (!temp)
			return (0);
		_strcpy(temp, token);
		_strcat(temp, newCommand);
		if (access(temp, F_OK | X_OK) != -1)
		{
			found = 1;
			break;
		}
		free(temp);
		token = strtok(NULL, ":");
	}
	free(newCommand);
	free(paths);
	if (found == 1)
		execute(temp, args);
	else
		perror("hsh");
	free(temp);
	return (1);
}
