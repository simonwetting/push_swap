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

int		chunksize(int chunks[500][2], int index)
{
	//printf("%d - %d + 1\n", chunks[index][HIGH], chunks[index][LOW]);
	return (chunks[index][HIGH] - chunks[index][LOW] + 1);
}

int		in_chunk(int i, int chunks[500][2], int chunk_index, int *numbers)
{
	int		n;

	n = chunks[chunk_index][LOW];
	while (n <= chunks[chunk_index][HIGH])
		if (i == numbers[n])
			return (1);
	return (0);
}

int		divide_chunk(int chunks[500][2], int chunk_index, t_data *data)
{
	int		c_size;
	int		s_c1;
	int		s_c2;

	//c_size = chunks[chunk_index][HIGH] - chunks[chunk_index][LOW] + 1;
	c_size = chunksize(chunks, chunk_index);
	if (c_size % 2 == 1)
		s_c1 = (c_size + 1) / 2;
	else
		s_c1 = c_size / 2;
	s_c2 = c_size - s_c1;
	//printf("c_size: %d s_c2: %d   s_c1: %d\n", c_size, s_c2, s_c1);
	chunks[data->chunk_count][LOW] = chunks[chunk_index][LOW];
	chunks[data->chunk_count][HIGH] = chunks[chunk_index][LOW] + s_c2 - 1;
	chunks[chunk_index][LOW] = chunks[chunk_index][LOW] + s_c2 ; //+ (c_size % 2 == 1);
	return (data->chunk_count++);
}

int		find_chunk(int i, int chunks[500][2], int *numbers)
{
	int		index;
	int		chunk_index;

	index = 0;
	while (numbers[index] != i)
		index++;
	chunk_index = 0;
	//printf("Low: %d    High: %d   number: %d index: %d\n", chunks[chunk_index][LOW], chunks[chunk_index][HIGH], i, index);\
	//printf("%d  %d\n", chunks[chunk_index][LOW] <= index, chunks[chunk_index][HIGH] >= index);
	//printf("%d\n", (chunks[chunk_index][LOW] <= index && chunks[chunk_index][HIGH] >= index));
	//printf("%d <= %d\n", chunks[chunk_index][HIGH], index);
	while ((chunks[chunk_index][LOW] <= index && chunks[chunk_index][HIGH] >= index) == 0)
		chunk_index++;
	//printf("chunk index: %d\n", chunk_index);
	return (chunk_index);
}

void	repeat_rotate(void (*f)(t_data *, int), int times, t_data *data, int stack)
{
	int		n;

	n = 0;
	while (n++ < times)
		f(data, stack);
}

void	print_chunks(t_data *data)
{
	int		n;

	n = 0;
	while (n < data->chunk_count)
		printf("chunk [%d] size [%d]", n, data->chunks[n][HIGH] - data->chunks[n][LOW] + 1);
}

int		stack_is_split(t_data *d, int stack)
{
	int	c_size;
	int	counter;

	printf("is the stack split?\n");
	counter = 0;
	while (d->stacks[stack])
	{
		printf("Chunk_id = %d\n",find_chunk(d->stacks[stack]->content, d->chunks, d->numbers));
		c_size = chunksize(d->chunks, find_chunk(d->stacks[stack]->content, d->chunks, d->numbers));
		printf("chunk %d of size %d\n", find_chunk(d->stacks[stack]->content, d->chunks, d->numbers), c_size);
		if (c_size > 5)
			return (0);
		repeat_rotate(&shift_up_stack, c_size, d, stack);
		if (counter++ > ft_lstsize(d->stacks[stack]));
			return (1);
	}
}

void	print_chunk(t_data *data, int chunk_id)
{
	printf("Chunk %d LOW: %d  HIGH: %d\n", chunk_id, data->chunks[chunk_id][LOW], data->chunks[chunk_id][HIGH]);
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
		printf("%d >= %d\n", data->stacks[stack]->content, hl[LOW]);
		printf("%d <= %d\n", data->stacks[stack]->content, hl[HIGH]);
		if (data->stacks[stack]->content >= hl[LOW] && data->stacks[stack]->content <= hl[HIGH])
			push(data, 1 - stack);
		else
			shift_up_stack(data, stack);
		n++;
		printf("done pushing/shifting");
	}
}

void	split(t_data *data)
{
	int		numbcount;
	int		split_chunk[2];
	int		c_size;
	int		stack;

	numbcount = ft_lstsize(data->stacks[A]) + ft_lstsize(data->stacks[B]) - 1;
	stack = A;
	while (stack < 3)
	{
		if (stack_is_split(data, stack))
			stack++;
		printf("TURK3\n");
		c_size = chunksize(data->chunks, find_chunk(data->stacks[stack]->content, data->chunks, data->numbers));
		if (c_size > 5)
		{
			printf("c_size < 5\n");
			split_chunk[0] = find_chunk(data->stacks[stack]->content, data->chunks, data->numbers);
			//print_chunk(data, split_chunk[0]);
			split_chunk[1] = divide_chunk(data->chunks, split_chunk[0], data);
			//printf("%d %d\n", split_chunk[0], split_chunk[1]);
			//print_chunk(data, split_chunk[0]);
			//print_chunk(data, split_chunk[1]);
			print_stacks(data->stacks[A], data->stacks[B]);
			splitter(data, stack, c_size, split_chunk);
			print_stacks(data->stacks[A], data->stacks[B]);
			printf("endif\n");
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
	for (int p = 0; p < lstsize; p++)
		printf("[%d] = %d\n", p, data->numbers[p]);
	ft_bzero(data->chunks, 4000);
	data->chunks[0][LOW] = 0;
	data->chunks[0][HIGH] = lstsize - 1;
	data->chunk_count = 1;
	split(data);
	printf("TURKed it!\n");
	// shift_up_stack(data, A);
	// push(data, B);
	//push_to_B(data->stackA, data->stackB);
	//shift_upA(data->stackA);
	//shift_up(data->stackA);
	print_stacks(data->stacks[A], data->stacks[B]);
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