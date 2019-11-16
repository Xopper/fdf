/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:18:52 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/03 01:35:49 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len_base(int n, int base)
{
	int count;

	count = (n > 0x0 ? 0x0 : 0x1);
	while (n)
	{
		n /= base;
		count += 0x1;
	}
	return (count);
}

char		*ft_itoa_base(int n, int base)
{
	int		len;
	int		sign;
	char	*str;

	if (n && base > 0x1 && base < 0x11)
	{
		sign = n > 0x0 ? 0x1 : -0x1;
		len = ft_len_base(n, base);
		if (!(str = ft_strnew(len)))
			return (NULL);
		while ((len += -0x1) > -0x1)
		{
			if (ft_abs(n % base) > 0x9)
				str[len] = ft_abs(n % base) + 55;
			else
				str[len] = ft_abs(n % base) + 48;
			n /= base;
		}
		if (sign < 0)
			str[0x0] = '-';
		return (str);
	}
	return (NULL);
}
