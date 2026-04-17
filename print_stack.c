/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/17 19:40:26 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/17 19:40:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	print_list(t_list *stack)
//{
//	while (stack)
//	{
//		printf("%p contains:\ncontent>%d\nnext>%p\n\n", stack, (stack->content), stack->next);
//		stack = stack->next;
//	}
//}

//void	print_stacks(t_list *stackA, t_list *stackB)
//{
//	printf("STACK A:\n");
//	while (stackA)
//	{
//		printf("%d\n", (stackA->content));
//		stackA = stackA->next;
//	}
//	printf("STACK B:\n");
//	while (stackB)
//	{
//		printf("%d\n", (stackB->content));
//		stackB = stackB->next;
//	}
//}

void	print_stack(t_list *stack, char c)
{
	printf("STACK %c:\n", c);
	while (stack)
	{
		printf("%d\n", (stack->content));
		stack = stack->next;
	}
}