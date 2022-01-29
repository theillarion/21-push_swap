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

void	ft_main_sort(t_main	*main_struct)
{
	if (main_struct->vector.count == 2)
		ft_sort_2(&main_struct->a, &main_struct->operations, true);
	else if (main_struct->vector.count == 3)
		ft_sort_3(&main_struct->a, &main_struct->operations, true);
	else if (main_struct->vector.count > 3 && main_struct->vector.count < 7)
		ft_sort_mini(main_struct);
	else if (ft_is_non_strict_sorted(main_struct->vector))
		ft_non_strict_sort(main_struct);
	else
		ft_sort_full(main_struct);
}
