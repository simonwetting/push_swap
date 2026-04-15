/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adaptive.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 11:21:31 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 11:21:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	adaptive(t_data *data, t_bench *bench)
{
	int		disorder = compute_disorder(data->stacks[A]);

	bench->strategy = 4;
	if (disorder < 2000)
		bubble(data->stackA);
	else if (disorder >= 2000 && disorder < 5000)
		four_chunks(data);
	else if (disorder >= 5000 && disorder <= 10000)
		merge_sort(data);
	else
		write(1, "disorder more than 1", 20);
}