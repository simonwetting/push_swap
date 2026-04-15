/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:25:31 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 14:41:22 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	update_data(t_data *data, int stack_id)
{
	if (stack_id == A || stack_id == 3)
	{
		data->p_stacks[A] = data->stackA;
		data->stacks[A] = *(data->stackA);
	}
	if (stack_id == B || stack_id == 3)
	{
		data->p_stacks[B] = data->stackB;
		data->stacks[B] = *(data->stackB);
	}
}

int		find_stack_for_number(t_data *data, int i)
{
	t_list	*tmp;

	tmp = data->stacks[A];
	while (tmp)
	{
		if (tmp->content == i)
			return (A);
		tmp = tmp->next;
	}
	tmp = data->stacks[B];
	while (tmp)
	{
		if (tmp->content == i)
			return (B);
		tmp = tmp->next;
	}
	return (-1);
}