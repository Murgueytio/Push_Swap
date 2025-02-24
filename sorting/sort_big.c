#include "../push_swap.h"

static void	normalize_stack(t_node **stack)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = *stack;
	while (i)
	{
		rank = 0;
		j = *stack;
		while (j)
		{
			if (i->value > j->value)
				rank++;
			j = j->next;
		}
		i->value = rank;
		i = i->next;
	}
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

static int	get_min_pos(t_node *stack, int start, int end)
{
	int		pos;
	int		min_pos;
	int		min;
	t_node	*current;

	pos = 0;
	min_pos = -1;
	min = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->value >= start && current->value <= end && current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	push_chunk(t_node **stack_a, t_node **stack_b, int start, int end)
{
	int	size;
	int	pos;
	int	middle;

	size = stack_size(*stack_a);
	while (size > 0)
	{
		pos = get_min_pos(*stack_a, start, end);
		if (pos == -1)
			break ;
		middle = size / 2;
		while (pos != 0)
		{
			if (pos <= middle)
				ra(stack_a);
			else
				rra(stack_a);
			pos = get_min_pos(*stack_a, start, end);
		}
		pb(stack_a, stack_b);
		size = stack_size(*stack_a);
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	chunk_size;
	int	i;
	int	start;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 5)
	{
		sort_small(stack_a, stack_b);
		return ;
	}
	normalize_stack(stack_a);
	chunk_size = get_chunk_size(size);
	i = 0;
	while (i < size)
	{
		start = i;
		push_chunk(stack_a, stack_b, start, start + chunk_size - 1);
		i += chunk_size;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
