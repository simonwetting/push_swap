/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 12:45:30 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/16 13:00:41 by swetting      ########   odam.nl         */
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
		swap_top_a(stack, bench);
}

void	bubble(t_list **stack_a, t_bench *bench)
{
	int		counter;
	int		lstsize;
	int		operations;

	counter = 0;
	lstsize = ft_lstsize(*stack_a);
	operations = 0;
	bench->strategy = 1;
	while (1)
	{
		if (counter++ < lstsize - 1)
			eval_swap(*stack_a, bench);
		else
			counter = 0;
		if (is_unsorted(*stack_a) == 0)
			break ;
		shift_downa(stack_a, bench);
		operations += 2;
	}
}
