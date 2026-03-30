/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 18:37:48 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/27 18:37:48 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


void	swap_topA(t_list *stackA)
{
	t_list	*tmp;

	tmp = stackA->next->content;
	stackA->next->content =  stackA->content;
	stackA->content = tmp;
	ft_putendl_fd("sa", 1);
}

void	swap_topB(t_list *stackB)
{
	t_list	*tmp;

	tmp = stackB->next->content;
	stackB->next->content =  stackB->content;
	stackB->content = tmp;
	ft_putendl_fd("sb", 1);
}

void	swap_topAB(t_list *stackA, t_list *stackB)
{
	swap_topA(stackA);
	swap_topB(stackB);
	ft_putendl_fd("ss", 1);
}

void	pushB(t_list **stackA, t_list **stackB)
{
	t_list *next;

	if (*stackB)
		next = *stackB;
	else
		next = NULL;
	*stackB = *stackA;
	*stackA = (*stackA)->next;
	(*stackB)->next = next;
	ft_putendl_fd("pb", 1);
}

void	pushA(t_list **stackA, t_list **stackB)
{
	t_list *next;

	if (*stackA)
		next = *stackA;
	else
		next = NULL;
	*stackA = *stackB;
	*stackB = (*stackB)->next;
	(*stackA)->next = next;
	ft_putendl_fd("pb", 1);
}

void	shift_upA(t_list **stackA)
{
	t_list *last;
	t_list *second_last;

	last = ft_lstlast(*stackA);
	second_last = *stackA;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = (*stackA)->next;
	(*stackA)->next = NULL;
	second_last->next = *stackA;
	*stackA = last;
	ft_putendl_fd("ra", 1);
}

void	sort(t_list **stackA)
{
	t_list	*stackB;

	swap_topA(*stackA);
	stackB = NULL;
	pushB(stackA, &stackB);
	pushB(stackA, &stackB);
	pushA(stackA, &stackB);
	shift_upA(stackA);
	printf("STACK B:\n");
	while (stackB)
	{
		printf("%s\n", stackB->content);
		stackB = stackB->next;
	}
}

int	main(int argcount, char **args)
{
	int		index;
	int		mode;
	t_list	*stackA;

	index = 1;
	mode = 0;
	if (args[1][0] < '0' || args[1][0] > '9' )
		index++;
	if (strncmp(args[1], "--simple", 9) == 0)
		mode = 1;
	if (strncmp(args[1], "--medium", 9) == 0)
		mode = 2;
	if (strncmp(args[1], "--complex", 9) == 0)
		mode = 3;
	if (strncmp(args[1], "--adaptive", 9) == 0)
		mode = 4;
	if (index == 2 && mode == 0 || argcount == 2)
		return (write(1, "invalid input", 14), 0);
	stackA = NULL;
	while (index < argcount)
		ft_lstadd_back(&stackA, ft_lstnew(args[index++]));
	//ft_lstlast(stackA)->next = stackA;
	sort(&stackA);
	printf("STACK A:\n");
	while (stackA)
	{
		printf("%s\n", stackA->content);
		stackA = stackA->next;
	}
	//printf("%s\n", stackA->content);
	//printf("%s\n", stackA->next->content);
	//printf("%s\n", stackA->next->next->content);
}