#include "../includes/push_swap.h"
#include <stdio.h>

// typedef struct	s_stack
// {
// 	int	*arr;
// 	int	size;
// 	int	top;
// }	t_stack;

static int find_min_index(t_stack *stack)
{
	int min;
	int i;
	int index;

	i = 0;
	index = 0;
	min = INT_MAX;
	while (i <= stack->top)
	{
		// printf("i = %d, arr[i] = %d\n", i, stack->arr[i]);
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			index = i;
		}
		i++;
	}
	// printf("Min = %d, min_index = %d\n", min, index);
	return (index);
}

static void sort_3(t_stack *stack)
{
	int bottom;
	int middle;
	int top;

	bottom = stack->arr[0];
	middle = stack->arr[1];
	top = stack->arr[2];
	// bottom [3 2 1] top
	if (is_sorted(stack))
		return;
	// bottom [3 1 2] top
	if (bottom > middle && bottom > top && middle < top)
		sa(stack, 1);
	// bottom [1 2 3] top
	else if (bottom < middle && bottom < top && middle < top)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	// bottom [2 3 1] top
	else if (middle > top && middle > bottom && top < bottom)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	// bottom [1 3 2] top
	else if (middle > top && middle > bottom && top > bottom)
		rra(stack, 1);
	// bottom [2 1 3] top
	else if (top > bottom && top > middle)
		ra(stack, 1);
}

static void sort_4(t_stack *a, t_stack *b)
{
	int min_index;

	if (is_sorted(a))
		return;
	min_index = find_min_index(a);
	if (min_index != a->top)
		move_to_top(a, min_index);
	pb(a, b);
	// int i = 0;
	// printf("a in process: BOTTOM: ");
	// while (i <= a->top)
	// {
	// 	printf("%d ", a->arr[i]);
	// 	i++;
	// }
	// printf("TOP\n");
	sort_3(a);
	pa(a, b);
}

static void sort_5(t_stack *a, t_stack *b)
{
	int min_index;

	if (is_sorted(a))
		return;
	min_index = find_min_index(a);
	if (min_index != a->top)
		move_to_top(a, min_index);
	pb(a, b);
	// int i = 0;
	// printf("a after pb: BOTTOM: ");
	// while (i <= a->top)
	// {
	// 	printf("%d ", a->arr[i]);
	// 	i++;
	// }
	// printf("TOP\n");
	// i = 0;
	// printf("b after pb: BOTTOM: ");
	// while (i <= b->top)
	// {
	// 	printf("%d ", b->arr[i]);
	// 	i++;
	// }
	// printf("TOP\n");
	sort_4(a, b);
	// i = 0;
	// printf("a after sort_4: BOTTOM: ");
	// while (i <= a->top)
	// {
	// 	printf("%d ", a->arr[i]);
	// 	i++;
	// }
	// printf("TOP\n");
	while (!is_empty(b))
		pa(a, b);
}

void small_sort(t_stack *a, t_stack *b)
{
	int size;

	if (is_sorted(a) || is_empty(a) || a->size == 1)
		return;
	size = a->size;
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3(a);
	// else if (size == 4 || size == 5)
	// 	sort_4_5(a, b);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	int i = 0;
	printf("BOTTOM ");
	while (i < a->size)
	{
		printf("%d ", a->arr[i]);
		i++;
	}
	printf("TOP\n");
}