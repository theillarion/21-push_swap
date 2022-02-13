/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:05:16 by glashli           #+#    #+#             */
/*   Updated: 2022/01/31 17:58:59 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_top(const t_stack	*head)
{
	if (head != NULL)
		return (head->data);
	return (INT_MIN);
}

int	ft_last(const t_stack	*head)
{
	if (head)
	{
		while (head->next)
			head = head->next;
		return (head->data);
	}
	return (INT_MIN);
}
