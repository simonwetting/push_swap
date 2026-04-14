/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/26 16:35:37 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/25 13:11:51 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>
// int		main(void)
// {
// 	char	*str = "2a";
// 	printf("%d", ft_str_is_numeric(str));
// }