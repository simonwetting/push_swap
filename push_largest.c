/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_largest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 14:15:09 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 14:16:08 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_number(t_data *data, int i)
{
	t_list	*tmp;
	int		n;

	n = 0;
	tmp = data->stacks[B];
	while (tmp)
	{
		if (tmp->content == i)
			return (n);
		tmp = tmp->next;
		n++;
	}
	return (-1);
}

void	move(t_data *data, int i)
{
	int	lst_size;

	lst_size = ft_lstsize(data->stacks[B]);
	if (i > lst_size - i)
		repeat_rotate(shift_down_stack, lst_size - i, data, B);
	else
		repeat_rotate(shift_up_stack, i, data, B);
	
}

void	push_largest(t_data *data, int *chunk_order)
{
	int		chunk_index;
	int		n;

	chunk_index = -1;
	while (++chunk_index < data->chunk_count)
	{
		n = data->chunks[chunk_order[chunk_index]][HIGH];
		while (n >= data->chunks[chunk_order[chunk_index]][LOW])
		{
			move(data, find_number(data, data->numbers[n]));
			push_to(data, A);
			n--;
		}	
	}
}

int		*index_chunks(t_data *data)
{
	int		*chunk_order;
	int		unsorted;
	int		n;

	chunk_order =  malloc(sizeof(int) * data->chunk_count);
	unsorted = 1;
	n = -1;
	while (++n < data->chunk_count)
		chunk_order[n] = n;
	while (unsorted)
	{
		unsorted = 0;
		n = -1;
		while (++n < data->chunk_count - 1)
			if (data->chunks[chunk_order[n]][LOW] < data->chunks[chunk_order[n + 1]][LOW])
				swap(chunk_order + n, chunk_order + n + 1, &unsorted);
	}
	return (chunk_order);
}