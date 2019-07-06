


#include "fillit.h"

/*
** Gets the size of the map size x size
*/

int	ft_sqrsize(int i)
{
	int size;

	size = 2;
	while ((size * size) < i)
		size++;
	return (size * size);
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
	while (j <= size)
	{
		map[j] = malloc(sizeof(char) * size);
		while (i < size)
		{
			map[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
	}
}

int		ft_tetr_right(t_tetr *piece, int j)
{
	if (piece->coords[j].y == piece->coords[j + 1].y
			&& piece->coords[j].x == piece->coords[j + 1].x + 1)
		return (1);
	else
		return (0);
}

int		ft_tetr_left(t_tetr *piece, int j)
{
	if (piece->coords[j].y == piece->coords[j + 1].y
			&& piece->coords[j].x == piece->coords[j + 1].x - 1)
		return (1);
	else
		return (0);
}

int		ft_tetr_down(t_tetr *piece, int j)
{
	if (piece->coords[j].x == piece->coords[j + 1].x
			&& piece->coords[j].y == piece->coords[j + 1].y + 1)
		return (1);
	else
		return (0);	
}

/*
** Checks if the piece fits in this map x,y position
*/

int	ft_piecefits(t_tetr *piece, char **map, int x, int y)
{
	int i;
	int	x2;
	int	y2;

	i = 0;
	x2 = x;
	y2 = x;
	if (map[y][x] == '0')
	{
		while (i < 4)
		{
			if (ft_tetr_right(piece, i))
				if (map[y][x + 1] == '0')
					x++;
			if (ft_tetr_left(piece, i))
				if (map[y][x - 1] == '0')
					x--;
			if (ft_tetr_down(piece, i))
				if (map[y + 1][x] == '0')
					y++;
			i++;
		}
	}
	return (1);
}

int	ft_puttetr(t_tetr *piece, char **map, int x, int y)
{
	int j;
	int	hor;
	int	ver;
	int	added;

	j = 0;
	hor = 0;
	ver = 0;
	added = 0;
	while (j < 4)
	{
		if (map[y + ver][x + hor] == '0')
		{
			map[x + ver][y + hor] = piece->id + 23;
			/*if ((ft_tetr_hor(piece, j)))
			{
				if (map[y + ver][x + hor + 1] == '0')
					map[y + ver][x + hor + 1] = piece->id + 23;
				else
					return (0);
				hor++;
				added = 1;
			}
			if ((ft_tetr_ver(piece, j)))
			{
				if(added == 0)
				{
					if (map[y + ver + 1][x + hor] == '0')
						map[y + ver + 1][x + hor] = piece->id + 23;
				} else if (added == 1)
				{
					if (map[y + ver + 1][x + hor - 1] == '0')
						map[y + ver + 1][x + hor - 1] = piece->id + 23;
					added = 0;
				}
				else
					return (0);
				ver++;
			}*/
			}
		j++;
	}
	return (1);
}
