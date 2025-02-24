#include "../push_swap.h"

// Checks if the stack is already sorted in ascending order.
int is_sorted(t_node *stack)
{
	t_node  *current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void    error_exit(t_node **stack_a, t_node **stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long    ft_atoi(const char *str)
{
	int     i;
	int     sign;
	long    result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || 
			(sign == -1 && result * sign < INT_MIN))
			return (LONG_MAX);
		i++;
	}
	if (str[i] != '\0')
		return (LONG_MAX);
	return (result * sign);
}

int     check_duplicates(t_node *stack)
{
	t_node  *current;
	t_node  *check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
