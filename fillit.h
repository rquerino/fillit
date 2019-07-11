/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:13:55 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/11 13:20:18 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tetr
{
	int		id;
	t_point	*coords;
}				t_tetr;

int				ft_checkchars(char *buff);
int				ft_checkformat(char *buff);
int				ft_checkconnections(char *buff);
int				ft_ultimatechecker(char *buff);
t_tetr			*ft_atributes(char *buff, int id);
int				ft_cleanandreturn0(char *str);
int				ft_createtetr(int fd, t_tetr **pieces);
int				ft_sqrsize(int i);
void			ft_createmap(int size, char **map);
int				ft_tetr_right(t_tetr *piece, int j);
int				ft_tetr_left(t_tetr *piece, int j);
int				ft_tetr_down(t_tetr *piece, int j);
int				ft_piecefits(t_tetr *piece, char **map, t_point pos, int size);
void			ft_puttetr(t_tetr *piece, char **map, int x, int y);
void			ft_cleanpiece(t_tetr *piece, char **map, int size);
int				ft_checklines(int fd);
int				ft_test_and_create(t_tetr **pieces, int fd1, int fd2);
void			ft_freeall(char **map, t_tetr **pieces);

#endif
