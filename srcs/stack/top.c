/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:05:16 by glashli           #+#    #+#             */
/*   Updated: 2022/01/12 17:37:37 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_top(t_stack	**head)
{
	if (head != NULL)
	{
		if (*head == NULL)
		{
			write(2, "Error: stack is empty\n", 22);
			exit(EXIT_FAILURE);
		}
		else
			return ((*head)->data);
	}
	else
	{
		write(2, "Error: stack is NULL\n", 21);
		exit(EXIT_FAILURE);
	}
}
