/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:33:41 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/05 09:29:04 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This functions will read the buffer and store the information
** in a t_tetr struct.
*/

/*
** This function will return a t_tetr with coordinates x,y and
** height/width. X and Y are stored everytime a # is found.
*/

t_tetr		*ft_atributes(char *buff)
{
	t_tetr		*piece;
	int			pos[4];
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(piece = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	piece->coords = (t_point*)malloc(sizeof(t_point) * 4);
	ft_sizes(buff, pos);
	piece->width = pos[1] - pos[0] + 1;
	piece->height = pos[3] - pos[2] + 1;
	piece->used = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			piece->coords[j].x = i % 5;
			piece->coords[j].y = i / 5;
			j++;
		}
		++i;
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
	{
		if (ft_strlen(buff) > 2)
		{
			ft_strcat(str, buff);
			ft_strcat(str, "\n");
			if (j == 3)
			{
				if (ft_ultimatechecker(str))
				{
					pieces[i] = ft_atributes(str);
					pieces[i]->id = i + 1;
					i++;
				}
				else
					return (0);
				j = -1;
				str = ft_strnew(20);
			}
			j++;
		}
	}
	ft_strdel(&str);
	return (i);
}

