#include "shell.h"

/**
 * prompt_read - read prompts and displays inputs
 * @fdescriptor_check: checks the number of byte read by getline
 *
 * Return: user_input
 */

char *prompt_read(ssize_t *fdescriptor_check)
{
	char *display_prompt = "$shell ";
	char *input = NULL;

	/* interactive_mode() */
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, display_prompt, 2);
	}

	input = _getline();
	if (input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	*fdescriptor_check = s_len(input);

	if (*fdescriptor_check == -1 && isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
		free(input);
		exit(EXIT_SUCCESS);
	}
	else if (*fdescriptor_check == -1)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (*fdescriptor_check == 0 && isatty(STDIN_FILENO))
	{
		free(input);
		return (prompt_read(fdescriptor_check));
	}

	/*write(STDOUT_FILENO, user_input, byte_size);*/
	input[_strcspn(input, "\n")] = '\0';
	return (input);
}
