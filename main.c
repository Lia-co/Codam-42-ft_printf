#include "ft_printf.h"

int	main(void)
{
	int	num_chr;

	num_chr = ft_printf("%s", "shiyuan");
	ft_printf("The number of character is: %d", num_chr);
}