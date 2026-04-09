/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchen <nchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:14:18 by chennating        #+#    #+#             */
/*   Updated: 2026/04/09 11:06:17 by nchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void selection_sort(int *array, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	tmp;

	if (!array || size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j ++;
		}
		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
		}
		i ++;
	}
}

static int	*list_to_array(t_list *list)
{
	int	*array;
	int	i;

	array = malloc (sizeof(int) * ft_lstsize(list));
	if (!array)
		return (NULL);
	i = 0;
	while (list)
	{
		array[i] = list->content;
		i ++;
		list = list->next;
	}
	return (array);
}

static int	chunk_size(t_list *stack)
{
	int	i;

	i = 1;
	if(ft_lstsize(stack) <= 0)
		return (0);
	while (i * i < ft_lstsize(stack))
		i ++;
	return (i);
}

static int	in_chunk(t_list *stack, int low_value, int high_value)
{
	return (stack->content >= low_value && stack->content <= high_value);
}

static void	push_chunk(t_list *stackA, t_list *stackB, int *rank, int low, int high)
{
	int	low_value;
	int	high_value;
	int	target_count;
	int	pushed;

	low_value = rank[low];
	high_value = rank[high];
	target_count = high - low + 1;
	pushed = 0 ;
	while (pushed < target_count)
	{
		if (in_chunk(stackA, low_value, high_value))
		{
			pushB(stackA, stackB);
			pushed ++;
		}
		else
			shift_upA(stackA);
	}
}

void	chunk_based_sorting(t_list **stackA, t_list **stackB)
{
	int	size;
	int	rank;
	int	chunk;
	int	low;
	int	high;

	size = ft_lstsize(*stackA);
	rank = list_to_array(*stackA);
	selection_sort(rank, size);
	chunk = chunk_size(*stackA);
	low = 0;
	while (low < size)
	{
		high = low + chunk - 1;
		if (high >= size)
			high = size - 1;
		push_chunk(*stackA, *stackB, low, high);
		low = high + 1;
	}
	free(rank);
}
