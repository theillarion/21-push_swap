/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:23 by illarion          #+#    #+#             */
/*   Updated: 2022/01/20 21:09:15 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rotate(t_stack	**head)
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
}

void	ft_reverse_rotate(t_stack	**head)
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
}