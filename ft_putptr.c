/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 13:30:02 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/05 11:20:35 by shiyuan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t ptr, int base, char *symbols)
{
	int		count;

	count = 0;
	if (ptr == 0)
		return ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		count = ft_putnbr(ptr / base, base, symbols);
		return (count + ft_putnbr(ptr % base, base, symbols) + 2);
	}
	return count;
}
