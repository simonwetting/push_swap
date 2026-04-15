/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:24:15 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 12:42:35 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_topA(t_list *stackA, t_bench *bench)
{
	swap_top(stackA);
	ft_putendl_fd("sa", 1);
	bench->sa++;
}

void	swap_topB(t_list *stackB, t_bench *bench)
{
	swap_top(stackB);
	ft_putendl_fd("sb", 1);
	bench->sb++; 
}

void	swap_topAB(t_list *stackA, t_list *stackB, t_bench *bench)
{
	swap_topA(stackA, bench);
	swap_topB(stackB, bench);
	ft_putendl_fd("ss", 1);
	bench->ss++;
}


