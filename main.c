/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/04 13:43:19 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/05 12:47:21 by shiyuan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void int_test(int test);
void chr_test(char test);
void str_test(char *test);
void hex_test(int test);
void uint_test(unsigned int test);
void ptr_test(int test);

int	main(void)
{	
	printf("|------------test for characters-----------|\n");
	chr_test('a');
	chr_test('b');
	chr_test('0');
	chr_test('&');
	chr_test(' ');
	chr_test('%');
	chr_test('\\');
	printf("\n");
	
	printf("|------------test for strings-----------|\n");
	str_test("Hi");
	str_test("alkjdlaiflasdlkjlfskdlfn");
	str_test("      ");
	str_test("asjh alksd as ");
	str_test("sd a*%%#@()|!~");
	str_test("\\\\\\");
	str_test("%%%%%%");
	ft_printf("%%%%");
	printf("\n");
	printf("%%%%");
	printf("\n");

	printf("|------------test for (unsigned)integers-----------|\n");
	int_test(0);
	int_test(1);
	int_test(-1);
	int_test(2147483647);
	int_test(-2147483648);
	uint_test(4294967295);
	printf("\n");
	
	printf("|------------test for hexadecimals-----------|\n");
	hex_test(0);
	hex_test(1);
	hex_test(-1);
	hex_test(2147483647);
	hex_test(-2147483648);
	printf("\n");

	printf("|------------test for pointers-----------|\n");
	ptr_test(0);
	ptr_test(1);
	ptr_test(-1);
	ptr_test(2147483647);
	ptr_test(-2147483648);
	printf("\n");
}

//how to make my own tester?
	//printf_test function
		//passing entry points as arguments
		//compare diff between ft_printf and printf
			//output in terminal
			//number of printed bytes

void int_test(int test)
{
	int	num_chr1;
	int	num_chr2;

	num_chr1 = ft_printf("%d", test);
	printf("\n");
	num_chr2 = printf("%d", test);
	printf("\n");
	ft_printf("num of chr | %d\n", num_chr1);
	printf("num of chr | %d\n", num_chr2);
}

void uint_test(unsigned int test)
{
	int	num_chr1;
	int	num_chr2;

	num_chr1 = ft_printf("%u", test);
	printf("\n");
	num_chr2 = printf("%u", test);
	printf("\n");
	ft_printf("num of chr | %d\n", num_chr1);
	printf("num of chr | %d\n", num_chr2);
}

void hex_test(int test)
{
	int	num_chr1;
	int	num_chr2;
	int	num_chr3;

	num_chr1 = ft_printf("%x", test);
	printf("\n");
	num_chr2 = printf("%x", test);
	printf("\n");
	num_chr3 = ft_printf("%X", test);
	printf("\n");
	ft_printf("num of chr | %d\n", num_chr1);
	ft_printf("num of chr | %d\n", num_chr3);
	printf("num of chr | %d\n", num_chr2);
}

void chr_test(char test)
{
	int	num_chr1;
	int	num_chr2;

	num_chr1 = ft_printf("%c", test);
	printf("\n");
	num_chr2 = printf("%c", test);
	printf("\n");
	ft_printf("num of chr | %d\n", num_chr1);
	printf("num of chr | %d\n", num_chr2);
}

void str_test(char *test)
{
	int	num_chr1;
	int	num_chr2;

	num_chr1 = ft_printf("%s", test);
	printf("\n");
	num_chr2 = printf("%s", test);
	printf("\n");
	ft_printf("num of chr | %d\n", num_chr1);
	printf("num of chr | %d\n", num_chr2);
}

void ptr_test(int test)
{
	int	num_chr1;
	int	num_chr2;

	num_chr1 = ft_printf("%p", &test);
	printf("\n");
	num_chr2 = printf("%p", &test);
	printf("\n");
	ft_printf("num of chr | %d\n", num_chr1);
	printf("num of chr | %d\n", num_chr2);
}