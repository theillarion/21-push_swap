#include "operations.h"

void	ft_error(t_main	*main_struct, char	*message)
{
	ft_deinitial_struct(main_struct);
	if (message != NULL)
		ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_success(t_main	*main_struct)
{
	ft_deinitial_struct(main_struct);
	exit(EXIT_SUCCESS);
}
