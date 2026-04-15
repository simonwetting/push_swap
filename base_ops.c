/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_ops.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:35:59 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 17:49:16 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_top(t_list *stack)
{
	int		tmp;

	tmp = stack->next->content;
	stack->next->content = stack->content;
	stack->content = tmp;
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

void	repeat_rotate(void (*f)(t_data *, int),
						int times, t_data *data, int stack)
{
	int		n;

	n = 0;
	while (n++ < times)
		f(data, stack);
}
