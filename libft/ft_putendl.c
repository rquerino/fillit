/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:56:10 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/15 11:49:22 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Outputs the string s to the standard output followed by '\n'.
*/

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
