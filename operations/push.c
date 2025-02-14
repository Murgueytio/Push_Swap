#include "push_swap.h"

void pa(long *stack_a, long *stack_b, int *numbers_a, int *numbers_b)
{
    if (*numbers_b > 0)
    {
        int i;
    
        i = *numbers_a;
        while (i > 0)
        {
            stack_a[i] = stack_a[i - 1];
            i--;
        }
        stack_a[0] = stack_b[0];
        (*numbers_a)++;
        (*numbers_b)--;
        int j;
        j = 0;
        while (j < *numbers_b - 1)
        {
            stack_b[j] = stack_b[j + 1];
            j++;
        }
    }
    write(1, "Push Stack B to A\n", 19);
}

void pb(long *stack_a, long *stack_b, int *numbers_a, int *numbers_b)
{
    if (*numbers_a > 0)
    {
        int i;
    
        i = *numbers_b;
        while (i > 0)
        {
            stack_b[i] = stack_b[i - 1];
            i--;
        }
        stack_b[0] = stack_a[0];
        (*numbers_b)++;
        (*numbers_a)--;
        int j;
        j = 0;
        while (j < *numbers_a - 1)
        {
            stack_a[j] = stack_a[j + 1];
            j++;
        }
    }
    write(1, "Push Stack A to B\n", 19);
}
