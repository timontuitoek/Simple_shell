#include "shell.h"


/**
 * free_array - Frees a dynamically allocated array of strings.
 * @argv: The array of strings to be freed.
 *
 * Return: 0 if successful
 */
void free_array(char **argv)
{
	char **temp = argv;

	for (; *temp != NULL; temp++)
	{
		free(*temp);
		*temp = NULL;
	}
	free(argv);
}

/**
 * s_len - counts the length of a string
 * @string: string whose length is to be countedi
 *
 * Return: the length of the string
 */
int s_len(char *string)
{
	int k;
	int num;

	num = 0;

	for (k = 0; string[k] != '\0'; k++)
		num++;

	return (num);
}


/**
 * s_copy - copy strings
 * @to: destination it is copying to
 * @from: where it is copying from
 * Return: void
 */
void s_copy(char *to, char *from)
{
	int k;

	for (k = 0; from[k] != '\0'; k++)
		to[k] = from[k];

	to[k] = '\0';
}


/**
 * s_cat - cat two strings
 * @text_add: where is it adding to
 * @text: where it is adding from
 * Return: void
 */
void s_cat(char *text_add, char *text)
{
	int k;
	int num;

	k = 0;
	num = 0;
	while (text_add[k] != '\0')
		k++;
	for (num = 0; text[num] != '\0'; num++)
		text_add[k++] = text[num];
	text_add[k] = '\0';
}
