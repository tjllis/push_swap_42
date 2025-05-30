#include "../includes/push_swap.h"

void	ft_quit()
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_clean_quit(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	success_clean(t_stack *a, t_stack *b, int *arr)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (arr)
		free(arr);
}