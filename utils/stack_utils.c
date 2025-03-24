#include "../push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	add_node_front(t_node **stack, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

int	stack_size(t_node *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

/*
🔹 add_node_front adds a node to the front of the stack (fast, O(1)).
For operations like 'pa' and 'pb', this takes constant time.
🔹 add_node_back adds a node to the back of the stack (slower, O(n)).
To initialize the stack, use 'init_stacks'. This takes linear time.
*/
