/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <mbarekerras@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:04:17 by merras            #+#    #+#             */
/*   Updated: 2019/12/29 15:33:16 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simplist.h"
#include <stdio.h>

t_list	*list_copy(t_list *head, int (*filter)(t_list *))
{
	t_list	*copy;
	void	*content;

	
	copy = NULL;
	while (head)
	{
		if (filter ? filter(head) : 1)
		{
			content = malloc(head->content_size);
			ft_memcpy(content, head->content, head->content_size);
			list_push_back(&copy, list_create_node(content, head->content_size));
			//printf(">>>>>>>>>> %p %p ", head, copy);
		}
		head = head->next;
	}
	return (copy);
}
