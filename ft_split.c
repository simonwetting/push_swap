/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 14:50:10 by swetting      #+#    #+#                 */
/*   Updated: 2026/03/25 14:48:16 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int	n_strings;

	if (s == 0)
		return (0);
	n_strings = 0;
	if (*s != c && *s)
	{
		n_strings++;
		while (*s != c && *s)
			s++;
	}
	else
		while (*s == c && *s)
			s++;
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			n_strings++;
		s++;
	}
	return (n_strings);
}

static size_t	str_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char	**delete(char **strings, int index)
{
	int	n;

	n = 0;
	if (index == -1)
	{
		free(strings);
		return (NULL);
	}
	while (n <= index)
		free(strings[n++]);
	free(strings);
	return (NULL);
}

static char	**fs(char const *s, char c, int string_count, char **strings)
{
	int		index;
	int		len;

	index = 0;
	while (index < string_count)
	{
		while (*s == c)
			s++;
		len = str_len(s, c);
		strings[index] = malloc(len + 1);
		if (!(strings[index]))
			return (delete(strings, index));
		ft_memcpy(strings[index], s, len);
		strings[index++][len] = 0;
		s += len;
	}
	strings[index] = 0;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	size_t	string_count;
	char	**strings;

	string_count = count_strings(s, c);
	strings = malloc(sizeof(char *) * (string_count + 1));
	if (!strings)
		return (delete(strings, -1));
	if (s == 0 || *s == 0)
		return (strings[0] = 0, strings);
	while (*s == c)
		s++;
	if (fs(s, c, string_count, strings) == NULL)
		return (NULL);
	return (strings);
}

// int		main()
// {
// 	char *invalidReadCheck = malloc(1);
// 	*invalidReadCheck = 0;
// 	char **split = ft_split(invalidReadCheck, 0);
// 	printf("%p\n", split[0]);
// 	free(split); free(invalidReadCheck);

// 	// char **split = ft_split(0, 0);
// 	// printf("%p\n", split[0]);
// 	// free(split);
// }

// // if (string_count == 0)
// 	// 	return (0);

//while (index < string_count)
//	{
//		while (*s == c)
//			s++;
//		len = str_len(s, c);
//		strings[index] = malloc(len + 1);
//		if (!(strings[index]))
//			return (delete(strings, index));
//		ft_memcpy(strings[index], s, len);
//		strings[index++][len] = 0;
//		s += len;
//	}