/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 09:17:17 by dpeck             #+#    #+#             */
/*   Updated: 2018/05/27 23:35:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		box_check(char **puzzle, int start_row, int start_col, char num)
{
	int row;
	int col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (puzzle[row + start_row][col + start_col] == num)
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int		ft_is_safe(char **puzzle, int row, int col, char num)
{
	return (!row_check(puzzle, row, num)
		&& !col_check(puzzle, col, num)
		&& !box_check(puzzle, row - (row % 3), col - (col % 3), num));
}

int		solve_sudoku(char **puzzle, int row, int col, char num)
{
	if (puzzle[row][col] != '0')
	{
		if (col < 8)
			return (solve_sudoku(puzzle, row, col + 1, num));
		else if (row < 8)
		{
			col = 0;
			return (solve_sudoku(puzzle, row + 1, col, num));
		}
		else
			return (1);
	}
	num = '1';
	while (num <= '9')
	{
		if (ft_is_safe(puzzle, row, col, num))
		{
			puzzle[row][col] = num;
			if (solve_sudoku(puzzle, row, col, num))
				return (1);
			puzzle[row][col] = '0';
		}
		num += 1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	**puzzle;
	int		row;
	int		column;
	char	num;

	num = '0';
	if (argc == 10)
	{
		row = 0;
		column = 0;
		puzzle = create_puzzle(argv);
		if (solve_sudoku(puzzle, row, column, num))
			print_puzzle(puzzle);
		else
			ft_putstr("Error\n");
	}
	return (0);
}
