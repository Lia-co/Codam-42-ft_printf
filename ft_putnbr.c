/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 11:06:49 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/03 17:30:05 by shiyuan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//based on libft version
/* int	ft_putnbr(int n, int base)
{
	char	*str;
	long	num;
	int		count;

	num = n;
	str = ft_itoa(num);
	if (str == NULL)
		return ;
	count = ft_putstr(str);
	free(str);
	return count;
} */

//new version
int	ft_putnbr(int n, int base)
{
	int		count;
	long	num;
	char	*symbols;

	symbols = "0123456789abcdef";
	num = n;
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