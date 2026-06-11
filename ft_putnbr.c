/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 11:06:49 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/11 19:18:08 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base, char *symbols)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (ft_putchr(symbols[n]));
	else
	{
		count = ft_putnbr(n / base, base, symbols);
		return (count + ft_putnbr(n % base, base, symbols));
	}
	return (count);
}
