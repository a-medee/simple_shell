#include "main.h"
#include <stdio.h>


/**
 * ctr_c_handler - catches SIGINT signal and reset signal
 * @sign: signal from stdint
 *
 * Return a type void element
 */
void ctr_c_handler(__attribute__((unused))int sign)
{
	signal(SIGINT, ctr_c_handler);
	write(STDOUT_FILENO, "\n", 1);
	fflush(stdout);
	exit(0);
}

/**
* args_number - the number of arguments
* @args: input array of strings
*
* Return: an int value representing number of strings
*/

int args_number(char **args)
{
	int i = 0;

	while (args[i])
		i++;
	return (i);
}

/**
* _atoi - change string to an integer
* @s: input string
* Return: -1 if it's not a valid number, else the converted number
*/
int _atoi(char *s)
{
	register int i = 0;
	unsigned long num = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + s[i] - '0';
		else
			return (-1);
		i++;
	}
	if (num > INT_MAX)
	{
		return (-1);
	}
	return (num);
}
