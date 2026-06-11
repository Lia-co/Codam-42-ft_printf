/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 11:05:36 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/08 13:53:40 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == 0)
		return (ft_putstr("(null)"));
	while (s[count] != '\0')
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
