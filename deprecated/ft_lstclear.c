/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/13 17:29:24 by swetting      #+#    #+#                 */
/*   Updated: 2026/03/25 13:27:09 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		del((*lst)->content);
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
// printf("freeing>%p\n", nodes[index]);

// t_list	**nodes;
	// t_list	*head;
	// int		index;
	// int		size;

	// head = *lst;
	// size = ft_lstsize(head);
	// nodes = malloc(sizeof(t_list *) * size + 1);
	// if (!nodes)
	// 	return ;
	// index = 0;
	// while (head)
	// {
	// 	nodes[index++] = head;
	// 	head = head->next;
	// }
	// nodes[index] = 0;
	// index = -1;
	// while (nodes[++index])
	// 	del(nodes[index]);
	// *lst = 0;
	// free(nodes);
