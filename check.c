#include "fillit.h"

/* 
** This block of functions will check if the buffer has a valid structure.
** Coordinates:
** 0  1  2  3  4
** 5  6  7  8  9
** 10 11 12 13 14
** 15 16 17 18 19
** Characters required: 4: '\n', 4: '#', 12: '.' 
 */

/*
** Checks that the piece in the buffer has the correct number of hashtags and dots.
** All pieces need to have 4 hashtags, the other chars remaining 12 must be dots.
*/

int			ft_checkchars(char *buff)
{
	int	dot;
	int	hashtag;
    int	i;

	i = 0;
	dot = 0;
	sharp = 0;
	while (i < 20)
	{
		if (buff[i] == '.')
			dot++;
		else if (buff[i] == '#')
			hashtag++;
		i++;
	}
	if ((hashtag == 4) && (dot == 12))
		return (1);
	else
		return (0);
}

/*
** Checks to see if the piece in buff has the correct layout.
** Positions 4, 9, 14 and 19 have to be '\n'.
** All other positions have to be dots or hashtags.
*/

int			ft_checkformat(char *buff)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else if (!(buff[i] == '.' || buff[i] == '#'))
			return (0);
		i++;
	}
	if (!(buff[20] == '\n' || buff[20] == '\0'))
		return (0);
	return (1);
}

/*
** Checks if the piece in buff has a valid tetris shape
** Squares have 8 connections, the others have 6.
** i % 5:
** 0  1  2  3  4
** 0  1  2  3  4
** 0  1  2  3  4
** 0  1  2  3  4
** i / 5:
** 0  0  0  0  0
** 1  1  1  1  1
** 2  2  2  2  2
** 3  3  3  3  3
** i % 5 checks horizontal connections, i / 5 checks vertical.
*/

int			ft_checkconnections(char *buff)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i <= 18)
	{
		if (buff[i] == '#')
		{
			if (i % 5 < 3)
				if (buff[i + 1] == '#')
					c++;
			if (i % 5 > 0)
				if (buff[i - 1] == '#')
					c++;
			if (i / 5 < 3)
				if (buff[i + 5] == '#')
					c++;
			if (i / 5 > 0)
				if (buff[i - 5] == '#')
					c++;
		}
		i++;
	}
	return (c == 6 || c == 8);
}

/*
** Gets the horizontal and verticaul positions of the piece
** Stores min horizontal[0], max horizontal[1]
** min vertical [2] and max vertical[3]
*/

void		ft_positions(char *buff, int *pos)
{
	int	i;

	i = 0;
	pos[0] = 3;
	pos[1] = 0;
	pos[2] = 3;
	pos[3] = 0;
	while (i <= 18)
	{
		if (buff[i] == '#')
		{
			if (i % 5 < pos[0])
				pos[0] = i % 5;
			if (i % 5 > pos[1])
				pos[1] = i % 5;
			if (i / 5 < pos[2])
				pos[2] = i / 5;
			if (i / 5 > pos[3])
				pos[3] = i / 5;
		}
		i++;
	}
}

