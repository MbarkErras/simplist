/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 02:00:23 by merras            #+#    #+#             */
/*   Updated: 2019/12/29 15:34:19 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLIST_H
# define SIMPLIST_H

# include <stdlib.h>
# include <unistd.h>
# include "centropy.h"

# define F_GET(x, f) (x & (1 << f))
# define F_BGET(x, f) (x & f)
# define F_SET(x, f) (x |= (1 << f))
# define F_BSET(x, f) (x |= f)
# define F_UNSET(x, f) (x &= ~(1 << f))
# define F_BUNSET(x, f) (x &= ~f)

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
}					t_list;

# define TLIST(name, type) ((type *)name->content)

# define HEAD_FLAG 0

# define LIST_SIZE(x) (x->data >> 8)
# define UPDATE_LIST_SIZE(x, i) (x->data = ((x->data >> 8) + i) << 8)
# define IS_HEAD(x) F_GET(x->data, HEAD_FLAG)

t_list				*list_create_node(void *content, size_t content_size);
t_list				*list_head_tail(t_list *node, int head_or_tail);
void				list_push(t_list **head, t_list *node, int x);
void				list_push_back(t_list **head, t_list *node);
void				list_push_front(t_list **head, t_list *node);
t_list				*list_find_node(t_list *head, int(*filter)(void *, void *),
					void *p);
t_list				**list_pointer_address(t_list **head, t_list *node);
t_list				*list_indexed_node(t_list *head, size_t index);
size_t				list_node_index(t_list *head, t_list *node);
void				list_delete(t_list **head, void(*delete_node)(void *));
void				list_delete_node(t_list **head, t_list *node,
					void(delete_node)(void *));
void				list_pop_node(t_list **head, t_list *node);
t_list				*list_copy(t_list *head, int (*filter)(t_list *));
size_t				list_counter(t_list *head, int (*filter)(t_list *));
#endif
