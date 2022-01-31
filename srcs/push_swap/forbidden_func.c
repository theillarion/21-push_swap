#include "forbidden_func.h"

/*
	!!!	FORBIDDEN	FILE	!!!
*/

void	ft_print_vector(const t_vector vector)
{
	size_t	i;

	i = 0;
	printf("Count: %ld\nElements:\n", vector.count);
	while (i < vector.count)
	{
		if (i == vector.count - 1)
			printf("%d\n", vector.elements[i]);
		else
			printf("%d -> ", vector.elements[i]);
		++i;
	}
	printf("\n");
}

void	print_stack(t_stack	*stack)
{
	printf("Count elements: %lu\nElements:\n", ft_size(stack));
	while (stack)
	{
		printf("%d", stack->data);
		stack = stack->next;
		if (stack != NULL)
			printf(" -> ");
	}
	printf("\n");
}
