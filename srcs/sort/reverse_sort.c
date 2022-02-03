#include "sort.h"

static int	ft_get_max_index(const t_stack	*head)
{
	int		max;
	size_t	max_index;
	size_t	index;
	size_t	size;

	size = ft_size(head);
	max = INT_MIN;
	index = 0;
	while (head != NULL)
	{
		if (head->data > max)
		{
			max = head->data;
			max_index = index;
		}
		++index;
		head = head->next;
	}
	if (max_index <= size - max_index)
		return (max_index);
	else
		return (-(size - max_index));
}

bool	ft_is_reverse_non_strict_sorted(const t_vector vector, const t_value value)
{
	size_t	i;
	size_t	max_i;

	i = 0;
	while (i < vector.count)
	{
		if (vector.elements[i] == value.max)
			break ;
		++i;
	}	
	max_i = i;
	if (max_i == 0)
		max_i = vector.count;
	while (i != max_i - 1)
	{
		if (i == vector.count)
			i = 0;
		if (i + 1 == vector.count)
		{
			if (vector.elements[i] < vector.elements[0])
				return (false);
		}	
		else if (vector.elements[i] < vector.elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}

/*bool	ft_is_reverse_sorted(const t_vector vector)
{
	size_t	i;

	i = 0;
	while (i < vector.count - 1)
	{
		if (vector.elements[i] < vector.elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}*/

void	ft_reverse_non_strict_sort(t_main	*main)
{
	int		max_index;
	int		i;

	max_index = ft_get_max_index(main->a);
	i = -1;
	if (max_index < 0)
		i = 1;
	while (max_index != 0)
	{
		if (i == -1)
			ft_rotate(&main->a, &main->operations, true);
		else
			ft_reverse_rotate(&main->a, &main->operations, true);
		max_index += i;
	}
	while (ft_size(main->a) != 3)
		ft_push(&main->a, &main->b,
			&main->operations, false);
	ft_sort_3(&main->a, &main->operations, true);
	while (!ft_empty(main->b))
	{
		ft_push(&main->b, &main->a,
			&main->operations, true);
		ft_rotate(&main->a, &main->operations, true);
	}
}
