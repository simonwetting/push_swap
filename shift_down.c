/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_down.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:38:59 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 18:01:05 by swetting      ########   odam.nl         */
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

void	shift_downab(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	shift_down(stack_b);
	shift_down(stack_a);
	ft_putendl_fd("rrr", 1);
	bench->rrr++;
}

void	shift_down_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_downa(data->stack_a, data->bench);
	if (stack_id == B)
		shift_downb(data->stack_b, data->bench);
	update_data(data, stack_id);
	data->count_ops++;
}
