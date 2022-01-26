#include "vector.h"

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

int		ft_get_back(const t_vector vector)
{
	if (vector.elements != NULL)
		return (vector.elements[vector.count - 1]);
	return (INT_MIN);
}

int		ft_get_element(const t_vector	vector, size_t	index)
{
	if (vector.elements != NULL)
		return (vector.elements[index]);
	return (INT_MIN);
}

size_t	ft_get_count(const t_vector vector)
{
	if (vector.elements != NULL)
		return (vector.count);
	return (0);
}
