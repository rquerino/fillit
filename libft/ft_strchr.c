/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:32:36 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 18:04:35 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Locates the first occurrence of c (converted to char)
 ** in the string s.
*/

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*(s + i) != c)
	{
		if (*(s + i) == '\0')
			return (0);
		i++;
	}
	return ((char *)s + i);
}
