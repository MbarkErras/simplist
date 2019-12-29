#include "simplist.h"

t_list	*list_copy(t_list *head)
{
	t_list	*copy;
	void	*content;

	copy = NULL;
	while (head)
	{
		content = malloc(head->content_size);
		ft_memcpy(content, haed->content, head->content_size);
		push_back(&copy, t_list_create_node(content, head->content_size));
		head = head->next;
	}
	return (copy);
}
