/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlbrotSet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:25:20 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/22 05:51:39 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	eq(t_init *dependency, float *x, float *y, t_ij *t)
{
	float	tmp;

	tmp = *x * *x - *y * *y + ((float)t->i / dependency->width)
		*(dependency->x.max - (dependency->x.min)) + (dependency->x.min);
	*y = 2.0 * *x * *y + ((float)t->j / dependency->hight)
		* (dependency->y.max - (dependency->y.min)) + (dependency->y.min);
	*x = tmp;
	if (*x * *x + *y * *y > 4)
		return (0);
	return (1);
}

void	mandelbrotset(t_init *dependency)
{
	t_ij	t;
	float	x;
	float	y;
	int		itr;

	t.j = 0;
	while (t.j < dependency->hight)
	{
		t.i = 0;
		while (t.i < dependency->width)
		{
			x = 0;
			y = 0;
			itr = 0;
			while (eq(dependency, &x, &y, &t) == 1 && itr < dependency->max_itr)
				itr++;
			if (0 < itr && itr < dependency->max_itr)
				printpixels(dependency, t.i, t.j, itr);
			t.i++;
		}
		t.j++;
	}
}
