/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 13:30:02 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/04 15:34:44 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long adr, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = HEX_LOW;
	if (adr == 0)
		return ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		count = ft_putnbr(adr / base, base);
		return (count + ft_putnbr(adr % base, base) + 2);
	}
	return count;
}
