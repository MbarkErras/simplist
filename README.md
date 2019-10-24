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
for the support of circular lists a convention is made: head previous pointer should be null.
_ _ _ _ _ _               _ _ _ _ _ _
|          | --- next --> |          |
| sentinel |              |   head   |
|_ _ _ _ _ | <-- *NULL* --- |_ _ _ _ _ |
