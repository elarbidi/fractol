/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaSet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:28:15 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/21 05:49:20 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


static int eq(float *a,float *b){
    float aa = *a * *a ;
	float bb = *b * *b;
	float twoab = 2 * *a * *b;
	*a = aa-bb-0.70176;
    *b = twoab - 0.3842;
	if(aa*bb > 4.0){
		return 0;
	}
    return 1;
    
}

void	juliatSet(t_init *dependency)
{
	int i = 0;
	int j = 0;
	float a;
	float b;
	int itr;

	j=0;
	while( j < dependency->hight){
		i = 0;
		while(i < dependency->width){
			a= ((float)i/dependency->width)*(dependency->x.max -(dependency->x.min))+(dependency->x.min);
			b= ((float)j/dependency->hight)*(dependency->y.max - (dependency->y.min))+(dependency->y.min);
			itr = 0;
			while(eq(&a,&b) == 1 && itr < dependency->max_itr)
				itr++;
			if(0 < itr  && itr < dependency->max_itr)
				printPixels(dependency->mlx,dependency->win, i, j,itr);
			i++;
		}
		j++;
	}
}
