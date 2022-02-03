/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:23 by illarion          #+#    #+#             */
/*   Updated: 2022/02/03 16:13:21 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rotate(t_stack	**head, t_vector	*operations, bool is_stack_a)
{
	t_stack	*current;
	t_stack	*backup;
	int		operation;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	backup = *head;
	*head = (*head)->next;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = backup;
	backup->next = NULL;
	operation = ra;
	if (!is_stack_a)
		operation = rb;
	if (operations != NULL && (ft_empty_vector(*operations)
			|| ft_get_back(*operations) + operation != rr))
		ft_push_back(operations, operation);
	else if (operations != NULL)
	{
		ft_erase_back(operations);
		ft_push_back(operations, rr);
	}
}

void	ft_reverse_rotate(t_stack	**head, t_vector	*operations,
	bool is_stack_a)
{
	t_stack	*current;
	t_stack	*backup;
	int		operation;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	backup = current->next;
	current->next = NULL;
	backup->next = *head;
	*head = backup;
	operation = rra;
	if (!is_stack_a)
		operation = rrb;
	if (operations != NULL && (ft_empty_vector(*operations)
			|| ft_get_back(*operations) + operation != rrr))
		ft_push_back(operations, operation);
	else if (operations != NULL)
	{
		ft_erase_back(operations);
		ft_push_back(operations, rrr);
	}
}
