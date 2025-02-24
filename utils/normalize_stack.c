#include "push_swap.h"

// Copies the contents of src array into dest array.
static void copy_array(long *dest, long *src, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

// Sorts an array using bubble sort.
static void bubble_sort(long *arr, int size)
{
	int     i;
	int     j;
	long    tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// Replaces each element in the original stack with its index 
// in the sorted array.
static void replace_with_indices(long *stack, long *sorted, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack[i] == sorted[j])
			{
				stack[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

// Normalizes the stack by replacing each number with its index 
// in the sorted order.
void    normalize_stack(long *stack, int size)
{
	long    *copy;

	copy = malloc(sizeof(long) * size);
	if (!copy)
		exit(EXIT_FAILURE);
	copy_array(copy, stack, size);
	bubble_sort(copy, size);
	replace_with_indices(stack, copy, size);
	free(copy);
}
