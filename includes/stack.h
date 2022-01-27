#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void	ft_pop(t_stack	**head);
int		ft_top(const t_stack	*head);
bool	ft_empty(const t_stack	*head);
void	ft_push_front(t_stack	**head, int data);
void	ft_push_array(t_stack	**head, int	*array, size_t	length);
size_t	ft_size(const t_stack	*head);

#endif