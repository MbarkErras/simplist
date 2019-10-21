/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_constructors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:12:35 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 01:21:08 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simplist.h"

t_list	*list_create_node(void *content, size_t content_size)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node->next = NULL;
	node->prev = NULL;
	node->content_size = content_size;
	node->content = content;
	return (node);
}

void	list_delete_node(t_list **head, t_list *node,
		void (*delete_node)(void *))
{
	if (!node || !head)
		return ;
	if (*head == node)
	{
		*head = node->next;
		delete_node(node->content);
		free(node);
		return ;
	}
	if ((node)->next)
		(node)->next->prev = (node)->prev;
	if ((node)->prev)
		(node)->prev->next = (node)->next;
	delete_node((node)->content);
}
