/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 01:24:29 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/10 22:04:20 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		ft_get_color(char *data)
{
	char *to_upper;
	int color;

	if (ft_strstr(data, "0x"))
	{
		to_upper = ft_upstr(ft_strstr(data, "0x") + 2);
		color = ft_atoi_base(to_upper, "0123456789ABCDEF");
		ft_strdel(&to_upper);
		return (color);
	}
	return (B_COLOR);
}

void	ft_store_data(char *fdf_file, t_cord **data, t_fdf_file *map)
{
	int			fd;
	char		**var;
	char		*buff;
	t_indexs	i;

	fd = open(fdf_file, O_RDONLY);
	i.ln = 0;
	while (get_next_line(fd, &buff) > 0)
	{
		i.cl = -1;
		var = ft_strsplit(buff, ' ');
		// if (buff != NULL)
		// 	ft_strdel(&buff);
		while (++i.cl < map->width && i.ln < map->height)
		{
			
			data[i.ln][i.cl].x = i.cl * Z_COEF + TR_COEF;
			data[i.ln][i.cl].y = i.ln * Z_COEF;
			data[i.ln][i.cl].z = ft_atoi(var[i.cl]) * H_COEF;
			// data[i.ln][i.cl].clr = B_COLOR;
			data[i.ln][i.cl].clr = ft_get_color(var[i.cl]);
			//printf("var[color] [%x] \n",data[i.ln][i.cl].clr);
		}
		i.ln += 1;
		// ft_free_2d(var);
	}
	close(fd);
}
