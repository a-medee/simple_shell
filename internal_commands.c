#include "main.h"

/**
 * env_builtins - prints the env builtins environment value
 * @input: a pointer to the first argument of the program
 * @variable: track useful variables from the program
 *
 * Return: an int value
 */
int env_builtins(user_t *input, __attribute__((unused))program_t *variable)
{
	print_listint(input->env);
	return (1);
}

/**
 * find_binary - check whether a string is a binary file
 * present in the envrionment variable PATH
 * @input: all things related to the user, its command for instance
 * @variable: all things related our program, that we drive almost
 *
 * Return: an int value
 */
int find_binary(user_t *input, program_t *variable)
{
	int len, in = 0;
	static char buffer[256];
	struct stat state;
	char *token, *copy, *tmp;

	if (handle_path(input, variable))
		return (1);
	copy = _strdup(variable->path);
	token = _strtok(copy, ":");

	while (token)
	{
		tmp = in ? token - 2 : token;
		if (*tmp == 0 && stat(input->args[0], &state) == 0)
		{
			variable->binary = input->args[0];
			free(copy);
			return (1);
		}
		len = _strlen(token) + _strlen(input->args[0]) + 2;
		_strcat(buffer, token);
		_strcat(buffer, "/");
		_strcat(buffer, input->args[0]);
		buffer[len - 1] = '\0';
		if (stat(buffer, &state) == 0)
		{
			free(copy);
			variable->binary = buffer;
			return (1);
		}
		buffer[0] = '\0';
		token = _strtok(NULL, ":");
		in = 1;
	}
	variable->binary = input->args[0];
	free(copy);
	return (0);
}

/**
 * handle_path - a function that handle the path environment variable
 * @input: all things related to the user, its command for instance
 * @variables: all things related our program, that we drive almost
 *
 * Return: 1 if found, 0 if things went wrong
 */

int handle_path(user_t *input, program_t *variables)
{
	char *path;
	struct stat state;

	path = _strdup(variables->path);
	if (!path)
	{
		variables->binary = input->args[0];
		free(path);
		return (1);
	}
	if (*path == ':' && stat(input->args[0], &state) == 0)
	{
		variables->binary = input->args[0];
		free(path);
		return (1);
	}
	free(path);
	return (0);
}
