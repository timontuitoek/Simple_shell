#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory containing,
 * a copy of the string given as a parameter.
 * @str: string to copy to
 * @dup: string to copy
 *
 * Return: pointer to the duplicated string.
 */
char *_strdup(char *dup, char *str)
{
	int k, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (k = 0; k < len; k++)
		dup[k] = str[k];
	dup[k] = '\0';

	return (dup);
}

/**
 * _strtok - splits a string into a series of tokens
 * @str: string to tokenize
 * @delim: delimiter
 *
 * Return: pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *saveptr;
	char *token;
	int k, p, len;

	if (str == NULL)
		str = saveptr;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	token = malloc(sizeof(char) * (len + 1));
	if (token == NULL)
		return (NULL);

	for (k = 0; str[k]; k++)
	{
		for (p = 0; delim[p]; p++)
		{
			if (str[k] == delim[p])
			{
				token[k] = '\0';
				saveptr = &str[k + 1];
				return (token);
			}
		}
		token[k] = str[k];
	}
	token[k] = '\0';
	saveptr = NULL;
	return (token);
}

/**
 * _getenv - searches the environment list to find the environment variable
 * @name: name of the variable to find
 *
 * Return: pointer to the value of the environment variable
 */
char *_getenv(const char *name)
{
	int k, p, len;

	if (name == NULL)
		return (NULL);

	len = 0;
	while (name[len])
		len++;

	for (k = 0; environ[k]; k++)
	{
		for (p = 0; p < len; p++)
		{
			if (environ[k][p] != name[p])
				break;
		}
		if (p == len && environ[k][p] == '=')
			return (&environ[k][p + 1]);
	}

	return (NULL);
}
