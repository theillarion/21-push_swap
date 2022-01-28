#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "vector.h"
# include "libft.h"

typedef enum e_operations
{
	sa = 1,
	sb = 2,
	ss = sa + sb,
	pa = 4,
	pb = 8,
	ra = 16,
	rb = 32,
	rr = ra + rb,
	rra = 64,
	rrb = 128,
	rrr = rra + rrb
}	t_operations;

void	ft_swap(t_stack	**head, t_vector	*operations, bool is_stack_a);
void	ft_push(t_stack	**src, t_stack	**dest, t_vector	*operations, bool is_stack_a);
void	ft_rotate(t_stack	**head, t_vector	*operations, bool is_stack_a);
void	ft_reverse_rotate(t_stack	**head, t_vector	*operations, bool is_stack_a);

#endif