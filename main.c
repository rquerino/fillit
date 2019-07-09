/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:26:09 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/09 11:45:17 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Cleans the map to scratch '.'
*/

void	ft_cleanmap(char **map, int size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

/*
** Prints the final map
*/

void	ft_printmap(char **map, int size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

/*
** Recursive. Tries to fit every piece in closer to the top left.
** Before adding +1 on map, tries all positions!
** If returns 0, while in main function adds +1 mapsize.
*/

int		ft_fillit(t_tetr **pieces, char **map, int mapsize, int n)
{
	t_point pos;

	if (pieces[n] == NULL)
		return (1);
	pos.x = 0;
	pos.y = 0;
	while (pos.y < mapsize)
	{
		while (pos.x < mapsize)
		{
			if ((ft_piecefits(pieces[n], map, pos, mapsize)))
			{
				ft_puttetr(pieces[n], map, pos.x, pos.y);
				if (ft_fillit(pieces, map, mapsize, n + 1))
					return (1);
				else
					ft_cleanpiece(pieces[n], map, mapsize);
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	return (0);
}

void	ft_main(t_tetr **pieces, char **map, int fd1, int fd2)
{
	static int	mapsize;

	mapsize = 2;
	if (fd1 != -1 && (ft_test_and_create(pieces, fd1, fd2)))
	{
		map = malloc(sizeof(char) * 100);
		ft_createmap(10, map);
		while (ft_fillit(pieces, map, mapsize++, 0) == 0)
			ft_cleanmap(map, mapsize);
		ft_printmap(map, mapsize - 1);
	}
	else
		ft_putstr("error\n");
}

int		main(int argc, char **argv)
{
	t_tetr		**pieces;
	int			fd1;
	int			fd2;
	char		**map;

	if (argc == 2)
	{
		pieces = malloc(sizeof(t_tetr*) * 27);
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[1], O_RDONLY);
		map = malloc(sizeof(char) * 100);
		ft_createmap(10, map);
		ft_main(pieces, map, fd1, fd2);
		ft_strdel(map);
		free(pieces);
	}
	else
		ft_putstr("Usage: ./fillit <tetriminoes_file>\n");
	return (0);
}
