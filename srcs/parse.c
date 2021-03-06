
#include "json.h"

static t_value		*wy_obj(char *str, int *i, char **key)
{
	t_value *value;

	*key = NULL;
	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		*key = ft_strjoinfree(*key, (char[2]){str[*i], '\0'}, 1);
		(*i)++;
	}
	(*i)++;
	wy_is_end(str[*i]);
	while (str[*i] && wy_is_space(str[*i]))
		(*i)++;
	if (!str[*i] || str[*i] != ':')
		wy_exit("missing separator : between Key and Value");
	(*i)++;
	while (str[*i] && wy_is_space(str[*i]))
		(*i)++;
	wy_is_end(str[*i]);
	value = wy_value(str, i);
	if (!(str[*i] == ',' || str[*i] == '}' || str[*i] == ']' || str[*i] == '\n'))
		wy_exit("invalid object");
	(*i)++;
	return (value);
}

static t_value 		*wy_array(char *str, int *i)
{
	t_value *value;
	value = wy_value(str, i);
	if (!(str[*i] == ',' || str[*i] == '}' || str[*i] == ']' || str[*i] == '\n'))
		wy_exit("invalid array");
	(*i)++;
	return (value);
}

t_json 			*wy_loop_obj(char *str, int *i, t_json *json)
{
	t_value *value;
	char 	*key;
	t_json *head;

	value = NULL;
	key = NULL;
	(*i)++;
	wy_push(&json, NULL, NULL);
	head = json;
	while (str[*i] != '}')
	{
		while (str[*i] && wy_is_space(str[*i]))
			(*i)++;
		wy_is_end(str[*i]);
		if (str[*i] == '}')
			break ;
		value = wy_obj(str, i, &key);
		wy_push(&json, value, key);
		json->key = key;
		(*i)++;
	}
	return (head);
}

t_json				*wy_loop_array(char *str, int *i, t_json *json)
{
	t_value *value;
	t_json *head;

	value = NULL;
	(*i)++;
	wy_push(&json, NULL, NULL);
	head = json;
	while (str[*i] != ']')
	{
		while (str[*i] && wy_is_space(str[*i]))
			(*i)++;
		wy_is_end(str[*i]);
		if (str[*i] == ']')
			break ;
		value = wy_array(str, i);
		wy_push(&json, value, NULL);
		(*i)++;
	}
	return (head);
}

t_json				*wy_loop(char *str, int *i)
{
	t_json *json;

	json = NULL;
	if (str[0] == '{')
		json = wy_loop_obj(str, i, json);
	else if (str[0] == '[')
		json = wy_loop_array(str, i, json);
	else
		ft_putendl_fd("Premier caracter invalide", 2);
	wy_display_json(json, 1);
	return (json);
}