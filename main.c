/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 18:37:48 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/30 14:12:08 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%p contains:\ncontent>%s\nnext>%p\n\n", stack, (char *)(stack->content), stack->next);
		stack = stack->next;
	}
}

void	print_stacks(t_list *stackA, t_list *stackB)
{
	printf("STACK A:\n");
	while (stackA)
	{
		printf("%s\n", (char *)(stackA->content));
		stackA = stackA->next;
	}
	printf("STACK B:\n");
	while (stackB)
	{
		printf("%s\n", (char *)(stackB->content));
		stackB = stackB->next;
	}
}

void	print_stack(t_list *stack, char c)
{
	printf("STACK %c:\n", c);
	while (stack)
	{
		printf("%s\n", (char *)(stack->content));
		stack = stack->next;
	}
}

void	swap_topA(t_list *stackA)
{
	char	*tmp;

	tmp = stackA->next->content;
	stackA->next->content =  stackA->content;
	stackA->content = tmp;
	// ft_putendl_fd("sa", 1);
}

void	swap_topB(t_list *stackB)
{
	char	*tmp;

	tmp = stackB->next->content;
	stackB->next->content =  stackB->content;
	stackB->content = tmp;
	// ft_putendl_fd("sb", 1);
}

void	swap_topAB(t_list *stackA, t_list *stackB)
{
	swap_topA(stackA);
	swap_topB(stackB);
	// ft_putendl_fd("ss", 1);
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
	// ft_putendl_fd("pb", 1);
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
	// ft_putendl_fd("pa", 1);
}

void	shift_down(t_list **stack)
{
	t_list	*second_last;

	second_last = ft_lstsecondlast(*stack);
	second_last->next->next = *stack;
	*stack = second_last->next;
	second_last->next = NULL;
}

void	shift_up(t_list **stack)
{
	t_list		*second;

	ft_lstlast(*stack)->next = *stack;
	second = (*stack)->next;
	(*stack)->next = NULL;
	*stack = second;
}

void	shift_downA(t_list **stack)
{
	shift_down(stack);
	ft_putendl_fd("rra", 1);
}

void	shift_downB(t_list **stack)
{
	shift_down(stack);
	ft_putendl_fd("rrb", 1);
}

void	shift_downAB(t_list **stackA, t_list **stackB)
{
	shift_down(stackB);
	shift_down(stackA);
	ft_putendl_fd("rrr", 1);
}

void	shift_upA(t_list **stack)
{
	shift_up(stack);
	// ft_putendl_fd("ra", 1);
}

void	shift_upB(t_list **stack)
{
	shift_up(stack);
	// ft_putendl_fd("rb", 1);
}

void	shift_upAB(t_list **stackA, t_list **stackB)
{
	shift_up(stackA);
	shift_up(stackB);
	// ft_putendl_fd("rr", 1);
}

void	sort(t_list **stackA)
{
	t_list	*stackB;

	swap_topA(*stackA);
	stackB = NULL;
	pushB(stackA, &stackB);
	pushB(stackA, &stackB);
	pushA(stackA, &stackB);
	shift_downA(stackA);
	pushB(stackA, &stackB);
	//pushB(stackA, &stackB);
	shift_downB(&stackB);
	shift_upA(stackA);
	// shift_downA(stackA);
	printf("BEFORE:\n");
	print_stack(*stackA, 'A');
	shift_down(stackA);
	printf("AFTER:\n");
	print_stack(*stackA, 'A');
	//swap_topB(stackB);
	//print_list(stackB);
}

int	main(int argcount, char **args)
{
	int		index;
	int		mode;
	t_list	*stackA;

	index = 1;
	mode = 0;
	if (argcount < 2)
		return (0);
	if (args[1][0] < '0' || args[1][0] > '9' )
		index++;
	if (ft_strncmp(args[1], "--simple", 9) == 0)
		mode = 1;
	if (ft_strncmp(args[1], "--medium", 9) == 0)
		mode = 2;
	if (ft_strncmp(args[1], "--complex", 9) == 0)
		mode = 3;
	if (ft_strncmp(args[1], "--adaptive", 9) == 0)
		mode = 4;
	if (index == 2 && mode == 0 || argcount == 2)
		return (write(1, "invalid input", 14), 0);
	stackA = NULL;
	while (index < argcount)
		ft_lstadd_back(&stackA, ft_lstnew(args[index++]));
	//ft_lstlast(stackA)->next = stackA;
	//sort(&stackA);
	radix(stackA, stackA);
}

// printf("STACK B:\n");
	// while (stackB)
	// {
	// 	printf("%s\n", (char *)(stackB->content));
	// 	stackB = stackB->next;
	// }

// printf("STACK A:\n");
	// while (stackA)
	// {
	// 	printf("%s\n", (char *)(stackA->content));
	// 	stackA = stackA->next;
	// }
	// //printf("%s\n", stackA->content);
	//printf("%s\n", stackA->next->content);
	//printf("%s\n", stackA->next->next->content);

// void	shift_downA(t_list **stackA)
// {
// 	t_list *last;
// 	t_list *second_last;

// 	if ((*stackA)->next == NULL)
// 		return ;
// 	if ((*stackA)->next->next == NULL)
// 	{
// 		swap_topB(*stackA);
// 		// ft_putendl_fd("rra", 1);
// 		return ;
// 	}
// 	last = ft_lstlast(*stackA);
// 	second_last = *stackA;
// 	while (second_last->next != last)
// 		second_last = second_last->next;
// 	last->next = (*stackA)->next;
// 	(*stackA)->next = NULL;
// 	second_last->next = *stackA;
// 	*stackA = last;
// 	// ft_putendl_fd("rra", 1);
// }

// void	shift_downB(t_list **stackB)
// {
// 	t_list *last;
// 	t_list *second_last;
// 	t_list *tmp;

// 	if ((*stackB)->next == NULL)
// 		return ;
// 	if ((*stackB)->next->next == NULL)
// 	{
// 		swap_topB(*stackB);
// 		// ft_putendl_fd("rrb", 1);
// 		return ;
// 	}
// 	last = ft_lstlast(*stackB);
// 	second_last = *stackB;
// 	while (second_last->next != last)
// 		second_last = second_last->next;
// 	last->next = (*stackB)->next;
// 	(*stackB)->next = NULL;
// 	second_last->next = *stackB;
// 	*stackB = last;
// 	// ft_putendl_fd("rrb", 1);
// }