/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:31:36 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 16:40:36 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Aux function to ft_strsplit. Counts how many words are in a string s
 ** separated by a char c.
*/

size_t	ft_word_count(const char *s, char c)
{
	unsigned int	i;
	size_t			count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			count++;
		while (*(s + i) != c && *(s + i + 1))
			i++;
		i++;
	}
	return (count);
}
