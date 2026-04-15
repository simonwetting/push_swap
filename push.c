/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:42:36 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 18:01:05 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_to_b(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*next;

	if (*stack_a == NULL)
	{
		ft_putendl_fd("nothing to push", 1);
		return ;
	}
	if (*stack_b)
		next = *stack_b;
	else
		next = NULL;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = next;
	ft_putendl_fd("pb", 1);
	bench->pb++;
}

void	push_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*next;

	if (*stack_b == NULL)
	{
		ft_putendl_fd("nothing to push", 1);
		return ;
	}
	if (*stack_a)
		next = *stack_a;
	else
		next = NULL;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = next;
	ft_putendl_fd("pa", 1);
	bench->pa++;
}

void	push_to(t_data *data, int stack)
{
	if (stack == A)
		push_to_a(data->stack_a, data->stack_b, data->bench);
	else if (stack == B)
		push_to_b(data->stack_a, data->stack_b, data->bench);
	data->count_ops++;
	update_data(data, 3);
}
