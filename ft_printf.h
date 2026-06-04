#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define BASE_DEC 10
#define	BASE_HEX 16
//prototype of ft_printf
int		ft_printf(const char *format, ...);

// all print functions
int	ft_putchr(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int base);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
