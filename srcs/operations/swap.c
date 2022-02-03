/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:23:23 by illarion          #+#    #+#             */
/*   Updated: 2022/02/03 16:13:38 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_swap(t_stack	**head, t_vector	*operations, bool is_stack_a)
{
	t_stack	*backup;
	int		operation;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	backup = *head;
	(*head) = (*head)->next;
	backup->next = (*head)->next;
	(*head)->next = backup;
	operation = sa;
	if (!is_stack_a)
		operation = sb;
	if (operations != NULL && (ft_empty_vector(*operations)
			|| ft_get_back(*operations) + operation != ss))
		ft_push_back(operations, operation);
	else if (operations != NULL)
	{
		ft_erase_back(operations);
		ft_push_back(operations, ss);
	}
}
