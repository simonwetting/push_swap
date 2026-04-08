/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chennating <chennating@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:14:18 by chennating        #+#    #+#             */
/*   Updated: 2026/04/08 23:27:00 by chennating       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_pair
{
	t_list	*node;
	int		rank;
}			t_pair;

static void sort(t_list *list)
{
	t_list	*current;
	t_list	*new;
	t_list	*min;

	if (!list || !list->next)
		return ;
	current = list;
	new = list->next;
	min = current;
	while (current)
	{
		new = current->next;
		while (new)
		{
			if (min > new)
				min = new;
			new = new->next;
		}
		current = current->next;
	}
}

static int	chunk_size(t_list **stack)
{
	int	i;

	i = 1;
	if(ft_lstsize(*stack) <= 0)
		return (0);
	while (i * i < ft_lstsize(*stack))
		i ++;
	return (i);
}

static t_pair	create_index(t_list *stack)
{
	t_pair	index;
	int		i;

	i = 0;
	while (stack)
	{
		index->node = copy;
		index->rank = i;
		copy = copy->next;
		i++;
	}
	return (index);
}

void	chunk_based_sorting(t_list **stackA, t_list **stackB)
{
	t_list	*copy;
	t_pair	index;

	copy = *stackA;
	sort(copy);
	index = create_index(copy);

//我需要把属于该chunk的node留下，不属于的放到别的地方（b)
}
