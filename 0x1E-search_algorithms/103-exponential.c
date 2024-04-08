#include "search_algos.h"

/**
  * _binary_search - This function implements binary.
  * @array: This is the array to be searched.
  * @left: This is the starting index of the array.
  * @right: This is the ending index of the array,
  * @value: This is the value to be searched in the array.
  *
  * Return: If the array is NULL or the value is not found.
  *         If the value is found, the function returns.
  *
  * Description: This function also prints the array.
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}

/**
  * exponential_search - This function implements.
  * @array: This is the array to be searched.
  * @size: This is the number of elements in the array.
  * @value: This is the value to be searched in the array.
  *
  * Return: If the array is NULL or the value is not found.
  *         If the value is found, the function returns.
  *
  * Description: This function prints.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (_binary_search(array, i / 2, right, value));
}
