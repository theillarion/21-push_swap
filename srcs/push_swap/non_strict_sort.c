#include "push_swap.h"

bool	ft_is_non_strict_sorted(const t_vector vector, const t_value value)
{
	size_t	i;
	size_t	min_i;

	i = 0;
	while (i < vector.count)
	{
		if (vector.elements[i] == value.min)
			break ;
		++i;
	}	
	min_i = i;
	while (i != min_i - 1)
	{
		if (i == vector.count)
			i = 0;
		if (i + 1 == vector.count)
		{
			if (vector.elements[i] > vector.elements[0])
				return (false);
		}	
		else if (vector.elements[i] > vector.elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}

static int	ft_get_min_index(const t_stack	*head)
{
	int		min;
	size_t	min_index;
	size_t	index;
	size_t	size;

	size = ft_size(head);
	min = INT_MAX;
	index = 0;
	while (head != NULL)
	{
		if (head->data < min)
		{
			min = head->data;
			min_index = index;
		}
		++index;
		head = head->next;
	}
	if (min_index <= size - min_index)
		return (min_index);
	else
		return (-(size - min_index));
}

void 	ft_non_strict_sort(t_main	*main)
{
	int		min_index;
	int		i;

	min_index = ft_get_min_index(main->a);
	i = -1;
	if (min_index < 0)
		i = 1;
	while (min_index != 0)
	{
		if (i == -1)
			ft_rotate(&main->a, &main->operations, true);
		else
			ft_reverse_rotate(&main->a, &main->operations, true);
		min_index += i;
	}
}
