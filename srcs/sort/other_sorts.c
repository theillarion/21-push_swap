#include "push_swap.h"

bool	ft_is_non_strict_sorted(const t_vector vector)
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
}

void	ft_non_strict_sort(t_main	*_main)
{
	while (ft_size(_main->a) != 3)
		ft_push(&_main->a, &_main->b,
			&_main->operations, false);
	ft_sort_3(&_main->a, &_main->operations, true);
	while (!ft_empty(_main->b))
	{
		ft_push(&_main->b, &_main->a,
			&_main->operations, true);
		ft_rotate(&_main->a, &_main->operations, true);
	}
}
