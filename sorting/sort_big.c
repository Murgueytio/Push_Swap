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
	if (size <= 20)
		return (5);
	else if (size <= 100)
		return (20); // Con 6 se acerca a los 800 y sin 'size/'
	else if (size <= 500)
		return (8 + size / 14);
	return (42);
}

static int	get_min_pos(t_node *stack, int start, int end)
{
	int		pos;
	int		min_pos;
	int		min;
	t_node	*now;

	pos = 0;
	min_pos = -1;
	min = INT_MAX;
	now = stack;
	while (now)
	{
		if (now->value >= start && now->value <= end && now->value < min)
		{
			min = now->value;
			min_pos = pos;
		}
		pos++;
		now = now->next;
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
			break;
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
		if (*stack_b && (*stack_b)->next &&
			(*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
		size = stack_size(*stack_a);
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	chunk_count;
	int	chunk_size;
	int	i;
	int	start;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 5)
		return (sort_small(stack_a, stack_b));
	normalize_stack(stack_a);
	if (size <= 100)
		chunk_count = 33;  // Para 100 números, usamos 5 chunks
	else
		chunk_count = size / get_chunk_size(size);
	chunk_size = size / chunk_count;
	i = 0;
	while (i++ < chunk_count)
	{
		start = i * chunk_size;
		push_chunk(stack_a, stack_b, start, start + chunk_size - 1);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

