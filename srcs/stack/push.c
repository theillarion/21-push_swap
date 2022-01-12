/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:05:56 by glashli           #+#    #+#             */
/*   Updated: 2022/01/12 16:36:14 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_stack	*ft_create_elem(int	data)
{
	t_stack*	new_elem;

	new_elem = (t_stack*)malloc(sizeof(new_elem));
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
	if (head != NULL)
	{
		if (*head == NULL)
			*head = ft_create_elem(data);
		else
		{
			while ((*head)->next != NULL)
				(*head) = (*head)->next;
			(*head)->next = ft_create_elem(data);
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
		if (*head == NULL)
			*head = ft_create_elem(array[i++]);
		while ((*head)->next != NULL)
			(*head) = (*head)->next;
		while (i < length)
		{
			(*head)->next = ft_create_elem(array[i++]);
			*head = (*head)->next;
		}
	}
	else
	{
		write(2, "Error: stack is NULL\n", 21);
		exit(EXIT_FAILURE);
	}
}