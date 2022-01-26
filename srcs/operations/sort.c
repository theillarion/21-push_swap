#include "operations.h"

void	ft_main_sort(t_main	*main_struct)
{
	if (ft_size(&main_struct->a) == 2)
		ft_swap(&main_struct->a, &main_struct->operations, sa);
}
