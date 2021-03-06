#ifndef SHARED_H
# define SHARED_H

# include "operations.h"
# include "vector.h"
# include "stack.h"

typedef struct s_value
{
	int	min;
	int	middle;
	int	max;
}		t_value;

typedef struct s_main
{
	t_stack		*a;
	t_stack		*b;
	t_vector	vector;
	t_vector	sorted_vector;
	t_vector	operations;
	t_value		value;
}				t_main;

bool	ft_validation(const t_vector	src, t_vector	*dest);

void	ft_error(t_main	*main_struct, char	*message);
void	ft_success(t_main	*main_struct);

void	ft_initial_struct(t_main	*main_struct);
void	ft_deinitial_struct(t_main	*main_struct);

void	ft_fill_vector(t_main	*main_struct, char	**argv);
void	ft_fill_stack(t_main	*main_struct);
void	ft_fill_values(t_main	*main_struct);

bool	ft_vector_is_sorted(const t_vector	vector);
bool	ft_stack_is_sorted(t_stack	*stack);

#endif