
#include "json.h"

static void			wy_check_str(char *nft, char *str, int *i)
{
	int j;

	j = 0;
	while (nft[*i] && nft[*i] == str[j])
	{
		j++;
		(*i)++;
	}
	if (str[j])
		wy_exit("True false or null only");
	if (!(nft[*i] == ',' || nft[*i] == '}' || nft[*i] == ']'))
		wy_exit("invalid");
}

static void		wy_check_number(char *str, int *i)
{
	while (str[*i] && (str[*i] == '.' || (str[*i] >= '0' && str[*i] <= '9') || str[*i] == '-'))
		(*i)++;
	wy_is_end(str[*i]);
}

static int		wy_obj_array(t_value **value, char *str, int *i)
{
	if (str[*i] == '{')
	{
		(*value)->type = 2;
		(*value)->ptr = wy_loop_obj(str, i, 0); // mettre ce t_json dans une value
	}
	else if (str[*i] == '[') // obj ou array
	{
		(*value)->type = 4;
		(*value)->ptr = wy_loop_array(str, i, 0); // mettre ce t_json dans une value
	}
	else
		return (0);
	return (1);
}

static void		wy_t_f_n(t_value **value, char *str, int *i)
{
	(*value)->type = 32;
	if (str[*i] == 'n') {
		wy_check_str(str, "null", i);
		if (!((*value)->ptr = ft_strdup("null")))
			wy_exit("strdup failled");
	}
	else if (str[*i] == 'f') {
		wy_check_str(str, "false", i);
		if (!((*value)->ptr = ft_strdup("false")))
			wy_exit("strdup failled");
	}
	else if (str[*i] == 't') {
		wy_check_str(str, "true", i);
		if (!((*value)->ptr = ft_strdup("true")))
			wy_exit("strdup failled");
	}
	else
		wy_exit("True false or null only");
}

static void		wy_string(t_value **value, char *str, int *i)
{
	char 		*tmp;

	tmp = NULL;
	(*value)->type = 1;
	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		tmp = ft_strjoinfree(tmp, (char[2]){str[*i], '\0'}, 1);
		(*i)++;
	}
	wy_is_end(str[*i]);
	(*value)->ptr = tmp;
	(*i)++;
	wy_is_end(str[*i]);
}

t_value		*wy_value(char *str, int *i)
{
	t_value 	*value;

	value = wy_init_value();
	if (wy_obj_array(&value, str, i))
		;
	else if (str[*i] >= '0' && str[*i] <= '9') // un nombre
	{
		value->type = 8; // 8/16 en fonction
		// prendre la value dans check number pour tout remplir
		wy_check_number(str, i);
	}
	else if (str[*i] == '"') // une string
		wy_string(&value, str, i);
	else // true false null
		wy_t_f_n(&value, str, i);
	return (value);
}