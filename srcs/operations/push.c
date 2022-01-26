/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:27 by illarion          #+#    #+#             */
/*   Updated: 2022/01/26 17:45:38 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_push(t_stack	**src, t_stack	**dest, t_vector	*operations, int operation)
{
	t_stack	*backup;

	backup = *src;
	*src = (*src)->next;
	backup->next = *dest;
	*dest = backup;
	ft_push_back(operations, operation);
}
