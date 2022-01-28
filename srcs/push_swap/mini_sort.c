#include "push_swap.h"

void	ft_sort_2(t_stack	**stack, t_vector	*operations, bool is_stack_a)
{
	if ((*stack)->data > (*stack)->next->data)
		ft_swap(stack, operations, is_stack_a);
}

void	ft_sort_3(t_stack	**stack, t_vector	*operations, bool is_stack_a)
{
	if (!ft_stack_is_sorted(*stack))
	{
		if ((*stack)->data > (*stack)->next->data)
		{
			if ((*stack)->data < (*stack)->next->next->data)
				ft_swap(stack, operations, is_stack_a);
			else
			{
				if ((*stack)->next->data < (*stack)->next->next->data)
					ft_rotate(stack, operations, is_stack_a);
				else
				{
					ft_swap(stack, operations, is_stack_a);
					ft_reverse_rotate(stack, operations, is_stack_a);
				}
			}
		}
		else 
		{
			if ((*stack)->data > (*stack)->next->next->data)
				ft_reverse_rotate(stack, operations, is_stack_a);
			else
			{
				ft_swap(stack, operations, is_stack_a);
				ft_rotate(stack, operations, is_stack_a);
			}
		}
	}
}



static void ft_split_stacks(t_main	*main_struct)
{
	size_t	i;
	size_t	count_a;

	count_a = ft_size(main_struct->a);
	i = 0;
	if (ft_max(main_struct->a) > ft_min(main_struct->b))
	{
		while (i < count_a)
		{	
			if (!ft_empty(main_struct->b) && ft_top(main_struct->a) > ft_top(main_struct->b))
			{
				ft_push(&main_struct->b, &main_struct->a, &main_struct->operations, true);
				++count_a;
			}
			else
			{
				if (ft_empty(main_struct->b) && ft_stack_is_sorted(main_struct->a))
					break ;
				ft_rotate(&main_struct->a, &main_struct->operations, true);
				++i;
			}
		}
	}
	while (!ft_empty(main_struct->b))
	{
		ft_push(&main_struct->b, &main_struct->a, &main_struct->operations, true);
		ft_rotate(&main_struct->a, &main_struct->operations, true);
	}
}

void	ft_sort_mini(t_main	*main_struct)
{
	size_t	i;
	size_t	median;

	median = main_struct->digits.count / 2;
	i = 0;
	while (i < median)
	{
		ft_push(&main_struct->a, &main_struct->b, &main_struct->operations, false);
		++i;
	}
	if (main_struct->digits.count == 4 || main_struct->digits.count == 5)
	{
		ft_sort_2(&main_struct->b, &main_struct->operations, false);
		if (main_struct->digits.count == 4)
			ft_sort_2(&main_struct->a, &main_struct->operations, true);
		else
			ft_sort_3(&main_struct->a, &main_struct->operations, true);
	}
	else if (main_struct->digits.count == 6)
	{
		ft_sort_3(&main_struct->a, &main_struct->operations, true);
		ft_sort_3(&main_struct->b, &main_struct->operations, false);
	}
	ft_split_stacks(main_struct);
}
