/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_upp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 13:31:02 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/04 13:52:36 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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