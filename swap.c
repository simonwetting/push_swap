/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:24:15 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/16 13:01:00 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_top_a(t_list *stack_a, t_bench *bench)
{
	swap_top(stack_a);
	ft_putendl_fd("sa", 1);
	bench->sa++;
}

void	swap_top_b(t_list *stack_b, t_bench *bench)
{
	swap_top(stack_b);
	ft_putendl_fd("sb", 1);
	bench->sb++; 
}

void	swap_top_ab(t_list *stack_a, t_list *stack_b, t_bench *bench)
{
	swap_top_a(stack_a, bench);
	swap_top_b(stack_b, bench);
	ft_putendl_fd("ss", 1);
	bench->ss++;
}


