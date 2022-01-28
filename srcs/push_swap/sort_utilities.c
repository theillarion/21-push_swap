#include "push_swap.h"

int	ft_max(const t_stack	*head)
{
	int max;

	max = head->data;
	while (head != NULL)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}

int	ft_min(const t_stack	*head)
{
	int min;

	min = head->data;
	while (head != NULL)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}
