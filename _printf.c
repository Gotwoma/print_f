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
	/*Handle conversion specifiers*/
		switch (*(++c))
		{
			case 'c':
				/* Print a character */
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				{
					/* Print a string */
					const char *str = va_arg(args, const char *);

					while (*str != '\0')
					{
						putchar(*str++);
						count++;
					}
					break;
				}
			case '%':
				/* Print a percent sign */
				putchar('%');
				count++;
				break;
			default:
				/* Unsupported conversion specifier, ignore it*/
				break;
		}
	}
		else
		{
			/* Print regular characters*/
			putchar(*c);
			count++;
		}
	}
	va_end(args);

	return (count);
}

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	int count = _printf("%s character is %c and %% is percent.\n", "Jo", 'A');

	printf("\nNo of characters printed: %d\n", count);
	return (0);
}
