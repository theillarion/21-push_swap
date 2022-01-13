/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:39:47 by glashli           #+#    #+#             */
/*   Updated: 2022/01/12 17:38:53 by glashli          ###   ########.fr       */
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

	if (head != NULL)
	{
		if (*head == NULL)
		{
			write(2, "Error: stack is empty\n", 22);
			exit(EXIT_FAILURE);
		}
		else
		{
			backup = (*head)->next;
			ft_del_elem(*head);
			*head = backup;
		}
	}
	else
	{
		write(2, "Error: stack is NULL\n", 21);
		exit(EXIT_FAILURE);
	}
}
