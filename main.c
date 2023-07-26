#include "shell.h"

/**
 * main - shell project
 * @ac: argument count
 * @argv: array of pointer to strings
 * Return: 1 or 0
 */
int main(int ac, char **argv)
{
	char *input, **get_argv;
	ssize_t fdescriptor_check;
	int k, execution_status = 0;
	data_shell shell_data;

	shell_data._environ = environ;
	(void)ac;
	(void)argv;

	while (1)
	{
		input = NULL, fdescriptor_check = 0;
		input = prompt_read(&fdescriptor_check);
		get_argv = tokenize(input, get_argv, fdescriptor_check);
		if (get_argv[0] == NULL)
			continue;
		if (_strcmp(get_argv[0], "env") == 0)
		{	free(input);
			_env(&shell_data);
			free_array(get_argv);
			continue;	}
		if (_strcmp(get_argv[0], "exit") == 0)
		{	free(input);
			exit_shell(get_argv, execution_status);
			free_array(get_argv);
			continue;
		}
		k = handle_env_commands(get_argv);
		if (k != 0)
		{	free(input);
			free_array(get_argv);
			continue;
		}
		execution_status = execute_command(argv);
		if (execution_status == 1)
			print_error(get_argv, "not found\n");
		free(input);
		free_array(get_argv);
	}
	return (0);
}
