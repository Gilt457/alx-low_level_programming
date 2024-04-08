#include "search_algos.h"

/**
 * linear_search - Implements the Linear search technique to find a specific
 * integer in a given list of integers.
 *
 * @array: The array to be searched.
 * @size: The number of elements in the array.
 * @value: The integer to locate within the array.
 * Return: The function returns EXIT_SUCCESS if successful.
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%u] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
