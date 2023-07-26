#include "shell.h"
/**
 * exit_shell - this function exits the simple_shell
 * @get_argv: this is the cmd entered
 * @execution_status: this is the status of the exit function
 *
 * Return: returns nothing when the shell is exited
 */
void exit_shell(char **get_argv, int execution_status)
{
	char **cmds = NULL;
	int k = 0, arg;
	const char *error_message = "$: too many arguments\n";

	while (get_argv[k] != NULL)
		k++;
	{

		if (k == 1)
		{
			free_array(get_argv);
			free(cmds);
			exit(execution_status);
		}
		else if (k == 2)
		{
			arg = _atoi(get_argv[1]);
			if (arg < 0)
			{
				print_error(get_argv, "Illegal number: ");
				_errputs(get_argv[1]);
				_errputs("\n");
			}
			else
			{
				free_array(get_argv);
				free(cmds);
				exit(arg);
			}
		}
		else
		write(STDERR_FILENO, error_message, strlen(error_message));
	}
}
