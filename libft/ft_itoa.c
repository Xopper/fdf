/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:41:32 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/01 00:20:12 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_len(int nbr)
{
	int		len;

	len = (nbr <= 0x0) ? 0x1 : 0x0;
	while (nbr != 0x0)
	{
		nbr = nbr / 0xA;
		len++;
	}
	return (len);
}

char			*ft_itoa(int nbr)
{
	int		len;
	int		sign;
	char	*str;

	sign = (nbr < 0x0) ? -0x1 : 0x1;
	len = ft_len(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = 0x0;
	len--;
	while (len >= 0x0)
	{
		str[len] = '0' + ft_abs(nbr % 0xA);
		nbr = ft_abs(nbr / 0xA);
		len--;
	}
	if (sign == -0x1)
		str[0x0] = '-';
	return (str);
}
