/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:19:43 by ahaloua           #+#    #+#             */
/*   Updated: 2019/10/30 09:09:35 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		s;
	long	oput;

	oput = 0x0;
	s = 0x1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		s = (*str++ == '-' ? -0x1 : 0x1);
	while (*str && ft_isdigit(*str))
	{
		oput = oput * 0xA + *str - '0';
		str++;
	}
	if (oput < 0x0)
		return (s > 0x0 ? -0x1 : 0x0);
	return (oput * s);
}
