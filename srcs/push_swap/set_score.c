#include "push_swap.h"

static int	ft_set_score_stack_a(const t_stack	*head, int value)
{
	int		prev_data;
	size_t	index;
	size_t	count;

	index = 0;
	count = ft_size(head);
	prev_data = ft_last(head);
	while (true)
	{
		if (head->data > value && value > prev_data)
		{
			if (index <= count)
				return (index);
			else
				return (-count);
		}
		++index;
		--count;
		prev_data = head->data;
		head = head->next;
	}
}

void	ft_set_score(t_main	*_main)
{
	t_stack		*backup;
	size_t		count;
	size_t		index;

	index = 0;
	count = ft_size(_main->b);
	backup = _main->b;
	while (_main->b != NULL)
	{
		_main->b->score_b = index;
		if (index > count)
			_main->b->score_b = -count;
		_main->b->score_a = ft_set_score_stack_a(_main->a, _main->b->data);
		++index;
		--count;
		_main->b = _main->b->next;
	}
	_main->b = backup;
}
