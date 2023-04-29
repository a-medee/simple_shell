#include "main.h"

/**
 * find_element - search a list for a value
 * @head: a pointer to head of list
 * @value: the string whose matched is being searched
 *
 * Return: index of node with matching string
 */
int find_element(envlist_t *head, char *value)
{
	int idx = 0, i = 0;
	int len = 0;
	envlist_t *actu = head;
	char *tmp, *ptr;

	while (actu)
	{
		ptr = _strchr(actu->name, '=');
		len = ptr - actu->name;
		tmp = malloc(sizeof(char) * len + 1);
		for (i = 0; i < len; i++)
			tmp[i] = actu->name[i];
		tmp[i] = '\0';
		if (_strcmp(value, tmp) == 0)
		{
			free(tmp);
			return (idx);
		}
		idx++;
		actu = actu->next;
		free(tmp);
	}
	return (-1);
}

/**
 * start_env_list - linked list for the env envrionment variable
 * variable
 * @env: the array that will made up the list
 *
 * Return: head of linked list
 */
envlist_t *start_env_list(char **env)
{
	int i = 0;
	envlist_t *head;

	head = NULL;
	while (env[i])
	{
		add_node_end(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * addNodeAtIndex - add node at index with string
 * @head: double pointer to head
 * @index: index to add at
 * @str: string to add
 * Return: address of node added
 */
envlist_t *addNodeAtIndex(envlist_t **head, int index, char *str)
{
	register int i = 0;
	envlist_t *newNode, *current;
	char *newStr;

	current = *head;
	if (!str)
		return (NULL);
	newNode  = malloc(sizeof(envlist_t));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		free(newNode);
		perror("Malloc failed\n");
		exit(errno);
	}

	newNode->name = newStr;
	newNode->next = NULL;

	while (i < index - 1)
	{
		if (current->next == NULL)
		{
			free(newNode);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	newNode->next = current->next;
	current->next = newNode;
	return (newNode);
}

/**
 * get_nodeint_at_index -  a function that returns the nth node of a
 * listint_t linked list.
 * @head: a pointer to the first element of our linked list
 * @index: is the index of the node, starting at 0
 *
 * Return: if the node does not exist, return NULL, the node otherwise
 */

char *get_nodeint_at_index(envlist_t *head, unsigned int index)
{
	unsigned int i, size = (unsigned int)list_len(head);
	envlist_t *firstnode = head, *node_to_be_returned;

	if (head && (index <= size))
	{
		for (i = 0; i < index; i++)
		{
			head = head->next;
		}
		node_to_be_returned = head;
		head = firstnode;
		return (_strdup(node_to_be_returned->name));
	}

	return (NULL);
}
