#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "operations.h"
# include "stack.h"
# include "vector.h"
# include "sort.h"
//	FORBIDDEN	HEADER
# include "forbidden_func.h"

int		main(int argc, char	**argv);

void	ft_error(t_main	*main_struct, char	*message);
void	ft_success(t_main	*main_struct);

void	ft_initial_struct(t_main	*main_struct);
void	ft_deinitial_struct(t_main	*main_struct);

bool	ft_validation(const t_vector	src, t_vector	*dest);

int		ft_abs(int value);
int		ft_get_max(const t_stack	*head);
int		ft_get_min(const t_stack	*head);

void	ft_fill_vector(t_main	*main_struct, char	**argv);
void	ft_fill_stack(t_main	*main_struct);
void	ft_fill_values(t_main	*main_struct);

void	ft_print_operations(t_vector	operations);

#endif