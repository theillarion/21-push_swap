/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:05:56 by glashli           #+#    #+#             */
/*   Updated: 2022/01/12 17:34:58 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_stack	*ft_create_elem(int	data)
{
	t_stack*	new_elem;

	new_elem = (t_stack*)malloc(sizeof(t_stack));
	if (new_elem == NULL)
	{
		write(2, "Error: no memory allocated\n", 27);
		exit(EXIT_FAILURE);
	}
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_push(t_stack	**head, int data)
{
	t_stack	*new_head;
	
	if (head != NULL)
	{
		new_head = ft_create_elem(data);
		if (*head == NULL)
			*head = new_head;
		else
		{
			new_head->next = *head;
			*head = new_head;
		}
	}
	else
	{
		write(2, "Error: stack is NULL\n", 21);
		exit(EXIT_FAILURE);
	}
}

void	ft_push_array(t_stack	**head, int	*array, size_t	length)
{
	size_t	i;

	if (head != NULL)
	{
		i = 0;
		while (i < length)
			ft_push(head, array[i++]);
	}
	else
	{
		write(2, "Error: stack is NULL\n", 21);
		exit(EXIT_FAILURE);
	}
}
