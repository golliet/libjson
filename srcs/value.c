
#include "json.h"

static int			wy_check_str(char *nft, char *str, int i)
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

static int 		wy_check_number(char *str, int i)
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