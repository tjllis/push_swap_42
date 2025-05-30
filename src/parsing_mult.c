#include "../includes/push_swap.h"

int parse_mult_input(char **str, int *nums, int capacity)
{
	int i;
	int result;

	i = 0;
	while (i < capacity)
	{
		if (str[i + 1] == NULL)
			return (0);
		if (ft_atoi_safe(str[i + 1], &result) != ATOI_SUCCESS)
			return (0);
		if (is_found(nums, i, result))
			return (0);
		nums[i] = result;
		i++;
	}
	if (i == 2 && nums[0] == nums[1])
		return (0);
	return (i == capacity);
}

int *process_mult_str(int ac, char **av)
{
	int *arr;
	int success;

	arr = malloc(sizeof(int) * (ac - 1));
	if (arr == NULL)
		return (NULL);
	if (!is_numeric_mult(av))
	{
		free(arr);
		return (NULL);
	}
	success = parse_mult_input(av, arr, (ac - 1));
	if (!success)
	{
		free(arr);
		return (NULL);
	}
	// else
	// {
	// 	int i = 0;
	// 	while (i < (ac - 1))
	// 	{
	// 		printf("arr[i] = %d\n", arr[i]);
	// 		i++;
	// 	}
	// }
	return (arr);
}
