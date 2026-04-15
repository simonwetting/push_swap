/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmark.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:21:10 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/14 17:30:26 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	benchmark(t_data *data, t_bench *bench)
{
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(bench->disorder / 100, 2);
	ft_putstr_fd(",", 2);
	ft_putnbr_fd(bench->disorder % 100, 2);
	ft_putendl_fd(" %", 2);
	(void)data;
}
