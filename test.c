#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return i;
}

int main(void)
{
	char *str;
	int	num;

	str = "shiyuan";
	num = ft_putstr(str);
	printf("%d\n", num);
}