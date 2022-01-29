#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_vector
{
	int		*elements;
	size_t	count;
}			t_vector;

void		ft_initial_vector(t_vector	*vector);
void		ft_push_back(t_vector	*vector, int element);
int			ft_get_back(const t_vector vector);
size_t		ft_get_count(const t_vector vector);
t_vector	ft_get_copy_vector(const t_vector	vector);
void		ft_delete_vector(t_vector	*vector);
bool		ft_sort_vector(t_vector	*vector);
void		ft_erase_back(t_vector	*vector);
bool		ft_empty_vector(const t_vector vector);

#endif
