/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:19:32 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/02 23:01:16 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_moment(unsigned int dur)
{
	if (dur < 60)
		return (ft_strjoin(ft_itoa(dur), (dur == 0x1 ?
				" second ago." : " seconds ago.")));
	else if (dur < 3600)
		return (ft_strjoin(ft_itoa(dur / 60), (dur / 60 == 0x1 ?
				" minute ago." : " minutes ago.")));
	else if (dur < 86400)
		return (ft_strjoin(ft_itoa(dur / 3600), (dur / 3600 == 0x1 ?
				" hour ago." : " hours ago.")));
	else if (dur < 2592000)
		return (ft_strjoin(ft_itoa(dur / 86400), (dur / 86400 == 0x1 ?
				" day ago." : " days ago.")));
	else if (dur <= UINT_MAX)
		return (ft_strjoin(ft_itoa(dur / 2592000), (dur / 2592000 == 0x1 ?
				" month ago." : " months ago.")));
		return (NULL);
}
