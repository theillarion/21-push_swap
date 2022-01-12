/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:39:47 by glashli           #+#    #+#             */
/*   Updated: 2022/01/12 16:19:59 by glashli          ###   ########.fr       */
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
	if (head != NULL)
	{
		if ((*head) == NULL)
			return ;
		if ((*head)->next == NULL)
		{
			ft_del_elem(*head);
			head = NULL;
		}
		else
		{
			while ((*head)->next->next != NULL)
				*head = (*head)->next;
			ft_del_elem((*head)->next);
			(*head)->next = NULL;
		}
	}
	else
	{
		write(2, "Error: stack is NULL\n", 21);
		exit(EXIT_FAILURE);
	}
}
