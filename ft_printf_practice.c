/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_printf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 13:43:07 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/04 13:43:08 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	num_chr1;
	int	num_chr2;
	int n = 42;

	num_chr1 = ft_printf("%p\n", &n);
	ft_printf("The number of character is: %d\n", num_chr1);
	num_chr2 = printf("%p\n", &n);
	printf("The number of character is: %d\n", num_chr2);

}

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

int	ft_putchr(int c)
{
	return write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write (1, &s[count], 1);
		count++;
	}
	return count;
}

int	ft_putnbr(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = HEX_LOW;
	if (n < 0)
	{
		write(1, "-", 1);
		return ft_putnbr(-n, base) + 1;
	}
	else if (n < base)
		return ft_putchr(symbols[n]);
	else
	{
		count = ft_putnbr(n / base, base);
		return count + ft_putnbr(n % base, base);
	}
	return count;
}

int	ft_puthex_upp(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = HEX_UPP;
	if (n < 0)
	{
		write(1, "-", 1);
		return ft_puthex_upp(-n, base) + 1;
	}
	else if (n < base)
		return ft_putchr(symbols[n]);
	else
	{
		count = ft_puthex_upp(n / base, base);
		return count + ft_puthex_upp(n % base, base);
	}
	return count;
}

int	ft_putptr(unsigned long adr, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = HEX_LOW;
	ft_putstr("0x");
	if ((int)adr < base)
		return ft_putchr(symbols[adr]);
	else
	{
		count = ft_putnbr(adr / base, base);
		return count + ft_putnbr(adr % base, base) + 2;
	}
	return count;
}
//type casting n to long; num doesn't work why?