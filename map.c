


#include "fillit.h"

/*
** Gets the size of the map size x size
*/

int	ft_sqrsize(int i)
{
	int size;

	size = 2;
	while (size * size < i)
		size++;
	return (size);
}

/*
** Crates a string **map[size][size]
*/

void	ft_createmap(int size, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			map[j][i] = 0;
			i++;
		}
		j++;
		i = 0;
	}
}

int		ft_tetr_hor(t_tetr *piece, int j)
{
	if (piece->coords[j].x == piece->coords[j + 1].x + 1)
		return (1);
	else
		return (0);
}

int		ft_tetr_ver(t_tetr *piece, int j)
{
	if (piece->coords[j].y == piece->coords[j + 1].y + 1)
		return (1);
	else
		return (0);	
}

int		ft_puttetr(t_tetr *piece, char **map, int x, int y)
{
	int j;
	int	hor;
	int	ver;

	j = 0;
	hor = 0;
	ver = 0;
	while (j < 4)
	{
		if (map[y + ver][x + hor] == 0)
		{
			map[x + ver][y + hor] = piece->id + 23;
			if ((ft_tetr_hor(piece, j)))
			{
				if (map[y][x + hor + 1] == 0)
					map[y][x + hor + 1] = piece->id + 23;
				else
					return (0);
				hor++;
			}
			if ((ft_tetr_ver(piece, j)))
			{
				if (map[y + ver + 1][x] == 0)
					map[y + ver + 1][x] = piece->id + 23;
				else
					return (0);
				ver++;
			}
		}
		j++;
	}
	return (1);
}