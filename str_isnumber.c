/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_isnumber.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 14:56:44 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/20 16:00:28 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_isnumber(char *s)
{
	int		n;

	n = -1;
	while (s[++n])
		if (!ft_isdigit(s[n]))
			return (0);
	return (1);
}

int	str_isnumb_or_space(char *s)
{
	int		n;

	n = -1;
	while (s[++n])
		if (!ft_isdigit(s[n]) && !(s[n] == ' '))
			return (0);
	return (1);
}
