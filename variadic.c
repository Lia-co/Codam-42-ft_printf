#include <stdarg.h>
#include <stdio.h>

int	average(int num, ...);

int main(void)
{
	int	average_age;

	average_age = average(5, 10, 10, 10, 10, 10);
	printf("The average age of 5 people is: %d\n", average_age);
}

int	average(int num, ...)
{
	va_list	ptr_args;
	int		total;
	int		i;

	total = 0;
	i = 0;
	va_start(ptr_args, num); //va_start makes ptr_args points to the 1st arg
	while (i < num)
	{
		total += va_arg(ptr_args, int);
		i++;
	}
	va_end(ptr_args);
	return ((int)(total / num));
}