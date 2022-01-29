#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "operations.h"
# include "stack.h"
# include "vector.h"
# include <stdio.h>

typedef struct s_main
{
	t_stack		*a;
	t_stack		*b;
	t_vector	vector;
	t_vector	operations;
}				t_main;

int		main(int argc, char	**argv);
bool	ft_validation(const t_vector vector);

bool	ft_vector_is_sorted(const t_vector	vector);
bool	ft_stack_is_sorted(t_stack	*stack);

void	ft_initial_struct(t_main	*main_struct);
void	ft_deinitial_struct(t_main	*main_struct);
void	ft_error(t_main	*main_struct, char	*message);
void	ft_success(t_main	*main_struct);

int		ft_max(const t_stack	*head);
int		ft_min(const t_stack	*head);

void	ft_fill_vector(t_main	*main_struct, char	**argv);
void	ft_fill_stack(t_main	*main_struct);

void	ft_non_strict_sort(t_main	*main_struct);
void	ft_sort_full(t_main	*main_struct);
void	ft_sort_mini(t_main	*main_struct);

void	ft_sort_2(t_stack	**stack, t_vector	*operations, bool is_stack_a);
void	ft_sort_3(t_stack	**stack, t_vector	*operations, bool is_stack_a);

void	ft_main_sort(t_main	*main_struct);

void	ft_print_operations(t_vector	operations);

#endif