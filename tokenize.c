#include "shell.h"
/**
 * tokenize - split user's command strings
 * @take_input: pointer to user_input
 * @argv: array of pointer to strings
 * @fdescriptor_check: size of input read in bytes
 *
 * Return: array of pointer to strings
 */

char **tokenize(char *take_input, char **argv, ssize_t fdescriptor_check)
{
	char *input_copy, *parse_token;
	const char *delimiter;
	int token_count = 0, num = 0;
	int token_length;

	delimiter = " \n";

	input_copy = malloc(sizeof(char) * (fdescriptor_check + 2));
	if (input_copy == NULL)
	{
		perror("Error: cannot allocate memory");
		return (NULL);
	}
	s_copy(input_copy, take_input);
	parse_token = _strtok(take_input, delimiter);

	while (parse_token != NULL)
	{
		token_count++;
		free(parse_token);
		parse_token = _strtok(NULL, delimiter);
	}
	token_count++;

	argv = malloc(sizeof(char *) * token_count);
	parse_token = _strtok(input_copy, delimiter);
	for (num = 0; parse_token != NULL; num++)
	{
		token_length = s_len(parse_token);
		argv[num] = malloc(sizeof(char) * token_length + 1);
		argv[num][token_length] = '\0';
		s_copy(argv[num], parse_token);
		free(parse_token);
		parse_token = _strtok(NULL, delimiter);
	}
	/*free(parse_token);*/
	argv[num] = NULL;
	free(input_copy);
	return (argv);

}
