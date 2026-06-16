#include "ft_printf.h"

int main()
{
	// unsigned int l_ma = ft_printf("%p\n", (void *)LONG_MAX);
	// unsigned int l_max = printf("%p\n", (void *)LONG_MAX);
	// printf("%u\n", l_ma);
	// printf("%u\n", l_max);

	// unsigned int l_mi = ft_printf("%p\n", (void *)-1);
	// unsigned int l_min = printf("%p\n", (void *)-1);
	// printf("%u\n", l_mi);
	// printf("%u\n", l_min);
	
	// unsigned int ul_ma = ft_printf("%p\n", (void *)ULONG_MAX);
	// unsigned int ul_max = printf("%p\n", (void *)ULONG_MAX);
	// printf("%u\n", ul_ma);
	// printf("%u\n", ul_max);

	unsigned int l_mi = ft_printf("");
	unsigned int l_min = printf("");
	printf("%d\n", l_mi);
	printf("%d\n", l_min);
}