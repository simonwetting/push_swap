/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turk.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 13:00:05 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/13 12:58:14 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int		stack_is_split(t_data *d, int stack)
//{
//	int	c_size;
//	int	counter;
//	//int	test;

//	printf("is the stack split?\n");
//	counter = 0;
//	while (d->stacks[stack])
//	{
//		printf("Chunk_id = %d\n",find_chunk(d->stacks[stack]->content, d->chunks, d->numbers));
//		c_size = chunksize(d->chunks, find_chunk(d->stacks[stack]->content, d->chunks, d->numbers));
//		printf("chunk %d of size %d\n", find_chunk(d->stacks[stack]->content, d->chunks, d->numbers), c_size);
//		printf("test1");
//		write(1, "test", 4);
//		if (c_size > 5)
//			return (0);
//		write(1, "tes2", 4);
//		printf("test2");
//		repeat_rotate(&shift_up_stack, c_size, d, stack);
//		//test = ft_lstsize(d->stacks[stack]);
//		write(1, "tes3", 4);
//		printf("test3");
//		if (counter++ > d->chunk_count)
//			return (1);
//	}
//	return (1);
//}

int		stack_is_split(t_data *d, int stack)
{
	t_list	*tmp;

	tmp = d->stacks[stack];
	while (tmp)
	{
		//printf("chunk found of size: %d", chunksize(d->chunks, find_chunk(tmp->content, d->chunks, d->numbers)));
		if (chunksize(d->chunks, find_chunk(tmp->content, d->chunks, d->numbers)) > 35)
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
		//printf("%d >= %d\n", data->stacks[stack]->content, hl[LOW]);
		//printf("%d <= %d\n", data->stacks[stack]->content, hl[HIGH]);
		if (data->stacks[stack]->content >= hl[LOW] && data->stacks[stack]->content <= hl[HIGH])
			push_to(data, 1 - stack);
		else
			shift_up_stack(data, stack);
		n++;
		//printf("done pushing/shifting");
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
	printf ("%d %d\n", stack_split[A], stack_split[B]);
	while (stack_split[A] == 0 || stack_split[B] == 0)
	{
		if (stack == A)
			printf ("Splitting A!\n");
		if (stack == B)
			printf ("Splitting B!\n");
		c_size = chunksize(data->chunks, find_chunk(data->stacks[stack]->content, data->chunks, data->numbers));
		if (c_size > 35)
		{
			split_chunk[0] = find_chunk(data->stacks[stack]->content, data->chunks, data->numbers);
			split_chunk[1] = divide_chunk(data->chunks, split_chunk[0], data);
			//print_stacks(data->stacks[A], data->stacks[B]);
			splitter(data, stack, c_size, split_chunk);
			//print_stacks(data->stacks[A], data->stacks[B]);
			stack_split[A] = stack_is_split(data, A);
			stack_split[B] = stack_is_split(data, B);
			if (stack_split[stack] == 1 && stack == A)
				stack = B;
			if (stack_split[stack] == 1 && stack == B)
				stack = A;
		}
		else
			repeat_rotate(&shift_up_stack, c_size, data, stack);
	}
	printf("done splitting\n");
}

void	turk(t_data *data)
{
	int	lstsize;
	int	*chunk_order;

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
	//print_stacks(data->stacks[A], data->stacks[B]);
	print_chunks(data);
	while (data->stacks[A])
		push_to(data, B);
	print_stacks(data->stacks[A], data->stacks[B]);
	chunk_order = index_chunks(data);
	//for (int n = 0; n < data->chunk_count; n++)
	//	printf("%d\n", chunk_order[n]);
	for (int n = 0; n < data->chunk_count; n++)
		printf("%d\n", data->chunks[chunk_order[n]][LOW]);
	push_largest(data, chunk_order);
	print_stacks(data->stacks[A], data->stacks[B]);
	printf("Sorted %d numbers in %d operations\n %d ops per number\n", ft_lstsize(data->stacks[A]), data->count_ops, data->count_ops / ft_lstsize(data->stacks[A]));
	//for (int n = 0; n < ft_lstsize(data->stacks[A]); n++)
	//	printf("[%d] %d\n", n, data->numbers[n]);
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