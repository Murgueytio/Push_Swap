#include "../push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*second_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node	*last;
	t_node	*second_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
