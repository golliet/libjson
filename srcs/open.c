
#include "../includes/json.h"

int         wy_open(const char *path)
{
    struct stat buf;
    int         fd;
    char        *str;

    if (!(str = strstr(path, ".json")))
        return (-1);
    if (!str[6])
        return (-1);
    if (stat(path, &buf) == -1)
        return (-1);
    if (!(buf.st_mode & S_IFREG))
        return (-1);
    if ((fd = open(path, O_RDONLY)) == -1)
        return (-1);
    return (fd);
}

char        *wy_read(int fd)
{
    char    *str;
    ssize_t     rd;
    char    buff[4097];

    str = NULL;
    while ((rd = read(fd, buff, 4096)) > 0)
    {
        buff[rd] = '\0';
        str = ft_strjoinfree(str, buff, 1);
    }
    if (rd == -1)
        ft_strdel(&str);
    close (fd);
    return (str);
}

char        *wy_open_read(const char *path)
{
    int fd;
    fd = wy_open(path);
    if (fd == -1)
        return (NULL);
    return (wy_read(fd));
}