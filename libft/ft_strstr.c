/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:42:10 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 17:55:24 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Locates the first occurrence of the string needle
 ** in the string haystack.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			j++;
			if (!*(needle + j))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
