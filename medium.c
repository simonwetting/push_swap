/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 12:48:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 15:02:48 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_chunk(t_data *data, int chunk_index, int stack)
{
	int	h;
	int	l;
	int	pushed;

	l = data->numbers[data->chunks[chunk_index][LOW]];
	h = data->numbers[data->chunks[chunk_index][HIGH]];
	pushed = 0;
	while (pushed < data->chunks[chunk_index][HIGH] -
			data->chunks[chunk_index][LOW] + 1)
	{
		if ((data->stacks[stack]->content >= l
				&& data->stacks[stack]->content <= h))
		{
			push_to(data, 1 - stack);
			pushed++;
		}
		else
			shift_up_stack(data, stack);
	}
}

void	four_chunks(t_data *data, t_bench *bench)
{
	int	chunk_order[4];

	chunk_order[0] = 0;
	chunk_order[1] = 3;
	chunk_order[2] = 1;
	chunk_order[3] = 2;
	bench->strategy = 2;
	data->numbers = indexate(data->stacks[A]);
	data->chunks[0][LOW] = 0;
	data->chunks[0][HIGH] = ft_lstsize(data->stacks[A]) - 1;
	data->chunk_count = 1;
	divide_chunk(data->chunks, 0, data);
	push_chunk(data, 1, A);
	divide_chunk(data->chunks, 1, data);
	push_chunk(data, 2, B);
	push_chunk(data, 2, A);
	divide_chunk(data->chunks, 0, data);
	push_chunk(data, 3, A);
	push_chunk(data, 0, A);
	push_largest(data, chunk_order);
}
