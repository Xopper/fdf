/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:42:34 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/18 01:14:28 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_iso(int *x, int *y, int z, t_fdf_file *map)
{
    int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y)* cos(0.523599);
	*y = -z + (previous_x + previous_y)* sin(0.523599);
}
void	ft_iso_shit(t_fdf_file *map, t_cord **cords)
{
	int x = 0;
	int y = 0;

	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_iso(&cords[y][x].x, &cords[y][x].y, cords[y][x].z , map);
			x++;
		}
		y++;
	}
}

int main(int argc, char **argv)
{
    t_fdf_file map;
    t_cord  **cord;
    t_cord st;
    t_cord fn;
    int i;
    t_bool stat;

    i = 0;
    map.ptr = mlx_init();
    map.win = mlx_new_window(map.ptr, 2500, 1400, "Qsnake");
    ft_checkmap(argv[1], &map);
	ft_error(argc, argv, ft_checkmap(argv[1], &map));
    cord = ft_create_map(map);
    ft_store_data(argv[1], cord, &map);
    ft_iso_shit(&map, cord);
    ft_draw_data(cord, map);
    mlx_loop(map.ptr);
    return (0);
}
