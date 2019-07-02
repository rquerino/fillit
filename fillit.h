#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct  s_point
{
    int x;
    int y;
}               t_point;

typedef struct  s_tetr
{
    int id;
    int used;
    t_point **coords;
    int height;
    int width;
}               t_tetr;

int		    ft_checkchars(char *buff);
int			ft_checkformat(char *buff);
int			ft_checkconnections(char *buff);
void		ft_positions(char *buff, int *pos);

#endif