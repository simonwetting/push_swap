/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turk.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 13:00:05 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/07 13:00:05 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		in_chunk(int i, int chunks[500][2], int chunk_index, int *numbers)
{
	int		n;

	n = chunks[chunk_index][LOW];
	while (n <= chunks[chunk_index][HIGH])
		if (i == numbers[n])
			return (1);
	return (0);
}

int		divide_chunk(int chunks[500][2], int chunk_index)
{
	int		chunksize;
	int		s_c1;
	int		s_c2;
	int		index_newchunk;

	chunksize = chunks[chunk_index][HIGH] - chunks[chunk_index][LOW];
	if (chunksize % 2 == 1)
		s_c1 = (chunksize + 1) / 2;
	else
		s_c1 = chunksize / 2;
	s_c2 = chunksize - s_c1;
	index_newchunk = 0;
	while (chunks[index_newchunk])
		index_newchunk++;
	chunks[index_newchunk][LOW] = chunks[chunk_index][LOW];
	chunks[index_newchunk][HIGH] = chunks[chunk_index][LOW] + s_c2;
	chunks[chunk_index][LOW] = chunks[index_newchunk][HIGH] -  s_c1;
	return (index_newchunk);
}

int		find_chunk(int i, int chunks[500][2], int *numbers)
{
	int		index;
	int		chunk_index;

	index = 0;
	while (numbers[index] != i)
		index++;
	chunk_index = 0;
	while ((chunks[chunk_index][LOW] >= index && chunks[chunk_index][HIGH] <= index) == 0)
		chunk_index++;
	return (chunk_index);
}

int		chunksize(int chunks[500][2], int index)
{
	return (chunks[index][HIGH] - chunks[index][LOW] + 1);
}

void	repeat_rotate(void (*f)(t_data *, int), int times, t_list *data, int stack)
{
	int		n;

	n = 0;
	while (n++ < times)
		f(data, stack);
}

void	splitter(t_data *data, int stack, int c_size, int hl[2])
{
	int		n;

	n = 0;
	while (n < c_size)
	{
		if (data->stacks[stack]->content >= hl[LOW] && data->stacks[stack]->content <= hl[HIGH])
			push(data->stackA, data->stackB, stack);
		else
			shift_up_stack(data, stack);
	}
}

int		stack_is_split(t_data *data, int stack)
{
	int	c_size;

	while (data->stacks[stack])
	{
		c_size = chunksize(data->chunks, find_chunk(data->stacks[stack]->content, data->chunks, data->numbers));
		if (c_size > 5)
			return (0);
		repeat_rotate(&shift_up_stack, c_size, data, stack);
	}
	return (1);
}

void	split(t_data *data)
{
	int		numbcount;
	int		split_chunk[2];
	int		c_size;
	int		stack;
	int		hl[2];

	numbcount = ft_lstsize(*(data->stackA))+ ft_lstsize(*(data->stackA) - 1);
	stack = A;
	while (stack < 3)
	{
		if (stack_split(data, stack))
			stack++;
		c_size = chunksize(data->chunks, find_chunk(data->stacks[stack]->content, data->chunks, data->numbers));
		if (c_size < 5)
		{
			split_chunk[0] = find_chunk(data->stacks[stack]->content, data->chunks, data->numbers);
			split_chunk[1] = divide_chunk(data->chunks, split_chunk[0]);
			hl[LOW] = data->numbers[data->chunks[split_chunk[1]][LOW]];
			hl[HIGH] = data->numbers[data->chunks[split_chunk[1]][HIGH]];
			splitter(data, split_chunk, stack, hl);
			print_stacks(data->stacks[A], data->stacks[B]);
		}
		else
			repeat_rotate(&shift_up_stack, c_size, data, stack);
	}
}

void	turk(t_data *data)
{
	int	lstsize;

	data->numbers = indexate(data->stacks[A]);
	lstsize = ft_lstsize(data->stacks[A]);
	ft_bzero(data->chunks, 4000);
	data->chunks[0][LOW] = 0;
	data->chunks[0][HIGH] = lstsize - 1;
	for (int p = 0; p < lstsize; p++)
		printf("[%d] = %d\n", p, data->numbers[p]);
}


//void	chunk_to_stack(t_list **stacks[2], int chunks[500][2], int *numbers, int split_chunk)
//{
//	t_list	**stackA;
//	t_list	**stackB;

//	stackA = stacks[A];
//	stackB = stacks[B];
//	if (in_chunk((*stackA)->content, chunks, numbers))
//}

//void	splitter(t_data *data, int split_chunk[2], int stack)
//{
//	int		l_push;
//	int		h_push;
//	int		l_leave;
//	int		h_leave;

//	l_push = data->numbers[split_chunk[LOW]];
//	h_push = data->numbers[split_chunk[HIGH]];
//	if (stack = A)
//	{
//		while (data->)
//	}
//}