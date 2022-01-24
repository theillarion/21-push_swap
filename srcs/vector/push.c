#include "vector.h"

void 	ft_push_back(t_vector	*vector, int element)
{
	int		*result;
	size_t	i;

	i = 0;
	if (vector->elements == NULL)
		vector->count = 0;
	result = (int *)malloc(sizeof(int) * (vector->count + 1));
	if (result == NULL)
		return ;
	while (i < vector->count)
	{
		result[i] = vector->elements[i];
		++i;
	}
	result[i] = element;
	vector->count += 1;
	if (vector->elements != NULL)
		free(vector->elements);
	vector->elements = result; 
}
