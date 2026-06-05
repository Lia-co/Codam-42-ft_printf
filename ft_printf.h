/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 11:33:46 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/05 11:36:55 by shiyuan       ########   odam.nl         */
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
#define DEC "0123456789"
#define HEX_UPP "0123456789ABCDEF"
#define HEX_LOW "0123456789abcdef"

//prototype of ft_printf
int		ft_printf(const char *format, ...);

// all print functions
int print_conversion(char specifier, va_list ptr_args);
int	ft_putchr(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long n, int base, char *symbols);
int	ft_puthex_upp(long n, int base, char *symbols);
int	ft_putptr(uintptr_t ptr, int base, char *symbols);

#endif
