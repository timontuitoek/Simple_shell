#include "shell.h"

/**
 * _errputs - Print a string to the standard error
 * @str: string to be printed
 *
 * Return: number of characters printed
 */
int _errputs(char *str)
{
	int k;

	if (!(str))
	{
		return (0);
	}
	for (k = 0; str[k]; k++)
	{
		write(2, &str[k], 1);
	}

	return (k);
}
/**
 * print_error - Print error message to the standard error
 * @av: The array of command and arguments
 * @err: The error message to be printed
 */
void print_error(char **av, char *err)
{
	_errputs(_getenv("_"));
	_errputs(": 1: ");
	_errputs(av[0]);
	_errputs(": ");
	_errputs(err);
}

