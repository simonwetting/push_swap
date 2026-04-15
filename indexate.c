/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 10:35:28 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/09 11:44:42 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(int *a, int *b,  int *unsorted)
{
	int tmp;

	//printf("%d > %d\n", *a, *b);
	tmp  = *a;
	*a = *b;
	*b = tmp;
	*unsorted = 1;
}


int		*indexate(t_list *stack)
{
	int		*numbers;
	int		n;
	int		unsorted;
	int		size;

	size = ft_lstsize(stack);
	numbers = malloc(size * sizeof(int));
	n = 0;
	while (stack)
	{
		numbers[n++]= stack->content;
		stack = stack->next;
	}
	unsorted = 1;
	while (unsorted)
	{
		unsorted = 0;
		n = -1;
		while (++n < size - 1)
			if (numbers[n] > numbers[n + 1])
				swap(numbers + n, numbers + n + 1, &unsorted);
	}
	return (numbers);
}