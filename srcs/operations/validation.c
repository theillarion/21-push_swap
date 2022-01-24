#include "operations.h"

bool ft_validation(t_vector	*vector)
{
	size_t	i;
	
	if (!ft_sort(vector))
		return (false);
	i = 0;
	while (i < vector->count - 1)
	{
		if (vector->elements[i] == vector->elements[i + 1])
			return (false);
		++i;
	}
	return (true);
}
