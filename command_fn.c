#include "shell.h"

/**
 * cd - Change the current working directory.
 * @directory: The directory to change to.
 *
 * Return: On success, returns 0. On failure, returns 1.
 */
int cd(char *directory)
{
	char *cwd = getcwd(NULL, 0);
	char *new_cwd;

	if (directory == NULL)
	{
		directory = getenv("HOME");
		if (directory == NULL)
		{
			perror("cd: Unable to determine home directory");
			free(cwd);
			return (1);
		}
	}

	if (chdir(directory) != 0)
	{
		perror("cd: Cannot change directory");
		free(cwd);
		return (1);
	}
	new_cwd = getcwd(NULL, 0);

	if (new_cwd == NULL)
	{
		perror("cd: Cannot get current working directory");
		free(cwd);
		return (1);
	}

	if (setenv("PWD", new_cwd, 1) != 0)
	{
		perror("cd: Failed to set PWD environment variable");
		free(cwd);
		free(new_cwd);
		return (1);
	}

	free(cwd);
	free(new_cwd);
	return (0);
}

