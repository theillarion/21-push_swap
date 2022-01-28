#include "push_swap.h"

bool	ft_stack_is_sorted(t_stack	*stack)
{
	if (stack != NULL)
	{
		while (stack->next != NULL)
		{
			if (stack->data > stack->next->data)
				return (false);
			stack = stack->next;
		}
		return (true);
	}
	return (true);
}

bool ft_vector_is_sorted(const t_vector	vector)
{
	size_t	i;

	i = 0;
	while (i < vector.count - 1)
	{
		if (vector.elements[i] > vector.elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}
