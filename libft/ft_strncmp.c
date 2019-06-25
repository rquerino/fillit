/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:26:41 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/15 11:58:41 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Compares no more than n characters. Characters after '\0' are not compared.
 ** Returns >0, <0 or 0, the first different unsigned char s1 - s2.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(s1 + i) != *(s2 + i))
			return (((unsigned char)*(s1 + i)) - ((unsigned char)*(s2 + i)));
		else if (*(s1 + i) == '\0')
			return (0);
		i++;
	}
	return (0);
}
