/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 14:43:23 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 14:51:13 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_everything(t_data *data)
{
	ft_lstclear(data->stackA, del);
	ft_lstclear(data->stackB, del);
	free(data->numbers);
	free(data);
}

void	del(void *p)
{
	free(p);
}