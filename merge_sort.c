/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 13:00:05 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 15:06:45 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stack_is_split(t_data *d, int stack)
{
	t_list	*tmp;

	tmp = d->stacks[stack];
	while (tmp)
	{
		if (chunksize(d->chunks,
				find_chunk(tmp->content, d->chunks, d->numbers)) > 35)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	splitter(t_data *data, int stack, int c_size, int split_chunk[2])
{
	int		n;
	int		hl[2];

	hl[LOW] = data->numbers[data->chunks[split_chunk[1]][LOW]];
	hl[HIGH] = data->numbers[data->chunks[split_chunk[1]][HIGH]];
	n = 0;
	while (n < c_size)
	{
		if (data->stacks[stack]->content >= hl[LOW]
			&& data->stacks[stack]->content <= hl[HIGH])
			push_to(data, 1 - stack);
		else
			shift_up_stack(data, stack);
		n++;
	}
}

void	split(t_data *data)
{
	int		split_chunk[2];
	int		c_size;
	int		stack;
	int		stack_split[2];

	stack = A;
	stack_split[A] = stack_is_split(data, A);
	stack_split[B] = 0;
	while (stack_split[A] == 0 || stack_split[B] == 0)
	{
		c_size = chunksize(data->chunks, find_chunk(data->stacks[stack]->content, data->chunks, data->numbers));
		if (c_size > 35)
		{
			split_chunk[0] = find_chunk(data->stacks[stack]->content, data->chunks, data->numbers);
			split_chunk[1] = divide_chunk(data->chunks, split_chunk[0], data);
			splitter(data, stack, c_size, split_chunk);
		}
		else
			repeat_rotate(shift_up_stack, c_size, data, stack);
		stack_split[A] = stack_is_split(data, A);
		stack_split[B] = stack_is_split(data, B);
		if (stack_split[stack] == 1 && stack == A)
			stack = B;
		if (stack_split[stack] == 1 && stack == B)
			stack = A;
	}
}

void	merge_sort(t_data *data, t_bench *bench)
{
	int	lstsize;
	int	*chunk_order;

	bench->strategy = 3;
	data->numbers = indexate(data->stacks[A]);
	lstsize = ft_lstsize(data->stacks[A]);
	ft_bzero(data->chunks, 4000);
	data->chunks[0][LOW] = 0;
	data->chunks[0][HIGH] = lstsize - 1;
	data->chunk_count = 1;
	split(data);

	while (data->stacks[A])
		push_to(data, B);
	chunk_order = index_chunks(data);
	push_largest(data, chunk_order);
}
