/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:06:24 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 17:34:37 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Aux function to ft_strtrim. Returns the last position without a space
 ** at the end of string s.
*/

int		ft_final_spaces(char const *s)
{
	int j;

	j = ft_strlen(s);
	if (j == 0)
		return (0);
	while (j > 0 && (*(s + j - 1) == ' ' || *(s + j - 1) == '\n'
			|| *(s + j - 1) == '\t'))
		j--;
	return (j);
}
