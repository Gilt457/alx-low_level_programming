#include "search_algos.h"

/**
 * recursive_search - Implements the Binary search algorithm.
 *
 * @array: The array to be searched
 * @size: The size of the array
 * @value: The value to be found
 * Return: The index of the value in the array
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (recursive_search(array, half, value));

	half++;

	return (recursive_search(array + half, size - half, value) + half);
}

/**
 * binary_search - Invokes recursive_search.
 *
 * @array: The array to be searched
 * @size: The size of the array
 * @value: The value to be found
 * Return: The index of the value in the array
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	index = recursive_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
