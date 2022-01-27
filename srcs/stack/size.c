/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:57:42 by glashli           #+#    #+#             */
/*   Updated: 2022/01/28 01:35:50 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	ft_size(const t_stack	*head)
{
	size_t	count;

	count = 0;
	while (head != NULL)
	{
		head = head->next;
		++count;
	}
	return (count);
}
