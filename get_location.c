#include "shell.h"

/**
 * get_location - gets the path to the command passed as argument
 * @cmd: command whose location is required
 *
 * Return: command path,then NULL if no path is found
 */
char *get_location(char *cmd)
{
	char *path, *copy_path, *path_tkn, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		copy_path = strdup(path);
		cmd_len = strlen(cmd);
		path_tkn = strtok(copy_path, ":");
		while (path_tkn != NULL)
		{
			dir_len = strlen(path_tkn);
			file_path = malloc(cmd_len + dir_len + 2);
			strcpy(file_path, path_tkn);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(copy_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_tkn = strtok(NULL, ":");
			}
		}
		free(copy_path);
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
