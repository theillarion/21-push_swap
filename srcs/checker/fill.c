#include "checker.h"

static bool	ft_push_operation(t_vector	*vector, int operation)
{
	ft_push_back(vector, operation);
	return (true);
}

static bool	ft_fill_vector_checker(t_vector	*vector, const char	*buff)
{
	if (ft_strncmp(buff, "sa", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, sa));
	else if (ft_strncmp(buff, "sb", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, sb));
	else if (ft_strncmp(buff, "ss", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, ss));
	else if (ft_strncmp(buff, "pa", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, pa));
	else if (ft_strncmp(buff, "pb", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, pb));
	else if (ft_strncmp(buff, "ra", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, ra));
	else if (ft_strncmp(buff, "rb", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, rb));
	else if (ft_strncmp(buff, "rr", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, rr));
	else if (ft_strncmp(buff, "rra", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, rra));
	else if (ft_strncmp(buff, "rrb", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, rrb));
	else if (ft_strncmp(buff, "rrr", ft_strlen(buff)) == 0)
		return (ft_push_operation(vector, rrr));
	else
		return (false);
}

void	ft_fill_operations(t_main	*main_struct)
{
	char	**operations;
	char	*buff;
	size_t	i;

	buff = ft_read(main_struct, 0);
	i = 0;
	operations = ft_split(buff, '\n');
	while (operations && operations[i])
	{
		if (!ft_fill_vector_checker(&main_struct->operations, operations[i]))
		{
			while (operations[i])
				free(operations[i++]);
			free(operations);
			ft_error(main_struct, "Error");
		}
		free(operations[i++]);
	}
	free(operations);
}
