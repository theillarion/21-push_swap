/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:57:42 by glashli           #+#    #+#             */
/*   Updated: 2022/01/12 16:04:49 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	ft_size(t_stack	**head)
{
	size_t	count;

	if (head == NULL)
	{
		count = 0;
		while (*head != NULL)
		{
			*head = (*head)->next;
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
