# simplist
linked lists primitives
simplist contains functions I use to handle linked lists. allocated nodes are prototyped as follows:
```
typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;
```
as it seems the lists are double linked.
for the support of circular lists a convention is made: **head previous pointer should be null**. 
</br>
`void list_delete_node(t_list **head, t_list *node, void(delete_node)(void *));`
when `list_delete_node` is called to delete list's head, **the head->next becomes the new head.** 
<p align="center">
  <img src="https://i.imgur.com/I2iEzy5.png">
</p>
</br>
