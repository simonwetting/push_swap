/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:42:36 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 17:53:16 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_to_b(t_list **stackA, t_list **stackB, t_bench *bench)
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
	bench->pb++; 
}

void	push_to_a(t_list **stackA, t_list **stackB, t_bench *bench)
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
	bench->pa++;
}

void	push_to(t_data *data, int stack)
{
	if (stack == A)
		push_to_a(data->stackA, data->stackB, data->bench);
	else if (stack == B)
		push_to_b(data->stackA, data->stackB, data->bench);
	data->count_ops++;
	update_data(data, 3);
}