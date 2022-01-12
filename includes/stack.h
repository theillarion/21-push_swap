#ifndef STACK_H
# define STACK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void	ft_pop(t_stack	**head);
int		ft_top(t_stack	**head);
bool	ft_empty(t_stack	**head);
void	ft_push(t_stack	**head, int data);
void	ft_push_array(t_stack	**head, int	*array, size_t	length);
size_t	ft_size(t_stack	**head);

#endif