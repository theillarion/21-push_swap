#include "operations.h"

bool ft_is_sorted_vector(const t_vector	vector)
{
	size_t	i;

	i = 0;
	while (i < vector.count - 1)
	{
		if (vector.elements[i] > vector.elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}

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
