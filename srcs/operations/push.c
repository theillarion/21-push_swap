/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:27 by illarion          #+#    #+#             */
/*   Updated: 2022/01/27 16:41:58 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_push(t_stack	**src, t_stack	**dest, t_vector	*operations, bool is_stack_a)
{
	t_stack	*backup;

	if (src == NULL || dest == NULL || *src == NULL)
		return ;
	backup = *src;
	*src = (*src)->next;
	backup->next = *dest;
	*dest = backup;
	if (is_stack_a)
		ft_push_back(operations, pa);
	else
		ft_push_back(operations, pb);
}
