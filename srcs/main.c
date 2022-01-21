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

t_stack	*ft_validation(char	**argv)
{
	char	**buff;
	t_stack	*stack;
	//size_t	i;
	//bool	is_digit;

	while (*argv)
	{
		buff = NULL;
		buff = ft_split(*(argv++), ' ');
		while (*buff)
		{
			//i = 0;
			/*while ((*buff)[i])
			{
				is_digit = ft_isdigit((*buff)[i++]);
				if (is_digit == false)
					break;
			}*/
			//if (is_digit)
			ft_push(&stack, ft_atoi(*buff));
			//else
			//	ft_error(stack);
			free((*buff)++);
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

int main(int argc, char	**argv)
{
	(void)argc;
	t_stack	*a;
	t_stack	*b;
	(void)b;

	a = ft_validation(argv);
	print_stack(a);
	exit(EXIT_SUCCESS);
}
