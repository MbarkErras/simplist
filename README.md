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
