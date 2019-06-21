/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:05:52 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/05/20 22:44:28 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int e, int x);

void	rush(int x, int y)
{
	int j;

	j = 1;
	if ((y < 1) || (x < 1))
	{
		return ;
	}
	while (j <= y)
	{
		if ((j == 1) || (j == y))
		{
			ft_putchar(1, x);
			write(1, "\n", 1);
		}
		else
		{
			ft_putchar(0, x);
			write(1, "\n", 1);
		}
		j++;
	}
}
