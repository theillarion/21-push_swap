#include "push_swap.h"

bool	ft_validation(const t_vector	src, t_vector	*dest)
{
	size_t		i;

	*dest = ft_get_copy_vector(src);
	ft_sort_vector(dest);
	i = 0;
	while (i < dest->count - 1)
	{
		if (dest->elements[i] == dest->elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}
