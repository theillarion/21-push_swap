#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
#include <stdbool.h>

typedef struct s_vector
{
	int		*elements;
	size_t	count;
}			t_vector;

void	ft_initial(t_vector	*vector);
void 	ft_push_back(t_vector	*vector, int element);
int		ft_get_element(const t_vector vector, size_t index);
size_t	ft_get_count(const t_vector vector);
void	ft_delete_vector(t_vector	*vector);
bool	ft_sort(t_vector	*vector);

#endif
