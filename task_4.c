#include "main.h"

/**
 * tokenize_ - return token from arguments
 * @input: all things related to the user, its command for instance
 * @variables: all things related our program, that we drive almost
 *
 * Return: 1 if everything went successful, 0 otherwise
 */

int tokenize_(user_t *input, __attribute__((unused))program_t *variables)
{
	unsigned int i = 0;
	char *token, *simple_copy;

	if (number_of_words(input->user_input) == 0)
	{
		input->args = NULL;
		free(input->user_input);
		return (0);
	}

	input->args = malloc((number_of_words(input->user_input) + 1)
			     * sizeof(char *));
	simple_copy = _strdup(input->user_input);
	token = _strtok(simple_copy, " ");
	while (token)
	{
		input->args[i] = _strdup(token);
		token = _strtok(NULL, " ");
		i++;
	}
	input->args[i] = NULL;
	free(simple_copy);
	return (1);
}

/**
 * number_of_words - word count
 * @str: input string
 *
 * Return: a type number of words
 */
int number_of_words(char *str)
{
	int words = 0, in = 0;

	while (*str)
	{
		if ((*str == ' ') && in)
			in = 0;
		else if (!(*str == ' ') && !in)
		{
			in = 1;
			words++;
		}
		str++;
	}
	return (words);
}
