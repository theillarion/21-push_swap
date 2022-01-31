#include "push_swap.h"

static t_stack	ft_search_min_opeartion(const	t_stack	*head)
{
	int		min;
	t_stack	current_min;

	min = INT_MAX;
	while (head)
	{
		if (min >= ft_abs(head->score_a) + ft_abs(head->score_b))
		{
			min = ft_abs(head->score_a) + ft_abs(head->score_b);
			current_min = *head;
		}
		head = head->next;
	}
	return (current_min);
}

static int	ft_substruction(int value1, int value2)
{
	if (value1 == 0)
		return (0);
	return (value1 + value2);
}

static void	ft_initial_indexs(const int score_a, const int score_b,
	int	*index_i, int	*index_j)
{
	*index_i = -1;
	*index_j = -1;
	if (score_a < 0)
		*index_i = 1;
	if (score_b < 0)
		*index_j = 1;
}

static void	ft_do_operation(t_stack	**stack, t_vector	*operations,
	int current_scope, bool is_stack_a)
{
	if (current_scope > 0)
		ft_rotate(stack, operations, is_stack_a);
	else
		ft_reverse_rotate(stack, operations, is_stack_a);
}

void	ft_do_operations(t_main	*_main)
{
	int		i;
	int		j;
	t_stack	current;

	current = ft_search_min_opeartion(_main->b);
	ft_initial_indexs(current.score_a, current.score_b, &i, &j);
	while (current.score_a != 0 || current.score_b != 0)
	{
		if (current.score_a != 0)
			ft_do_operation(&_main->a, &_main->operations, current.score_a,
				true);
		if (current.score_b != 0)
			ft_do_operation(&_main->b, &_main->operations, current.score_b,
				false);
		current.score_a = ft_substruction(current.score_a, i);
		current.score_b = ft_substruction(current.score_b, j);
	}
	ft_push(&_main->b, &_main->a, &_main->operations, true);
}
