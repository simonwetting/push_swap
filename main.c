/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 18:37:48 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/20 16:39:05 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	turn_bench_on(int	*index, t_bench *bench)
{
	(*index)++;
	bench->bench_on = 1;
}

void	fill_stack(char **input, char **args, t_data *data, t_bench *bench)
{
	int		index;

	index = 1;
	//if (ft_isdigit(args[1][0]) == 0)
	//	index++;
	if (ft_strncmp(args[1], "--bench", 11) == 0)
		turn_bench_on(&index, bench);
	index = data->flag_count + 1;
	//printf("flagcount>%d\n", data->flag_count);
	//printf("args[%d] %s\n", data->flag_count, args[data->flag_count]);
	if (input == NULL)
		while (index < data->argcount)
			ft_lstadd_back(data->stack_a, ft_lstnew(ft_atoi(args[index++])));
	index = 0;
	if (input)
		while (input[index])
			ft_lstadd_back(data->stack_a, ft_lstnew(ft_atoi(input[index++])));
	update_data(data, 3);
}

void	run(char **input, char **args, t_data *data, t_bench *bench)
{
	fill_stack(input, args, data, bench);
	//print_stacks(data->stacks[A], data->stacks[B]);
	bench->disorder = compute_disorder(data->stacks[A]);
	if (ft_strncmp(args[1 + bench->bench_on], "--simple", 9) == 0)
		bubble (data->stack_a, bench);
	else if (ft_strncmp(args[1 + bench->bench_on], "--medium", 9) == 0)
		four_chunks(data, bench);
	else if (ft_strncmp(args[1 + bench->bench_on], "--complex", 10) == 0)
		merge_sort(data, bench);
	else if (ft_strncmp(args[1 + bench->bench_on], "--adaptive", 11) == 0)
		adaptive(data, bench);
	else if (str_isnumb_or_space(args[1 + bench->bench_on]))
		merge_sort(data, bench);
	else if (input == NULL)
		write(1, "invalid input\n", 14);
	if (bench_arg(args))
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

char	**init_input(int argcount, char **args, t_data *data)
{
	char	**input;
	int		size;

	data->argcount = argcount;
	if (argcount == data->flag_count + 2)
	{
		//tmp = ft_strjoin(args[0], " ");
		//tmp2 = ft_strjoin(tmp, args[1]);
		input = ft_split(args[data->flag_count + 1], ' ');
		//free(tmp);
		//free(tmp2);
		size = 0;
		while (input[size])
			size++;
		data->argcount = size;
	}
	else
		input = NULL;
	return (input);
}

int	main(int argcount, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	*data;
	t_bench	*bench;
	char	**input;

	bench = malloc(sizeof(t_bench));
	data = malloc(sizeof(t_data));
	init_bench(bench);
	data->flag_count = check_input(argcount, args);
	if (data->flag_count == -1)
		return (ft_putendl_fd("Error", 2), 0);
	input = init_input(argcount, args, data);
	data->bench = bench;
	stack_a = NULL;
	stack_b = NULL;
	data->stack_a = &stack_a;
	data->stack_b = &stack_b;
	update_data(data, 3);
	data->count_ops = 0;
	run(input, args, data, bench);
	printf("Chunk count>%d\n", data->chunk_count);
	free_everything(data);
	return (0);
}
