#include "push_swap.h"

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

void	ft_fill_vector(t_main	*main_struct, char	**argv)
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
			ft_push_back(&main_struct->vector, ft_atoi(buff[i]));
			free(buff[i++]);
		}
		free(buff);
	}
}

void	ft_fill_stack(t_main	*main_struct)
{
	int	i;

	i = main_struct->vector.count - 1;
	while (i >= 0)
	{
		ft_push_front(&main_struct->a, main_struct->vector.elements[i]);
		--i;
	}
}

void ft_fill_values(t_main	*main_struct)
{
	main_struct->value.min = main_struct->sorted_vector.elements[0];
	main_struct->value.max = main_struct->sorted_vector.elements[main_struct->vector.count - 1];
	main_struct->value.middle = main_struct->sorted_vector.elements[main_struct->vector.count / 2 - 1];
}
