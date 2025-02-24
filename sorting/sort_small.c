#include "../push_swap.h"

static int  get_min_pos(t_node *stack)
{
    int     min;
    int     pos;
    int     min_pos;
    t_node  *current;

    if (!stack)
        return (0);
    min = stack->value;
    pos = 0;
    min_pos = 0;
    current = stack;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (min_pos);
}

void    sort_three(t_node **stack)
{
    int first;
    int second;
    int third;

    if (!*stack || !(*stack)->next || !(*stack)->next->next)
        return ;
    first = (*stack)->value;
    second = (*stack)->next->value;
    third = (*stack)->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack);
    else if (first > second && second > third)
    {
        sa(stack);
        rra(stack);
    }
    else if (first > second && second < third && first > third)
        ra(stack);
    else if (first < second && second > third && first < third)
    {
        sa(stack);
        ra(stack);
    }
    else if (first < second && second > third && first > third)
        rra(stack);
}

void    sort_small(t_node **stack_a, t_node **stack_b)
{
    int     size;
    int     min_pos;

    size = stack_size(*stack_a);
    if (size <= 3)
    {
        sort_three(stack_a);
        return ;
    }
    while (size > 3)
    {
        min_pos = get_min_pos(*stack_a);
        while (min_pos > 0)
        {
            if (min_pos <= size / 2)
                ra(stack_a);
            else
                rra(stack_a);
            min_pos = get_min_pos(*stack_a);
        }
        pb(stack_a, stack_b);
        size--;
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}
