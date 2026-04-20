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

int	bench_arg(char **args)
{
	if (ft_strncmp(args[1], "--bench", 11) == 0
		|| ft_strncmp(args[2], "--bench", 11) == 0)
		return (1);
	return (0);
}
