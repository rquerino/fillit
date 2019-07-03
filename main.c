/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:26:09 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/03 12:29:55 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetr	*pieces;
	char	*buff;
	int		i;
	int		order;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		i = 0;
		order = 1;
		while (get_next_line(fd, &buff) > 0)
		{
			if (ft_ultimatechecker(buff))
			{
				ft_positions(buff, *pieces[i]); //store coordinates
				ft_size(buff, *pieces[i]); //store height and width
				pieces[i].id = order;
				pieces[i].used = 0;
				i++;
				order++;
			}
			else
				return (0);
		}
	}
}
