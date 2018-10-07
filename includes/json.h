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
	void            *ptr;
	long            n_l;
	double          n_d;
}                   t_value;

typedef struct      s_array
{
	struct s_array  *next;
	unsigned char	type;
	t_value         *value;
}                   t_array;

typedef struct      s_obj
{
	struct s_obj    *next;
	char            *string;
	t_value         *value;
	unsigned char	type;
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

int		        wy_loop(char *str, int i, int level);
int				wy_value(char *str, int i, int level);
int		 		wy_loop_obj(char *str, int i, int level);
int		 		wy_loop_array(char *str, int i, int level);

/*
** MISC
*/

void				wy_is_end(char c);
void				wy_exit(char *str);
void        		wy_level(int level);
int					wy_is_space(char c);



#endif
