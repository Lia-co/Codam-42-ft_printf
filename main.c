/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 13:43:19 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/04 15:32:33 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	num_chr1;
	int	num_chr2;
	int *test = 0;

	num_chr1 = ft_printf("%p\n", test);
	ft_printf("The number of character is: %d\n", num_chr1);
	num_chr2 = printf("%p\n", test);
	printf("The number of character is: %d\n", num_chr2);

}
