/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:00:11 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/16 16:25:53 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Converts the initial portion of the string to int.
 ** Returns the converted value.
*/

int		ft_atoi(const char *str)
{
	unsigned long long	result;
	unsigned long long	max;
	int					neg;
	int					i;

	neg = 1;
	result = 0;
	max = 9223372036854775807;
	i = 0;
	while (*(str + i) == ' ' || *(str + i) == '\n' || *(str + i) == '\t'
			|| *(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == '\r')
		i++;
	if (*(str + i) == '-')
		neg = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		result = result * 10 + (*(str + i) - '0');
		i++;
	}
	if (result > max)
		return ((neg < 0) ? 0 : -1);
	return (result * neg);
}
