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

int	main(int argcount, char **args)
{
	int		index;
	int		mode;

	index = 1;
	mode = 0;
	if (strncmp(args[1], "--", 2) == 0)
		index++;
	if (strncmp(args[1], "--simple", 9) == 0)
		mode = 1;
	if (strncmp(args[1], "--simple", 9) == 0)
		mode = 1;
	if (strncmp(args[1], "--simple", 9) == 0)
		mode = 1;
	if (strncmp(args[1], "--simple", 9) == 0)
		mode = 1;
	while (index < argcount)
	
}