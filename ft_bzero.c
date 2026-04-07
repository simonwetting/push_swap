/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/11 10:01:56 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/25 13:13:28 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*pointer;

	index = -1;
	pointer = (char *)(s);
	while (++index < n)
		pointer[index] = 0;
}

// int		main()
// {
// 	char s[] = "test";

// 	printf("%s\n", s);
// 	ft_bzero(s + 2, 1);
// 	printf("%s\n", s);
// }