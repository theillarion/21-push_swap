#include "push_swap.h"

void ft_print_operations(t_vector	operations)
{
	size_t	i;

	i = 0;
	while (i < operations.count)
	{
		if (operations.elements[i] == sa)
			write(1, "sa\n", 3);
		else if (operations.elements[i] == sb)
			write(1, "sb\n", 3);
		else if (operations.elements[i] == ss)
			write(1, "ss\n", 3);
		else if (operations.elements[i] == pa)
			write(1, "pa\n", 3);
		else if (operations.elements[i] == pb)
			write(1, "pb\n", 3);
		else if (operations.elements[i] == ra)
			write(1, "ra\n", 3);
		else if (operations.elements[i] == rb)
			write(1, "rb\n", 3);
		else if (operations.elements[i] == rr)
			write(1, "rr\n", 3);
		else if (operations.elements[i] == rra)
			write(1, "rra\n", 4);
		else if (operations.elements[i] == rrb)
			write(1, "rrb\n", 4);
		else if (operations.elements[i] == rrr)
			write(1, "rrr\n", 4);
		++i;
	}
}
