#include "push_swap.h"

void	ft_non_strict_sort(t_main	*main_struct)
{
	while (ft_size(main_struct->a) != 3)
		ft_push(&main_struct->a, &main_struct->b,
			&main_struct->operations, false);
	ft_sort_3(&main_struct->a, &main_struct->operations, true);
	while (!ft_empty(main_struct->b))
	{
		ft_push(&main_struct->b, &main_struct->a,
			&main_struct->operations, true);
		ft_rotate(&main_struct->a, &main_struct->operations, true);
	}
}

void	ft_sort_full(t_main	*main_struct)
{
	(void)main_struct;
}
/*
	IN FUTURE
*/