/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:33:41 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/09 11:50:38 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This functions will read the buffer and store the information
** in a t_tetr struct.
*/

/*
** This function will return a t_tetr with coordinates x,y and
** id. X and Y are stored everytime a # is found.
*/

t_tetr	*ft_atributes(char *buff, int id)
{
	t_tetr		*piece;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(piece = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	piece->coords = (t_point*)malloc(sizeof(t_point) * 4);
	piece->id = id;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			piece->coords[j].x = i % 5;
			piece->coords[j].y = i / 5;
			j++;
		}
		i++;
	}
	return (piece);
}

/*
** Reads the fd and store the information on a **t_tetr
** Returns 0 if an error occurred, or the number of tetriminos added..
*/

int		ft_createtetr(int fd, t_tetr **pieces)
{
	int		i;
	int		j;
	char	*str;
	char	*buff;

	str = ft_strnew(20);
	i = 0;
	j = 0;
	while (get_next_line(fd, &buff) > 0)
		if (ft_strlen(buff) > 2 && (++j || 1))
		{
			ft_strcat(ft_strcat(str, buff), "\n");
			if (j > 0 && j % 4 == 0)
			{
				if (ft_ultimatechecker(str) == 0)
					return (0);
				pieces[i] = ft_atributes(str, i + 1);
				i++;
				ft_bzero(str, 20);
			}
		}
	pieces[i] = NULL;
	ft_strdel(&str);
	return (i);
}

int		ft_checklines(int fd)
{
	char	*buff;
	int		row;

	row = 0;
	while (get_next_line(fd, &buff) > 0)
	{
		row++;
		if (row >= 1 && row <= 4 && ft_strlen(buff) != 4)
			return (0);
		if (row == 5 & ft_strlen(buff) > 0)
			return (0);
		if (row == 5)
			row = 0;
	}
	if (row != 4)
		return (0);
	return (1);
}

int		ft_test_and_create(t_tetr **pieces, int fd1, int fd2)
{
	if (ft_checklines(fd1) == 0)
		return (0);
	if (ft_createtetr(fd2, pieces) == 0)
		return (0);
	return (1);
}
