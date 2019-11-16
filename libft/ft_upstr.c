/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:40:19 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/04 15:45:53 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_upstr(char *lower)
{
	int		index;
	char	*upper;

	index = 0x0;
	upper = ft_strnew(ft_strlen(lower));
	while (lower[index])
	{
		if (ft_islower(lower[index]))
			upper[index] = ft_toupper(lower[index]);
		else
			upper[index] = lower[index];
		index += 0x1;
	}
	return (upper);
}
