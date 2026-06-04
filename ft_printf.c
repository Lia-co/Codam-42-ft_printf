#include "ft_printf.h"

/*
while loop put char by char from format in fd 1, write function/ft_putstr_fd;
if find %, check next char
	if c-->take it as char
	if s-->take it as str
	if d/i-->take it as int
	if u-->take it as unsigned int
	if x-->take it as hexadecimal lower character
	if X-->take it as hexadecimal upper character
	if p-->take it as pointer

Q: How to calculate the number of printed characters?
*/

int	ft_printf(const char *format, ...)
{
	va_list	ptr_args;
	int		num_chr;

	num_chr = 0;
	va_start(ptr_args, format);
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format = format + 1;
			num_chr += print_format(*format, ptr_args);
		}
		else
			num_chr += write(1, format, 1);
		format++;
	}
	va_end(ptr_args);
	return (num_chr);
}

//test version
int print_format(char specifier, va_list ptr_args)
{
	int	num_chr;

	num_chr = 0;
	if (specifier == 'c')
		num_chr += ft_putchr(va_arg(ptr_args, int));//type promotion. char and short --> int
	else if (specifier == 's')
		num_chr += ft_putstr(va_arg(ptr_args, char *));
	else if (specifier == 'd' || specifier == 'i')
		num_chr += ft_putnbr((long)va_arg(ptr_args, int), BASE_DEC);
	else if (specifier == 'u')
		num_chr += ft_putnbr((long)va_arg(ptr_args, unsigned int), BASE_DEC);
	else if (specifier == 'x')
		num_chr += ft_putnbr((long)va_arg(ptr_args, unsigned int), BASE_HEX);//why use unsigned int? hex without any negative sign
	else if (specifier == 'X')
		num_chr += ft_puthex_upp((long)va_arg(ptr_args, unsigned int), BASE_HEX);
	else if (specifier == 'p')
		num_chr += ft_putptr((unsigned long)va_arg(ptr_args, void *), BASE_HEX);//why do I need unsigned long here?
	else if (specifier == '%')
		num_chr += write(1, &specifier, 1);
	return num_chr;
}
