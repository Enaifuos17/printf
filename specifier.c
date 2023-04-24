#include "main.h"

/**
 * get_specifier - finds the format function
 *
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s)) (va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_octal},
		{"x", print_octal},
		{"X", print_octal},
		{"p", print_octal},
		{"S", print_octal},
		{"r", print_octal},
		{"R", print_octal},
		{NULL, NULL}
	};
	int i = 0;

	/* loop into each item of the specifiers[] array */
	while (specifiers[i].specifier)
	{
		/* if s (char) is one of the chars (c, d, i....) */
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f); /* return the function */
		}
		i++; /* increment to move to the next one */
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 *
 * @s: format string
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
	{
		return (f(ap, params));
	}
	return (0);
}

/**
 * get_flag - finds the flag function
 *
 * @s: format string
 * @params: parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier function
 *
 * @s: format string
 * @params: parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 *
 * @s: format string
 * @params: parameters struct
 * @ap: argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
		{
			d = d * 10 + (*s++ - '0');
		}
	}
	params->width = d;
	return (s);
}
