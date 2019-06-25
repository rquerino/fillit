/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:23:17 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 16:49:07 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Copies bytes from string src to string dst until the character c
 ** (converted to unsigned char) occurs in the string src.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		*(ptr + i) = *(ptr2 + i);
		if (*(ptr2 + i) == ((unsigned char)c))
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
