/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:19:09 by ahaloua           #+#    #+#             */
/*   Updated: 2019/11/05 23:29:48 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <math.h>

typedef struct	s_rgb
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}				t_rgb;

int main()
{
	t_rgb red;
	float ratio = 0.89;
	int int_rate = ratio * 100;
	int red_pure = 0xffaaee;
	//int blue = 0x00ff00;
	//int green = 0x0000ff;

	red.red = (red_pure >> 16) & 255;
	red.green = (red_pure >> 8) & 255;
	red.blue = (red_pure) & 255;
	printf("[%d] >> red[%d], green[%d], blue[%d]\n", red_pure, red.red, red.green, red.blue);
	// printf("the new value is [%#x]", (red.red << 16) + (red.green << 8) + red.blue);
	// after gradient
	red.red = round(((red_pure >> 16) & 255) * ratio);
	red.green = round(((red_pure >> 8) & 255) * ((double)int_rate / 100));
	red.blue = round(((red_pure) & 255) * ratio);
	printf("[%d] >> red[%d], green[%d], blue[%d]\n", red_pure, red.red, red.green, red.blue);
	printf("the new value is [%#x]", (red.red << 16) + (red.green << 8) + red.blue);
	return (0);
}
