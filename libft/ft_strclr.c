/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:56:56 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 13:47:42 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Sets every character of the string to the value '\0'.
*/

void	ft_strclr(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i))
	{
		*(s + i) = 0;
		i++;
	}
}
