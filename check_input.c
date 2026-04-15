/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 16:16:00 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 17:14:32 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_duplicates(int argcount, char **args, int flag_count)
{
	int		n;
	int		m;

	n =  flag_count + 1;
	while (n < argcount)
	{
		m = flag_count;
		while (++m < argcount)
			if (ft_strncmp(args[n], args[m], 10) == 0 && n != m)
				return (1);
		n++;
	}
	return (0);	
}

int	str_isnumber(char *s)
{
	int		n;

	n = -1;
	while (s[++n])
		if(!ft_isdigit(s[n]))
			return (0);
	return (1);
}

int	flag_exists(char *str)
{
	printf("flag>%s\n", str);
	if (ft_strncmp(str, "--simple", 11) == 0
		|| ft_strncmp(str, "--medium", 11) == 0
		|| ft_strncmp(str, "--complex", 11) == 0
		|| ft_strncmp(str, "--adaptive", 11) == 0
		|| ft_strncmp(str, "--bench", 11) == 0)
		return (1);
	return (0);
}

int	check_flags(char **args)
{
	int		flag_count;

	flag_count = 0;
	if (!str_isnumber(args[1]))
	{
		if (flag_exists(args[1]))
			flag_count++;
		else
			return (-1);
	}
	if (!str_isnumber(args[2]))
	{
		if (flag_exists(args[2]))
			flag_count++;
		else
			return (-1);
	}
	if (flag_count == 2)
		if (ft_strncmp(args[2], args[1], 11) == 0)
			return (-1);
	return (flag_count);
}

int	check_input(int argcount, char **args)
{
	int		n;
	int		flag_count;

	flag_count = check_flags(args);
	if (flag_count == -1)
		return (1);
	if (check_duplicates(argcount, args, flag_count))
		return (1);
	n = flag_count;
	while (++n < argcount)
		if (!str_isnumber(args[n]))
			return (1);
	return (0);
}