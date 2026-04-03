/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 11:01:15 by swetting      #+#    #+#                 */
/*   Updated: 2026/03/16 12:23:34 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		n;
	int		negative;
	long	number;

	n = 0;
	negative = 1;
	number = 0;
	while (nptr[n] == ' ' || (nptr[n] >= 9 && nptr[n] <= 13))
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			negative *= -1;
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		number *= 10;
		number += nptr[n++] - '0';
	}
	return (negative * number);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	printf("-1234 %d\n", ft_atoi(" ---+--+1234ab567"));
// 	printf("0 %d\n", atoi(" ---+--+1234ab567"));
// 	printf("%d\n", ft_atoi("2147483648"));
// 	printf("%d\n", atoi("2147483648"));
// 	printf("%d\n", ft_atoi("2147483647"));
// 	printf("%d\n", atoi("2147483647"));
// 	printf("%d\n", ft_atoi("+0"));
// 	printf("%d\n", atoi("+0"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", atoi("-2147483648"));
// 	printf("%d\n", ft_atoi("-10"));
// 	printf("%d\n", atoi("-10"));
// 	printf("%d\n", ft_atoi("+10"));
// 	printf("%d\n", atoi("+10"));
// 	printf(">>ft++10  %d\n", ft_atoi("++10"));
// 	printf(">>at++10  %d\n", atoi("++10"));
// 	printf(">>ft --10  %d\n", ft_atoi("--10"));
// 	printf(">>at --10  %d\n", atoi("--10"));
// 	printf("%d\n", ft_atoi("   10"));
// 	printf("%d\n", atoi("    10"));
// 	printf("%d\n", ft_atoi("   10ab"));
// 	printf("%d\n", atoi("    10ab"));
// 	printf("%d\n", ft_atoi("   10ab1"));
// 	printf("%d\n", atoi("    10ab1"));
// 	printf("%d\n", ft_atoi("   10ab324"));
// 	printf("%d\n", atoi("    10ab324"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", atoi("-2147483648"));
// 	printf("working %d\n", ft_atoi("--10"));
// 	printf("normal %d\n", atoi("--10"));
// 	printf(">>ft --10 %d\n", ft_atoi("--10"));
// 	printf(">>at --10 %d\n", atoi("--10"));
// }