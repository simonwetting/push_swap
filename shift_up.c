/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_up.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:39:07 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 18:01:05 by swetting      ########   odam.nl         */
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

void	shift_up_ab(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	shift_up(stack_a);
	shift_up(stack_b);
	ft_putendl_fd("rr", 1);
	bench->rr++;
}

void	shift_up_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_up_a(data->stack_a, data->bench);
	if (stack_id == B)
		shift_up_b(data->stack_b, data->bench);
	update_data(data, stack_id);
	data->count_ops++;
}
