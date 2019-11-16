/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelamra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:42:44 by anelamra          #+#    #+#             */
/*   Updated: 2019/06/26 17:42:50 by anelamra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_n(const char *string, const char *reject)
{
	int	count;
	int i;

	i = 0;
	count = 0;
	while (string[i] && string[i] != *reject)
	{
		i++;
	}
	return (i);
}
