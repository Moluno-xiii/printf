#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Function that produces output according to a format
 * @format: format string
 *
 * Return: Always 0 (success)
 */

int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					chars_printed += printf("%c", va_arg(args, int));
					break;
				case 's':
					chars_printed += printf("%s", va_arg(args, char *));
					break;
				case '%':
					chars_printed += printf("%%");
					break;
				default:
					chars_printed += write(1, format - 1, 1);
					chars_printed += write(1, format, 1);
			}
		}
		else
		{
			chars_printed += write(1, format, 1);
		}
		format++;
	}

	va_end(args);
	return (chars_printed);
}
