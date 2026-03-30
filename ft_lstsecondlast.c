/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsecondlast.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/30 18:56:45 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/30 18:56:45 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsecondlast(t_list *lst)
{
	t_list	*second_last;
	if (lst == 0)
		return (0);
	while (lst->next)
	{
		second_last = lst;
		lst = lst->next;
	}
	return (second_last);
}
