/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:51:11 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/15 11:46:54 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Allocates with malloc and returns a "fresh" '\0' ending string
 ** representing the int n.
*/

static int		ft_num_length(int n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while ((n /= 10))
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0) ? 1 : 0;
	len = ft_num_length(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	*(str + len--) = '\0';
	while (len >= neg)
	{
		if (n < 0)
			n *= -1;
		*(str + len) = n % 10 + '0';
		n /= 10;
		len--;
	}
	if (neg)
		*(str + 0) = '-';
	return (str);
}
