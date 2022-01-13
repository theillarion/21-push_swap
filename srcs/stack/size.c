/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:57:42 by glashli           #+#    #+#             */
/*   Updated: 2022/01/13 01:55:13 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	ft_size(t_stack	**head)
{
	t_stack	*new_stack;
	size_t	count;

	if (head != NULL)
	{
		new_stack = *head;
		count = 0;
		while (new_stack != NULL)
		{
			new_stack = new_stack->next;
			count++;
		}
		return (count);
	}
	else
	{
		write(2, "Error: stack is NULL\n", 21);
		exit(EXIT_FAILURE);
	}
}
