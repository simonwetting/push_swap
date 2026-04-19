/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 18:37:48 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/16 14:52:38 by swetting      ########   odam.nl         */
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

	index = 1;
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
	else if (str_isnumber(args[1 + bench->bench_on]))
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

char	**init_input(int *argcount, char **args)
{
	char	**input;
	char	*tmp;
	char	*tmp2;
	int		size;

	if (*argcount == 2)
	{
		tmp = ft_strjoin(args[0], " ");
		tmp2 = ft_strjoin(tmp, args[1]);
		input = ft_split(tmp2, ' ');
		free(tmp);
		free(tmp2);
		size = 0;
		while (input[size])
			size++;
		*argcount = size;
	}
	else
		input = args;
	return (input);
}

int	main(int argcount, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	*data;
	t_bench	*bench;
	char	**input;

	input = init_input(&argcount, args);
	if (check_input(argcount, input))
		return (ft_putendl_fd("Error", 2), 0);
	bench = malloc(sizeof(t_bench));
	init_bench(bench);
	data = malloc(sizeof(t_data));
	data->bench = bench;
	stack_a = NULL;
	stack_b = NULL;
	data->stack_a = &stack_a;
	data->stack_b = &stack_b;
	update_data(data, 3);
	data->count_ops = 0;
	run(argcount, input, data, bench);
	printf("Chunk count>%d\n", data->chunk_count);
	free_everything(data);
	return (0);
}
