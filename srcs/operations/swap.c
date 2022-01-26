/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:23:23 by illarion          #+#    #+#             */
/*   Updated: 2022/01/26 17:37:46 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_swap(t_stack	**head, t_vector	*operations, int operation)
{
	t_stack	*backup;

	if (head != NULL && *head != NULL && (*head)->next != NULL)
	{
		backup = *head;
		(*head) = (*head)->next;
		backup->next = (*head)->next;
		(*head)->next = backup;
		if (ft_empty_vector(*operations) || ft_get_back(*operations) + operation != ss)
			ft_push_back(operations, operation);
		else
		{
			ft_erase_back(operations);
			ft_push_back(operations, ss);
		}
	}
}
