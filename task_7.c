#include "main.h"

/**
 * addNode - adds a new node at the beginning of a envlist_t list
 * @head: reference to head of linked list
 * @str: string to be added on new node
 * Return: address of new head;
 */
envlist_t *addNode(envlist_t **head, char *str)
{
	envlist_t *newNode;
	char *newStr;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(envlist_t));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->name = newStr;
	newNode->next = *head;
	*head = newNode;
	return (*head);
}

/**
 * add_node_end - add a new node at the end of a list_t list.
 * @head: head of list_t
 * @str: a pointer to the string to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */

envlist_t *add_node_end(envlist_t **head, char *str)
{
	envlist_t *a = malloc(sizeof(envlist_t));
	envlist_t **ad = head;
	envlist_t *first = *head;

	if (a)
	{
		while ((*ad))
		{
			if ((*ad)->next == NULL)
			{
				break;
			}
			*ad = (*ad)->next;
		}
		a->next = NULL;
		a->name = _strdup(str);
		if ((*head) == NULL)
			*head = a;

		else
		{
			(*ad)->next = a;
			(*head) = first;
		}
		return (a);
	}
	return (NULL);
}

/**
 * print_listint - a function that prints all the elements of a listint_t list.
 * @h: a variable of type list_t, the h whose elements will be printed
 *
 * Return: the number of node successfully printed
 */

size_t print_listint(const envlist_t *h)
{
	size_t count = 0;

	while (h)
	{
		write(STDIN_FILENO, h->name, _strlen(h->name));
		write(STDERR_FILENO, "\n", 2);
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * delete_index_node - deletes the node at index
 * index of a envlist_t linked list
 * @head: double pointer to head of list
 * @index: index of node to be deleted
 *
 * Return: 1 if successful, -1 otherwise
 */
int delete_index_node(envlist_t **head, unsigned int index)
{
	envlist_t *current;
	envlist_t *next;

	register uint i;

	if (!head || !(*head))
		return (-1);
	current = *head;
	if (!index)
	{
		*head = current->next;
		free(current);
		return (1);
	}
	for (i = 0; current && i < index - 1; i++)
		current = current->next;
	if (!current || !(current->next))
		return (-1);
	next = current->next->next;
	free(current->next->name);
	free(current->next);
	current->next = next;
	return (1);
}

/**
 * list_len - return the number of elements in a linked list.
 * @h: a type list_t variable whose elements are  to be counted
 *
 * Return: a type size_t value
 */

size_t list_len(const envlist_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
