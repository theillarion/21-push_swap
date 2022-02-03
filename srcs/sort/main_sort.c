#include "sort.h"

void	ft_main_sort(t_main	*main_struct)
{
	if (main_struct->vector.count == 2)
		ft_sort_2(&main_struct->a, &main_struct->operations, true);
	else if (main_struct->vector.count == 3)
		ft_sort_3(&main_struct->a, &main_struct->operations, true);
	else if (main_struct->vector.count > 3 && main_struct->vector.count < 7)
		ft_sort_mini(main_struct);
	else if (ft_is_reverse_sorted(main_struct->vector))
		ft_reverse_sort(main_struct);
	else if (ft_is_non_strict_sorted(main_struct->vector, main_struct->value))
		ft_non_strict_sort(main_struct);
	else
		ft_sort_full(main_struct);
}
