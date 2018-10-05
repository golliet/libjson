//
// Created by Gaetan Olliet on 04/10/2018.
//

#ifndef JSON_H
#define JSON_H

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

#include <stdio.h> //printf

/*
** type
**  1 -> string
**  2 -> object
**  4 -> array
**  8 -> n_l
** 16 -> n_d
** 32 -> bool
*/

typedef struct      s_value
{
    unsigned char   type;
    void            *ptr; // String, Object, array
    long            n_l;
    double          n_d;
}                   t_value;

typedef struct      s_array
{
    t_value         *value;
    struct s_array  *next;
}                   t_array;

typedef struct      s_obj
{
    char            *string;
    t_value         *value;
    struct s_obj    *next;
}                   t_obj;

/*
** Open Read
*/

int                 wy_open(const char *path);
char                *wy_read(int fd);
char                *wy_open_read(const char *path);

/*
** Parse
*/

void        		wy_loop(char *str);
int         		wy_recu(char *str, int i, int level, char c);

/*
** MISC
*/

void				wy_is_end(char c);
void				wy_exit(char *str);
void        		wy_level(int level);
int					wy_is_space(char c);



#endif
