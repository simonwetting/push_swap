/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 18:37:48 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/14 17:48:50 by swetting      ########   odam.nl         */
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

void	swap_top(t_list *stack)
{
	int		tmp;

	tmp = stack->next->content;
	stack->next->content =  stack->content;
	stack->content = tmp;
}

void	swap_topA(t_list *stackA)
{
	swap_top(stackA);
	 ft_putendl_fd("sa", 1);
}

void	swap_topB(t_list *stackB)
{
	swap_top(stackB);
	 ft_putendl_fd("sb", 1);
}

void	swap_topAB(t_list *stackA, t_list *stackB)
{
	swap_topA(stackA);
	swap_topB(stackB);
	 ft_putendl_fd("ss", 1);
}

void	push_to_B(t_list **stackA, t_list **stackB)
{
	t_list *next;

	if (*stackA == NULL)
	{
		ft_putendl_fd("nothing to push", 1);
		return ;
	}
	if (*stackB)
		next = *stackB;
	else
		next = NULL;
	*stackB = *stackA;
	*stackA = (*stackA)->next;
	(*stackB)->next = next;
	 ft_putendl_fd("pb", 1);
}

void	push_to_A(t_list **stackA, t_list **stackB)
{
	t_list *next;

	if (*stackB == NULL)
	{
		ft_putendl_fd("nothing to push", 1);
		return ;
	}
	if (*stackA)
		next = *stackA;
	else
		next = NULL;
	*stackA = *stackB;
	*stackB = (*stackB)->next;
	(*stackA)->next = next;
	 ft_putendl_fd("pa", 1);
}

void	push_to(t_data *data, int stack)
{
	if (stack == A)
		push_to_A(data->stackA, data->stackB);
	else if (stack == B)
		push_to_B(data->stackA, data->stackB);
	data->count_ops++;
	update_data(data, 3);
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

void	shift_up_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_upA(data->stackA);
	if (stack_id == B)
		shift_upB(data->stackB);
	update_data(data, stack_id);
	data->count_ops++;
}
void	shift_down_stack(t_data *data, int stack_id)
{
	if (stack_id == A)
		shift_downA(data->stackA);
	if (stack_id == B)
		shift_downB(data->stackB);
	update_data(data, stack_id);
	data->count_ops++;
}


void	shift_upA(t_list **stack)
{
	shift_up(stack);
	 ft_putendl_fd("ra", 1);
}

void	shift_upB(t_list **stack)
{
	shift_up(stack);
	 ft_putendl_fd("rb", 1);
}

void	shift_upAB(t_list **stackA, t_list **stackB)
{
	shift_up(stackA);
	shift_up(stackB);
	 ft_putendl_fd("rr", 1);
}

void	sort(t_list **stackA)
{
	t_list	*stackB;

	swap_topA(*stackA);
	stackB = NULL;
	push_to_B(stackA, &stackB);
	push_to_B(stackA, &stackB);
	push_to_A(stackA, &stackB);
	shift_downA(stackA);
	push_to_B(stackA, &stackB);
	//push_to_B(stackA, &stackB);
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

void	del(void *p)
{
	free(p);
}

void	free_everything(t_data *data)
{
	ft_lstclear(data->stackA, del);
	ft_lstclear(data->stackB, del);
	free(data->numbers);
	free(data);
}

void	run(int argcount, char **args, t_data *data, t_bench *bench)
{
	int		index;

	index  = 1;
	if (ft_isdigit(args[1][0]) == 0)
		index++;
	if (ft_strncmp(args[1], "--bench", 11) == 0)
		index++;
	while (index < argcount)
		ft_lstadd_back(data->stackA, ft_lstnew(ft_atoi(args[index++])));
	update_data(data, 3);
	bench->disorder = compute_disorder(data->stacks[A]);
	if (ft_strncmp(args[1 + (index - ft_lstsize(data->stacks[A]) == 3)], "--simple", 9) == 0)
		bubble (data->stackA);
	else if (ft_strncmp(args[1 + (index - ft_lstsize(data->stacks[A]) == 3)], "--medium", 9) == 0)
		four_chunks(data);
	else if (ft_strncmp(args[1 + (index - ft_lstsize(data->stacks[A]) == 3)], "--complex", 10) == 0)
		merge_sort(data);
	else if (ft_strncmp(args[1 + (index - ft_lstsize(data->stacks[A]) == 3)], "--adaptive", 11) == 0)
		adaptive(data);
	else if (args[1 + (index - ft_lstsize(data->stacks[A]) == 3)][0] > '0' && args[1 + (index - ft_lstsize(data->stacks[A]) == 3)][0] < '9')
		merge_sort(data);
	else
		write(1, "invalid input\n", 14);
	if (ft_strncmp(args[1], "--bench", 11) == 0 || ft_strncmp(args[2], "--bench", 11) == 0)
		benchmark(data, bench);
}

int	main(int argcount, char **args)
{
	t_list	*stackA;
	t_list	*stackB;
	t_data	*data;
	t_bench	*bench;
;
	if (argcount < 2)
		return (0);
	bench = malloc(sizeof(t_bench));
	data = malloc(sizeof(t_data));
	stackA = NULL;
	stackB = NULL;
	data->stackA = &stackA;
	data->stackB = &stackB;
	data->stacks[A] = stackA;
	data->stacks[B] = stackB;
	data->p_stacks[A] = &stackA;
	data->p_stacks[B] = &stackB;
	data->count_ops = 0;
	run(argcount, args, data, bench);
	free_everything(data);
	return (0);
}

//	else if (ft_strncmp(args[1], "--medium", 9) == 0)
//		quatro_chunk(&stackA, &stackB);
//	else if (ft_strncmp(args[1], "--complex", 9) == 0)
//		merge_sort(data);
//	else if (ft_strncmp(args[1], "--adaptive", 9) == 0)
//		mode = 4;
//	else if (index == 2 || argcount == 2)
//		return (write(1, "invalid input", 14), 0);
//}

//ft_lstlast(stackA)->next = stackA;

//sort(&stackA);
	// radix(stackA, stackA);
	//print_stack(stackA, 'A');
	// bubble(&stackA);
	// shift_down(&stackA);
	

	// eval_swap(stackA);
	// print_stack(stackA, 'A');
	//print_stack(stackA, 'A');


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

//void	shift_up2(t_data *data, int stack)
//{
//	if (stack == A)
//		shift_upA(data->p_stacks[A]);
//	else if (stack == B)
//		shift_upA(data->p_stacks[B]);
//}

//void	shift_up_stack(t_data *data, int stack_id)
//{
//	t_list		*second;
//	t_list		**stack;

//	//if (stack_id == A)
//		// ft_putendl_fd("ra", 1);
//	//if (stack_id == B)
//		// ft_putendl_fd("rb", 1);
//	stack = data->p_stacks[stack_id];
//	ft_lstlast(*stack)->next = *stack;
//	second = (*stack)->next;
//	(*stack)->next = NULL;
//	*stack = second;
//}

//void	push_to_A(t_list **stackA, t_list **stackB)
//{
//	t_list *next_b;
//	t_list *next_a;

//	if (*stack)
//		next = *stackA;
//	else
//		next = NULL;
//	(*stackA)->next = next;

//}

// void	swap_top(t_list *stack)
// {
// 	char	*tmp;

// 	tmp = stack->next->content;
// 	stack->next->content =  stack->content;
// 	stack->content = tmp;
// }

// void	print_stacks(t_list *stackA, t_list *stackB)
// {
// 	printf("STACK A:\n");
// 	while (stackA)
// 	{
// 		printf("%s\n", (char *)(stackA->content));
// 		stackA = stackA->next;
// 	}
// 	printf("STACK B:\n");
// 	while (stackB)
// 	{
// 		printf("%s\n", (char *)(stackB->content));
// 		stackB = stackB->next;
// 	}
// }