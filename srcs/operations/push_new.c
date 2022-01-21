/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:27 by illarion          #+#    #+#             */
/*   Updated: 2022/01/20 20:48:27 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_push_(t_stack	**src, t_stack	**dest)
{
	t_stack	*backup;

	backup = *src;
	*src = (*src)->next;
	backup->next = *dest;
	*dest = backup;
}
