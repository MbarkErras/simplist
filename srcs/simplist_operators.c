/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:14:34 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 01:21:06 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simplist.h"

void	list_push(t_list **head, t_list *node, int x)
{
	t_list	*appendto;

	if (!head || !node)
		return ;
	if (!*head)
		*head = node;
	else
	{
		appendto = list_head_tail(*head, x);
		if (x)
		{
			appendto->next = node;
			node->prev = appendto;
			node->next = NULL;
		}
		else
		{
			appendto->prev = node;
			node->next = appendto;
			node->prev = NULL;
		}
	}
}

void	list_push_back(t_list **head, t_list *node)
{
	list_push(head, node, 1);
}

void	list_push_front(t_list **head, t_list *node)
{
	list_push(head, node, 0);
}
