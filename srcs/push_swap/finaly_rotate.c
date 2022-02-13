#include "push_swap.h"

static int	ft_find_min(const t_stack	*head, int min)
{
	int	index;
	int	count;

	index = 0;
	count = ft_size(head);
	while (head)
	{
		if (head->data == min)
		{
			if (index <= count)
				return (index);
			else
				return (-count);
		}
		++index;
		--count;
		head = head->next;
	}
	return (0);
}

void	ft_finaly_rotate(t_main	*_main)
{
	int	i;
	int	count;

	count = ft_find_min(_main->a, _main->value.min);
	i = -1;
	if (count < 0)
		i = 1;
	while (count)
	{
		if (i == -1)
			ft_rotate(&_main->a, &_main->operations, true);
		else
			ft_reverse_rotate(&_main->a, &_main->operations, true);
		count += i;
	}
}
