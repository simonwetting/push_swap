/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turk.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 13:00:05 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/09 16:29:30 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	repeat_rotate(void (*f)(t_data *, int), int times, t_data *data, int stack)
{
	int		n;

	n = 0;
	while (n++ < times)
		f(data, stack);
}

int		stack_is_split(t_data *d, int stack)
{
	int	c_size;
	int	counter;
	//int	test;

	printf("is the stack split?\n");
	counter = 0;
	while (d->stacks[stack])
	{
		printf("Chunk_id = %d\n",find_chunk(d->stacks[stack]->content, d->chunks, d->numbers));
		c_size = chunksize(d->chunks, find_chunk(d->stacks[stack]->content, d->chunks, d->numbers));
		printf("chunk %d of size %d\n", find_chunk(d->stacks[stack]->content, d->chunks, d->numbers), c_size);
		printf("test1");
		write(1, "test", 4);
		if (c_size > 5)
			return (0);
		write(1, "tes2", 4);
		printf("test2");
		repeat_rotate(&shift_up_stack, c_size, d, stack);
		//test = ft_lstsize(d->stacks[stack]);
		write(1, "tes3", 4);
		printf("test3");
		if (counter++ > d->chunk_count)
			return (1);
	}
	return (1);
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
		printf("Turk4");
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