/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:56:42 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 17:59:14 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Locates the first occurrence of needle in haystack, where no more
 ** than n characters are searched.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && i < n)
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && i + j < n)
		{
			j++;
			if (!*(needle + j))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
