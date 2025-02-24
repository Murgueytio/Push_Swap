#include "../push_swap.h"

static int  get_max_bits(t_node *stack)
{
    int     max;
    int     max_bits;
    t_node  *current;

    if (!stack)
        return (0);
    max = stack->value;
    current = stack->next;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    sort_big(t_node **stack_a, t_node **stack_b)
{
    int     i;
    int     j;
    int     size;
    int     max_bits;
    t_node  *current;

    size = stack_size(*stack_a);
    max_bits = get_max_bits(*stack_a);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            current = *stack_a;
            if (((current->value >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}
