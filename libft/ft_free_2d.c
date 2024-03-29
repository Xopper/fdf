/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 00:53:40 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/17 17:23:42 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d(char **free_me)
{
	int i;

	i = 0x0;
	if (free_me[i])
	{
		while (free_me[i])
		{
			ft_strdel(&free_me[i]);
			i += 0x1;
		}
		ft_strdel(free_me);
	}
}
