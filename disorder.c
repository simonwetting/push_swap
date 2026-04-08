/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chennating <chennating@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:43:26 by chennating        #+#    #+#             */
/*   Updated: 2026/04/08 21:42:34 by chennating       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	compute_disorder(t_list **a)
{
	double	mistakes;
	double	total_pairs;
	t_list	*current;
	t_list	*new;

	mistakes = 0;
	total_pairs = 0;
	current = *a;
	new = (*a)->next;
	while (current)
	{
		new = current->next;
		while (new)
		{
			if (current->content > new->content)
				mistakes ++;
			new = new->next;
			total_pairs ++;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

/*************Testing code******************/
// static	t_list *build_list(int *value, int num)
// {
// 	t_list *list;
// 	int	i = 0;

// 	list = NULL;
// 	while (i < num)
// 	{
// 		ft_lstadd_back(&list, ft_lstnew(value[i]));
// 		i ++;
// 	}
// 	return (list);
// }

// static void print_list(t_list *list)
// {
// 	while (list)
// 	{
// 		printf("%d\n", list->content);
// 		if (list->next)
// 			printf("->");
// 		list = list->next;
// 	}
// }

// int	main()
// {
// 	int		values[] = {5, 4, 3, 1};
// 	t_list	*a;

// 	a = build_list(values, 4);
// 	print_list(a);
// 	printf("disorder = %.3f\n", compute_disorder(&a));
// 	return (0);
// }
