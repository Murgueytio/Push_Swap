#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

// Stack operations
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// Stack utils
t_node	*create_node(int value);
void	add_node_back(t_node **stack, t_node *new_node);
void	add_node_front(t_node **stack, t_node *new_node);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);

// Utils
int		is_sorted(t_node *stack);
void	error_exit(t_node **stack_a, t_node **stack_b);
long	ft_atoi(const char *str);
int		check_duplicates(t_node *stack);

// Split
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	free_split(char **res, int k);

// Sorting algorithms
void	sort_three(t_node **stack);
void	sort_small(t_node **stack_a, t_node **stack_b);
void	sort_big(t_node **stack_a, t_node **stack_b);

#endif
