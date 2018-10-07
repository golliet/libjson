
#include "json.h"

static int			wy_obj(char *str, int i, int level)
{
	i++;
	while (str[i] && str[i] != '"') {
		ft_putchar(str[i]);
		i++;
	}
	i++;
	if (!str[i])
		return (-1);
	while (str[i] && wy_is_space(str[i]))
		i++;
	if (!str[i] || str[i] != ':')
		wy_exit("missing :");
	ft_putstr(": ");
	i++;
	while (str[i] && wy_is_space(str[i]))
		i++;
	wy_is_end(str[i]);
	i = wy_value(str, i, level);
	if (!(str[i] == ',' || str[i] == '}' || str[i] == ']' || str[i] == '\n'))
		wy_exit("invalidsfsdfd");
	i++;
	return (i);
}

static int 		wy_array(char *str, int i, int level)
{
	i = wy_value(str, i, level);
	if (!(str[i] == ',' || str[i] == '}' || str[i] == ']' || str[i] == '\n'))
		wy_exit("invalidsfsdfd");
	i++;
	return (i);
}

int 		wy_loop_obj(char *str, int i, int level)
{
	wy_level(level);
	printf("-> {\n");
	i++;
	while (str[i] != '}')
	{
		while (str[i] && wy_is_space(str[i]))
			i++;
		wy_is_end(str[i]);
		if (str[i] == '}')
			break ;
		i = wy_obj(str, i, level);
		i++;
	}
	wy_level(level);
	printf("<- }\n");
	return (i);
}

int 		wy_loop_array(char *str, int i, int level)
{
	wy_level(level);
	printf("-> [\n");
	i++;
	while (str[i] != ']')
	{
		while (str[i] && wy_is_space(str[i]))
			i++;
		wy_is_end(str[i]);
		if (str[i] == ']')
			break ;
		i = wy_array(str, i, level);
		i++;
	}
	wy_level(level);
	printf("-> ]\n");
	return (i);
}

int        wy_loop(char *str, int i, int level)
{
	printf("str |%c|\n", str[0]);
	if (str[0] == '{')
		i = wy_loop_obj(str, i, level);
	else if (str[0] == '[')
		i = wy_loop_array(str, i, level);
	else
		ft_putendl_fd("Premier caracter invalide", 2);
	return (i);
}