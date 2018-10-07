
#include "json.h"

int			wy_check_str(char *nft, char *str, int i)
{
	int j;

	j = 0;
	while (nft[i] && nft[i] == str[j])
	{
		j++;
		i++;
	}
	if (str[j])
		wy_exit("True false or null only");
	if (!(nft[i] == ',' || nft[i] == '}' || nft[i] == ']'))
		wy_exit("invalid");
	return (i);
}

int 		wy_check_number(char *str, int i)
{
	while (str[i] && (str[i] == '.' || (str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int			wy_value(char *str, int i, int level)
{
	wy_level(level);
	if (str[i] == '{')
		i = wy_loop_obj(str, i, level + 1);
	else if (str[i] == '[') // obj ou array
		i = wy_loop_array(str, i, level + 1);
	else if (str[i] >= '0' && str[i] <= '9') // un nombre
	{
		i = wy_check_number(str, i);
		ft_putchar('\n');
	}
	else if (str[i] == '"') // une string
	{
		i++;
		while (str[i] && str[i] != '"') {
			ft_putchar(str[i]);
			i++;
		}
		wy_is_end(str[i]);
		i++;
		wy_is_end(str[i]);
		ft_putchar('\n');
	}
	else // true false null
	{
		if (str[i] == 'n') {
			ft_putstr("null");
			i = wy_check_str(str, "null", i);
		}
		else if (str[i] == 'f') {
			ft_putstr("false");
			i = wy_check_str(str, "false", i);
		}
		else if (str[i] == 't') {
			ft_putstr("true");
			i = wy_check_str(str, "true", i);
		}
		else
			wy_exit("True false or null only");
		ft_putchar('\n');
	}
	return (i);
}

int			wy_obj(char *str, int i, int level)
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

int 		wy_array(char *str, int i, int level)
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