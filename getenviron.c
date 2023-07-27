#include "shell.h"

/**
 * builtin_exit - Exit the shell
 *
 * Return: 0 to exit the shell
 */
int builtin_exit(void)
{
	return (0);
}

/**
 * builtin_env - Print the environ variables
 *
 * @env: Environ variables
 *
 * Return: Always returns 1
 */
int builtin_env(char **env)
{
	int k;

	for (k = 0; env[k]; k++)
	{
	write(STDOUT_FILENO, env[k], _strlen(env[k]));
	write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}

