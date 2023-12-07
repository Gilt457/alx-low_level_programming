#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieves the node at the specified index
 *                         in a dlistint_t linked list
 * @head: Pointer to the head of the list
 * @index: Index of the target node
 *
 * Return: Pointer to the node at the given index, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL) /* Traverse to the actual head of the list */
		head = head->prev;

	i = 0;

	while (head != NULL) /* Loop through the list nodes */
	{
		if (i == index) /* Check if the current node is the target node */
			break;
		head = head->next; /* Move to the next node */
		i++;
	}

	return (head); /* Return the node at the specified index */
}
