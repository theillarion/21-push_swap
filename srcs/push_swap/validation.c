#include "push_swap.h"

bool ft_validation(const t_vector	vector)
{
	t_vector	vec;
	size_t	i;
	
	vec = ft_get_copy_vector(vector);
	ft_sort_vector(&vec);
	i = 0;
	while (i < vec.count - 1)
	{
		if (vec.elements[i] == vec.elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}
