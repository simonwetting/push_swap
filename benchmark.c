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
	if (bench->adaptive == 1)
	{
		if (bench->disorder < 2000)
			ft_putendl_fd("Adaptive / O(n\xC2\xB2)", 2);
		else if (bench->disorder >= 2000 && bench->disorder < 5000)
			ft_putendl_fd("Adaptive /  O(n\xe2\x88\x9an)", 2);
		else if (bench->disorder >= 5000 && bench->disorder <= 10000)
			ft_putendl_fd("Adaptive / O(nlogn)", 2);
	}
	else if (bench->strategy == 1)
		ft_putendl_fd("Simple / O(n\xC2\xB2)", 2);
	else if (bench->strategy == 2)
		ft_putendl_fd("Medium /  O(n\xe2\x88\x9an)", 2);
	else if (bench->strategy == 3)
		ft_putendl_fd("Complex / O(nlogn)", 2);
}

int	get_total_ops(t_bench *bench)
{
	return (bench->sa + bench->sb + bench->ss
		+ bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr);
}

void	print_ops_1(t_bench *bench)
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
}

void	print_ops_2(t_bench *bench)
{
	int		total_ops;

	total_ops = get_total_ops(bench);
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
	print_ops_1(bench);
	print_ops_2(bench);
}
