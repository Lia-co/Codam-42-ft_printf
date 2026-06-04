/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 11:06:49 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/04 15:27:46 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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