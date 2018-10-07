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
	char 			*t_f_n;
	unsigned char	type;
}                   t_value;

typedef struct      s_json
{
	struct s_json    *next;
	char            *key;
	t_value         *value;
}                   t_json;

/*
** Open Read
*/

int                 wy_open(const char *path);
char                *wy_read(int fd);
char                *wy_open_read(const char *path);

/*
** Parse
*/

t_json				*wy_loop(char *str, int *i, int level);
t_value				*wy_value(char *str, int *i, int level);
t_json				*wy_loop_obj(char *str, int *i, int level, t_json *json);
t_json				*wy_loop_array(char *str, int *i, int level, t_json *json);

/*
** List
*/

void				wy_push(t_json **list, t_value *value, char *key);
void				wy_free_json(t_json **list);
void				wy_display_json(t_json *list);
t_value				*wy_init_value(void);


/*
** MISC
*/

void				wy_is_end(char c);
void				wy_exit(char *str);
void        		wy_level(int level);
int					wy_is_space(char c);



#endif
