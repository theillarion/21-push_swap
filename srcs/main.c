/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/01/27 20:12:13 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"
#include <stdio.h>

static bool	ft_chars_is_digit(const char	*str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-')
			return (false);
		++str;
	}
	return (true);
}

void	ft_fill_vector(t_main	*main_struct,char	**argv)
{
	size_t		i;
	char		**buff;

	while (*argv)
	{
		buff = NULL;
		i = 0;
		buff = ft_split(*(argv++), ' ');
		while (buff[i] != NULL)
		{
			if (!ft_chars_is_digit(buff[i]))
				ft_error(main_struct, "Error");
			ft_push_back(&main_struct->digits, ft_atoi(buff[i]));
			free(buff[i++]);
		}
		free(buff);
	}
}

void	print_stack(t_stack	*stack)
{
	printf("Count elements: %lu\nElements:\n", ft_size(&stack));
	while (!ft_empty(&stack))
	{
		printf("%d", ft_top(&stack));
		ft_pop(&stack);
		if (!ft_empty(&stack))
			
			
			printf(" -> ");
	}
	printf("\n");
}

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

void ft_print_operations(t_vector	operations)
{
	size_t	i;

	i = 0;
	while (i < operations.count)
	{
		if (operations.elements[i] == sa)
			write(1, "sa\n", 3);
		else if (operations.elements[i] == sb)
			write(1, "sb\n", 3);
		else if (operations.elements[i] == ss)
			write(1, "ss\n", 3);
		else if (operations.elements[i] == pa)
			write(1, "pa\n", 3);
		else if (operations.elements[i] == pb)
			write(1, "pb\n", 3);
		else if (operations.elements[i] == ra)
			write(1, "ra\n", 3);
		else if (operations.elements[i] == rb)
			write(1, "rb\n", 3);
		else if (operations.elements[i] == rr)
			write(1, "rr\n", 3);
		else if (operations.elements[i] == rra)
			write(1, "rra\n", 4);
		else if (operations.elements[i] == rrb)
			write(1, "rrb\n", 4);
		else if (operations.elements[i] == rrr)
			write(1, "rrr\n", 4);
		++i;
	}
}

void	ft_fill_stack(t_main	*main_struct)
{
	int i;

	i = main_struct->digits.count - 1;
	while (i >= 0)
	{
		ft_push_front(&main_struct->a, main_struct->digits.elements[i]);
		--i;
	}
}

int	main(int argc, char	**argv)
{
	t_main	main_struct;

	ft_initial_struct(&main_struct);
	if (argc > 1)
	{
		ft_fill_vector(&main_struct, ++argv);
		if (ft_is_sorted_vector(main_struct.digits))
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
