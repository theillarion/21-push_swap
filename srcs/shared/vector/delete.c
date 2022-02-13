#include "vector.h"

void	ft_erase_back(t_vector	*vector)
{
	size_t	i;
	int		*result;

	if (vector->elements == NULL)
		return ;
	if (vector->count == 1)
	{
		vector->count = 0;
		free(vector->elements);
		vector->elements = NULL;
		return ;
	}
	result = (int *)malloc(sizeof(int) * (vector->count - 1));
	i = 0;
	while (i < vector->count - 1)
	{
		result[i] = vector->elements[i];
		++i;
	}
	free(vector->elements);
	vector->count -= 1;
	vector->elements = result;
}

void	ft_delete_vector(t_vector	*vector)
{
	if (vector->elements != NULL)
	{
		free(vector->elements);
		vector->elements = NULL;
		vector->count = 0;
	}
}
