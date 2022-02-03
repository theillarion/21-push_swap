#include "checker.h"

static void	ft_do(t_main	*main_struct, int operation)
{
	if (operation == sa || operation == ss)
		ft_swap(&main_struct->a, NULL, true);
	if (operation == sb || operation == ss)
		ft_swap(&main_struct->b, NULL, false);
	if (operation == pa)
		ft_push(&main_struct->b, &main_struct->a, NULL, true);
	if (operation == pb)
		ft_push(&main_struct->a, &main_struct->b, NULL, false);
	if (operation == ra || operation == rr)
		ft_rotate(&main_struct->a, NULL, true);
	if (operation == rb || operation == rr)
		ft_rotate(&main_struct->b, NULL, false);
	if (operation == rra || operation == rrr)
		ft_reverse_rotate(&main_struct->a, NULL, true);
	if (operation == rrb || operation == rrr)
		ft_reverse_rotate(&main_struct->b, NULL, false);
}

bool	ft_check(t_main	*main_struct)
{
	size_t	i;

	i = 0;
	while (i < main_struct->operations.count)
	{
		ft_do(main_struct, main_struct->operations.elements[i]);
		++i;
	}
	if (ft_empty(main_struct->b) && ft_stack_is_sorted(main_struct->a))
		return (true);
	return (false);
}
