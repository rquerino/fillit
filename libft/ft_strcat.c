/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:43:10 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 17:22:30 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Append a copy of s2 to the end of s1, then add '\0'.
 ** Returns the pointer s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*(s1 + i))
		i++;
	while (*(s2 + j))
	{
		*(s1 + i + j) = *(s2 + j);
		j++;
	}
	*(s1 + i + j) = '\0';
	return (s1);
}
