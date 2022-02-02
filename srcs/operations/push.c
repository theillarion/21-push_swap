/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:27 by illarion          #+#    #+#             */
/*   Updated: 2022/02/02 23:19:19 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_push(t_stack	**src, t_stack	**dest, t_vector	*operations,
	bool is_stack_a)
{
	t_stack	*backup;

	if (src == NULL || dest == NULL || *src == NULL)
		return ;
	backup = *src;
	*src = (*src)->next;
	backup->next = *dest;
	*dest = backup;
	if (operations != NULL && is_stack_a)
		ft_push_back(operations, pa);
	else if (operations != NULL)
		ft_push_back(operations, pb);
}
