/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 03:03:15 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/10 16:41:36 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool	ft_checkmap(char *fdf_file, t_fdf_file *map)
{
	int		fd;
	char	**var;
	char	*buff;
	int		count;

	fd = open(fdf_file, O_RDONLY);
	map->height = 0;
	if (!fd || read(fd, NULL, 0))
		return (false);
	while (get_next_line(fd, &buff) != 0)
	{
		count = 0;
		var = ft_strsplit(buff, ' ');
		ft_memdel((void**)&buff);
		while (var[count])
			count += 1;
		map->width = (map->height == 0 ? count : map->width);
		if (map->height != 0 && map->width > count)
			return (failure);
		ft_free_2d(var);
		map->height += 1;
		map->size = map->width * map->height;
	}
	close(fd);
	return (map->size == 0 ? empty : true);
}

t_cord	**ft_create_map(t_fdf_file map)
{
	int i;

	i = 0;
	t_cord ** cord;
	cord = (t_cord **)malloc(sizeof(t_cord *) * map.height);
    while (i < map.height)
    {
    	cord[i] = (t_cord *)malloc(sizeof(t_cord) * map.width);
    	i++;
    }
	cord[i] = 0;
	return (cord);
}

void	ft_error(int argc, char **argv, t_bool stat)
{
	if (argc == 2)
	{
		if (stat == false)
		{
			ft_puterr("No file ");
			ft_errendl(argv[1]);
		}
		else if (stat == failure)
			ft_errendl("Found wrong line length. Exiting.");
		else if (stat == empty)
			ft_errendl("No data found.");
		else
			ft_putendl("all is ok");
	}
	else
		ft_errendl("Usage : ./fdf <filename>");
	if (stat != true)
		exit(0);
}
