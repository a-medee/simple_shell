#include "main.h"
#include <unistd.h>

/**
 * construct_envp - do something
 * @input: input build
 * @variables:
 *
 * Return: a type void element
 */
void construct_envp(user_t *input, __attribute__((unused))program_t *variables)
{
	int i = 0;
	size_t count = 0;
	char **envp = NULL;
	envlist_t *tmp = input->env;

	count = list_len(input->env);
	envp = malloc(sizeof(char *) * (count + 1));
	if (!envp)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		envp[i] = _strdup(tmp->name);
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	input->argv = envp;
}

/**
 * _error_function - print errors
 * @pgr_name: the first agument to our program
 * @bin_name: bin which failed
 *
 * Return: a type void element
 */

void _error_function(char *pgr_name, char *bin_name)
{
	if (bin_name != NULL)
	{
		write(STDERR_FILENO, pgr_name, _strlen(pgr_name));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, bin_name, _strlen(bin_name));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}
