#include "checker.h"

bool	ft_add(t_vector	*vector, int	operation)
{
	ft_push_back(vector, operation);
	return (true);
}

bool	ft_fill_vector__(t_vector	*vector, const char	*buff)
{
	if (ft_strncmp(buff, "sa", ft_strlen(buff)) == 0)
		return (ft_add(vector, sa));
	else if (ft_strncmp(buff, "sb", ft_strlen(buff)) == 0)
		return (ft_add(vector, sb));
	else if (ft_strncmp(buff, "ss", ft_strlen(buff)) == 0)
		return (ft_add(vector, ss));
	else if (ft_strncmp(buff, "pa", ft_strlen(buff)) == 0)
		return (ft_add(vector, pa));
	else if (ft_strncmp(buff, "pb", ft_strlen(buff)) == 0)
		return (ft_add(vector, pb));
	else if (ft_strncmp(buff, "ra", ft_strlen(buff)) == 0)
		return (ft_add(vector, ra));
	else if (ft_strncmp(buff, "rb", ft_strlen(buff)) == 0)
		return (ft_add(vector, rb));
	else if (ft_strncmp(buff, "rr", ft_strlen(buff)) == 0)
		return (ft_add(vector, rr));
	else if (ft_strncmp(buff, "rra", ft_strlen(buff)) == 0)
		return (ft_add(vector, rra));
	else if (ft_strncmp(buff, "rrb", ft_strlen(buff)) == 0)
		return (ft_add(vector, rrb));
	else if (ft_strncmp(buff, "rrr", ft_strlen(buff)) == 0)
		return (ft_add(vector, rrr));
	else
		return (false);
}

void	ft_fill_operations(t_main	*main_struct)
{
	char	*buff;

	buff = get_next_line(0);
	while (buff != NULL)
	{
		if (ft_fill_vector__(&main_struct->operations, buff) == false)
		{
			free(buff);
			ft_deinitial_struct(main_struct);
			exit(EXIT_FAILURE);
		}
		free(buff);
		buff = get_next_line(0);
	}
}

void	ft_do(t_main	*main_struct, int operation)
{
	if (operation == sa || operation == ss)
		ft_swap(&main_struct->a, NULL, true);
	if (operation == sb || operation == ss)
		ft_swap(&main_struct->b, NULL, false);	
	if (operation == pa)
		ft_push(&main_struct->b, &main_struct->a, NULL, true);
	if (operation == pb)
		ft_push(&main_struct->a, &main_struct->b, NULL, false);
	if (operation == ra || operation == rr)
		ft_rotate(&main_struct->a, NULL, true);
	if (operation == rb || operation == rr)
		ft_rotate(&main_struct->b, NULL, false);
	if (operation == rra || operation == rrr)
		ft_reverse_rotate(&main_struct->a, NULL, true);
	if (operation == rrb || operation == rrr)
		ft_reverse_rotate(&main_struct->b, NULL, false);
}

bool	ft_check(t_main	*main_struct)
{
	size_t	i;

	i = 0;
	while (i < main_struct->operations.count)
	{
		ft_do(main_struct, main_struct->operations.elements[i]);
		++i;
	}
	if (ft_empty(main_struct->b) && ft_stack_is_sorted(main_struct->a))
		return (true);
	return (false);
}

int	main(int argc, char	**argv)
{
	t_main		main_struct;	

	if (argc > 1)
	{
		ft_initial_struct(&main_struct);
		ft_fill_vector(&main_struct, ++argv);
		if (ft_vector_is_sorted(main_struct.vector))
			ft_success(&main_struct);
		if (!ft_validation(main_struct.vector, &main_struct.sorted_vector))
			ft_error(&main_struct, "Error");
		ft_fill_stack(&main_struct);
		ft_fill_operations(&main_struct);
		if (ft_check(&main_struct))
			write(1, "OK\n", 3);
		else 
			write(1, "KO\n", 3);
		ft_success(&main_struct);
	}
	exit(EXIT_SUCCESS);
}