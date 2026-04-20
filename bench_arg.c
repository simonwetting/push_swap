int		bench_arg(char **args)
{
	if (ft_strncmp(args[1], "--bench", 11) == 0 || ft_strncmp(args[2], "--bench", 11) == 0)
		return (1);
	return (0);
}