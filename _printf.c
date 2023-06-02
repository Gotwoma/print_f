#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string with one or more directives
 * @...: variable number of arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *c;
	va_list args;

	va_start(args, format);
	for (c = format; *c != '\0'; c++)
	{
		if (*c == '%')
	{
		switch (*(++c))
		{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				{
					const char *str = va_arg(args, const char *);

					while (*str != '\0')
					{
						putchar(*str++);
						count++;
					}
					break;
				}
			case '%':
				putchar('%');
				count++;
				break;
		}
	}
		else
		{
			putchar(*c);
			count++;
		}
	}
	va_end(args);
	return (count);
}
