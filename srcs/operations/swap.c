/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:23:23 by illarion          #+#    #+#             */
/*   Updated: 2022/01/20 18:19:35 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_swap(t_stack	**head)
{
	t_stack	*backup;

	backup = *head;
	(*head) = (*head)->next;
	backup->next = (*head)->next;
	(*head)->next = backup;
}
