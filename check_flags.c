/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 16:16:00 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/20 16:07:02 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flag_exists(char *str)
{
	if (ft_strncmp(str, "--simple", 11) == 0
		|| ft_strncmp(str, "--medium", 11) == 0
		|| ft_strncmp(str, "--complex", 11) == 0
		|| ft_strncmp(str, "--adaptive", 11) == 0
		|| ft_strncmp(str, "--bench", 11) == 0)
		return (1);
	return (0);
}

int	flags_cant_coexist(char **args)
{
	if (ft_strncmp(args[1], "--bench", 11 == 0))
		if (ft_strncmp(args[2], "--bench", 11 == 0))
			return (1);
	if (ft_strncmp(args[1], "--simple", 11) == 0
		|| ft_strncmp(args[1], "--medium", 11) == 0
		|| ft_strncmp(args[1], "--complex", 11) == 0
		|| ft_strncmp(args[1], "--adaptive", 11) == 0)
		if (ft_strncmp(args[2], "--simple", 11) == 0
			|| ft_strncmp(args[2], "--medium", 11) == 0
			|| ft_strncmp(args[2], "--complex", 11) == 0
			|| ft_strncmp(args[2], "--adaptive", 11) == 0)
			return (1);
	return (0);
}

int	check_flags(char **args, int argcount)
{
	int		flag_count;

	flag_count = 0;
	if (argcount >= 2)
		if (!str_isnumb_or_space(args[1]))
		{
			if (flag_exists(args[1]))
				flag_count++;
			else
				return (-1);
		}
	if (argcount >= 3)
		if (!str_isnumb_or_space(args[2]))
		{
			if (flag_exists(args[2]))
				flag_count++;
			else
				return (-1);
		}
	if (flag_count == 2)
		if (ft_strncmp(args[2], args[1], 11) == 0)
			return (-1);
	if (flag_count == 2)
		if (flags_cant_coexist(args))
			return (-1);
	return (flag_count);
}
