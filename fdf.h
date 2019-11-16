/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 02:41:49 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/09 03:05:15 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

#include<stdio.h>


# define H_COEF 10
# define Z_COEF 10
# define TR_COEF 600

# define B_COLOR 0x32bfae

typedef struct  s_rgb
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;

}               t_rgb;

typedef struct  s_indexs
{
    int cl;
    int ln;
}               t_indexs;

typedef struct  s_cord
{
    int x;
    int y;
    int z;
    int clr;
}               t_cord;

typedef struct  s_fdf_file
{
    void    *ptr;
    void    *win;
    int     width;
    int     height;
    int     size;
    int     dx;
    int     dy;
    int     dxi;
    int     dyi;
    int     sx;
    int     sy;
    int     p;
}               t_fdf_file;

void    ft_iso(int *x, int *y, int z, t_fdf_file *map);
void	ft_error(int argc, char **argv, t_bool stat);
void    ft_plot_high(t_cord st, t_cord fn, t_fdf_file *map, int clr);
void    ft_plot_low(t_cord st, t_cord fn, t_fdf_file *map, int clr);
void	ft_plot_low_all(t_cord st, t_cord fn, t_fdf_file *map, int clr); // new
void	ft_plot_high_all(t_cord st, t_cord fn, t_fdf_file *map, int clr); // new
int		ft_gradient(int color, float ratio);
t_bool  ft_checkmap(char *fdf_file, t_fdf_file *map);
void    ft_store_data(char *fdf_file, t_cord **data, t_fdf_file *map);
void	ft_draw_line(t_cord st, t_cord fn, t_fdf_file *map, int clr);
void	ft_draw_data(t_cord **cord, t_fdf_file map);
int     ft_get_color(char *data);
t_cord	**ft_create_map(t_fdf_file map);
void	ft_iso_shit(t_fdf_file *map, t_cord **cords);
t_bool  ft_isupperstr(char *str);
t_bool  ft_islowstr(char *str);

#endif
