#include "push_swap.h"

static void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int check_valid_number(const char *str, long *num)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
    if (!str || !str[0])
        return (0);
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        if (result > (LONG_MAX - (str[i] - '0')) / 10)
            return (0);
        result = result * 10 + (str[i] - '0');
        i++;
    }
    *num = result * sign;
    return (1);
}

static int has_duplicates(long *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void parse_args(int argc, char **argv, long **stack_a,
                        long **stack_b, int *numbers_a)
{
    int i;
    long num;

    *numbers_a = argc - 1;
    *stack_a = malloc(sizeof(long) * (*numbers_a));
    *stack_b = malloc(sizeof(long) * (*numbers_a));
    if (!(*stack_a) || !(*stack_b))
        error_exit();
    i = 1;
    while (i < argc)
    {
        if (!check_valid_number(argv[i], &num))
            error_exit();
        (*stack_a)[i - 1] = num;
        i++;
    }
    if (has_duplicates(*stack_a, *numbers_a))
        error_exit();
}

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
			error_exit();
		new_node = create_node((int)num);
		if (!new_node)
			error_exit();
		add_node_back(stack_a, new_node);
		i++;
	}
	if (check_duplicates(*stack_a))
		error_exit();
}

static void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	init_stacks(&stack_a, argv, argc);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
