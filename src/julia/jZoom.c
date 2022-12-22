/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jZoom.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:32:19 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/22 05:52:39 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ranger(t_init *param, float range_x, float range_y, float z)
{
		param->x.min = range_x + ((param->x.min - range_x) * z);
		param->x.max = range_x + ((param->x.max - range_x) * z);
		param->y.min = range_y + ((param->y.min - range_y) * z);
		param->y.max = range_y + ((param->y.max - range_y) * z);
}

int	jzoom(int button, int x, int y, t_init *param)
{
	float	range_x;
	float	range_y;

	range_x = ((float)x / param->width)
		* (param->x.max - (param->x.min)) + (param->x.min);
	range_y = ((float)y / param->hight)
		* (param->y.max - (param->y.min)) + (param->y.min);
	if (button == 4)
	{	
		ranger(param, range_x, range_y, 0.9);
		param->max_itr += 2;
	}
	else if (button == 5)
	{
		ranger(param, range_x, range_y, 1.1);
		param->max_itr -= 2;
	}
	mlx_clear_window(param->mlx, param->win);
	juliatset(param);
	return (0);
}
