/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_up.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:39:07 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 17:52:47 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	shift_up_a(t_list **stack, t_bench *bench)
{
	shift_up(stack);
	ft_putendl_fd("ra", 1);
	bench->ra++;
}

void	shift_up_b(t_list **stack, t_bench *bench)
{
	shift_up(stack);
	ft_putendl_fd("rb", 1);
	bench->rb++; 
}

void	shift_up_ab(t_list **stackA, t_list **stackB, t_bench *bench)
{
	shift_up(stackA);
	shift_up(stackB);
	ft_putendl_fd("rr", 1);
	bench->rr++; 
}

void	shift_up_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_up_a(data->stackA, data->bench);
	if (stack_id == B)
		shift_up_b(data->stackB, data->bench);
	update_data(data, stack_id);
	data->count_ops++;
}