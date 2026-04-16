/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/11 13:09:17 by swetting      #+#    #+#                 */
/*   Updated: 2026/03/25 13:29:20 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;
	char	*p_src;
	char	*p_dest;

	if (!dest && !src)
		return (NULL);
	p_src = (char *)src;
	p_dest = (char *)dest;
	index = -1;
	while (++index < n)
		p_dest[index] = p_src[index];
	return (dest);
}

// int		main()
// {
// 	// char s[] = "test";

// 	// printf("%s\n", s);
// 	// ft_memcpy(s + 1, "ab", 2);
// 	// printf("%s\n", s);
// 	int		array[] = {1, 2, 3 , 4};
// 	// int		array2[] = {500, 500};
// 	for (int n = 0; n < 4; n ++)
// 		printf("%d\n", array[n]);
// 	ft_memcpy(array + 1, array, 8);
// 	printf("\n");
// 	for (int n = 0; n < 4; n ++)
// 		printf("%d\n", array[n]);
// }