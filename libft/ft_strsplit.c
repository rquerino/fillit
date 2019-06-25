/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:49:54 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 16:52:04 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Allocates with malloc and returns an array of "fresh" '\0' ending strings
 ** obtained by spliting s using the char c as delimiter.
*/

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s || !(res = (char **)malloc(sizeof(char *)
						* (ft_word_count(s, c) + 1))))
		return (NULL);
	while (i < ft_word_count(s, c))
	{
		if (!(res[i] = (char *)malloc(sizeof(char)
						* (ft_word_length(&s[k], c) + 1))))
			return (NULL);
		j = 0;
		while (*(s + k) == c)
			k++;
		while (*(s + k) != c && *(s + k))
			res[i][j++] = *(s + k++);
		res[i][j] = '\0';
		i++;
	}
	*(res + i) = NULL;
	return (res);
}
