#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string s
 * Return: length of string
 */
int _strlen(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	return (1 + _strlen(str + 1));
}
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied
 * Return: copied string
 */
char *_strdup(char *str)
{
	int i, len;
	char *copy;

	if (!str)
		return (NULL);
	len = _strlen(str);
	copy = malloc(sizeof(char) * len + 1);
	if (!copy)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
}

/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte
 * @dest: copied string
 * @src: string to be copied
 * Return: pointer to new copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (ptr);
}

/**
 * _getline - reads a line
 * @lineptr: pointer that stores adress of buffer
 * @n: size of buffer
 * @stream: stream to read from
 * Return: number of characters read on the line
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	unsigned int size = 1024, len = 0;
	char *line;

	if (!lineptr || !n || !stream)
		return (-1);

	line = malloc(size);
	if (!line)
		return (-1);

	do {
		c = fgetc(stream);
		if (c != EOF)
		{
			if (len < size - 1)
				line[len] = c;
			else
			{
				(c != '\n') ? (size += 1) : (size += 2);
				line = realloc(line, size);
				if (!line)
					return (-1);
				line[len] = c;
			}
			len++;
		}
	} while (c != '\n');

	line[len] = '\0';
	*n = len;

	if (size != len + 1)
		*lineptr = _strdup(line);
	else
		*lineptr = line;

	free(line);
	return (len);
}
