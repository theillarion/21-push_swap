/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/01/25 00:01:25 by illarion         ###   ########.fr       */
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

int	main(int argc, char	**argv)
{
	t_vector	vector;
	t_stack		*a;
	t_stack		*b;

	(void)a;
	(void)b;
	(void)argc;
	ft_initial(&vector);
	if (argc > 1)
	{
		ft_fill_vector(&vector, ++argv);
		ft_print_vector(vector);
		if (!ft_validation(&vector))
		{
			write(1, "Error: not validation\n", 22);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* ERROR */
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
