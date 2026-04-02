/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/02 10:17:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/02 10:17:16 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	swap_and_shift(t_list **stackA)
{
	swap_topA(*stackA);
	shift_upA(stackA);
	return (ft_lstsize(*stackA));
}

void	bubble(t_list **stackA)
{
	int		unsorted;

	while (unsorted)
	{
		unsorted = ft_lstsize(*stackA);
		while ((*stackA)->next)
			if (ft_strncmp((*stackA)->content, (*stackA)->next->content, 12) > 0)
				unsorted = swap_and_shift(stackA);
			else
				unsorted--;
	}
}