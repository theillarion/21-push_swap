/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/02/02 23:34:26 by illarion         ###   ########.fr       */
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
		ft_success(&main_struct);
	}
	exit(EXIT_FAILURE);
}
