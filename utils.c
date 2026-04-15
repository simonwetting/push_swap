/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 12:25:31 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/15 13:08:32 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	repeat_rotate(void (*f)(t_data *, int), int times, t_data *data, int stack)
{
	int		n;

	n = 0;
	while (n++ < times)
		f(data, stack);
}

void	update_data(t_data *data, int stack_id)
{
	if (stack_id == A || stack_id == 3)
	{
		data->p_stacks[A] = data->stackA;
		data->stacks[A] = *(data->stackA);
	}
	if (stack_id == B || stack_id == 3)
	{
		data->p_stacks[B] = data->stackB;
		data->stacks[B] = *(data->stackB);
	}
}

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%p contains:\ncontent>%d\nnext>%p\n\n", stack, (stack->content), stack->next);
		stack = stack->next;
	}
}

void	print_stacks(t_list *stackA, t_list *stackB)
{
	printf("STACK A:\n");
	while (stackA)
	{
		printf("%d\n", (stackA->content));
		stackA = stackA->next;
	}
	printf("STACK B:\n");
	while (stackB)
	{
		printf("%d\n", (stackB->content));
		stackB = stackB->next;
	}
}

void	print_stack(t_list *stack, char c)
{
	printf("STACK %c:\n", c);
	while (stack)
	{
		printf("%d\n", (stack->content));
		stack = stack->next;
	}
}