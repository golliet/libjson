
#include "json.h"

static void		wy_level(int level)
{
	int i = 0;
	while (i++ < level)
		ft_putstr(" ");
}

static void		wy_obj_array(int type, int open)
{

	if (type & 2)
		open == 1 ? ft_putendl("{") : ft_putendl("}");
	else
		open == 1 ? ft_putendl("[") : ft_putendl("]");
}

void			wy_display_json(t_json *list, int level)
{
	t_json 		*json;

	json = list;
	while (json)
	{
		if (json->key)
		{
			wy_level(level);
			ft_putstr(json->key);
			ft_putstr(":");
		}
		if (json->value)
		{
			wy_level(level);
			if (json->value->type & 1 || json->value->type & 32)
				ft_putendl((char *) json->value->ptr);
			else if (json->value->type & 8 || json->value->type & 16)
				ft_putendl("nombre"); // fill la valeur
			else if (json->value->type & 2 || json->value->type & 4)
			{
				wy_obj_array(json->value->type, 1);
				wy_display_json((t_json *) json->value, level + 1);
				wy_level(level);
				wy_obj_array(json->value->type, 0);
			}
			else
				ft_putendl("null");
		}
		json = json->next;
	}
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
