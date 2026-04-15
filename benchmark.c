/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmark.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:21:10 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 13:43:01 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_strategy(t_bench *bench)
{
	if (bench->strategy == 1)
		ft_putendl_fd("Simple", 2);
	if (bench->strategy == 2)
		ft_putendl_fd("Medium", 2);
	if (bench->strategy == 3)
		ft_putendl_fd("Complex", 2);
	if (bench->strategy == 4)
		ft_putendl_fd("Adaptive", 2);
}

int	get_total_ops(t_bench *bench)
{
	return (bench->sa + bench->sb + bench->ss +
			bench->pa + bench->pb +
			bench->ra + bench->rb + bench->rr +
			bench->rra + bench->rrb + bench->rrr);
}

void	print_ops(t_bench *bench)
{
	int		total_ops;

	total_ops = get_total_ops(bench);
	ft_putstr_fd("[bench] total_ops:   ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putchar_fd('\n', 2);

	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putchar_fd('\n', 2);
	
}

void	benchmark(t_bench *bench)
{
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(bench->disorder / 100, 2);
	ft_putstr_fd(",", 2);
	ft_putnbr_fd(bench->disorder % 100, 2);
	ft_putendl_fd("%", 2);
	ft_putstr_fd("[bench] strategy:   ", 2);
	print_strategy(bench);
	print_ops(bench);
}
