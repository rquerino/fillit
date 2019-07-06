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

int		main(int argc, char **argv)
{
	t_tetr	**pieces;
	int		fd;
	int		i;
	char		**map;
	int		k;

	k = 0;
	if (argc == 2)
	{
		pieces = malloc(sizeof(t_tetr*) * 27);
		fd = open(argv[1], O_RDONLY);
		if ((i = ft_createtetr(fd, pieces)) > 0)
		{
			map = malloc(sizeof(int) * 40);
			ft_createmap(ft_sqrsize(i), map);
			//testing to put a tetrimino in the map
			printf("how many pieces i: %d\n", i);
			printf("map size x size: %d\n", ft_sqrsize(i));
			map[0][0] = '1';
			while (k++ < 4)
				printf("%s\n", map[k]);
			//ft_puttetr(pieces[0], map, 0, 0);
			//k = 0;
			printf("piece fits: %d\n",  ft_piecefits(pieces[0], map, 0, 0));
			//while (k++ < 4)
			//	printf("%s\n", map[k]);
			/*
			// Printing atributes
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
			}*/
		}
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
