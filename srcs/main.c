
#include "../includes/json.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putendl_fd("Seulement un argument", 2);
        return (1);
    }
    char * str = wy_open_read(argv[1]);
    if (!str)
    {
        ft_putendl_fd("Le fichier est incorrect", 2);
        return (1);
    }
    ft_putendl_fd("Le fichier est correct", 2);
    wy_loop(str);
    return 0;
}