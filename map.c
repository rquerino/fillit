


#include "fillit.h"
#include <stdio.h>

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
	while (j < size)
	{
		map[j] = malloc(sizeof(char) * size);
		while (i < size)
		{
			map[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
}
/*
** Don't need them anymore
int		ft_tetr_right(t_tetr *piece, int j)
{
	if (piece->coords[j].x + 1 == piece->coords[j + 1].x)
		return (1);
	else
		return (0);
}

int		ft_tetr_left(t_tetr *piece, int j)
{
	if (piece->coords[j].x - 1 == piece->coords[j + 1].x)
		return (1);
	else
		return (0);
}

int		ft_tetr_down(t_tetr *piece, int j)
{
	if (piece->coords[j].y + 1 == piece->coords[j + 1].y)
		return (1);
	else
		return (0);	
}
*/

/*
** Checks if the piece fits in this map x,y position
** in case it is a 
** .#..
** .##.
** .#..
** ....
** the tetr is stored like this: 
** y,x: 0,1 ; 1,1 ; 1,2 ; 2;1
** Always storing from top to right, how to solve all cases?
** NOW WORKING!!!!!!
*/

int	ft_piecefits(t_tetr *piece, char **map, int x, int y)
{
	int i;
	//int	ok;
	int	varx;
	int	vary;

	varx = x;
	vary = y;
	i = 0;
	//ok = 0;
	if (map[y][x] == '.')
	{
		while (i <= 3)
		{
			if (i > 0)
			{
				vary += piece->coords[i].y - piece->coords[i - 1].y;
				varx += piece->coords[i].x - piece->coords[i - 1].x;
			}
			if (//(ft_tetr_right(piece, i) || ft_tetr_left(piece, i)|| ft_tetr_down(piece, i)) && 
				map[vary][varx] == '.')
			{
				/*/ok = 1;*/
				printf("ok, x = %d y = %d !\n", varx, vary);
				i++;
			}
			/*
			if (ft_tetr_left(piece, i) && map[y + vary][x + varx] == '0')
			{
				ok = 1;
				printf("i = %d and 1 left!\n", i);
			}
			if (ft_tetr_down(piece, i) && map[y + vary][x + varx] == '0')
			{
				ok = 1;
				printf("i = %d and 1 down!\n", i);
			}*/
			
			//if (ok == 0)
			else
			{
				printf("not ok on x = %d, y = %d\n", x + varx, y + vary);
				return (0);			
			}
			//ok = 0;
			//i++;
		}
		printf("It FITS!\n");
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
