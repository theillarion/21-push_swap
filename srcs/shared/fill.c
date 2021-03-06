#include "push_swap.h"

static bool	ft_prevalidation(const char	*str)
{
	size_t	count;
	size_t	i;
	bool	is_pos;

	i = 0;
	is_pos = true;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			is_pos = false;
	count = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
		++count;
	}
	if (count > 10 || count == 0
		|| (count == 10 && is_pos && ft_strncmp(str, "2147483647", count) > 0)
		|| (count == 10 && !is_pos && ft_strncmp(str, "2147483648", count) > 0))
		return (false);
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
			if (!ft_prevalidation(buff[i]))
			{
				free(buff[i]);
				free(buff);
				ft_error(main_struct, "Error");
			}
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

void	ft_fill_values(t_main	*main_struct)
{
	main_struct->value.min = main_struct->sorted_vector.elements[0];
	main_struct->value.max = main_struct->sorted_vector.elements
	[main_struct->vector.count - 1];
	main_struct->value.middle = main_struct->sorted_vector.elements
	[main_struct->vector.count / 2 - 1];
}
