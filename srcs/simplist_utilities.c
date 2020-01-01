/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:22:52 by merras            #+#    #+#             */
/*   Updated: 2019/10/29 13:02:55 by merras           ###   ########.fr       */
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

void	list_pop_node(t_list **head, t_list *node)
{
	if (!head || !node)
		return ;
	if (*head == node)
		*head = node->next;
	else
	{
		if (node->next)
			node->next->prev = node->prev;
		if (node->prev)
			node->prev->next = node->prev;
	}
}

size_t	list_counter(t_list *head, int (*filter)(t_list *))
{
	int counter;

	counter = 0;
	while (head)
	{
		if (filter ? filter(head) : 1)
			counter++;
		head = head->next;
	}
	return (counter);
}