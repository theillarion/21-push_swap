#include "push_swap.h"

void	ft_initial_struct(t_main	*main_struct)
{
	main_struct->a = NULL;
	main_struct->b = NULL;
	ft_initial_vector(&main_struct->vector);
	ft_initial_vector(&main_struct->sorted_vector);
	ft_initial_vector(&main_struct->operations);
}

void	ft_deinitial_struct(t_main	*main_struct)
{
	while (!ft_empty(main_struct->a))
		ft_pop(&main_struct->a);
	while (!ft_empty(main_struct->b))
		ft_pop(&main_struct->b);
	ft_delete_vector(&main_struct->vector);
	ft_delete_vector(&main_struct->sorted_vector);
	ft_delete_vector(&main_struct->operations);
}

// FOR THE FUTURE: delete vector copy