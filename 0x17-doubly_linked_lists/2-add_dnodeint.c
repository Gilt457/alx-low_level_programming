#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * of a dlistint_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current_head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	current_head = *head;

	if (current_head != NULL)
	{
		while (current_head->prev != NULL)
			current_head = current_head->prev;
	}

	new_node->next = current_head;

	if (current_head != NULL)
		current_head->prev = new_node;

	*head = new_node;

	return (new_node);
}
