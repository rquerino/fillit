/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:35:58 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 17:20:02 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Copies len characters from src into dst. If src is less than len,
 ** fills the remaning of dst with '\0'. Returns dst.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (*(src + i) && (i < len))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < len)
	{
		*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
