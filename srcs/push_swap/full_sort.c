#include "push_swap.h"

void	ft_non_strict_sort(t_main	*_main)
{
	while (ft_size(_main->a) != 3)
		ft_push(&_main->a, &_main->b,
			&_main->operations, false);
	ft_sort_3(&_main->a, &_main->operations, true);
	while (!ft_empty(_main->b))
	{
		ft_push(&_main->b, &_main->a,
			&_main->operations, true);
		ft_rotate(&_main->a, &_main->operations, true);
	}
}

void	ft_presort(t_main	*_main)
{
	while (ft_size(_main->a) != 2)
	{
		if (ft_top(_main->a) == _main->value.min
			|| ft_top(_main->a) == _main->value.max)
		{
			ft_rotate(&_main->a, &_main->vector, true);
			continue ;
		}
		ft_push(&_main->a, &_main->b, &_main->operations, false);                 // 
		if (ft_top(_main->b) > _main->value.middle && _main->b->next != NULL)     // оптимизировать
			ft_rotate(&_main->b, &_main->operations, false);
	}
	//print_stack(_main->a);
	//print_stack(_main->b);
}

int	ft_min_2(int	value1, int	value2)
{
	if (value1 <= value2)
		return (value1);
	return (value2);
}

int	ft_set_score_a(const t_stack	*head, int value)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = ft_size(head);
	while (true)
	{
		if (value < head->data)
		{
			if (index <= count)
				return (index);
			else
				return (-count);
		}
		++index;
		head = head->next;
	}
}

void ft_set_score_b(t_main	*_main)
{
	t_stack		*backup;
	size_t		count;
	size_t		index;

	index = 0;
	count = ft_size(_main->b);
	backup = _main->b;
	while (_main->b != NULL)
	{
		_main->b->score_b = ft_min_2(index, count);
		if (index > count)
			_main->b->score_b *= -1;
		_main->b->score_a = ft_set_score_a(_main->a, _main->b->data);
		++index;
		--count;
		_main->b = _main->b->next;
	}
	_main->b = backup;
}

void ft_print_score(const t_stack	*head)
{
	while (head)
	{
		printf("%d ", ABS(head->score_a) + ABS(head->score_b));
		head = head->next;
	}
	printf("\n");
}

t_stack	ft_search_min_opeartion(const	t_stack	*head)
{
	int 	min;
	t_stack	current_min;

	min = INT_MAX;
	while (head)
	{
		if (min >= ABS(head->score_a) + ABS(head->score_b))
		{
			min = ABS(head->score_a) + ABS(head->score_b);
			current_min = *head;
		}
		head = head->next;
	}
	return (current_min);
}

int ft_substruction(int value1, int value2)
{
	if (value1 + value2 < 0)
		return (0);
	return (value1 + value2);
}

void	ft_do_operation(t_main	*_main)
{
	int		i;
	int		j;
	t_stack	current;

	current = ft_search_min_opeartion(_main->b);
	i = -1;
	j = -1;
	if (current.score_a < 0)
		i = 1;
	if (current.score_b < 0)
		j = 1;
	while (current.score_a != 0 || current.score_b != 0)
	{
		if (current.score_a != 0)
		{
			if (current.score_a > 0)
				ft_rotate(&_main->a, &_main->operations, true);
			else
				ft_reverse_rotate(&_main->a, &_main->operations, true);
		}
		if (current.score_b != 0)
		{
			if (current.score_b > 0)
				ft_rotate(&_main->b, &_main->operations, false);
			else
				ft_reverse_rotate(&_main->b, &_main->operations, false);
		}
		current.score_a = ft_substruction(current.score_a, i);
		current.score_b = ft_substruction(current.score_b, j);
	}
	ft_push(&_main->b, &_main->a, &_main->operations, true);
}

int	ft_find_min(const t_stack	*head, int min)
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

void ft_finaly_rotate(t_main	*_main)
{
	int i;
	int count;

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

void	ft_sort_full(t_main	*_main)
{
	ft_presort(_main);
	while (!ft_empty(_main->b))
	{
		ft_set_score_b(_main);
		//ft_print_score(_main->b);
		ft_do_operation(_main);
	}
	ft_finaly_rotate(_main);
	//i = ft_find_begin()
	
	//ft_set_score_b(_main);
	//ft_print_score(_main->b);
}
/*
	IN FUTURE
*/