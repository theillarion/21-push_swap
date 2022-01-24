#include "vector.h"

static void	ft_xor_swap(int	*element1, int	*element2)
{
	if (*element1 != *element2)
	{
		*element1 ^= *element2;
		*element2 ^= *element1;
		*element1 ^= *element2;
	}
}

bool	ft_sort(t_vector	*vector)
{
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	small_index;
	bool	is_sort;

	is_sort = false;
	count = ft_get_count(*vector);
	i = 0;
	while (i < count - 1)
	{
		small_index = i;
		j = i + 1;
		while (j < count)
		{
			if (vector->elements[j] < vector->elements[small_index])
				small_index = j;
			++j;
		}
		if (i != small_index)
			is_sort = true;
		ft_xor_swap(&vector->elements[i], &vector->elements[small_index]);
		++i;
	}
	return (is_sort);
}
