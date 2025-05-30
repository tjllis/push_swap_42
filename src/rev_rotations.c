#include "../includes/push_swap.h"

// typedef struct	s_stack
// {
// 	int	*arr;
// 	int	size;
// 	int	top;
// }	t_stack;

void	rra(t_stack *stack, int is_to_print)
{
	int	i;
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack->arr[0];
	i = 0;
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->top] = temp;
	if (is_to_print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack, int is_to_print)
{
	int	i;
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack->arr[0];
	i = 0;
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->top] = temp;
	stack->arr[0] = temp;
	if (is_to_print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}