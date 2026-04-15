/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 18:37:48 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/15 18:01:05 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



void	turn_bench_on(int	*index, t_bench *bench)
{
	(*index)++;
	bench->bench_on = 1;
}

void	run(int argcount, char **args, t_data *data, t_bench *bench)
{
	int		index;

	index  = 1;
	if (ft_isdigit(args[1][0]) == 0)
		index++;
	if (ft_strncmp(args[1], "--bench", 11) == 0)
		turn_bench_on(&index, bench);
	while (index < argcount)
		ft_lstadd_back(data->stack_a, ft_lstnew(ft_atoi(args[index++])));
	update_data(data, 3);
	bench->disorder = compute_disorder(data->stacks[A]);
	if (ft_strncmp(args[1 + bench->bench_on], "--simple", 9) == 0)
		bubble (data->stack_a, bench);
	else if (ft_strncmp(args[1 + bench->bench_on], "--medium", 9) == 0)
		four_chunks(data, bench);
	else if (ft_strncmp(args[1 + bench->bench_on], "--complex", 10) == 0)
		merge_sort(data, bench);
	else if (ft_strncmp(args[1 + bench->bench_on], "--adaptive", 11) == 0)
		adaptive(data, bench);
	else if (args[1 + (index - ft_lstsize(data->stacks[A]) == 3)][0] > '0' && args[1 + (index - ft_lstsize(data->stacks[A]) == 3)][0] < '9')
		merge_sort(data, bench);
	else
		write(1, "invalid input\n", 14);
	if (ft_strncmp(args[1], "--bench", 11) == 0 || ft_strncmp(args[2], "--bench", 11) == 0)
		benchmark(bench);
}

void	init_bench(t_bench *bench)
{
	bench->bench_on = 0;
	bench->adaptive = 0;
	bench->disorder = 0;
	bench->strategy = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

int	main(int argcount, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	*data;
	t_bench	*bench;

	if (argcount < 2)
		return (0);
	if (check_input(argcount, args))
		return(ft_putendl_fd("Error", 2), 0);
	bench = malloc(sizeof(t_bench));
	init_bench(bench);
	data = malloc(sizeof(t_data));
	data->bench = bench;
	stack_a = NULL;
	stack_b = NULL;
	data->stack_a = &stack_a;
	data->stack_b = &stack_b;
	data->stacks[A] = stack_a;
	data->stacks[B] = stack_b;
	data->p_stacks[A] = &stack_a;
	data->p_stacks[B] = &stack_b;
	data->count_ops = 0;
	run(argcount, args, data, bench);
	//free_everything(data);
	return (0);
}
