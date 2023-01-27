#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - prints a string in a formated way
 * @format: string to print (char *)
 * @...: variadic parameters (unknown)
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0; 
	int count = 0;
       	int value = 0;
	va_list args;
	int (*f)(va_list);
	va_start (args, format);
	/*Prevent passing a null pointer*/
	if (format == NULL)
		return (-1);

	/*Print each character of string*/	
	while (format[i])
	{
		if (format[i] != '%')
		{
			value = write(1, &format[i], 1);
			count = count + value;
			i++;
			continue;
		}

		if (format[i] == '%')
		{
			f = specifier_checker(&format[i + 1]);
			if (f != NULL)
			{
				value =	f(args);
				count = count + value; 
				i = i + 2;
				continue;
			}

			if (format[i + 1] == '\n')  
			{
				break;
			}	

			if (format[i + 1] != '\0')
			{
				value = write(1, &format[i + 1], 1);
				count = count + value;
				i = i + 2;
				continue;
			}
		}
		
	}
	return (count); 
}

