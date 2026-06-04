/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/25 13:12:35 by sliang        #+#    #+#                 */
/*   Updated: 2026/06/04 13:54:15 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
DESCRIPTION
	The calloc() function allocates memory for an array of nmemb elements
    of size bytes each and returns a pointer to the allocated memory. The
    memory is set to zero. If nmemb or size is 0,  then  calloc() returns
    either  NULL,  or a unique pointer value that can later be successfully
    passed to free().
	
	integer overflow issue: If the multiplication of nmemb and size would result 
	in integer overflow, then calloc() returns an error.
	
	By contrast, an integer overflow would not be detected in the following call 
	to malloc(), with the result that an incorrectly sized block of memory would 
	be allocated:

        malloc(nmemb * size);
	
	The calloc() function has two parameters:
		amount - Specifies the amount of items to allocate
		size - Specifies the size of each item measured in bytes

RETURN VALUE
	return a pointer to  the  allocated memory or NULL

LOGIC
	1. declare a pointer to allocate memory and it can be returned later
	2. declare a variable for malloc() allocates all memory needed
	3. if nmemb or size is 0, return NULL
	4. else nmemb or size is not 0, set memory to 0; return the pointer
*/

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	allmem;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	else
	{
		allmem = nmemb * size;
		ptr = malloc(allmem);
		if (!ptr)
			return (NULL);
		else
			ft_bzero(ptr, allmem);
		return (ptr);
	}
} */