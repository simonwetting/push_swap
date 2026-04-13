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
	// int		H1;
	// int		L1;
	int		H2;
	int		L2;
	int		pushed;

	// L1 = data->numbers[data->chunks[split_chunk[0]][LOW]];
	// H1 = data->numbers[data->chunks[split_chunk[0]][HIGH]];
	L2 = data->numbers[data->chunks[chunk_index][LOW]];
	H2 = data->numbers[data->chunks[chunk_index][HIGH]];
	pushed = 0;
	printf("lstsize: %d\n", ft_lstsize(data->stacks[A]));
	printf("chunk 0 %d   %d\n", data->chunks[0][LOW], data->chunks[0][HIGH]);
	printf("chunk 1 %d   %d\n", data->chunks[1][LOW], data->chunks[1][HIGH]);
	printf("c_size %d", data->chunks[chunk_index][HIGH] - data->chunks[chunk_index][LOW] + 1);
	print_chunks(data);
	while (pushed < data->chunks[chunk_index][LOW] - data->chunks[chunk_index][LOW] + 1)
	{
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
	printf("%d   %d\n", data->chunks[0][LOW], data->chunks[0][HIGH]);
	div_chunk(data->chunks, 0, data);	//DIVIDE the first chunk into two
	//print_stacks(data->stacks[A], data->stacks[B]);
	push_chunk(data, 1, A);	//PUSH the second chunk to B
	//print_stacks(data->stacks[A], data->stacks[B]);
	//DIVIDE CHUNK 1, AND PUSH CHUNK 2 A
	//PUSH CHUNK 2 back to B
	//DIVIDE CHUNK 0, AND PUSH CHUNK 3 to B
	//PUSH CHUNK 0 to B

	//Per Chunk push the largest number first to A.
}