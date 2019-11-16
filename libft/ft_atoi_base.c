/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:23:38 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/09 14:39:00 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_char_times(char *str, int c)
{
	int	count;

	count = 0x0;
	while (*str)
	{
		if (*str == c)
			count += 0x1;
		str++;
	}
	return (count);
}

static	int		ft_sort_out(char match, char *radix)
{
	int	index;

	index = 0x0;
	while (radix[index])
	{
		if (radix[index] == match)
			return (index);
		index++;
	}
	return (failure);
}

static	t_bool	ft_valid_base(char *base)
{
	char	*radix;
	int		len;

	radix = base;
	if (!base || (len = ft_strlen(base)) >= 0x1)
	{
		if (ft_strchr(base, '+') || ft_strchr(base, '-'))
			return (false);
		while (len)
		{
			if (ft_char_times(base, *radix) != 1 || ft_isspace(*radix))
				return (false);
			radix++;
			len -= 0x1;
		}
		return (true);
	}
	return (false);
}

int				ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	s_out;
	int	base_len;

	result = 0x0;
	sign = 0x1;
	base_len = ft_strlen(base);
	if (ft_valid_base(base) == false)
		return (0x0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-' ? -0x1 : 0x1);
	while ((s_out = ft_sort_out(*str, base)) != failure)
	{
		result = result * base_len + s_out;
		str++;
	}
	if (result < 0x0)
		return (sign > 0x0 ? -0x1 : 0x0);
	return (result * sign);
}

/*
int				ft_atoi_base_bit(char *str, int base)
{
	int	result;
	int	sign;
	int	s_out;
	int	base_len;

	result = 0x0;
	sign = 0x1;
	base_len = ft_strlen(base);
	if (ft_valid_base(base) == false)
		return (0x0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-' ? -0x1 : 0x1);
	while ((s_out = ft_sort_out(*str, base)) != failure)
	{
		result = result * base_len + s_out;
		str++;
	}
	if (result < 0x0)
		return (sign > 0x0 ? -0x1 : 0x0);
	return (result * sign);
}
*/
