#include "../includes/push_swap.h"

#include <stdio.h>

int main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	int *arr;
	int capacity;

	if (ac < 2)
		return (EXIT_SUCCESS);
	if (ac == 2)
		capacity = count_spaces(av[1]);
	if (ac > 2)
		capacity = ac - 1;
	if (ac == 2)
		arr = process_one_str(av[1], capacity);
	if (ac > 2)
		arr = process_mult_str(ac, av);
	if (arr == NULL)
		ft_quit();
	a = create_stack(capacity);
	b = create_stack(capacity);
	if (a == NULL || b == NULL)
		ft_clean_quit(a, b);
	fill_stack(a, arr);
	main_sort(a, b);
	success_clean(a, b, arr);
	return (EXIT_SUCCESS);
}