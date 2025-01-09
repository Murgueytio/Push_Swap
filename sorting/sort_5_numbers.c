/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscamurg <oscamurg@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-09 13:29:09 by oscamurg          #+#    #+#             */
/*   Updated: 2025-01-09 13:29:09 by oscamurg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_stack_a_radix(long *stack_a, int *numbers_in_stack_a)
{
	rotate_stack_a(stack_a, numbers_in_stack_a);
	rotate_stack_a(stack_a, numbers_in_stack_a);
}

void	reverse_rotate_stack_a_radix(long *stack_a, int *numbers_in_stack_a)
{
	reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
}

void	first_stack(long *stack_a, long *stack_b, int *numbers_in_stack_a, int *numbers_in_stack_b)
{
	if (stack_b[0] < stack_a[0])
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	}
	else if (stack_b[0] > stack_a[2])
	{
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		rotate_stack_a(stack_a, numbers_in_stack_a);
	}
}

void	second_stack(long *stack_a, long *stack_b, int *numbers_in_stack_a, int *numbers_in_stack_b)
{
	if (stack_b[0] < stack_a[0])
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		swap_stack_a(stack_a, numbers_in_stack_a);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	}
	else if ((stack_b[0] > stack_a[2]) && (stack_b[0] < stack_a[3]))
	{
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		rotate_stack_a_radix(stack_a, numbers_in_stack_a);
	}
	else if (stack_b[0] > stack_a[3])
		parameters(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
}

void	sort_5_numbers(long *stack_a, long *stack_b, int *numbers_in_stack_a, int *numbers_in_stack_b)
{
	push_stack_b(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
	push_stack_b(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
	sort_3_numbers(stack_a, numbers_in_stack_a);
	while (*numbers_in_stack_b != 0)
	{
		if (numbers_in_stack_a[1] == 3)
			first_stack(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		else if (numbers_in_stack_a[1] == 4)
			second_stack(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
	}
}