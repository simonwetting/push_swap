/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 16:28:21 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 14:41:55 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		chunksize(int chunks[500][2], int index)
{
	return (chunks[index][HIGH] - chunks[index][LOW] + 1);
}

int		divide_chunk(int chunks[500][2], int chunk_index, t_data *data)
{
	int		c_size;
	int		s_c1;
	int		s_c2;

	c_size = chunksize(chunks, chunk_index);
	if (c_size % 2 == 1)
		s_c1 = (c_size + 1) / 2;
	else
		s_c1 = c_size / 2;
	s_c2 = c_size - s_c1;
	chunks[data->chunk_count][LOW] = chunks[chunk_index][LOW];
	chunks[data->chunk_count][HIGH] = chunks[chunk_index][LOW] + s_c2 - 1;
	chunks[chunk_index][LOW] = chunks[chunk_index][LOW] + s_c2 ;
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
	while ((chunks[chunk_index][LOW] <= index && chunks[chunk_index][HIGH] >= index) == 0)
		chunk_index++;
	return (chunk_index);
}

int		find_stack_for_chunk(t_data *data, int chunk_index)
{
	return (find_stack_for_number(data, data->numbers[data->chunks[chunk_index][LOW]]));
}
int		verify_chunk_in_stack(t_data *data, int chunk_index, int stack)
{
	int		numb_index;

	numb_index = data->chunks[chunk_index][LOW];
	while (numb_index <= data->chunks[chunk_index][HIGH])
		if (find_stack_for_number(data, data->numbers[numb_index++]) != stack)
			return (data->numbers[--numb_index]);
	return (900900900);
}
//int		in_chunk(int i, int chunks[500][2], int chunk_index, int *numbers)
//{
//	int		n;

//	n = chunks[chunk_index][LOW];
//	while (n <= chunks[chunk_index][HIGH])
//		if (i == numbers[n])
//			return (1);
//	return (0);
//}