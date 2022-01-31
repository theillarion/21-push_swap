#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
# include <stdbool.h>

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

void	ft_main_sort(t_main	*main_struct);

void	ft_sort_mini(t_main	*main_struct);
void	ft_sort_2(t_stack	**stack, t_vector	*operations, bool is_stack_a);
void	ft_sort_3(t_stack	**stack, t_vector	*operations, bool is_stack_a);

void	ft_sort_full(t_main	*main_struct);
void	ft_presort(t_main	*_main);
void	ft_do_operations(t_main	*_main);
void	ft_set_score(t_main	*_main);
void	ft_finaly_rotate(t_main	*_main);

bool	ft_is_non_strict_sorted(const t_vector vector);
void	ft_non_strict_sort(t_main	*main_struct);

bool	ft_vector_is_sorted(const t_vector	vector);
bool	ft_stack_is_sorted(t_stack	*stack);

#endif