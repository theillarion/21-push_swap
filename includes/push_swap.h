#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "operations.h"
# include "stack.h"
# include "vector.h"
# include "shared.h"
# include "sort.h"
//	FORBIDDEN	HEADER
# include "forbidden_func.h"

int		main(int argc, char	**argv);

int		ft_abs(int value);
int		ft_get_max(const t_stack	*head);
int		ft_get_min(const t_stack	*head);

void	ft_print_operations(t_vector	operations);

#endif