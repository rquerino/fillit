/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:55:17 by rquerino          #+#    #+#             */
/*   Updated: 2019/07/10 13:28:06 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_line(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub(*str, 0, i);
		tmp = ft_strdup((*str) + i + 1);
		ft_strdel(str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	ft_return(int fd, int r, char **str, char **line)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && str[fd] == NULL)
		return (0);
	else
		return (ft_read_line(&str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			r;
	static char	*str[4864];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ft_return(fd, r, str, line));
}
