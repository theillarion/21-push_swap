#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

/*typedef	struct s_score
{
	size_t	rotate_all;
	size_t	rotate_a;
	size_t	rotate_b;
	bool	is_reverse_a;
	bool	is_reverse_b;
}			t_score;*/

typedef struct s_stack
{
	int				data;
	int				score_a;
	int				score_b;
	struct s_stack	*next;
}					t_stack;

void	ft_pop(t_stack	**head);
int		ft_top(const t_stack	*head);
bool	ft_empty(const t_stack	*head);
void	ft_push_front(t_stack	**head, int data);
void	ft_push_array(t_stack	**head, int	*array, size_t	length);
size_t	ft_size(const t_stack	*head);

#endif