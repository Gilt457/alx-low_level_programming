#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * f4 - finds the biggest number
 *
 * @usrn: username
 * @len: length of username
 * Return: the biggest number
 */
int f4(char *usrn, int len)
{
	int ch = *usrn;
	int vch = 0;

	while (vch < len)
	{
		if (ch < usrn[vch])
			ch = usrn[vch];
		vch++;
	}

	srand(ch ^ 14);
	return (rand() & 63);
}

/**
 * f5 - multiplies each char of username
 *
 * @usrn: username
 * @len: length of username
 * Return: multiplied char
 */
int f5(char *usrn, int len)
{
	int ch = 0;
	int vch = 0;

	while (vch < len)
	{
		ch += usrn[vch] * usrn[vch];
		vch++;
	}

	return (((unsigned int)ch ^ 239) & 63);
}

/**
 * f6 - generates a random char
 *
 * @usrn: username
 * Return: a random char
 */
int f6(char *usrn)
{
	int ch = 0;
	int vch = 0;

	while (vch < *usrn)
	{
		ch = rand();
		vch++;
	}

	return (((unsigned int)ch ^ 229) & 63);
}

/**
 * main - Entry point
 *
 * @argc: arguments count
 * @argv: arguments vector
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char keygen[7];
	int len, ch, vch;
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474F, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494B646850};
	(void)argc;

	for (len = 0; argv[1][len]; len++)
		;

	keygen[0] = ((char *)alph)[(len ^ 59) & 63];
	ch = vch = 0;

	while (vch < len)
	{
		ch += argv[1][vch];
		vch++;
	}
	keygen[1] = ((char *)alph)[(ch ^ 79) & 63];

	ch = 1;
	vch = 0;

	while (vch < len)
	{
		ch *= argv[1][vch];
		vch++;
	}
	keygen[2] = ((char *)alph)[(ch ^ 85) & 63];

	keygen[3] = ((char *)alph)[f4(argv[1], len)];
	keygen[4] = ((char *)alph)[f5(argv[1], len)];
	keygen[5] = ((char *)alph)[f6(argv[1])];
	keygen[6] = '\0';

	for (ch = 0; keygen[ch]; ch++)
		printf("%c", keygen[ch]);

	return (0);
}
