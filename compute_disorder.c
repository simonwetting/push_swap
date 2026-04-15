/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_disorder.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 12:59:27 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 13:44:52 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	compute_disorder(t_list *stack)
{
	t_list	*tmp;
	int		pairs;
	long	mistakes;

	tmp = stack;
	pairs = 0;
	mistakes = 0;
	while (tmp->next)
	{
		pairs++;
		if (tmp->content > tmp->next->content)
			mistakes++;
		tmp = tmp->next;
	}
	mistakes *= 10000;
	return (mistakes / pairs);
}


//mistakes = 0
//total_pairs = 0
//for i from 0 to size(a)-1:
//for j from i+1 to size(a)-1:
//total_pairs += 1
//if a[i] > a[j]:
//mistakes += 1
//return mistakes / total_pairs