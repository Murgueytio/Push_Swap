#include "../push_swap.h"

void    sa(t_node **stack_a)
{
    t_node  *first;
    t_node  *second;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    first = *stack_a;
    second = (*stack_a)->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1, "sa\n", 3);
}

void    sb(t_node **stack_b)
{
    t_node  *first;
    t_node  *second;

    if (!*stack_b || !(*stack_b)->next)
        return ;
    first = *stack_b;
    second = (*stack_b)->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    write(1, "sb\n", 3);
}

void    ss(t_node **stack_a, t_node **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1, "ss\n", 3);
}
