#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"

int		main(int argc, char	**argv);
void	ft_fill_operations(t_main	*main_struct);
bool	ft_check(t_main	*main_struct);
char	*ft_read(t_main	*main_struct, int fd);

#endif