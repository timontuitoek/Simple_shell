#ifndef SHELL_H
#define SHELL_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
/*protoypes of cd_command.c*/
int cd(char *directory);
/*prototypes of get_loc.c*/
char *get_location(char *command);
/*protoypes of command_exemd.c*/
void execmd(char **argv);
int stat(const char *pathname, struct stat *statbuf);

/*prototypes of getline.c*/
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
/*prototypes of get environ.c*/
char *_getenv(const char *name);
void inter_mode(void);
/*pro comment.c*/
void handleComment(char *string);
#endif

