/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/01/24 15:00:32 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"
#include <stdio.h>

void	ft_error(t_stack	*stack)
{
	while (!ft_empty(&stack))
		ft_pop(&stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

bool	ft_chars_is_digit(const char	*str)
{
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (false);
	return (true);
}

t_stack	*ft_fill_stack(char	**argv)
{
	size_t	i;
	char	**buff;
	t_stack	*stack;

	while (*argv)
	{
		buff = NULL;
		i = 0;
		buff = ft_split(*(argv++), ' ');
		while (buff[i] != NULL)
		{
			if (!ft_chars_is_digit(buff[i]))
				ft_error(stack);
			ft_push(&stack, ft_atoi(buff[i]));
			free(buff[i++]);
		}
		free(buff);
	}
	return (stack);
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

int	main(int argc, char	**argv)
{
	t_stack	*a;
	t_stack	*b;


	(void)b;
	(void)argc;
	if (argc > 1)
	{
		a = ft_fill_stack(++argv);
		print_stack(a);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* ERROR */
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
