#include "push_swap.h"

void	ft_presort(t_main	*_main)
{
	while (ft_size(_main->a) != 2)
	{
		if (ft_top(_main->a) == _main->value.min
			|| ft_top(_main->a) == _main->value.max)
		{
			ft_rotate(&_main->a, &_main->operations, true);
			continue ;
		}
		ft_push(&_main->a, &_main->b, &_main->operations, false);
		if (ft_top(_main->b) > _main->value.middle && _main->b->next != NULL)
			ft_rotate(&_main->b, &_main->operations, false);
	}
}

void	ft_sort_full(t_main	*_main)
{
	ft_presort(_main);
	while (!ft_empty(_main->b))
	{
		ft_set_score(_main);
		ft_do_operations(_main);
	}
	ft_finaly_rotate(_main);
}
