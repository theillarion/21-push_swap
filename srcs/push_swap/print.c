#include "push_swap.h"

static void	ft_handler_operation(int operation)
{
	if (operation == sa)
		write(1, "sa\n", 3);
	else if (operation == sb)
		write(1, "sb\n", 3);
	else if (operation == ss)
		write(1, "ss\n", 3);
	else if (operation == pa)
		write(1, "pa\n", 3);
	else if (operation == pb)
		write(1, "pb\n", 3);
	else if (operation == ra)
		write(1, "ra\n", 3);
	else if (operation == rb)
		write(1, "rb\n", 3);
	else if (operation == rr)
		write(1, "rr\n", 3);
	else if (operation == rra)
		write(1, "rra\n", 4);
	else if (operation == rrb)
		write(1, "rrb\n", 4);
	else if (operation == rrr)
		write(1, "rrr\n", 4);
}

void	ft_print_operations(t_vector	operations)
{
	size_t	i;

	i = 0;
	while (i < operations.count)
	{
		ft_handler_operation(operations.elements[i]);
		++i;
	}
}
