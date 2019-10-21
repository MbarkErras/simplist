/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:25:36 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 01:58:19 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simplist.h"

void	list_delete(t_list **head, void (*delete_node)(void *))
{
	while (*head)
		list_delete_node(head, *head, delete_node);
}
