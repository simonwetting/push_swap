/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 16:49:31 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/09 16:30:45 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define A 0
# define B 1
# define LOW 0
# define HIGH 1

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct	s_data
{
	t_list		**stackA;
	t_list		**stackB;
	t_list		**p_stacks[2];
	t_list		*stacks[2];
	int 		*numbers;
	int			chunks[500][2];
	int			chunk_count;
}				t_data;

int		ft_atoi(const char *nptr);
 void	ft_bzero(void *s, size_t n);
// void	*ft_calloc(size_t nmemb, size_t size);
// int		ft_isalnum(int c);
// int		ft_isalpha(int c);
// int		ft_isdigit(int c);
// int		ft_isprint(int c);
// int		ft_isascii(int c);
// void	*ft_memcpy(void *dest, const void *src, size_t n);
// void	*ft_memset(void *s, int c, size_t n);
// void	*ft_memmove(void *dest, const void *src, size_t n);
// void	*ft_memchr(const void *s, int c, size_t n);
// int		ft_memcmp(const void *s1, const void *s2, size_t n);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strdup(const char *s);
// size_t	ft_strlcat(char *dest, const char *src, size_t size);
// size_t	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
// char	*ft_strnstr(const char *big, const char *little, size_t len);
// char	*ft_strrchr(const char *s, int c);
// int		ft_tolower(int c);
// int		ft_toupper(int c);

// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strtrim(char const *s1, char const *set);
// char	**ft_split(char const *s, char c);
// char	*ft_itoa(int n);
// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// void	ft_putchar_fd(char c, int fd);
// void	ft_putstr_fd(char *s, int fd);
 void	ft_putendl_fd(char *s, int fd);
// void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstsecondlast(t_list *lst);
void	radix(t_list *stackA, t_list *stackB);
void	bubble(t_list **stackA);

// void	shift_down(t_list **stack);
// void	shift_up(t_list **stack);
// void	swap_top(t_list *stack);

void	swap_topA(t_list *stackA);
void	swap_topB(t_list *stackB);
void	swap_topAB(t_list *stackA, t_list *stackB);

void	pushB(t_list **stackA, t_list **stackB);
void	pushA(t_list **stackA, t_list **stackB);
void	push(t_data *data, int stack);

void	shift_downA(t_list **stack);
void	shift_downB(t_list **stack);
void	shift_downAB(t_list **stackA, t_list **stackB);

void	shift_upA(t_list **stack);
void	shift_upB(t_list **stack);
void	shift_upAB(t_list **stackA, t_list **stackB);

void	shift_up(t_list **stack);
void	shift_up_stack(t_data *data, int stack_id);

void	print_stack(t_list *stack, char c);
void	print_stacks(t_list *stackA, t_list *stackB);
int		*indexate(t_list *stack);
void	simple(t_list *stackA);

void	quatro_chunk(t_list **stackA, t_list **stackB);

void	turk(t_data *data);

int		chunksize(int chunks[500][2], int index);
int		in_chunk(int i, int chunks[500][2], int chunk_index, int *numbers);
int		divide_chunk(int chunks[500][2], int chunk_index, t_data *data);
int		find_chunk(int i, int chunks[500][2], int *numbers);
void	print_chunks(t_data *data);
void	print_chunk(t_data *data, int chunk_id);

#endif