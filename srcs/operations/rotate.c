/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:23 by illarion          #+#    #+#             */
/*   Updated: 2022/01/26 17:48:21 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rotate(t_stack	**head, t_vector	*operations, int operation)
{
	t_stack	*current;
	t_stack	*backup;

	backup = *head;
	*head = (*head)->next;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = backup;
	backup->next = NULL;
	if (ft_empty_vector(*operations) || ft_get_back(*operations) + operation != rr)
			ft_push_back(operations, operation);
	else
	{
			ft_erase_back(operations);
			ft_push_back(operations, rr);
	}
}

void	ft_reverse_rotate(t_stack	**head, t_vector	*operations, int operation)
{
	t_stack	*current;
	t_stack	*backup;

	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	backup = current->next;
	current->next = NULL;
	backup->next = *head;
	*head = backup;
	if (ft_empty_vector(*operations) || ft_get_back(*operations) + operation != rrr)
			ft_push_back(operations, operation);
	else
	{
			ft_erase_back(operations);
			ft_push_back(operations, rrr);
	}
}
