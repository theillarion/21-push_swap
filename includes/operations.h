#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "vector.h"

typedef struct s_main
{
	t_stack		*a;
	t_stack		*b;
	t_vector	digits;
	t_vector	operations;
}				t_main;

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

void	ft_swap(t_stack	**head, t_vector	*operations, int operation);
void	ft_push(t_stack	**src, t_stack	**dest, t_vector	*operations, int operation);
void	ft_rotate(t_stack	**head, t_vector	*operations, int operation);
void	ft_reverse_rotate(t_stack	**head, t_vector	*operations, int operation);
bool	ft_validation(const t_vector vector);

void	ft_main_sort(t_main	*main_struct);

#endif