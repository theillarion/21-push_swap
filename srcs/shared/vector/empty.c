#include "vector.h"

bool	ft_empty_vector(const t_vector vector)
{
	if (vector.elements == NULL || vector.count == 0)
		return (true);
	return (false);
}
