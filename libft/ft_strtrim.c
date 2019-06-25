/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:17:33 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 17:11:37 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Allocates with malloc and returns a fresh copy of s wihout spaces
 ** at the start or end of the string.
*/

char		*ft_strtrim(char const *s)
{
	int i;
	int j;

	if (!s)
		return (NULL);
	i = ft_initial_spaces(s);
	j = ft_final_spaces(s) - i;
	if (j <= 0)
		return (ft_strnew(0));
	return (ft_strsub(s, i, j));
}
