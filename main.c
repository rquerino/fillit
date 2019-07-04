/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:26:09 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/04 16:31:01 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
						break;;
					j = -1;
					str = ft_strnew(20);
				}
				j++;
			}
		}
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
	printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[0]->id, pieces[0]->used,
			pieces[0]->coords[0].x, pieces[0]->coords[0].y, pieces[0]->height, pieces[0]->width);
	printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[0]->id, pieces[0]->used,
			pieces[0]->coords[1].x, pieces[0]->coords[1].y, pieces[0]->height, pieces[0]->width);
	printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[0]->id, pieces[0]->used,
			pieces[0]->coords[2].x, pieces[0]->coords[2].y, pieces[0]->height, pieces[0]->width);
	printf("id: %d, used: %d, x: %d, y: %d, height: %d, width: %d\n", pieces[0]->id, pieces[0]->used,
			pieces[0]->coords[3].x, pieces[0]->coords[3].y, pieces[0]->height, pieces[0]->width);
	}
	return (0);
}
