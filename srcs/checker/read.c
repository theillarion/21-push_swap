#include "checker.h"

bool	ft_prevalidation_operations(const char	*operation)
{
	if (ft_strlen(operation) == 3 && (ft_strncmp(operation, "sa\n", 3) == 0
		|| ft_strncmp(operation, "sb\n", 3) == 0
		|| ft_strncmp(operation, "ss\n", 3) == 0
		|| ft_strncmp(operation, "pa\n", 3) == 0
		|| ft_strncmp(operation, "pb\n", 3) == 0
		|| ft_strncmp(operation, "ra\n", 3) == 0
		|| ft_strncmp(operation, "rb\n", 3) == 0
		|| ft_strncmp(operation, "rr\n", 3) == 0))
		return (true);
	if (ft_strlen(operation) == 4 && (ft_strncmp(operation, "rra\n", 4) == 0 || ft_strncmp(operation, "rrb\n", 4) == 0
		|| ft_strncmp(operation, "rrr\n", 4) == 0))
		return (true);
	return (false);	
}

char	*ft_read(t_main	*main_struct, int fd)
{
	char	buff[10];
	char	*operation;
	char	*backup;
	ssize_t	count;

	operation = (char *)ft_calloc(1, sizeof(char));
	ft_memset(&buff, 0, 10);
	count = read(fd, &buff, 9);
	while (count > 0)
	{
		buff[count] = '\0';
		backup = operation;
		operation = ft_strjoin(operation, buff);
		if (backup != NULL)
			free(backup);
		if (!ft_prevalidation_operations(operation))
		{
			free(operation);
			ft_error(main_struct, "Error");
		}
		count = read(fd, &buff, 9);
	}
	return (operation);
}
