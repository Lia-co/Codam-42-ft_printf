/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 11:00:29 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/03 13:34:38 by shiyuan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int n);

//convert int to char function
char	*ft_itoa(int n)
{
	char	*chr;
	int		i;
	long	num;

	num = n;
	i = ft_len(num);
	chr = ft_calloc((i + 1), sizeof(char));
	if (!chr)
		return (NULL);
	if (num < 0)
	{
		chr[0] = '-';
		num = -num;
	}
	if (num == 0)
		chr[0] = '0';
	while (num > 0)
	{
		chr[i - 1] = num % 10 + 48;
		num = num / 10;
		i--;
	}
	return (chr);
}

//integer length calculation function
static int	ft_len(int n)
{
	int		len;
	long	num;

	num = n;
	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}