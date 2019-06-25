/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:26:07 by dpeck             #+#    #+#             */
/*   Updated: 2018/05/27 23:29:40 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**create_puzzle(char **input)
{
	char	**puzzle;
	int		i;
	int		j;

	i = 0;
	puzzle = (char**)malloc(sizeof(char*) * 9);
	while (i < 9)
	{
		puzzle[i] = (char*)malloc(sizeof(char) * 9);
		j = 0;
		while (j < 9)
		{
			puzzle[i][j] = input[i + 1][j];
			if (puzzle[i][j] == '.')
				puzzle[i][j] = '0';
			j++;
		}
		i++;
	}
	return (puzzle);
}

void	print_puzzle(char **puzzle)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(puzzle[i][j]);
			j++;
			if (j < 9)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}

int		row_check(char **puzzle, int row, char num)
{
	int col;

	col = 0;
	while (col < 9)
	{
		if (puzzle[row][col] == num)
			return (1);
		col++;
	}
	return (0);
}

int		col_check(char **puzzle, int col, char num)
{
	int row;

	row = 0;
	while (row < 9)
	{
		if (puzzle[row][col] == num)
			return (1);
		row++;
	}
	return (0);
}
