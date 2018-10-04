
#include "../includes/json.h"

void        wy_level(int level)
{
    int i;

    i = 0;
    while (i < level)
    {
        ft_putstr("|");
        i++;
    }
}

int         wy_recu(char *str, int i, int level)
{
    int test;

    i++;
    test = i;
    while (str[i])
    {
        if (str[i] == '{' || str[i] == '[')
            i = wy_recu(str, i, level + 1);
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
        i++;
    }
    printf("Erreur pas de fin array\n");
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
            i = wy_recu(str, i, level);
        i++;
    }
}