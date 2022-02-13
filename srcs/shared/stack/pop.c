/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:39:47 by glashli           #+#    #+#             */
/*   Updated: 2022/01/28 01:32:57 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_del_elem(t_stack	*element)
{
	if (element != NULL)
	{
		element->data = 0;
		element->next = NULL;
		free(element);
	}
}

void	ft_pop(t_stack	**head)
{
	t_stack	*backup;

	if (head != NULL && *head != NULL)
	{
		backup = (*head)->next;
		ft_del_elem(*head);
		*head = backup;
	}
}
