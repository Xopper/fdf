/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 23:30:40 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/15 21:06:41 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 200000

void	ft_join_free(char **rest, char *buff);
int		get_next_line(const int fd, char **line);
#endif
