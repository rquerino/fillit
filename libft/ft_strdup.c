/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:11:25 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/14 17:12:04 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Allocates memory for a copy of string s1, does the copy,
 ** and returns a pointer to it.
*/

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	copy = (char *)malloc(sizeof(*copy) * (i + 1));
	if (!copy)
		return (NULL);
	j = 0;
	while (*(s1 + j) != '\0')
	{
		*(copy + j) = *(s1 + j);
		j++;
	}
	*(copy + j) = '\0';
	return (copy);
}
