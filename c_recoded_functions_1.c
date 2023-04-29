#include "main.h"

/**
 * _strncmp - act as the strncmp C stantard function
 * @str1: the first string
 * @str2: the second string
 * @n: the size count
 *
 * Return: an int value
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	int result = 0;
	size_t i;

	if (str1 == NULL || str2 == NULL)
		return (-1);

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			result = str1[i] - str2[i];
			break;
		}
	}

	return (result);
}

/**
 * _getenv - act as the getenv C stantard function
 * @name: the environment variable to be looked for
 * @environ: the general environment variable
 *
 * Return: a pointer to char
 */

char *_getenv(char *name, char **environ)
{
	char *value = NULL;
	int i = 0;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			value = environ[i] + _strlen(name) + 1;
			break;
		}
	}

	if (value == NULL)
	{
		return (NULL);
	}
	return (value);
}

/**
 * _strcat - our clone of the strcat function
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to string
 */

char *_strcat(char *dest, const char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while ((*p++ = *src++) != '\0')
		continue;
	return (dest);
}

/**
 * parse_delim - tokenizes a string
 * @c: the characters to be compared to
 * @delim: delimiter
 * Return: number of characters read on the line
 */

unsigned int parse_delim(char c, char *delim)
{
	char *d;

	for (d = delim; *d != '\0'; d++)
	{
		if (c == *d)
			return (1);
	}
	return (0);
}

/**
* _strtok - our clone of the strtok c standard function
* @str: the string to be parsed
* @delim: the delimiator to be sought
*
* Return: a char type
*/

char *_strtok(char *str, char *delim)
{
	static char *srtc;
	char *tobe;

	if (!str)
		str = srtc;
	if (!str)
		return (NULL);

	while (3)
	{
		if (parse_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}

	tobe = str;
	while (3)
	{
		if (*str == '\0')
		{
			srtc = str;
			return (tobe);
		}
		if (parse_delim(*str, delim))
		{
			*str = '\0';
			srtc = str + 1;
			return (tobe);
		}
		str++;
	}
}
