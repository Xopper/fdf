/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 23:49:02 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/15 21:13:50 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_join_free(char **rest, char *buff)
{
	char *tmp;

	tmp = ft_strjoin(*rest, buff);
	ft_strdel(rest);
	*rest = tmp;
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*rest[0xFF];
	int			ret;
	char		*tmp;

	if ((BUFF_SIZE < 1) || read(fd, NULL, 0) || !line || fd < 0 || fd > 0xFF)
		return (-1);
	ret = 0;
	rest[fd] = !rest[fd] ? ft_strnew(0) : rest[fd];
	while (!ft_strchr(rest[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		ft_join_free(&rest[fd], buf);
	}
	if (rest[fd][0] == '\0' && ret < 1)
	{
		ft_strdel(&rest[fd]);
		return (ret);
	}
	*line = ft_strsub(rest[fd], 0, ft_strcspn(rest[fd], "\n"));
	tmp = ft_strdup(rest[fd][ft_strcspn(rest[fd], "\n")] == '\n' ?
	&rest[fd][ft_strcspn(rest[fd], "\n") + 1] : "\0");
	free(rest[fd]);
	rest[fd] = tmp;
	return (1);
}
