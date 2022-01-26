#include "operations.h"

t_vector	ft_get_copy_vector(const t_vector	vector)
{
	size_t		i;
	t_vector	new_vector;

	ft_initial_vector(&new_vector);
	i = 0;
	new_vector.elements = (int *)malloc(sizeof(int) * vector.count);
	while (i < vector.count)
	{
		new_vector.elements[i] = vector.elements[i];
		++i;
	}
	new_vector.count = vector.count;
	return (new_vector);
}

bool ft_validation(const t_vector	vector)
{
	t_vector	vec;
	size_t	i;
	
	vec = ft_get_copy_vector(vector);
	if (!ft_sort_vector(&vec))
		return (false);
	i = 0;
	while (i < vec.count - 1)
	{
		if (vec.elements[i] == vec.elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}
