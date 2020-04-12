#include "shell.h"

/**
 * _strcmp - Compare 2 strings
 * @s1: String 1
 * @s2: String 2
 * Return: 0 if the same
 * > 0 if s1 is smaller than s2
 * < 0 if s1 is bigger than s1
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;

	return (s1[i] - s2[i]);
}

/**
 * _putchar - print a character
 * @c: The character to print
 * Return: on success 1, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Get the length of a string
 * @str: String
 * Return: Length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		++i;

	return (i);
}

/**
 * _strcat - Concatenates 2 strings
 * @dest: Destination (to)
 * @src: Source (from)
 * Return: Pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int desLen = 0;

	if (src && dest)
	{
		while (dest[desLen])
			++desLen;

		for (i = 0; src[i]; i++)
		{
			dest[desLen + i] = src[i];
		}
		dest[desLen + i] = '\0';
	}

	return (dest);
}

/**
 * _strcpy - String copy
 * @dest: Buffer
 * @src: Source
 * Return: Pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';

	return (dest);
}
