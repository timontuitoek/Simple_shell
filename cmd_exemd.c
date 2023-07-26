#include "shell.h"
/**
 * execute_command - execute user's command
 * @get_argv: array to pointer of strings
 *
 * Return: nothing
 */
int execute_command(char **get_argv)
{
	char *first_cd, *final_cmd;
	pid_t child_process;
	int process_status = 0;

	first_cd = NULL;
	final_cmd = NULL;
	child_process = -1;
	first_cd = get_argv[0];
	final_cmd = get_path(first_cd);

	if (final_cmd == NULL)
		return (1);
	if (get_argv && access(final_cmd, X_OK) != -1)
	{
		child_process = fork();

		if (child_process == -1)
		{
			print_error(get_argv, "command not found\n");
		}
		else if (child_process == 0)
		{

			if (execve(final_cmd, get_argv, NULL) == -1)
				print_error(get_argv, "command not found\n");

		}
		else
		{
			if (waitpid(child_process, &process_status, 0) == -1)
				print_error(get_argv, "command not found\n");
		}
		if (_strcmp(final_cmd, first_cd) != 0)
			free(final_cmd);
		if (WIFEXITED(process_status))
			process_status = WEXITSTATUS(process_status);
		return (process_status);
	}
	free(final_cmd);
	return (1);
}
