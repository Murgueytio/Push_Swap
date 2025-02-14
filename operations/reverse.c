/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscamurg <oscamurg@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-09 13:24:22 by oscamurg          #+#    #+#             */
/*   Updated: 2025-01-09 13:24:22 by oscamurg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void rra(long *stack_a, int *numbers_a)
{
    int i;
    long temporary_value;
    i = *numbers_a - 1;

    if (*numbers_a > 1)
    {
        temporary_value = stack_a[*numbers_a - 1];
 
        while (i > 0)
        {
            stack_a[i] = stack_a[i - 1];
            i--;
        }
        stack_a[0] = temporary_value;
        write(1, "Reverse Rotate Stack in A\n", 26);
    }
}

void rrb(long *stack_b, int *numbers_b)
{
    int i;
    long temporary_value;
    i = numbers_b[0] - 1;

    if (numbers_b[0] > 0)
    {
        temporary_value = stack_b[numbers_b[0] - 1];
    
        while (i > 0)
        {
            stack_b[i] = stack_b[i - 1];
            i--;
        }
        stack_b[0] = temporary_value;
        write(1, "Reverse Rotate Stack in B\n", 26);
    }
}

void rrr(long *stack_a, long *stack_b, int *numbers_a, int *numbers_b)
{
    int i_a;
    int i_b;
    long temporary_value_a;
    long temporary_value_b;

    if (numbers_a[0] > 0)
    {
        temporary_value_a = stack_a[numbers_a[0] - 1];
        i_a = numbers_a[0] - 1;

        while (i_a > 0)
        {
            stack_a[i_a] = stack_a[i_a - 1];
            i_a--;
        }
        stack_a[0] = temporary_value_a;
    }

    if (numbers_b[0] > 0)
    {
        temporary_value_b = stack_b[numbers_b[0] - 1];
        i_b = numbers_b[0] - 1;

        while (i_b > 0)
        {
            stack_b[i_b] = stack_b[i_b - 1];
            i_b--;
        }
        stack_b[0] = temporary_value_b;
    }
    write(1, "Reverse Rotate Stacks A & B\n", 28);
}
