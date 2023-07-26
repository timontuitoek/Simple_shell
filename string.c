#include "shell.h"

/**
 * _atoi - changes a string to an integer
 * @s: string to changed
 *
 * Return: the converted int
 */
int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
		{
			return (-1);
		}
		else if ((*s < '0' || *s > '9') && *s != '\0')
		{
			return (-1);
		}
		else if (*s >= '0'  && *s <= '9')
		{
			n = (n * 10) + (*s - '0');
		}
		else if (n > 0)
		{
			break;
		}
	} while (*s++);

	return (n);
}

/**
 * _strchr - locates a char in a string
 * @s: string to be searched
 * @c: char to be checked
 *
 * Return: pointer to the first occurrence of `c` in `s`
 */
char *_strchr(char *s, char c)
{
	int k = 0;

	for (; s[k] != c && s[k] != '\0'; k++)
		;

	if (s[k] == c)
	{
		return (s + k);
	}
	else
	{
		return (NULL);
	}
}

/**
 * _strcspn - computes segment of str
 * @s: string to be searched
 * @charset: string to be used
 *
 * Return: index at which a char in `s` exists in `charset`
 */
int _strcspn(char *s, char *charset)
{
	int count = 0, k;

	for (k = 0; s[k] != '\0'; k++)
	{
		if (_strchr(charset, s[k]) != NULL)
		{
			break;
		}
		count++;
	}

	return (count);
}


/**
 * _strcmp - compares two strings
 * @s: first string to compare
 * @c: second string to compare
 *
 * Return: return 1 when strings match
 */
int _strcmp(char *s, char *c)
{
	int k;

	for (k = 0; s[k] != '\0' && c[k] != '\0'; k++)
	{
		if (s[k] != c[k])
		{
			return (s[k] - c[k]);
		}
	}

	return (s[k] - c[k]);
}
