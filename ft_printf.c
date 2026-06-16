/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/06 16:13:49 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/16 13:30:00 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ptr_args;
	int		num_chr;

	num_chr = 0;
	if (!format)
		return (-1);
	va_start(ptr_args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (-1);
			else
			{
				format++;
				num_chr += print_conversion(*format, ptr_args);
			}
		}
		else
			num_chr += write(1, format, 1);
		format++;
	}
	va_end(ptr_args);
	return (num_chr);
}

// test version
int	print_conversion(char specifier, va_list ptr_args)
{
	int	num_chr;

	num_chr = 0;
	if (specifier == 'c')
		num_chr += ft_putchr(va_arg(ptr_args, int));
	else if (specifier == 's')
		num_chr += ft_putstr(va_arg(ptr_args, char *));
	else if (specifier == 'd' || specifier == 'i')
		num_chr += ft_putnbr((long)va_arg(ptr_args, int), BASE_DEC, DEC);
	else if (specifier == 'u')
		num_chr += ft_putnbr_unsigned((unsigned long)va_arg(ptr_args,
					unsigned int), BASE_DEC, DEC);
	else if (specifier == 'x')
		num_chr += ft_putnbr_unsigned((unsigned long)va_arg(ptr_args, unsigned int),
				BASE_HEX, HEX_LOW);
	else if (specifier == 'X')
		num_chr += ft_putnbr_unsigned((unsigned long)va_arg(ptr_args, unsigned int),
				BASE_HEX, HEX_UPP);
	else if (specifier == 'p')
		num_chr += ft_putptr((uintptr_t)va_arg(ptr_args, void *), BASE_HEX,
				HEX_LOW);
	else if (specifier == '%')
		num_chr += write(1, &specifier, 1);
	return (num_chr);
}
