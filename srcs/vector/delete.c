#include "vector.h"

void	ft_delete_vector(t_vector	*vector)
{
	if (vector->elements != NULL)
	{
		free(vector->elements);
		vector->elements = NULL;
		vector->count = 0;
	}
}
