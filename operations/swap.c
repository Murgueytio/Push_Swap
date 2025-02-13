/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscamurg <oscamurg@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-09 13:25:57 by oscamurg          #+#    #+#             */
/*   Updated: 2025-01-09 13:25:57 by oscamurg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void sa(long *stack_a, int *numbers_a)
{
    long temporary_value;

    if (numbers_a[0] > 1)
    {
        temporary_value = stack_a[0];
        stack_a[0] = stack_a[1];
        stack_a[1] = temporary_value;
    }
    write(1, "Swap Stack in A\n", 16);
}

void sb(long *stack_b, int *numbers_b)
{
    long temporary_value;

    if (*numbers_b > 1)
    {
        temporary_value = stack_b[0];
        stack_b[0] = stack_b[1];
        stack_b[1] = temporary_value;
    }
    write(1, "Swap Stack in B\n", 16);
}

void ss(long *stack_a, long *stack_b, int *numbers_a, int *numbers_b)
{
    long temporary_value_a;
    long temporary_value_b;

    if (numbers_a[0] > 1)
    {
        temporary_value_a = stack_a[0];
        stack_a[0] = stack_a[1];
        stack_a[1] = temporary_value_a;
    }
    if (*numbers_b > 1)
    {
        temporary_value_b = stack_b[0];
        stack_b[0] = stack_b[1];
        stack_b[1] = temporary_value_b;
    }
    write(1, "Swap Stacks A & B\n", 18);
}
