/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:26:09 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/06 16:41:55 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Recursive. Tries to fit every piece in closer to the top left.
** If can't fit in a 4x4 map, tries on 5x5.
*/

void	ft_fillit(t_tetr **pieces, char **map, int size, int n, int i)
{
	int y;
	int x;
	int	placed;

	y = 0;
	x = 0;
	placed = 0;
	while (y < size && placed == 0)
	{
		while ((x <= 1 || x <= y) && placed == 0)
		{
			printf("Testing piece %d for x = %d and y = %d\n", i, x, y);
			if ((ft_piecefits(pieces[i], map, x, y)))
			{
				printf("Piece %d fits x = %d and y = %d\n", i, x, y);
				ft_puttetr(pieces[i], map, x, y);
				placed = 1;
			}
			x++;
		}
		y++;
		x = 0;
	}
	if (placed == 1 && i + 1 < n)
	{
		ft_fillit(pieces, map, size, n, i + 1);
		printf("piece %i placed, now calling next one.\n", i);
	}
	else if (placed == 0)
	{
		printf("Piece %d could not be placed in this map of size %d.\nCalling ft_fillit again from scratch in size %d\n", i, size, size + 1);
		ft_fillit(pieces, map, size + 1, n, 0);
	}
	printf("All pieces placed.\n");
}

/*
** Gets the size of the map with the fitted pieces to print
*/

int		ft_finalmapsize(char **map)
{
	int x;
	int max;
	int y;


	x = 0;
	y = 0;
	max = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] != '.')
			{
				if (x > y && x > max)
					max = x;
				if (y > x && y > max)
					max = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (max);
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
	while (y <= size)
	{
		while (x <= size)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_tetr	**pieces;
	int		fd;
	int		i;
	char		**map;

	if (argc == 2)
	{
		pieces = malloc(sizeof(t_tetr*) * 27);
		fd = open(argv[1], O_RDONLY);
		if ((i = ft_createtetr(fd, pieces)) > 0)
		{
			map = malloc(sizeof(char) * 120);
			//ft_createmap(ft_sqrsize(i), map);
			ft_createmap(8, map);
			printf("parameters: size %d, n %d\n", ft_sqrsize(i), i);
			ft_fillit(pieces, map, 4, i, 0);
			ft_printmap(map, ft_finalmapsize(map));
			/*
			if (ft_fillit(pieces, map, ft_sqrsize(i), i))
			{
				printf("Solved:\n");
				while (k < 4)
				{
					printf("%s\n", map[k]);
					k++;
				}
			}
			else
				printf("error\n");*/
			
			/* TESTS
			//testing to put a tetrimino in the map
			printf("how many pieces i: %d\n", i);
			printf("map size x size: %d\n", ft_sqrsize(i));
			map[1][1] = '1';
			while (k < 4)
			{
				printf("%s\n", map[k]);
				k++;
			}
			ft_puttetr(pieces[0], map, 0, 0);
			k = 0;
			printf("piece fits: %d\n",  ft_piecefits(pieces[0], map, 0, 0));
			while (k < 4)
			{
				printf("%s\n", map[k]);
				k++;
			} */
			/*
			// Printing atributes
			printf("Atributes of piece:\n");
			i -= 1;
			while (i > -1)
			{
				printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
						pieces[i]->coords[0].x, pieces[i]->coords[0].y, pieces[i]->height, pieces[i]->width);
				printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
						pieces[i]->coords[1].x, pieces[i]->coords[1].y, pieces[i]->height, pieces[i]->width);
				printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
						pieces[i]->coords[2].x, pieces[i]->coords[2].y, pieces[i]->height, pieces[i]->width);
				printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
						pieces[i]->coords[3].x, pieces[i]->coords[3].y, pieces[i]->height, pieces[i]->width);
			i--;
			} */
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}

//Original testing main
/*
int		main(int argc, char **argv)
{
	t_tetr	**pieces;
	char	*str;
	char	*buff;
	int		i;
	int		j;
	int		fd;

	if (argc == 2)
	{
		pieces = malloc(sizeof(t_tetr*) * 27);
		str = ft_strnew(20);
		fd = open(argv[1], O_RDONLY);
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
						break ;
					j = -1;
					str = ft_strnew(20);
				}
				j++;
			}
		}*/
			//testing check OK!!!!
			/*if (j == 3)
			{
				printf("%s\n", str);
				printf("ft_checkchars: %d\n", ft_checkchars(str));
				printf("ft_checkformat: %d\n", ft_checkformat(str));
				printf("ft_checkconnections: %d\n", ft_checkconnections(str));
				printf("ft_ultimatechecker: %d\n", ft_ultimatechecker(str));
			}
			j++;
		} */
		/*
		i -= 1;
		while (i > -1)
		{
			printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
					pieces[i]->coords[0].x, pieces[i]->coords[0].y, pieces[i]->height, pieces[i]->width);
			printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
					pieces[i]->coords[1].x, pieces[i]->coords[1].y, pieces[i]->height, pieces[i]->width);
			printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
					pieces[i]->coords[2].x, pieces[i]->coords[2].y, pieces[i]->height, pieces[i]->width);
			printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[i]->id, pieces[i]->used,
					pieces[i]->coords[3].x, pieces[i]->coords[3].y, pieces[i]->height, pieces[i]->width);
		i--;
		}
	}
	return (0);
}*/
