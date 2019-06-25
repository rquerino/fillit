/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:25:07 by dpeck             #+#    #+#             */
/*   Updated: 2018/05/27 23:32:50 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
char	**create_puzzle(char **input);
void	print_puzzle(char **puzzle);
int		row_check(char **puzzle, int row, char num);
int		col_check(char **puzzle, int col, char num);
#endif
