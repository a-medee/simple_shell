#ifndef _MAIN_H_
#define _MAIN_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

#define _GNU_SOURCE_

extern char **environ;

/**
 * struct envlist - linked list for the env envrionment variable
 * @name: name of the environment variable
 * @next: pointer to next node
 */
struct envlist
{
	char *name;
	struct envlist *next;
};

typedef struct envlist envlist_t;
/**
 * struct program - gather all of the useful informations
 * to have about the running program
 * @path: array of $PATH locations
 * @binary: string of path with correct prepended $PATH
 * @pgr_name:  name of the first argument to our proram
 * @e_stat: an int variable that hold value issued by the program
 * in error case
 */
struct program
{
	int e_stat;
	char *path;
	char *binary;
	char *pgr_name;
};

/**
 * struct user - gather all of the related user variables
 * @env: linked list of local env variables
 * @argv: array of env variables to put into execve
 * @args: array of argument strings
 * @user_input: user input
 */
struct user
{
	envlist_t *env;
	char **argv;
	char **args;
	char *user_input;
};

typedef struct user user_t;
typedef struct program program_t;

envlist_t *addNode(envlist_t **, char *);
envlist_t *add_node_end(envlist_t **, char *);
size_t print_listint(const envlist_t *);
int find_element(envlist_t *, char *str);
size_t list_len(const envlist_t *);
int delete_index_node(envlist_t **, unsigned int);
void free_all(user_t *, program_t *);
void free_args(char **);
void free_list(envlist_t *);
int _isalpha(int c);
int args_number(char **);
int _atoi(char *s);

int _strlen(char *s);
char *_strcat(char *, const char *);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *, char *);
char *_strtok(char *, char *);

char *_strchr(char *s, char c);
void super_simple_shell(user_t *, program_t *);
void handling_argument(user_t *, program_t *);
int find_binary(user_t *, program_t *);
int handle_path(user_t *, program_t *);
int tokenize_(user_t *, program_t *);
int number_of_words(char *s);

void children_job_equal_zero(user_t *, program_t *);
void handle_comment_from_input(char *str);
void construct_envp(user_t *, program_t *);
char *_getenv(char *input, char **environ);

/**
 * struct builtins - a structure to execute builtins functions
 * @command: builtins to checked for
 * @func: the associated builtins functions
 */

typedef struct builtins
{
	char *command;
	int (*func)(user_t *input, program_t *variables);
} builtins_t;

int handle_builtins_command(user_t *, program_t *);
int exit_builtins(user_t *, program_t *);
int alias_builtins(user_t *, program_t);
envlist_t *start_env_list(char **);
char *get_nodeint_at_index(envlist_t *, unsigned int);
void _error_function(char *pgr_name, char *bin_name);
void free_some_struct_(user_t *, program_t *);
int env_builtins(user_t *, program_t *);
int cd_builtins(user_t *, program_t *);
int previous_dir(user_t *);
int change_(user_t *);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
