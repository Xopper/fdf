/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:28:17 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/08 17:26:39 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_gradient(int color, float ratio)
{
	t_rgb	grad;

	grad.red = ft_round(((color >> 16) & 255) * ratio);
	grad.green = ft_round(((color >> 8) & 255) * ratio);
	grad.blue = ft_round((color & 255) * ratio);
	return ((grad.red << 16) + (grad.green << 8) + grad.blue);
}

void	ft_plot_low(t_cord st, t_cord fn, t_fdf_file *map, int clr)
{
	map->dxi = ft_abs(fn.x - st.x);
	map->dyi = ft_abs(fn.y - st.y);
	map->dx = map->dxi;
	map->dy = map->dyi;
	map->sx = fn.x > st.x ? 1 : -1;
	map->sy = fn.y > st.y ? 1 : -1;
	while (map->dxi >= map->dyi)
	{
		mlx_pixel_put(map->ptr, map->win, st.x, st.y, clr);
		if (st.x == fn.x && st.y == fn.y)
			break ;
		map->dy += map->dyi;
		if (map->dx <= map->dy)
		{
			st.y += map->sy;
			map->dx += map->dxi;
		}
		st.x += map->sx;
	}
}

void	ft_plot_high(t_cord st, t_cord fn, t_fdf_file *map, int clr)
{
	map->dxi = ft_abs(fn.x - st.x);
	map->dyi = ft_abs(fn.y - st.y);
	map->dx = map->dxi;
	map->dy = map->dyi;
	map->sx = fn.x > st.x ? 1 : -1;
	map->sy = fn.y > st.y ? 1 : -1;
	while (map->dxi <= map->dyi)
	{
		mlx_pixel_put(map->ptr, map->win, st.x, st.y, clr);
		if (st.x == fn.x && st.y == fn.y)
			break ;
		map->dx += map->dxi;
		if (map->dx >= map->dy)
		{
			st.x += map->sx;
			map->dy += map->dyi;
		}
		st.y += map->sy;
	}
}

void	ft_draw_line(t_cord st, t_cord fn, t_fdf_file *map, int clr)
{
	map->dx = ft_abs(fn.x - st.x);
	map->dy = ft_abs(fn.y - st.y);
	if (map->dx <= map->dy)
		ft_plot_high(st, fn, map, clr);
	else if (map->dx > map->dy)
		ft_plot_low(st, fn, map, clr);
}

void	ft_draw_data(t_cord **c, t_fdf_file map)
{
	int ln;
	int cl;

	ln = 0;
	while (ln < map.height)
	{
		cl = 0;
		while (cl < map.width)
		{
			if (cl < map.width - 1)
				ft_draw_line(c[ln][cl], c[ln][cl + 1], &map, c[ln][cl].clr);
			if (ln < map.height - 1)
				ft_draw_line(c[ln][cl], c[ln + 1][cl], &map, c[ln][cl].clr);
			cl += 1;
		}
		ln += 1;
	}
}
