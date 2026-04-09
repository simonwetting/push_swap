/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 12:48:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/09 16:44:07 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	push_chunk(t_data *data, int chunk_index)
{
	
}

void	four_chunks(t_data *data)
{
	data->numbers = indexate(data->numbers);
	data->chunks[0][LOW] = 0;	//FIRST CHUNK
	data->chunks[0][HIGH] = ft_lstsize(data->stacks[A]) - 1;	//FIRST CHUNK
	divide_chunk(data->chunks, 0, data);	//DIVIDE the first chunk into two
	push_chunk(data, 1);	//PUSH the second chunk
	
	//DIVIDE CHUNK 1, AND PUSH CHUNK 2 A
	//PUSH CHUNK 2 back to B
	//DIVIDE CHUNK 0, AND PUSH CHUNK 3 to B
	//PUSH CHUNK 0 to B

	//Per Chunk push the largest number first to A.
}