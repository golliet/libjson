
#include "json.h"

void			wy_display_json(t_json *list)
{
	(void)list;
}

void			wy_free_json(t_json **list)
{
	(void)list;

}

static void		wy_affect(t_json **list, t_value *value, char *key)
{
	ft_bzero(*list, sizeof(t_json));
	(*list)->value = value;
	(*list)->next = NULL;
	(*list)->key = key;
}

t_value			*wy_init_value(void)
{
	t_value	*value;

	if (!(value = (t_value *)malloc(sizeof(t_value))))
		wy_exit("init_value failled");
	ft_bzero(value, sizeof(t_value));
	return (value);
}

void		wy_push(t_json **list, t_value *value, char *key)
{
	if (*list)
	{
		if (!((*list)->next = (t_json *)malloc(sizeof(t_json))))
			wy_exit("push failled");
		wy_affect(&(*list)->next, value, key);
		*list = (*list)->next;
	}
	else
	{
		if (!(*list = (t_json *)malloc(sizeof(t_json))))
			wy_exit("push failled");
		wy_affect(list, value, key);
	}
}
