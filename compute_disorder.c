/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_disorder.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 12:59:27 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/13 13:27:45 by swetting      ########   odam.nl         */
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
	while (stack)
	{
		pairs++;
		if (tmp->content > tmp->next->content)
			mistakes++;
		tmp = tmp->next;
	}
	mistakes *= 10000;
	return ((mistakes) / pairs);
}

void	adaptive(t_data *data)
{
	int		disorder = compute_disorder(data->stacks[A]);

	if (disorder < 2000)
		simple(data->stacks[A]);
	else if (disorder >= 2000 && disorder < 5000)
		four_chunks(data);
	else if (disorder >= 5000 && disorder <= 10000)
		turk(data);
	else
		write(1, "disorder more than 1", 20);
}


//mistakes = 0
//total_pairs = 0
//for i from 0 to size(a)-1:
//for j from i+1 to size(a)-1:
//total_pairs += 1
//if a[i] > a[j]:
//mistakes += 1
//return mistakes / total_pairs