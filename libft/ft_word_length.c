/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:40:45 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 16:51:36 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Aux function to ft_strsplit. Gets the word length after the first
 ** appearances of char c and before its next appearance.
*/

size_t	ft_word_length(const char *s, char c)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (*(s + i) == c)
		i++;
	while (*(s + i) != c && *(s + i))
	{
		i++;
		len++;
	}
	return (len);
}
