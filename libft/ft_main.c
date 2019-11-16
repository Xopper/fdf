/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:40:20 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/09 14:59:56 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_bool  ft_isupperstr(char *str)
{
	int i = 0;
    while (str[i])
    {
        if (ft_isalpha(str[i]))
        {
            if (ft_islower(str[i]))
                return (false);
        }
        i += 1;
    }
    return (true);
}

t_bool  ft_islowstr(char *str)
{
	int i = 0;
    while (str[i])
    {
        if (ft_isalpha(str[i]))
        {
            if (ft_isupper(str[i]))
                return (false);
        }
        i += 1;
    }
    return (true);
}

int		ft_get_color(char *data)
{
    char *to_upper;
    int color;
	if (ft_strstr(data, "0x"))
	{
		to_upper = ft_upstr(ft_strstr(data, "0x") + 2);
		// if (ft_islowstr(ft_strstr(data, "0x") + 2))
			// return (ft_atoi_base(ft_strstr(data, "0x") + 2, "0123456789abcdef"));
		// if (ft_isupperstr(ft_strstr(data, "0x") + 2))
        color = ft_atoi_base(to_upper, "0123456789ABCDEF");
        ft_strdel(&to_upper);
		    return (color);
	}
	return (B_COLOR);
}

int main()
{
    printf("the return is [%#x]\n", ft_get_color("13,0xff"));
    return 0;
}

