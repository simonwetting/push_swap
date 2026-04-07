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

#define LOW 0
#define HIGH 1

int		in_chunk(int i, int chunks[500][2], int chunk_index, int *numbers)
{
	int		n;

	n = chunks[chunk_index][LOW];
	while (n <= chunks[chunk_index][HIGH])
		if (i == numbers[n])
			return (1);
	return (0);
}

void	search_and_push(t_list **stacks[2], int chunks[500][2], int stack, int *)
{
	//while (in_chunk)
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
	chunks[index_newchunk][HIGH] = chunks[chunk_index][LOW] + s_c1;
	chunks[chunk_index][LOW] = chunks[index_newchunk][HIGH] -  s_c2;
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

void	rotate(void (*f)(t_list **), int times, t_list **stack)
{
	int		n;

	n = 0;
	while (n++ < times)
		f(stack);
}

void	split(t_list **stacks[2], int chunks[500][2], int *numbers)
{
	int		numbcount;
	int		chunkcount;
	int		split_chunk[2];
	int		c_size;
	int		stack;

	numbcount = ft_lstsize(*(stacks[A]) )+ ft_lstsize(*(stacks[A]) - 1);
	chunkcount = 1;
	c_size = chunksize(chunks, find_chunk((*(stacks[A]))->content, chunks, numbers));
	stack = A;
	while (stack < 3)
	{
		if (c_size < 5)
		{
			split_chunk[0] = find_chunk((*(stacks[stack]))->content, chunks, numbers);
			split_chunk[1] = divide_chunk(chunks, split_chunk[0]);
			
		}
		else
			rotate(&shift_upA, c_size, stacks[A]);
	}

}

void	turk(t_list **stacks[2])
{
	int	*numbers;
	int	lstsize;
	int	chunks[500][2];

	numbers = indexate(stacks[A]);
	lstsize = ft_lstsize(stacks[A]);
	ft_bzero(&chunks, 4000);
	chunks[0][LOW] = 0;
	chunks[0][HIGH] = lstsize - 1;
	for (int p = 0; p < lstsize; p++)
		printf("[%d] = %d\n", p, numbers[p]);
}