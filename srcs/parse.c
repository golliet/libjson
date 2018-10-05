
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
	while (str[i] && (str[i] == '.' || (str[i] >= '0' && str[i] <= '9')))
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int			wy_value(char *str, int i, int level)
{
	if (str[i] == '{' || str[i] == '[') // obj ou array
	{
		char c = str[i];
		if (str[i] == '{')
			ft_putstr("-> obj : {\n");
		else
			ft_putstr("-> array : [\n");
		i = wy_recu(str, i, level + 1, str[i]);
		wy_level(level);

		if (c == '{')
			ft_putstr("}\n");
		else
			ft_putstr("]\n");
	}
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

int			wy_key_value(char *str, int i, int level, char c)
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
	if (c == '{')
	{
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
	}
	else
		if (!(str[i] == ',' || str[i] == '}' || str[i] == ']' || str[i] == '\n'))
			wy_exit("invalidsfsdfd");
	return (i);
}

int         wy_recu(char *str, int i, int level, char c)
{
    int test;

    i++;
    test = i;
    while (str[i])
    {
        if (str[i] == '{' || str[i] == '[')
			i = wy_recu(str, i, level + 1, str[i]);
        else if (str[i] == ']')
        {
            wy_level(level);
            printf("array de %d a %d\n", test, i);
            return (i);
        }
        else if (str[i] == '}')
        {
            wy_level(level);
            printf("Obj de %d a %d\n", test, i);
            return (i);
        }
        else if (str[i] == '"')
			i = wy_key_value(str, i, level, c);
        else
        	i++;
    }
    printf("Erreur pas de fin array/obj\n");
    return (i);
}

void        wy_loop(char *str)
{
    int i;
    int level;

    level = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '{' || str[i] == '[')
            i = wy_recu(str, i, level, str[i]);
        i++;
    }
}