/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_chunks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 14:04:34 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 14:56:00 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

//void	print_chunk(t_data *data, int chunk_id)
//{
//	printf("Chunk %d LOW: %d  HIGH: %d\n", chunk_id, data->chunks[chunk_id][LOW], data->chunks[chunk_id][HIGH]);
//}

//void	print_chunks(t_data *data)
//{
//	int		n;
//	int		c_size;
//	int		n_index;
//	int		status;

//	n = -1;
//	while (++n < data->chunk_count)
//	{
//		c_size = data->chunks[n][HIGH] - data->chunks[n][LOW] + 1;
//		printf("chunk [%d] size [%d]\n", n, c_size);
//		status = find_stack_for_chunk(data, n);
//		if (status == 0)
//			printf("Inside stack [A]\n");
//		if (status == 1)
//			printf("Inside stack [B]\n");
//		status = verify_chunk_in_stack(data, n, status);
//		if (status != 900900900)
//			printf("Though %d is not in this stack, and maybe more\n", status);
//		n_index =  data->chunks[n][LOW];
//		while (n_index <= data->chunks[n][HIGH])
//			printf("%d\n", data->numbers[n_index++]);
//	}
//}

//int		verify_chunk_in_stack(t_data *data, int chunk_index, int stack)
//{
//	int		numb_index;

//	numb_index = data->chunks[chunk_index][LOW];
//	while (numb_index <= data->chunks[chunk_index][HIGH])
//		if (find_stack_for_number(data, data->numbers[numb_index++]) != stack)
//			return (data->numbers[--numb_index]);
//	return (900900900);
//}
//int		in_chunk(int i, int chunks[500][2], int chunk_index, int *numbers)
//{
//	int		n;

//	n = chunks[chunk_index][LOW];
//	while (n <= chunks[chunk_index][HIGH])
//		if (i == numbers[n])
//			return (1);
//	return (0);
//}