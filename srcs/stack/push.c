/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:05:56 by glashli           #+#    #+#             */
/*   Updated: 2022/01/28 16:52:29 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_stack	*ft_create_elem(int data)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (new_elem == NULL)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_push_front(t_stack	**head, int data)
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
}

void	ft_push_array(t_stack	**head, int	*array, size_t	length)
{
	size_t	i;

	if (head != NULL)
	{
		i = 0;
		while (i < length)
		{
			ft_push_front(head, array[i]);
			++i;
		}
	}
}
