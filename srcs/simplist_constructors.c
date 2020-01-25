/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_constructors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <merras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:12:35 by merras            #+#    #+#             */
/*   Updated: 2020/01/25 21:27:52 by merras           ###   ########.fr       */
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

void	list_delete_node(t_list **head, t_list *node, void (*delete_node)(void *))
{
	if (!node || !head)
		return ;
	if (IS_HEAD(node))
	{
		*head = node->next;
		if (*head)
			F_SET((*head)->data, HEAD_FLAG);
		if (node->next)
		{
			node->prev = NULL;
		}
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
