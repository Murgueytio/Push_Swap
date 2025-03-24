#include "push_swap.h"

static void	init_stacks(t_node **stack_a, char **argv, int argc)
{
	int		i;
	long	num;
	t_node	*new_node;

	*stack_a = NULL;
	i = 0;
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

void	handle_arguments(int argc, char **argv, t_node **stack_a)
{
	char	**args;
	int		new_argc;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		new_argc = 0;
		while (args[new_argc])
			new_argc++;
		init_stacks(stack_a, args, new_argc);
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	else
		init_stacks(stack_a, argv + 1, argc - 1);
}

void	execute_sorting(t_node **stack_a, t_node **stack_b)
{
	if (stack_size(*stack_a) <= 3)
		sort_three(stack_a);
	else if (stack_size(*stack_a) <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	handle_arguments(argc, argv, &stack_a);
	execute_sorting(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

