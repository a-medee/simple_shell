#include "main.h"

/**
 * super_simple_shell - this is a super simple shell function
 * @input: a pointer to the first argument of the program
 * @variables: track useful variables from the program
 *
 * Return: type void
 */

void super_simple_shell(user_t *input, program_t *variables)
{
	while (1)
	{
		handling_argument(input, variables);
		if (tokenize_(input, variables) == 0)
			continue;
		if (handle_builtins_command(input, variables) == 1)
			continue;
		find_binary(input, variables);
		children_job_equal_zero(input, variables);
	}
}

/**
 * handling_argument - handle arguments passed to the program
 * @input: the user input
 * @variables: help track the program
 *
 * Description - parse and process the user input to get
 * the actual command and
 * its argument.
 * Return: a type void element
 */

void handling_argument(user_t *input, program_t *variables)
{
	int len;
	size_t n = 0;

	input->args = NULL;
	input->argv = NULL;
	variables->lineCounter++;

	if (isatty(STDIN_FILENO))
		write(STDERR_FILENO, "$ ", 2);

	len = _getline(&(input->user_input), &n, stdin);
	if (len == -1)
	{
		free_some_struct_(input, variables);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		if (variables->errorStatus)
			exit(variables->errorStatus);
		exit(EXIT_SUCCESS);

	}

	if (_strchr(input->user_input, '\n') || _strchr(input->user_input, '\t'))
		input->user_input[len - 1] = '\0';
	handle_comment_from_input(input->user_input);
}

/**
 * handle_comment_from_input - handle the # character when present in the
 * user command line
 * @str: input string
 *
 * Return: this function is of a type void
 */

void handle_comment_from_input(char *str)
{
	int i = 0, inString = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '#')
		{
			str[i] = '\0';
			return;
		}
		if (inString)
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				str[i] = '\0';
				return;
			}
		}
		i++;
		inString = 1;
	}
}

/**
 * children_job_equal_zero - fork current build and execute processes
 * @input: a pointer to the first argument of the program
 * @variables: track useful variables from the program
 *
 * Return a type void element
 */
void children_job_equal_zero(user_t *input, program_t *variables)
{
	int status;
	pid_t children_pid = fork();

	construct_envp(input, variables);
	if (children_pid == -1)
	{
		perror("error\n");
		free_some_struct_(input, variables);
		free_args(input->argv);
		exit(1);
	}
	if (children_pid == 0)
	{
		if (execve(variables->fullPath, input->args, input->argv) == -1)
		{
			_error_function(variables->pgr_name, variables->fullPath);
			free_some_struct_(input, variables);
			free_args(input->argv);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			variables->errorStatus = WEXITSTATUS(status);
		free_all(input, variables);
		free_args(input->argv);
	}
}
