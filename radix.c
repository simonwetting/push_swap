/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 18:55:26 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/01 18:55:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len_largest(t_list *stackA)
{
	int		len;

	len = 0;
	while (stackA)
	{
		if (ft_strlen(stackA->content) > len)
			len = ft_strlen(stackA->content);
		stackA = stackA->next;
	}
}

void	radix(t_list *stackA, t_list *stackB)
{
	int		count_numbers[10];
	int		biggest_len;

	biggest_len = len_largest(stackA);
	
}