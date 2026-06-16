/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_unsigned.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/16 13:18:48 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/16 13:23:32 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned long n, unsigned int base, char *symbols)
{
	int	count;

	count = 0;
	if (n < base)
		return (ft_putchr(symbols[n]));
	else
	{
		count = ft_putnbr_unsigned(n / base, base, symbols);
		return (count + ft_putnbr_unsigned(n % base, base, symbols));
	}
	return (count);
}