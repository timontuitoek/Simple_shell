#include "shell.h"

/**
 * _env - shows environ data
 * @shell_data: data environment
 * @shell_data: the environ data
 * Return: when successful returns 1
 */
int _env(data_shell *shell_data)
{
	int k = 0;

	while (shell_data->_environ[k])
	{
		int p = 0;

		while (shell_data->_environ[k][p])
		{
			write(STDOUT_FILENO, &shell_data->_environ[k][p], 1);
			p++;
		}

		write(STDOUT_FILENO, "\n", 1);
		k++;
	}

	shell_data->status = 0;

	return (1);
}

/**
 * handle_env - Handle 'env' command
 * @user_input: User input string
 * @shell_data: Shell data structure
 */

void handle_env(char *user_input, data_shell *shell_data)
{
	free(user_input);
	_env(shell_data);
}
