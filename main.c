#include "main.h"

/**
 * main - program entry point
 * @argc: arguments count for the program
 * @arg: an array containing the command line arguments passed to our
 * program
 *
 * Return: 0 on success
 */

int main(__attribute__((unused))int argc, char **arg)
{
	user_t input;
	program_t variables;

	input.env = start_env_list(environ);
	input.argv = NULL;
	input.args = NULL;
	input.user_input = NULL;

	variables.path = _getenv("PATH", environ);
	variables.binary = NULL;
	variables.pgr_name = NULL;
	variables.e_stat = 0;
	variables.pgr_name = arg[0];

	super_simple_shell(&input, &variables);
	return (0);
}
