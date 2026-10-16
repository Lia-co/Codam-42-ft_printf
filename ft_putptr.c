/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 13:30:02 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/16 13:39:17 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t ptr, unsigned int base, char *symbols)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	else
	{
		ft_putstr("0x");
		return (ft_putnbr_unsigned(ptr, base, symbols) + 2);
	}
}
