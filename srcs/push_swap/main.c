/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/01/31 16:10:24 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_main	main_struct;

	ft_initial_struct(&main_struct);
	if (argc > 1)
	{
		ft_fill_vector(&main_struct, ++argv);
		if (ft_vector_is_sorted(main_struct.vector))
			ft_success(&main_struct);
		if (!ft_validation(main_struct.vector, &main_struct.sorted_vector))
			ft_error(&main_struct, "Error");
		ft_fill_stack(&main_struct);
		ft_fill_values(&main_struct);
		ft_main_sort(&main_struct);
		ft_print_operations(main_struct.operations);
		ft_deinitial_struct(&main_struct);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
}
