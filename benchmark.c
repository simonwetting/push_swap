/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmark.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:21:10 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 12:21:24 by swetting      ########   odam.nl         */
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

void	benchmark(t_data *data, t_bench *bench)
{
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(bench->disorder / 100, 2);
	ft_putstr_fd(",", 2);
	ft_putnbr_fd(bench->disorder % 100, 2);
	ft_putendl_fd(" %", 2);
	ft_putstr_fd("[bench] disorder:   ", 2);
	print_strategy(bench);
	(void)data;
}
