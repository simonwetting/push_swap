/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench_arg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 13:16:31 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/20 13:19:19 by swetting      ########   odam.nl         */
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
