/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_down.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:38:59 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 17:57:23 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	shift_downa(t_list **stack, t_bench *bench)
{
	shift_down(stack);
	ft_putendl_fd("rra", 1);
	bench->rra++;
}

void	shift_downb(t_list **stack, t_bench *bench)
{
	shift_down(stack);
	ft_putendl_fd("rrb", 1);
	bench->rrb++;
}

void	shift_downab(t_list **stackA, t_list **stackB, t_bench *bench)
{
	shift_down(stackB);
	shift_down(stackA);
	ft_putendl_fd("rrr", 1);
	bench->rrr++;
}

void	shift_down_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_downa(data->stackA, data->bench);
	if (stack_id == B)
		shift_downb(data->stackB, data->bench);
	update_data(data, stack_id);
	data->count_ops++;
}
