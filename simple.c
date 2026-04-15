/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 12:45:30 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 17:56:37 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_unsorted(t_list *stack)
{
	int		unsorted;

	unsorted = 0;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			unsorted = 1;
		stack = stack->next;
	}
	return (unsorted);
}

static void	eval_swap(t_list *stack, t_bench *bench)
{
	if ((stack)->content > (stack)->next->content)
		swap_topA(stack, bench);
}

void	bubble(t_list **stackA, t_bench *bench)
{
	int		counter;
	int		lstsize;
	int		operations;

	counter = 0;
	lstsize = ft_lstsize(*stackA);
	operations = 0;
	bench->strategy = 1;
	while (1)
	{
		if (counter++ < lstsize - 1)
			eval_swap(*stackA, bench);
		else
			counter = 0;
		if (is_unsorted(*stackA) == 0)
			break ;
		shift_downa(stackA, bench);
		operations += 2;
	}
}
