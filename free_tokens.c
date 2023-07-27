#include "shell.h"

/**
 * free_tokens - frees the memory allocated for the tokens array
 * @tokens: array of pointers to the tokens
 */
void free_tokens(char **tokens)
{
	int k = 0;

	while (tokens[k] != NULL)
	{
		free(tokens[k]);
		k++;
	}
	free(tokens[k]);
}

