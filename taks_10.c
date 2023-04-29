#include "main.h"

/**
 * handle_builtins_command - check whether the user command is builtin
 * and executes the appropriate function
 * @input: user stuff
 * @variables: program stuff
 *
 * Return: 1 succesful
 */

int handle_builtins_command(user_t *input, program_t *variables)
{
	int i = 0;
	builtins_t all_builtins[] = {
		{"cd", cd_builtins},
		{"exit", exit_builtins},
		{"env", env_builtins},
		{NULL, NULL}
	};

	while (all_builtins[i].command)
	{
		if (_strcmp(input->args[0], all_builtins[i].command) == 0)
		{
			all_builtins[i].func(input, variables);
			free_all(input, variables);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * exit_builtins - act as the exit c standard function
 * @input: all things related to the user, its command for instance
 * @variables: all things related our program, that we drive almost
 * everywhere
 *
 * Return: 1 on success, 0 on failure
 */
int exit_builtins(user_t *input, program_t *variables)
{
	int number, status;

	number = args_number(input->args);
	if (number == 1)
	{
		free_some_struct_(input, variables);
		if (variables->errorStatus)
			exit(variables->errorStatus);
		exit(EXIT_SUCCESS);
	}
	else if (number > 1)
	{
		status = _atoi(input->args[1]);
		if (status == -1)
		{
			_error_function(variables->pgr_name, input->user_input);
			return (0);
		}
		free_some_struct_(input, variables);
		exit(status);
	}
	return (1);
}
