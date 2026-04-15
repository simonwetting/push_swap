/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_chunks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 14:04:34 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 14:05:02 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_chunk(t_data *data, int chunk_id)
{
	printf("Chunk %d LOW: %d  HIGH: %d\n", chunk_id, data->chunks[chunk_id][LOW], data->chunks[chunk_id][HIGH]);
}

void	print_chunks(t_data *data)
{
	int		n;
	int		c_size;
	int		n_index;
	int		status;

	n = -1;
	while (++n < data->chunk_count)
	{
		c_size = data->chunks[n][HIGH] - data->chunks[n][LOW] + 1;
		printf("chunk [%d] size [%d]\n", n, c_size);
		status = find_stack_for_chunk(data, n);
		if (status == 0)
			printf("Inside stack [A]\n");
		if (status == 1)
			printf("Inside stack [B]\n");
		status = verify_chunk_in_stack(data, n, status);
		if (status != 900900900)
			printf("Though %d is not in this stack, and maybe more\n", status);
		n_index =  data->chunks[n][LOW];
		while (n_index <= data->chunks[n][HIGH])
			printf("%d\n", data->numbers[n_index++]);
	}
}