/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/01/30 17:55:13 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	!!!	FORBIDDEN FUNCTION	!!!
*/

void	print_stack(t_stack	*stack)
{
	printf("Count elements: %lu\nElements:\n", ft_size(stack));
	while (stack)
	{
		printf("%d", stack->data);
		stack = stack->next;
		if (stack != NULL)
			printf(" -> ");
	}
	printf("\n");
}

/*
	!!!	FORBIDDEN FUNCTION	!!!
*/
/*
static void	ft_print_vector(const t_vector vector)
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
}*/

void ft_fill_value(t_main	*main_struct)
{
	main_struct->value.min = main_struct->sorted_vector.elements[0];
	main_struct->value.max = main_struct->sorted_vector.elements[main_struct->vector.count - 1];
	main_struct->value.middle = main_struct->sorted_vector.elements[main_struct->vector.count / 2];
}

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
		ft_fill_value(&main_struct);
		ft_main_sort(&main_struct);
		ft_print_operations(main_struct.operations);
		ft_deinitial_struct(&main_struct);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
}
