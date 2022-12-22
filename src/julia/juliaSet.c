/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaSet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:28:15 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/22 05:51:46 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	eq(float *x, float *y, t_init *dep)
{
	float	xx;
	float	yy;
	float	twoxy;

	xx = *x * *x ;
	yy = *y * *y;
	twoxy = 2 * *x * *y;
	*x = xx - yy - dep->j.x;
	*y = twoxy - dep->j.y;
	if (xx * yy > 4.0)
		return (0);
	return (1);
}

int	assigne(t_init *dependency)
{
	return ((dependency->x.max - (dependency->x.min)));
}

void	juliatset(t_init *dependency)
{
	int		i;
	int		j;
	float	a;
	float	b;
	int		itr;

	j = -1;
	while (j++ < dependency->hight)
	{
		i = -1;
		while (i++ < dependency->width)
		{
			a = ((float)i / dependency->width)
				* (dependency->x.max - (dependency->x.min))
				+ (dependency->x.min);
			b = ((float)j / dependency->hight)
				* (dependency->y.max - (dependency->y.min))
				+ (dependency->y.min);
			itr = 0;
			while (eq(&a, &b, dependency) == 1 && itr < dependency->max_itr)
				itr++;
			if (0 < itr && itr < dependency->max_itr)
				printpixels(dependency, i, j, itr);
		}
	}
}
