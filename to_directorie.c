#include "main.h"

/**
 * cd_builtins - handle the cd builtin command and everything
 * related
 * @input: all things related to the user, its command for instance
 * @variables: all things related our program, that we drive almost
 *
 * Return: 1 on success, 0 on failure
 */

int cd_builtins(user_t *input, program_t *variables)
{
	int count = 0, i, file;
	char *node, *presence;

	count = args_number(input->args);
	if (count == 1)
	{
		i = find_element(input->env, "HOME");
		if (i == -1)
		{
			file = 1;
		}
		node = get_nodeint_at_index(input->env, i);
		presence = _strchr(node, '=');
		presence++;
		chdir(presence);
		free(node);
	}
	else if (count == 2 && _strcmp(input->args[1], "-") == 0)
	{
		if (previous_dir(input) == 1)
			change_(input);
	}
	else
	{
		file = chdir(input->args[1]);
		if (file == -1)
			_error_function(variables->pgr_name, input->user_input);
		change_(input);
	}
	return (1);
}

/**
 * previous_dir - change current, to previous directory
 * @input: all things related to the user, its command for instance
 *
 * Return: 1 if everything goes according to plan
 */
int previous_dir(user_t *input)
{
	int i;
	char *s, *other_pin, *dir_acut = NULL;

	dir_acut = getcwd(dir_acut, 0);
	i = find_element(input->env, "OLDPWD");
	if (i == -1)
	{
		chdir(dir_acut);
		write(STDOUT_FILENO, dir_acut, _strlen(dir_acut));
		write(STDERR_FILENO, "\n", 2);
		return (1);
	}
	s = get_nodeint_at_index(input->env, i);
	other_pin = _strchr(s, '=');
	other_pin++;
	chdir(other_pin);
	write(STDOUT_FILENO, other_pin, _strlen(other_pin));
	write(STDOUT_FILENO, "\n", 1);
	free(s);
	return (1);
}

/**
 * change_ - handle the program after the use of the cd builtins
 * @input: all things related to the user, its command for instance
 * everywhere
 *
 * Return: true on success false on failure
 */
int change_(__attribute__((unused))user_t *input)
{
	return (0);
}
