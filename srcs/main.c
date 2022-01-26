/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/01/26 18:42:26 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"
#include <stdio.h>

void	ft_error(t_vector	*vector)
{
	ft_delete_vector(vector);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

bool	ft_chars_is_digit(const char	*str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-')
			return (false);
		++str;
	}
	return (true);
}

void	ft_fill_vector(t_vector	*vector,char	**argv)
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
				ft_error(vector);
			ft_push_back(vector, ft_atoi(buff[i]));
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

void	ft_initial_main(t_main	*main_struct)
{
	main_struct->a = NULL;
	main_struct->b = NULL;
	ft_initial_vector(&main_struct->digits);
	ft_initial_vector(&main_struct->operations);
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

int	main(int argc, char	**argv)
{
	t_main	main_struct;
	/*t_vector	vector;
	t_stack		*a;
	t_stack		*b;

	(void)a;
	(void)b;
	(void)argc;
	ft_initial_vector(&vector);*/
	ft_initial_main(&main_struct);
	if (argc > 1)
	{
		ft_fill_vector(&main_struct.digits, ++argv);
		ft_print_vector(main_struct.digits);
		if (!ft_validation(main_struct.digits))
		{
			write(1, "Error: not validation\n", 22);
			exit(EXIT_FAILURE);
		}
		int	i = main_struct.digits.count - 1;
		while (i >= 0)
		{
			ft_push_front(&main_struct.a, main_struct.digits.elements[i]);
			--i;
		}
		ft_main_sort(&main_struct);
		ft_print_operations(main_struct.operations);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* ERROR */
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
