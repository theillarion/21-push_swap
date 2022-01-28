/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/01/28 16:31:03 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	!!!	FORBIDDEN FUNCTION	!!!
*/

void	print_stack(t_stack	*stack)
{
	printf("Count elements: %lu\nElements:\n", ft_size(stack));
	while (!ft_empty(stack))
	{
		printf("%d", ft_top(stack));
		ft_pop(&stack);
		if (!ft_empty(stack))
			
			
			printf(" -> ");
	}
	printf("\n");
}

/*
	!!!	FORBIDDEN FUNCTION	!!!
*/

void	ft_print_vector(const t_vector vector)
{
	size_t	i;

	i = 0;
	printf("Count: %ld\nElements:\n", vector.count);
	while (i < vector.count)
	{
		if (i == vector.count - 1)
			printf("%d\n", vector.elements[i]);
		else
			printf("%d -> ", vector.elements[i]);
		++i;
	}
	printf("\n");
}

int	main(int argc, char	**argv)
{
	t_main	main_struct;

	ft_initial_struct(&main_struct);
	if (argc > 1)
	{
		ft_fill_vector(&main_struct, ++argv);
		if (ft_vector_is_sorted(main_struct.digits))
			ft_success(&main_struct);
		if (!ft_validation(main_struct.digits))
			ft_error(&main_struct, "Error");
		ft_fill_stack(&main_struct);
		ft_main_sort(&main_struct);
		ft_print_operations(main_struct.operations);
		ft_deinitial_struct(&main_struct);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
}
