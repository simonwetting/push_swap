/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 14:43:23 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 18:01:05 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_everything(t_data *data)
{
	ft_lstclear(data->stack_a, del);
	ft_lstclear(data->stack_b, del);
	free(data->numbers);
	free(data);
}

void	del(void *p)
{
	free(p);
}