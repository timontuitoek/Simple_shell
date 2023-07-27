#include "shell.h"

/**
 * parse_command - parse the command string into tokens
 * @command: command string to parse
 *
 * Return: array of pointers to the tokens
 */
char **parse_command(char *command)
{
	char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
	char *tokenize;
	int k = 0;

	if (!tokens)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}

	tokenize = strtok(command, DELIMITER);

	while (tokenize != NULL)
	{
		tokens[k] = tokenize;
		k++;
		tokenize = strtok(NULL, DELIMITER);
	}

	tokens[k] = NULL;
	return (tokens);
}

