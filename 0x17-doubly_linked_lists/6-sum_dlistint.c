#include "lists.h"

/**
 * sum_dlistint - Calculates the total sum of all 'n' data elements
 *                within a doubly linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: Total sum of 'n' data elements
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}

	return (sum);
}
