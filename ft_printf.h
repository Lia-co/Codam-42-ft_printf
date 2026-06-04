/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 11:33:46 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/04 14:05:18 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define BASE_DEC 10
#define	BASE_HEX 16
#define HEX_UPP "0123456789ABCDEF"
#define HEX_LOW "0123456789abcdef"

//prototype of ft_printf
int		ft_printf(const char *format, ...);

// all print functions
int print_format(char specifier, va_list ptr_args);
int	ft_putchr(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long n, int base);
int	ft_puthex_upp(long n, int base);
int	ft_putptr(unsigned long adr, int base);

// char	*ft_itoa(int n);
// void	ft_bzero(void *s, size_t n);
// void	*ft_memset(void *s, int c, size_t n);
// void	*ft_calloc(size_t nmemb, size_t size);

#endif
