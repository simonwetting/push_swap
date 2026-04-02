/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 18:55:26 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/02 18:05:31 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len_largest(t_list *stackA)
{
	int		len;

	len = 0;
	while (stackA)
	{
		if (ft_strlen(stackA->content) > len)
			len = ft_strlen(stackA->content);
		stackA = stackA->next;
	}
	return (len);
}

void	count(t_list *stack, int numbcount[10], int index)
{
	int		n;

	n = 0;
	while (n < 10)
		numbcount[n++] = 0;
	while (stack)
	{
		if (ft_strlen(stack->content) - index < 0)
			numbcount[0]++;
		else
			numbcount[stack->content[ft_strlen(stack->content) - index]  - '0']++;
		stack = stack->next;
	}
}

void	print_numbcount(int numbcount[10])
{
	int		n;
	n = -1;
	while (++n < 10)
		printf("%dx  %d's\n", numbcount[n], n);
}

void	radix(t_list *stackA, t_list *stackB)
{
	int		numbcount[10];
	int		biggest_len;

	//biggest_len = len_largest(stackA);
	// count(stackA, numbcount, 0);
	// print_numbcount(numbcount);
	
}