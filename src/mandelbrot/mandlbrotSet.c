/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlbrotSet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:25:20 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/21 05:55:35 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


static int eq(t_init *dependency , float *x, float *y,int i , int j){
    float tmp;
    tmp = *x * *x - *y * *y + ((float)i/dependency->width)*(dependency->x.max -(dependency->x.min))+(dependency->x.min);
	*y = 2.0* *x * *y + ((float)j/dependency->hight)*(dependency->y.max - (dependency->y.min))+(dependency->y.min);
	*x = tmp;
    if(*x * *x + *y * *y > 4){
        return 0;
    }
    return 1;
}

void	mandelbrotSet(t_init *dependency){
	int i;
	int j;
	float x;
	float y;
	int itr;

	j=0;
	while( j < dependency->hight){
		i = 0;
		while(i < dependency->width){
			x = 0;
			y = 0;
			itr = 0;
			while(eq(dependency,&x,&y,i,j) == 1 && itr < dependency->max_itr){
				itr++;
			}
			if(0 < itr  && itr < dependency->max_itr)
				printPixels(dependency->mlx,dependency->win, i, j,itr);
			i++;
		}
		j++;
	}
}
