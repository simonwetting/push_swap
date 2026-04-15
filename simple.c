/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 12:45:30 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 12:21:41 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_unsorted(t_list *stack)
{
	int		unsorted;

	unsorted  = 0;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			unsorted = 1;
		stack =  stack->next;
	}
	return (unsorted);
}

static void	eval_swap(t_list *stack)
{
	// printf("eval swap\n%d\n", (stack)->content - (stack)->next->content);
	if ((stack)->content > (stack)->next->content)
	{
		// printf("\n%d > %d\n", (stack)->content, (stack)->next->content);
		swap_topA(stack);
	}
	// else
	// 	printf("not swapping %d < %d \n", (stack)->content, (stack)->next->content);
	// printf("done\n");
}

void	bubble(t_list **stackA, t_bench *bench)
{
	int		counter;
	int		lstsize = ft_lstsize(*stackA);
	int		operations;

	counter = 0;
	lstsize = ft_lstsize(*stackA);
	operations = 0;
	bench->strategy = 1;
	while (1)
	{
		if (counter++ < lstsize - 1)
			eval_swap(*stackA);
		else
			counter = 0;
		if (is_unsorted(*stackA) == 0)
			break;
		shift_downA(stackA);
		operations += 2;
	}
	print_stack(*stackA, 'A');
	printf("SIMPLE: ");
	printf("%d numbers in %d operations", lstsize, operations);
}
