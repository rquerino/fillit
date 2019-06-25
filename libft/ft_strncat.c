/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:50:00 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 17:43:27 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Appends no more then n characters from s2 to s1 and adds '\0'.
 ** Returns the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (*(s1 + i))
		i++;
	while (*(s2 + j) && j < n)
	{
		*(s1 + i + j) = *(s2 + j);
		j++;
	}
	*(s1 + i + j) = '\0';
	return (s1);
}
