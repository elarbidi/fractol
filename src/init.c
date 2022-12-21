/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:23:50 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/21 01:24:48 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_init *init_dependency(int width, int hight)
{
    t_init  *dependency;

    dependency = malloc(sizeof(t_init));
	dependency->width = width;
	dependency->hight = hight;
	dependency->x.max = 0.7;
	dependency->x.min = -2.0;
	dependency->y.max = 1.2;
	dependency->y.min = -1.2;
	dependency->max_itr = 100;
	dependency->mlx = mlx_init();
	dependency->win = mlx_new_window(dependency->mlx, width, hight, "fractol");
	dependency->img = mlx_new_image(dependency->mlx, width, hight);
	return (dependency);
}