/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adaptive.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 11:21:31 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 18:00:59 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	adaptive(t_data *data, t_bench *bench)
{
	int		disorder;

	disorder = compute_disorder(data->stacks[A]);
	bench->adaptive = 1;
	if (disorder < 2000)
		bubble(data->stack_a, bench);
	else if (disorder >= 2000 && disorder < 5000)
		four_chunks(data, bench);
	else if (disorder >= 5000 && disorder <= 10000)
		merge_sort(data, bench);
	else
		write(1, "disorder more than 1", 20);
}
