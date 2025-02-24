#include "../push_swap.h"

void    ra(t_node **stack_a)
{
    t_node  *first;
    t_node  *last;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    first = *stack_a;
    last = *stack_a;
    while (last->next)
        last = last->next;
    *stack_a = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}

void    rb(t_node **stack_b)
{
    t_node  *first;
    t_node  *last;

    if (!*stack_b || !(*stack_b)->next)
        return ;
    first = *stack_b;
    last = *stack_b;
    while (last->next)
        last = last->next;
    *stack_b = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb\n", 3);
}

void    rr(t_node **stack_a, t_node **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}
