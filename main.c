#include "push_swap.h"

static void	init_stacks(t_node **stack_a, char **argv, int argc)
{
	int		i;
	long	num;
	t_node	*new_node;

	*stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num == LONG_MAX || num > INT_MAX || num < INT_MIN)
			error_exit(stack_a, NULL);
		new_node = create_node((int)num);
		if (!new_node)
			error_exit(stack_a, NULL);
		add_node_back(stack_a, new_node);
		i++;
	}
	if (check_duplicates(*stack_a))
		error_exit(stack_a, NULL);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	init_stacks(&stack_a, argv, argc);
	if (stack_size(stack_a) <= 3)
		sort_three(&stack_a);
	else if (stack_size(stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
