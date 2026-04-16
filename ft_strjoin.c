/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 10:46:52 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/25 12:06:31 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;
	char	*output;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	output = malloc(len_s1 + len_s2 + 1);
	if (!output)
		return (NULL);
	index = -1;
	while (++index < len_s1)
		output[index] = s1[index];
	index = -1;
	while (++index < len_s2)
		output[len_s1 + index] = s2[index];
	output[len_s1 + index] = 0;
	return (output);
}
