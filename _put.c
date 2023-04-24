#include "main.h"

/**
 * _puts - prints a string with newline
 *
 * @str: string to be printed
 *
 * Return: length of string
 */
int _puts(char *str)
{
	/* a --> start of str */
	char *a = str;

	/* while *str not empty */
	while (*str)
		_putchar(*str++);
	return (str - a);
	/* in the end str -> will be the last thing */
	/* and a -> will be the first thing */
	/* SO well ge the LENGTH */
}

/**
 * _putchar - writes the character c to stdout
 *
 * @c: the character to print
 *
 * Return: 1, on error -1
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	/* after c == -1 well enter here (write()) */
	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	/* c != BUF_FLUSH -> c != -1 */
	/* always it willNot be -1 at the first */
	/* itll == -1 UNTIL the END (THEN we enter in the first IF */
	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}
	return (1);
}
