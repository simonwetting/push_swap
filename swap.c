/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:24:15 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 18:01:05 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_topA(t_list *stack_a, t_bench *bench)
{
	swap_top(stack_a);
	ft_putendl_fd("sa", 1);
	bench->sa++;
}

void	swap_topB(t_list *stack_b, t_bench *bench)
{
	swap_top(stack_b);
	ft_putendl_fd("sb", 1);
	bench->sb++; 
}

void	swap_topAB(t_list *stack_a, t_list *stack_b, t_bench *bench)
{
	swap_topA(stack_a, bench);
	swap_topB(stack_b, bench);
	ft_putendl_fd("ss", 1);
	bench->ss++;
}


