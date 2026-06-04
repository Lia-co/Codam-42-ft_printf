#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_printf(const char *format, ...);
int print_format(char specifier, va_list ptr_args);
int	ft_putchr(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int base);

int	main(void)
{
	int	num_chr1;
	int	num_chr2;

	num_chr1 = ft_printf("%s\n", "Hi!");
	ft_printf("The number of character is: %d\n", num_chr1);
	num_chr2 = printf("%s\n", "Hi!");
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
			*++format;
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
		num_chr += ft_putnbr(va_arg(ptr_args, int), 10);
	else if (specifier == 'x')
		num_chr += ft_putnbr(va_arg(ptr_args, unsigned int), 16);//why use unsigned int? hex without any negative sign
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
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return i;
}

int	ft_putnbr(int n, int base)
{
	int		count;
	char	*symbols;
	long	num;

	count = 0;
	num = n;
	symbols = "0123456789abcdef";
	if (num < 0)
	{
		write(1, "-", 1);
		return ft_putnbr(-num, base) + 1;
	}
	else if (num < base)
		return ft_putchr(symbols[num]);
	else
	{
		count = ft_putnbr(num / base, base);
		return count + ft_putnbr(num % base, base);
	}
	return count;
}

//type casting n to long; num doesn't work why?