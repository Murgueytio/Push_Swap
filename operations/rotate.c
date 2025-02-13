/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscamurg <oscamurg@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-09 13:25:18 by oscamurg          #+#    #+#             */
/*   Updated: 2025-01-09 13:25:18 by oscamurg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void ra(long *stack_a, int *numbers_a)
{
    int i;
    long temporary_value;
    i = 0;

    if (*numbers_a > 1) // No rotar si hay 0 o 1 elementos
    {
        temporary_value = stack_a[0];

        while (i < *numbers_a - 1)
        {
            stack_a[i] = stack_a[i + 1];
            i++;
        }
        stack_a[*numbers_a - 1] = temporary_value;
    }
    write(1, "Rotate Stack in A\n", 18);
}

void rb(long *stack_b, int *numbers_b)
{
    int i;
    long temporary_value;
    i = 0;

    if (numbers_b[0] > 0)
    {
        temporary_value = stack_b[0];

        while (i < numbers_b[0] - 1)
        {
            stack_b[i] = stack_b[i + 1];
            i++;
        }
        stack_b[numbers_b[0] - 1] = temporary_value;
    }
    write(1, "Rotate Stack in B\n", 18);
}

void    rr(long *stack_a, long *stack_b, int *numbers_a, int *numbers_b)
{
    int i;
    long temporary_value_a;
    long temporary_value_b;
    i = 0;

    if (numbers_a[0] > 0)
    {
        temporary_value_a = stack_a[0];

        while (i < numbers_a[0] - 1)
        {
            stack_a[i] = stack_a[i + 1];
            i++;
        }
        stack_a[numbers_a[0] - 1] = temporary_value_a;
    }
    i = 0;
    if (numbers_b[0] > 0)
    {
        temporary_value_b = stack_b[0];

        while (i < numbers_b[0] - 1)
        {
            stack_b[i] = stack_b[i + 1];
            i++;
        }
        stack_b[numbers_b[0] - 1] = temporary_value_b;
    }
    write(1, "Rotate Stack A & B\n", 19);   
}
