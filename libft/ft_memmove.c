/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:13:25 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 13:34:48 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Copies len bytes from string src to string dst.
 ** Returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*ptr_src;
	size_t	i;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (ptr_dst > ptr_src)
		while (len--)
			*(ptr_dst + len) = *(ptr_src + len);
	else
		while (i < len)
		{
			*(ptr_dst + i) = *(ptr_src + i);
			i++;
		}
	return (dst);
}
