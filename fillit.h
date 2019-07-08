/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:13:55 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/06 16:28:34 by rquerino         ###   ########.fr       */
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
	int		used;
	t_point	*coords;
	int		height;
	int		width;
}				t_tetr;

int		ft_checkchars(char *buff);
int		ft_checkformat(char *buff);
int		ft_checkconnections(char *buff);
void	ft_sizes(char *buff, int *pos);
int		ft_ultimatechecker(char *buff);
t_tetr	*ft_atributes(char *buff);
int		ft_createtetr(int fd, t_tetr **pieces);
int		ft_sqrsize(int i);
void	ft_createmap(int size, char **map);
int		ft_tetr_right(t_tetr *piece, int j);
int		ft_tetr_left(t_tetr *piece, int j);
int		ft_tetr_down(t_tetr *piece, int j);
int		ft_piecefits(t_tetr *piece, char **map, int x, int y);
void	ft_puttetr(t_tetr *piece, char **map, int x, int y);
//int		ft_fillit(t_tetr **pieces, char **map, int size, int n);

#endif
