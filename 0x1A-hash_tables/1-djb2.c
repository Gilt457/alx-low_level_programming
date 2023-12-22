#include "hash_tables.h"

/**
 * hash_djb2 - Hash function using the djb2 algorithm.
 * @str: The string to be hashed.
 *
 * Return: The resulting hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while (c = *str)
	{
		hash = hash * 33 + c; /* hash = (hash << 5) + hash + c */
		str++;
	}

	return (hash);
}
