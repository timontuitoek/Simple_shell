#include "shell.h"

/**
 * split_line - Split a line into separate arguments
 *
 * @line: The line to be split
 *
 * Return: Array of strings containing the arguments
 */
char **split_line(char *line)
{
	char *DELIM = " \t\r\n\a";
	char *arg;
	int k = 0;
	int p;
	char **args = malloc((MAX_ARGS + 1) * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	for (arg = strtok(line, DELIM); arg != NULL && k < MAX_ARGS; arg = strtok(NULL, DELIM))
	{
		args[k] = malloc((MAX_ARG_LENGTH + 1) * sizeof(char));
		if (args[k] == NULL)
		{
			perror("malloc failed");
			for (p = 0; p < k; p++)
			{
				free(args[p]);
			}
			free(args);
			return (NULL);
		}

		_strncpy(args[k], arg, MAX_ARG_LENGTH);
		args[k][MAX_ARG_LENGTH] = '\0';
		k++;
	}
	args[k] = NULL;
	return (args);
}

/**
 * handle_semicolon - Handles the semicolon operator in a line of code.
 * @line: The input line to process.
 *
 * Return: The result of processing the semicolon.
 */
int handle_semicolon(char *line)
{
	char **commands = split_line(line);
	int k;

	for (k = 0; commands[k] != NULL; k++)
	{
		int status = execute((char **)commands[k]);

		if (status != 0)
		{
			return (status);
		}
	}

	free_args(commands);

	return (0);
}
