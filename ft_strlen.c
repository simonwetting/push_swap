/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/22 16:03:36 by anonymous     #+#    #+#                 */
/*   Updated: 2026/01/22 16:03:36 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}

// #include <stdio.h>
// int		main(void)
// {
// 	printf("length = %d", ft_strlen("len\0gth"));
// }