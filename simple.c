/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 12:45:30 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/07 12:45:30 by anonymous     ########   odam.nl         */
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

void	simple(t_list *stackA)
{
	int		counter = 0;
	int		lstsize = ft_lstsize(stackA);
	int		operations = 0;
	while (1)
	{
		if (counter++ < lstsize - 1)
			eval_swap(stackA);
		else
			counter = 0;
		// print_stack(stackA, 'A');
		if (is_unsorted(stackA) == 0)
			break;
		shift_downA(&stackA);
		// print_stack(stackA, 'A');
		operations += 2;
	}
	print_stack(stackA, 'A');
	printf("SIMPLE: ");
	printf("%d numbers in %d operations", lstsize, operations);
}