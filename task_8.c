#include "main.h"

/**
 * free_some_struct_ - free some part of structures when needed
 * @input: all things related to the user, its command for instance
 * @variables: all things related our program, that we drive almost
 * everywhere
 *
 * Return: a type void
 */

void free_some_struct_(user_t *input, __attribute__((unused))program_t
		       *variables)
{
	if (input->env)
		free_list(input->env);
	if (input->args)
		free_args(input->args);
	if (input->user_input)
		free(input->user_input);
}

/**
 * free_all - free everything
 * @input: all things related to the user, its command for instance
 * @variables: all things related our program, that we drive almost
 * everywhere
 *
 * Return: a type void
 */

void free_all(user_t *input, __attribute__((unused))program_t *variables)
{
	free_args(input->args);
	free(input->user_input);
}

/**
 * free_list - a function that frees a envlist_t list
 * @head: the head of the list to be freed
 *
 * Return: a type void
 */

void free_list(envlist_t *head)
{
	envlist_t *torm;

	if (head)
	{
		while (head)
		{
			torm = head;
			head = head->next;
			free(torm->name);
			free(torm);
		}

	}
}

/**
 * free_args - free arguments the user entered in
 * @args: array of char pointers to the the user made arguments
 *
 * Return: a type void
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
