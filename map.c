/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:33:35 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/11 14:04:39 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Crates a string **map[size][size]
*/

void	ft_createmap(int size, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		map[j] = malloc(size + 1);
		i = 0;
		while (i < size)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = 0;
		j++;
	}
	map[j] = NULL;
}

/*
** Checks if the piece fits in this map x,y position
** The map is huge. That's why there is a limiter mapsize.
*/

int		ft_piecefits(t_tetr *piece, char **map, t_point pos, int mapsize)
{
	int i;
	int	varx;
	int	vary;

	varx = pos.x;
	vary = pos.y;
	i = -1;
	if (map[vary][varx] == '.')
	{
		while (++i <= 3)
		{
			if (i > 0)
			{
				vary += piece->coords[i].y - piece->coords[i - 1].y;
				varx += piece->coords[i].x - piece->coords[i - 1].x;
				if (varx >= mapsize || vary >= mapsize
						|| (varx < 0 || vary < 0))
					return (0);
			}
			if (map[vary][varx] != '.')
				return (0);
		}
		return (1);
	}
	return (0);
}

/*
** Functions to be used right after ft_piecefits = 1 in the exact x,y position.
*/

void	ft_puttetr(t_tetr *piece, char **map, int x, int y)
{
	int i;
	int	varx;
	int	vary;

	i = 0;
	varx = x;
	vary = y;
	while (i <= 3)
	{
		if (i > 0)
		{
			vary += piece->coords[i].y - piece->coords[i - 1].y;
			varx += piece->coords[i].x - piece->coords[i - 1].x;
		}
		map[vary][varx] = piece->id + '0' + 16;
		i++;
	}
}

/*
** Cleans one specific piece from the map
*/

void	ft_cleanpiece(t_tetr *piece, char **map, int size)
{
	int		x;
	int		y;
	char	letter;

	letter = piece->id + '0' + 16;
	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			if (map[y][x] == letter)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

/*
** Free the memory of map and pieces
*/

void	ft_freeall(char **map, t_tetr **pieces)
{
	int x;

	if (map)
	{
		x = 0;
		while (map[x])
		{
			ft_strdel(&map[x]);
			x++;
		}
		free(map);
	}
	if (pieces)
	{
		x = 0;
		while (pieces[x])
		{
			free(pieces[x]->coords);
			free(pieces[x]);
			x++;
		}
		free(pieces);
	}
}
