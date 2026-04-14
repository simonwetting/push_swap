/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 12:48:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/13 13:40:27 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	push_chunk(t_data *data, int chunk_index, int stack)
{
	int		H2;
	int		L2;
	int		pushed;

	L2 = data->numbers[data->chunks[chunk_index][LOW]];
	H2 = data->numbers[data->chunks[chunk_index][HIGH]];
	pushed = 0;
	// printf("lstsize: %d\n", ft_lstsize(data->stacks[A]));
	// printf("chunk 0 %d   %d\n", data->chunks[0][LOW], data->chunks[0][HIGH]);
	// printf("chunk 1 %d   %d\n", data->chunks[1][LOW], data->chunks[1][HIGH]);
	// printf("c_size %d", data->chunks[chunk_index][HIGH] - data->chunks[chunk_index][LOW] + 1);
	// print_chunks(data);
	while (pushed < data->chunks[chunk_index][HIGH] - data->chunks[chunk_index][LOW] + 1)
	{
		// printf("c_size %d\n", chunksize(data->chunks, chunk_index));
		if ((data->stacks[stack]->content >= L2 && data->stacks[stack]->content <= H2))
		{
			push_to(data, 1 - stack);
			pushed++;
		}
		else
			shift_up_stack(data, stack);
	}
}

void	four_chunks(t_data *data)
{
	data->numbers = indexate(data->stacks[A]);
	data->chunks[0][LOW] = 0;	//FIRST CHUNK
	data->chunks[0][HIGH] = ft_lstsize(data->stacks[A]) - 1;	//FIRST CHUNK
	data->chunk_count = 1;
	// printf("%d   %d\n", data->chunks[0][LOW], data->chunks[0][HIGH]);
	divide_chunk(data->chunks, 0, data);	//DIVIDE the first chunk into two
	//print_stacks(data->stacks[A], data->stacks[B]);
	push_chunk(data, 1, A);	//PUSH the second chunk to B
	// print_stacks(data->stacks[A], data->stacks[B]);
	//DIVIDE CHUNK 1, AND PUSH CHUNK 2 A
	divide_chunk(data->chunks, 1, data);
	push_chunk(data, 2, B);
	// print_stacks(data->stacks[A], data->stacks[B]);
	// //PUSH CHUNK 2 back to B
	push_chunk(data, 2, A);
	// print_stacks(data->stacks[A], data->stacks[B]);
	// //DIVIDE CHUNK 0, AND PUSH CHUNK 3 to B
	divide_chunk(data->chunks, 0, data);
	push_chunk(data, 3, A);
	// print_stacks(data->stacks[A], data->stacks[B]);
	// //PUSH CHUNK 0 to B
	push_chunk(data, 0, A);
	// print_chunks(data);
	// print_stacks(data->stacks[A], data->stacks[B]);
	//Per Chunk push the largest number first to A.
	int		chunk_order[4] = {0, 3, 1, 2};
	// h = 0, l = 1
	// ll = 2, hl = 1
	// lh = 3 
	push_largest(data, chunk_order);
	print_stacks(data->stacks[A], data->stacks[B]);
	printf("MEDIUM: ");
	printf("Sorted %d numbers in %d operations\n %d ops per number\n", ft_lstsize(data->stacks[A]), data->count_ops, data->count_ops / ft_lstsize(data->stacks[A]));
}