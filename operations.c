/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:24:15 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 12:24:31 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_top(t_list *stack)
{
	int		tmp;

	tmp = stack->next->content;
	stack->next->content =  stack->content;
	stack->content = tmp;
}

void	swap_topA(t_list *stackA)
{
	swap_top(stackA);
	 ft_putendl_fd("sa", 1);
}

void	swap_topB(t_list *stackB)
{
	swap_top(stackB);
	 ft_putendl_fd("sb", 1);
}

void	swap_topAB(t_list *stackA, t_list *stackB)
{
	swap_topA(stackA);
	swap_topB(stackB);
	 ft_putendl_fd("ss", 1);
}

void	push_to_B(t_list **stackA, t_list **stackB)
{
	t_list *next;

	if (*stackA == NULL)
	{
		ft_putendl_fd("nothing to push", 1);
		return ;
	}
	if (*stackB)
		next = *stackB;
	else
		next = NULL;
	*stackB = *stackA;
	*stackA = (*stackA)->next;
	(*stackB)->next = next;
	 ft_putendl_fd("pb", 1);
}

void	push_to_A(t_list **stackA, t_list **stackB)
{
	t_list *next;

	if (*stackB == NULL)
	{
		ft_putendl_fd("nothing to push", 1);
		return ;
	}
	if (*stackA)
		next = *stackA;
	else
		next = NULL;
	*stackA = *stackB;
	*stackB = (*stackB)->next;
	(*stackA)->next = next;
	 ft_putendl_fd("pa", 1);
}

void	push_to(t_data *data, int stack)
{
	if (stack == A)
		push_to_A(data->stackA, data->stackB);
	else if (stack == B)
		push_to_B(data->stackA, data->stackB);
	data->count_ops++;
	update_data(data, 3);
}

void	shift_down(t_list **stack)
{
	t_list	*second_last;

	second_last = ft_lstsecondlast(*stack);
	second_last->next->next = *stack;
	*stack = second_last->next;
	second_last->next = NULL;
}

void	shift_up(t_list **stack)
{
	t_list		*second;

	ft_lstlast(*stack)->next = *stack;
	second = (*stack)->next;
	(*stack)->next = NULL;
	*stack = second;
}

void	shift_downA(t_list **stack)
{
	shift_down(stack);
	 ft_putendl_fd("rra", 1);
}

void	shift_downB(t_list **stack)
{
	shift_down(stack);
	 ft_putendl_fd("rrb", 1);
}

void	shift_downAB(t_list **stackA, t_list **stackB)
{
	shift_down(stackB);
	shift_down(stackA);
	ft_putendl_fd("rrr", 1);
}

void	shift_up_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_upA(data->stackA);
	if (stack_id == B)
		shift_upB(data->stackB);
	update_data(data, stack_id);
	data->count_ops++;
}
void	shift_down_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_downA(data->stackA);
	if (stack_id == B)
		shift_downB(data->stackB);
	update_data(data, stack_id);
	data->count_ops++;
}


void	shift_upA(t_list **stack)
{
	shift_up(stack);
	 ft_putendl_fd("ra", 1);
}

void	shift_upB(t_list **stack)
{
	shift_up(stack);
	 ft_putendl_fd("rb", 1);
}

void	shift_upAB(t_list **stackA, t_list **stackB)
{
	shift_up(stackA);
	shift_up(stackB);
	 ft_putendl_fd("rr", 1);
}