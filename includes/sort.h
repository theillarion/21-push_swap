#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
# include <stdbool.h>

void	ft_main_sort(t_main	*main_struct);

void	ft_sort_mini(t_main	*main_struct);
void	ft_sort_2(t_stack	**stack, t_vector	*operations, bool is_stack_a);
void	ft_sort_3(t_stack	**stack, t_vector	*operations, bool is_stack_a);

void	ft_sort_full(t_main	*main_struct);
void	ft_presort(t_main	*_main);
void	ft_do_operations(t_main	*_main);
void	ft_set_score(t_main	*_main);
void	ft_finaly_rotate(t_main	*_main);

bool	ft_is_non_strict_sorted(const t_vector vector, const t_value value);
void 	ft_non_strict_sort(t_main	*main);

bool	ft_is_reverse_sorted(const t_vector vector);
void	ft_reverse_sort(t_main	*main_struct);

#endif