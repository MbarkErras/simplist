/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_node_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:24:14 by merras            #+#    #+#             */
/*   Updated: 2019/10/28 22:01:23 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simplist.h"

size_t	list_node_index(t_list *head, t_list *node)
{
	size_t index;

	index = 1;
	if (!head || !node)
		return (0);
	while (head != node)
	{
		index++;
		head = head->next;
	}
	return (index);
}

t_list	*list_indexed_node(t_list *head, size_t index)
{
	size_t i;

	i = 1;
	while (head)
	{
		if (i == index)
			return (head);
		i++;
		head = head->next;
	}
	return (0);
}

t_list	**list_pointer_address(t_list **head, t_list *node)
{
	t_list *i;

	if (!head || !node || !*head)
		return (NULL);
	if (*head == node)
		return (head);
	i = *head;
	while (i)
	{
		if (i == node)
			return (&i->prev->next);
		i = i->next;
	}
	return (NULL);
}

t_list	*list_find_node(t_list *head, int (*filter)(void *, void *), void *p)
{
	while (head)
	{
		if (filter(head, p))
			return (head);
		head = head->next;
	}
	return (NULL);
}
