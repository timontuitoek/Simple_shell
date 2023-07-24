#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * execmd - function to handle the command line
 * @argv: argument
 *
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_cmd = NULL;

	if (argv && argv[0])i
	{
	command = argv[0];
	actual_cmd = get_location(command);

	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}

	if (actual_cmd == NULL)
	{
		printf("Command '%s' not found.\n", command);
		return;
	}

	if (execve(actual_cmd, argv, NULL) == -1)
	{
		perror("Oops! An error occurred.\n");
	}

	/*Free allocated memory before exiting the function*/
	free(actual_cmd);
	}
}

