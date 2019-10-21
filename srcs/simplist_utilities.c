/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:22:52 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 01:24:07 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simplist.h"

t_list	*list_head_tail(t_list *node, int head_or_tail)
{
	if (!node)
		return (NULL);
	while (head_or_tail ? node->next : node->prev)
		node = head_or_tail ? node->next : node->prev;
	return (node);
}

size_t	list_size(t_list *head)
{
	size_t	size;

	size = 0;
	while (head && ++size)
		head = head->next;
	return (size);
}
