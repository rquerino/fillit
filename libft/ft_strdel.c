/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:46:13 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/15 10:47:40 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Takes as a parameter the adress of a string that need to be freed.
 ** Then sets its pointer to NULL.
*/

void	ft_strdel(char **as)
{
	if (as && *as)
		ft_memdel((void **)as);
}
