#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "vector.h"

void	ft_swap(t_stack	**head);
void	ft_push_(t_stack	**src, t_stack	**dest);
void	ft_rotate(t_stack	**head);
void	ft_reverse_rotate(t_stack	**head);
bool	ft_validation(t_vector	*vector);

#endif